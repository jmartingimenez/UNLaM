package ar.com.lazoblanco.security;

import javax.validation.constraints.NotNull;

import lombok.Data;

@Data
public class PasswordChange {
	
	@NotNull
	private String oldPassword;
	
	@NotNull
	private String password;
	
	@NotNull
	private String password2;

}