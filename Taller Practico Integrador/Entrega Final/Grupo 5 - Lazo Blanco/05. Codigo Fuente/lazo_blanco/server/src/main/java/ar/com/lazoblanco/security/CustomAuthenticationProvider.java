package ar.com.lazoblanco.security;

import java.util.Collection;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.access.AccessDeniedException;
import org.springframework.security.authentication.AuthenticationProvider;
import org.springframework.security.authentication.BadCredentialsException;
import org.springframework.security.authentication.InternalAuthenticationServiceException;
import org.springframework.security.authentication.UsernamePasswordAuthenticationToken;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.AuthenticationException;
import org.springframework.security.core.GrantedAuthority;
import org.springframework.security.core.authority.SimpleGrantedAuthority;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;

import ar.com.lazoblanco.entity.Permission;
import ar.com.lazoblanco.entity.User;
import ar.com.lazoblanco.service.LoginService;

@Deprecated
public class CustomAuthenticationProvider implements AuthenticationProvider {

    @Autowired
    LoginService loginService;

    @Override
    @Transactional(propagation = Propagation.REQUIRED, readOnly = true)
    public Authentication authenticate(Authentication authentication) throws AuthenticationException {

        String username = authentication.getName();
        String password = authentication.getCredentials().toString();

        try {
            password = password;
        } catch (Exception e1) {
            throw new AccessDeniedException("Fallo en la autenticación del usuario");
        }

        User user = null;

        try {
            user = loginService.getUserByCredentials(username, password);
        } catch (Exception e) {
            throw new InternalAuthenticationServiceException("Ha ocurrido un error con el servicio de autenticación: " + e.getMessage());
        }

        if (user != null) {
            UserSession session = new UserSession(user, getAuthorities(user.getPermissions()));
            return new UsernamePasswordAuthenticationToken(session, password, getAuthorities(user.getPermissions()));
        } else {
            throw new BadCredentialsException("login.badcredentials.error");
        }

    }

    @Override
    public boolean supports(Class<?> authentication) {
        return authentication.equals(UsernamePasswordAuthenticationToken.class);
    }

    /**
     * Retrieves a collection of {@link GrantedAuthority} based on a list of
     * roles
     * 
     * @param roles
     *            the assigned roles of the user
     * @return a collection of {@link GrantedAuthority}
     */
    public Collection<? extends GrantedAuthority> getAuthorities(List<Permission> permissions) {

        Set<SimpleGrantedAuthority> authList = new HashSet<SimpleGrantedAuthority>();
        for (Permission p : permissions) {
            authList.add(new SimpleGrantedAuthority("allow-" + p.getName()));
        }

        return authList;
    }

}
