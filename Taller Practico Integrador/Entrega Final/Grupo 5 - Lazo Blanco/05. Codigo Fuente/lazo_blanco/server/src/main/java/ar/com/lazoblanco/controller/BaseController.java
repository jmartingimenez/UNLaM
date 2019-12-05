package ar.com.lazoblanco.controller;

import java.util.List;

import javax.persistence.EntityNotFoundException;
import javax.servlet.http.HttpServletRequest;

import org.hibernate.exception.ConstraintViolationException;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.dao.DataIntegrityViolationException;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.http.converter.HttpMessageNotReadableException;
import org.springframework.security.access.AccessDeniedException;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.validation.BindingResult;
import org.springframework.validation.FieldError;
import org.springframework.web.bind.MethodArgumentNotValidException;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.multipart.support.MissingServletRequestPartException;

import ar.com.lazoblanco.controller.common.CustomValidationException;
import ar.com.lazoblanco.controller.common.Response;
import ar.com.lazoblanco.security.UserSession;
import ar.com.lazoblanco.service.JsonService;
import lombok.Getter;

@CrossOrigin
public abstract class BaseController {

	public static final String REST_URI = "/rest/v1";

	private static final Logger logger = LoggerFactory.getLogger(BaseController.class);

	@Autowired
	@Getter
	private JsonService jsonService;

	protected UserSession getUserPrincipal() {
		Authentication auth = SecurityContextHolder.getContext().getAuthentication();
		return ((UserSession) auth.getPrincipal());
	}

	protected Authentication getUserAuth() {
		return SecurityContextHolder.getContext().getAuthentication();
	}

	@ExceptionHandler(EntityNotFoundException.class)
	protected ResponseEntity<Response> entityNotFoundExceptionHandler(HttpServletRequest request,
			EntityNotFoundException exception) {
		return new ResponseEntity<Response>(new Response(false, "entity-not-found", exception.getMessage()),
				HttpStatus.NOT_FOUND);
	}

	@ExceptionHandler(AccessDeniedException.class)
	protected ResponseEntity<Response> accessDeniedExceptionHandler(HttpServletRequest request,
			AccessDeniedException exception) {
		return new ResponseEntity<Response>(new Response(false, "access-denied", exception.getMessage()),
				HttpStatus.FORBIDDEN);
	}

	@ExceptionHandler(MethodArgumentNotValidException.class)
	protected ResponseEntity<Response> exceptionHandler(HttpServletRequest request,
			MethodArgumentNotValidException exception) {
		logger.error("Error en parametros request", exception);

		BindingResult result = exception.getBindingResult();
		List<FieldError> errors = result.getFieldErrors();

		return new ResponseEntity<Response>(new Response(errors), HttpStatus.BAD_REQUEST);
	}

	@ExceptionHandler(DataIntegrityViolationException.class)
	protected ResponseEntity<Response> exceptionHandler(HttpServletRequest request,
			DataIntegrityViolationException exception) {
		logger.error("Error en parametros request", exception);

		ConstraintViolationException cause = (ConstraintViolationException) exception.getCause();

		return new ResponseEntity<Response>(new Response(cause), HttpStatus.BAD_REQUEST);
	}

	@ExceptionHandler(HttpMessageNotReadableException.class)
	protected ResponseEntity<Response> exceptionHandler(HttpMessageNotReadableException request,
			HttpMessageNotReadableException exception) {
		logger.error("Validación de datos (request)", exception);
		return new ResponseEntity<Response>(new Response(false, "data-format", exception.getMessage()),
				HttpStatus.BAD_REQUEST);
	}

	@ExceptionHandler(CustomValidationException.class)
	protected ResponseEntity<Response> exceptionHandler(HttpServletRequest request,
			CustomValidationException exception) {
		logger.error("Validación de negocio", exception);
		return new ResponseEntity<Response>(new Response(false, exception.getCode(), exception.getMessage()),
				HttpStatus.BAD_REQUEST);
	}

	@ExceptionHandler(MissingServletRequestPartException.class)
	protected ResponseEntity<Response> exceptionHandler(HttpServletRequest request,
			MissingServletRequestPartException exception) {
		logger.error("Post sin archivo", exception);
		return new ResponseEntity<Response>(new Response(false, "error-missing-expected-file", exception.getMessage()),
				HttpStatus.BAD_REQUEST);
	}

	@ExceptionHandler(Exception.class)
	protected ResponseEntity<Response> exceptionHandler(HttpServletRequest request, Exception exception) {
		logger.error("Error general", exception);
		return new ResponseEntity<Response>(
				new Response(false, "general-error", "Ha ocurrido un problema interno, consulte con el administrador."),
				HttpStatus.INTERNAL_SERVER_ERROR);
	}

	protected ResponseEntity<Response> errorResponse(String message) {
		return new ResponseEntity<Response>(new Response(false, null, message), HttpStatus.INTERNAL_SERVER_ERROR);
	}

}
