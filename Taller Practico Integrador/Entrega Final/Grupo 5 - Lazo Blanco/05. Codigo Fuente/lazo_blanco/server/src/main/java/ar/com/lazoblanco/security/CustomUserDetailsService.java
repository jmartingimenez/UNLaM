package ar.com.lazoblanco.security;

import java.util.Collection;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.authentication.BadCredentialsException;
import org.springframework.security.core.GrantedAuthority;
import org.springframework.security.core.authority.SimpleGrantedAuthority;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.stereotype.Component;
import org.springframework.transaction.annotation.Transactional;

import ar.com.lazoblanco.entity.Permission;
import ar.com.lazoblanco.entity.User;
import ar.com.lazoblanco.entity.UserStatusEnum;
import ar.com.lazoblanco.repository.UserRepository;

@Component
public class CustomUserDetailsService implements UserDetailsService {

    @Autowired
    UserRepository userRepository;

    @Override
    @Transactional(readOnly = true)
    public UserDetails loadUserByUsername(String username) throws UsernameNotFoundException {

        User user = userRepository.findByEmailAndStatus(username, UserStatusEnum.ACTIVE);

        if (user == null) {
            throw new BadCredentialsException("login.badcredentials.error");
        }

        return new UserSession(user, getAuthorities(user.getPermissions()));
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