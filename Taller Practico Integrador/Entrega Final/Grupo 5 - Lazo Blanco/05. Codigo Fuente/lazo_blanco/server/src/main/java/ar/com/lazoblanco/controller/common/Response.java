package ar.com.lazoblanco.controller.common;

import java.io.Serializable;
import java.util.List;

import lombok.Getter;
import lombok.Setter;

import org.hibernate.exception.ConstraintViolationException;
import org.springframework.validation.FieldError;

public class Response implements Serializable {

	private static final long serialVersionUID = -3583372036207126472L;
	
	@Getter @Setter
	private String field;

	@Getter @Setter
	private Boolean success;
	
	@Getter @Setter
	private String code;
	
	@Getter @Setter
	private String message;

	@Getter @Setter
    private List<FieldError> errors;
	
	public Response() {
		super();
	}
	
	public Response(Boolean success, String code, String message) {
		super();
		this.success = success;
		this.code = code;
		this.message = message;
	}
	
	public Response(String message) {
		super();
		this.success = Boolean.TRUE;
		this.message = message;
	}

	public Response(FieldError error) {
		super();
		this.success = Boolean.FALSE;
		this.code = error.getCode();
		this.message = error.getObjectName() + "." + error.getField() + " " + error.getDefaultMessage();
	}

    public Response(List<FieldError> errors) {
        super();
        this.errors = errors;
        this.success = Boolean.FALSE;
    }
    
    public Response(ConstraintViolationException cve) {
    	super();
    	this.success = Boolean.FALSE;
    	this.code = cve.getConstraintName();
    	this.message = "";
    }

	public Response(Throwable result) {
		super();
		this.success = Boolean.FALSE;
		this.code = "error";
		this.message = result.getMessage();
	}
}
