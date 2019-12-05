package ar.com.lazoblanco.security;

import org.hibernate.validator.constraints.NotEmpty;

import lombok.Data;

@Data
public class PasswordRecovery {
	
	@NotEmpty
	private String token;
	
	@NotEmpty
	private String password;
	
	@NotEmpty
	private String password2;

}