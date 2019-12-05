package ar.com.lazoblanco.service.impl;

import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.List;
import java.util.UUID;

import javax.persistence.EntityNotFoundException;

import org.apache.commons.lang3.RandomStringUtils;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.dao.DataIntegrityViolationException;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.GrantedAuthority;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.util.Assert;

import ar.com.lazoblanco.controller.common.CustomValidationException;
import ar.com.lazoblanco.entity.User;
import ar.com.lazoblanco.entity.UserStatusEnum;
import ar.com.lazoblanco.repository.UserRepository;
import ar.com.lazoblanco.security.PasswordChange;
import ar.com.lazoblanco.security.PasswordRecovery;
import ar.com.lazoblanco.security.UserSession;
import ar.com.lazoblanco.service.LoginService;

@Service
@Transactional(propagation = Propagation.SUPPORTS, readOnly = true)
public class LoginServiceImpl implements LoginService {

    private final Logger logger = LoggerFactory.getLogger(this.getClass());

    @Autowired
    UserRepository userRepository;

    @Value("${security.recover.token.validity:12}")
    private int tokenValidityHours;

    @Override
    public User getUserByCredentials(String value, String password) throws Exception {
        Assert.notNull(value, "Value cannot be null.");
        Assert.notNull(password, "Password cannot be null.");
        return userRepository.findByCredentials(value, password);
    }

    @Override
    @Transactional
    public String regeneratePasswordForUser(String uuid) {
        User user = userRepository.findByUuid(uuid);
        user.setPassword(RandomStringUtils.randomAlphabetic(12));
        userRepository.save(user);
        return user.getPassword();
    }

    @Override
    @Transactional
    public String userForgotPassword(String value) {
        User user = userRepository.findByEmailAndStatus(value, UserStatusEnum.ACTIVE);
        if (user == null) {
            throw new EntityNotFoundException("El usuario no está registrado en el sistema.");
        }

        logger.info("Forgot password requested for {}", user.getEmail());

        Calendar now = new GregorianCalendar();
        now.setTime(new Date());
        now.add(Calendar.HOUR_OF_DAY, tokenValidityHours);

        user.setTokenExpirationDate(now.getTime());
        user.setPasswordToken(UUID.randomUUID().toString());

        //emailService.sendForgotPasswordEmail(user);

        return user.getPasswordToken();
    }

    @Override
    @Transactional
    public boolean userConfirmForgotPassword(PasswordRecovery recovery) throws Exception {
        User user = userRepository.findByPasswordToken(recovery.getToken());

        if (user == null) {
            throw new EntityNotFoundException("No se encontró usuario para el token");
        }

        logger.info("Confirm new password by recover e-mail requested for {}", user.getEmail());

        user.setPassword(recovery.getPassword());
        user.setPasswordToken(null);
        user.setStatus(UserStatusEnum.ACTIVE);
        user.setTokenExpirationDate(null);

        logger.info("SUCCESS - Confirm new password by recover e-mail requested for {}", user.getEmail());
        
        return true;
    }

    @Override
    public void invalidateTokens() {
        List<User> users = userRepository.findByPasswordTokenIsNotNullAndTokenExpirationDateAfter(new Date());

        logger.info("Se encontraron " + users.size() + " con token expirado");
        for (User user : users) {
            user.setPasswordToken(null);
            user.setTokenExpirationDate(null);
            userRepository.save(user);
        }

    }

    @Override
    public boolean hasAnyAuthority(List<String> requiredRoles) {
        Authentication authentication = SecurityContextHolder.getContext().getAuthentication();

        for (GrantedAuthority auth : authentication.getAuthorities()) {
            if (requiredRoles.contains(auth.getAuthority()))
                return true;
        }

        return false;
    }

    @Override
    public boolean hasAuthority(String requiredRole) {
        Authentication authentication = SecurityContextHolder.getContext().getAuthentication();
        for (GrantedAuthority auth : authentication.getAuthorities()) {
            if (auth.getAuthority().equals(requiredRole))
                return true;
        }
        return false;
    }

    @Override
    @Transactional
    public String changePassword(PasswordChange passwordChange) throws Exception {
        User user = userRepository.getOne(getUserUuid());
        encryptPasswords(passwordChange);
        if (!passwordChange.getPassword().equals(passwordChange.getPassword2())) {
            throw new DataIntegrityViolationException("Las nuevas contraseñas no coinciden.");
        }

        if (!user.getPassword().equals(passwordChange.getOldPassword())) {
            throw new CustomValidationException("La constraseña no es correcta.");
        }

        user.setPassword(passwordChange.getPassword());
        userRepository.save(user);

        return user.getUuid();
    }

    private void encryptPasswords(PasswordChange passwordChange) throws Exception {
        passwordChange.setOldPassword(passwordChange.getOldPassword());
        passwordChange.setPassword(passwordChange.getPassword());
        passwordChange.setPassword2(passwordChange.getPassword2());
    }

    protected String getUserUuid() {
        Authentication auth = SecurityContextHolder.getContext().getAuthentication();
        return ((UserSession) auth.getPrincipal()).getUserUuid();
    }

	@Override
	public UserSession loadUserByUsername(String username) throws UsernameNotFoundException {
		return new UserSession(userRepository.findByEmailAndStatus(username, UserStatusEnum.ACTIVE));
	}
    
}