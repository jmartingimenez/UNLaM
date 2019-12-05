package ar.com.lazoblanco.controller;

import static ar.com.lazoblanco.controller.BaseController.REST_URI;

import java.util.HashMap;
import java.util.Map;
import java.util.stream.Collectors;

import javax.validation.Valid;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.security.access.prepost.PreAuthorize;
import org.springframework.security.core.Authentication;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import ar.com.lazoblanco.controller.common.Response;
import ar.com.lazoblanco.security.PasswordChange;
import ar.com.lazoblanco.security.PasswordRecovery;
import ar.com.lazoblanco.security.UserSession;
import ar.com.lazoblanco.service.LoginService;
import ar.com.lazoblanco.service.UserService;

@RestController
@RequestMapping(REST_URI + "/security")
public class SecurityController extends BaseController {

    private static final Logger logger = LoggerFactory.getLogger(SecurityController.class);

    @Autowired
    LoginService loginService;

    @Autowired
    UserService userService;

    @PreAuthorize("permitAll")
    @RequestMapping(value = "/forgot-password", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_UTF8_VALUE)
    public ResponseEntity<Response> forgotPassword(@RequestBody String value) {

        String token;
        try {
            token = loginService.userForgotPassword(value);
        } catch (Exception e) {
            return new ResponseEntity<Response>(new Response(e), HttpStatus.BAD_REQUEST);
        }

        return new ResponseEntity<Response>(new Response(token), HttpStatus.OK);
    }

    @PreAuthorize("permitAll")
    @RequestMapping(value = "/confirm-password", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_UTF8_VALUE)
    public ResponseEntity<Response> confirmPassword(@Valid @RequestBody PasswordRecovery recovery) throws Exception {

        if (!recovery.getPassword().equals(recovery.getPassword2())) {
            return new ResponseEntity<Response>(new Response(Boolean.FALSE, "error-different-passwords", "Las contraseñas no coinciden"),
                    HttpStatus.BAD_REQUEST);
        }

        loginService.userConfirmForgotPassword(recovery);

        return new ResponseEntity<Response>(new Response(""), HttpStatus.OK);
    }

    @PreAuthorize("isFullyAuthenticated()")
    @RequestMapping(value = "/me", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_UTF8_VALUE)
    public ResponseEntity<Map<String, Object>> me() {

        Authentication auth = getUserAuth();

        UserSession session = (UserSession) auth.getPrincipal();

        Map<String, Object> data = new HashMap<String, Object>();
        data.put("firstname", session.getFirstName());
        data.put("lastname", session.getLastName());
        data.put("permissions", auth.getAuthorities().stream().map(a -> a.getAuthority()).collect(Collectors.toList()));
        data.put("role", session.getRole());
        data.put("userUuid", session.getUserUuid());

        return new ResponseEntity<Map<String, Object>>(data, HttpStatus.OK);
    }

    @PreAuthorize("isFullyAuthenticated()")
    @RequestMapping(value = "/change-password", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_UTF8_VALUE)
    public ResponseEntity<Response> changePassword(@Valid @RequestBody PasswordChange passwordChange) throws Exception {

        if (!passwordChange.getPassword().equals(passwordChange.getPassword2())) {
            return new ResponseEntity<Response>(new Response(Boolean.FALSE, "new-password-mismatch", "Las nuevas contraseñas no coinciden."),
                    HttpStatus.BAD_REQUEST);
        }

        String userUuid = loginService.changePassword(passwordChange);
        logger.debug("Se cambio el password para el usuario:" + userUuid);

        return new ResponseEntity<Response>(new Response(Boolean.TRUE, "password-changed", "Se cambió la contraseña con éxito"), HttpStatus.OK);
    }
    
}