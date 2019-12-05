package ar.com.lazoblanco.security;

import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.stereotype.Component;

@Component
public class CustomPasswordEncoder implements PasswordEncoder {

    @Override
    public String encode(CharSequence rawPassword) {
        try {
            return rawPassword.toString();
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }

    @Override
    public boolean matches(CharSequence rawPassword, String encodedPassword) {
        try {
            String base64Password = rawPassword.toString();
            return base64Password.equals(encodedPassword);
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }

}
