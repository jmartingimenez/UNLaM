package ar.com.lazoblanco.controller.common;

public class CustomValidationException extends CustomErrorCodeException{

	private static final long serialVersionUID = -8690250863015625644L;

	public CustomValidationException() {
		super();
	}

	public CustomValidationException(String message, Throwable cause, boolean enableSuppression, boolean writableStackTrace) {
		super(message, cause, enableSuppression, writableStackTrace);
	}

	public CustomValidationException(String message, Throwable cause) {
		super(message, cause);
	}

	public CustomValidationException(String message) {
		super(message);
	}

	public CustomValidationException(Throwable cause) {
		super(cause);
	}

	public CustomValidationException(String code, String message) {
		super(code, message);
	}
	
	public CustomValidationException(String code, String message, Throwable cause) {
		super(code, message, cause);
	}
}
