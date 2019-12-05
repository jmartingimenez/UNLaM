package ar.com.lazoblanco.security;

import java.util.Collection;

import org.springframework.security.core.GrantedAuthority;
import org.springframework.security.core.userdetails.UserDetails;

import ar.com.lazoblanco.entity.User;
import ar.com.lazoblanco.entity.UserRoleEnum;
import lombok.Getter;

public class UserSession implements UserDetails {

    private static final long serialVersionUID = -2347614059646226255L;

    @Getter
    private String username;

    @Getter
    private String password;

    @Getter
    private String firstName;

    @Getter
    private String lastName;

    @Getter
    private String userUuid;

    @Getter
    private UserRoleEnum role;

    @Getter
    Collection<? extends GrantedAuthority> authorities;

    public UserSession(User user) {
        this.username = user.getEmail();
        this.password = user.getPassword();
        this.firstName = user.getFirstName();
        this.lastName = user.getLastName();
        this.userUuid = user.getUuid();
        this.role = user.getRole();
    }

    public UserSession(User user, Collection<? extends GrantedAuthority> authorities) {
        this(user);
        this.authorities = authorities;
    }

    @Override
    public String toString() {
        return username;
    }

    @Override
    public boolean isAccountNonExpired() {
        return true;
    }

    @Override
    public boolean isAccountNonLocked() {
        return true;
    }

    @Override
    public boolean isCredentialsNonExpired() {
        return true;
    }

    @Override
    public boolean isEnabled() {
        return true;
    }
}