package ar.com.lazoblanco.service;

import java.util.List;

import org.springframework.security.core.userdetails.UserDetailsService;

import ar.com.lazoblanco.entity.User;
import ar.com.lazoblanco.security.PasswordChange;
import ar.com.lazoblanco.security.PasswordRecovery;

public interface LoginService extends UserDetailsService {

	User getUserByCredentials(String value, String password) throws Exception;
	
	String regeneratePasswordForUser(String uuid);

	String userForgotPassword(String value) throws Exception;

	boolean userConfirmForgotPassword(PasswordRecovery recovery) throws Exception;

	void invalidateTokens();

	boolean hasAnyAuthority(List<String> requiredRoles);
	
	boolean hasAuthority(String requiredRole);

	String changePassword(PasswordChange passwordChange) throws Exception;
	
}