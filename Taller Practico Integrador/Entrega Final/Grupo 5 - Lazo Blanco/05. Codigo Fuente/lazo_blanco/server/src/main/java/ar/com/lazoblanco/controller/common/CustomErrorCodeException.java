package ar.com.lazoblanco.controller.common;

public class CustomErrorCodeException extends RuntimeException {

	private static final long serialVersionUID = -5397804803267512868L;

	private String code;
	
	public CustomErrorCodeException() {
		super();
	}

	public CustomErrorCodeException(String message, Throwable cause, boolean enableSuppression, boolean writableStackTrace) {
		super(message, cause, enableSuppression, writableStackTrace);
	}

	public CustomErrorCodeException(String message, Throwable cause) {
		super(message, cause);
	}

	public CustomErrorCodeException(String message) {
		super(message);
	}

	public CustomErrorCodeException(Throwable cause) {
		super(cause);
	}
	
	public CustomErrorCodeException(String code, String message) {
		super(message);
		this.code = code;
	}

	public CustomErrorCodeException(String code, String message, Throwable cause) {
		super(message, cause);
		this.code = code;
	}
	
	public String getCode() {
		return code;
	}

}
