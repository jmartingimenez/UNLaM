package ar.com.lazoblanco.controller;

public class PasswordChangeAuthenticationException extends Exception {

	private static final long serialVersionUID = 3316010259315106638L;
	
	public PasswordChangeAuthenticationException() {
	}

	public PasswordChangeAuthenticationException(String arg0) {
		super(arg0);
	}

	public PasswordChangeAuthenticationException(Throwable cause) {
		super(cause);
	}

	public PasswordChangeAuthenticationException(String message, Throwable cause) {
		super(message, cause);
	}
	public PasswordChangeAuthenticationException(String message, Throwable cause, boolean enableSuppression, boolean writableStackTrace) {
		super(message, cause, enableSuppression, writableStackTrace);
	}

}
