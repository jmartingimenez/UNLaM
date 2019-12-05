package ar.com.lazoblanco.controller;

import static ar.com.lazoblanco.controller.BaseController.REST_URI;

import java.util.List;

import javax.validation.Valid;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import ar.com.lazoblanco.entity.dto.UserDTO;
import ar.com.lazoblanco.service.UserService;

@RestController
@RequestMapping(REST_URI + "/user")
public class UserController extends BaseController {
	
	private final Logger logger = LoggerFactory.getLogger(this.getClass());
	
	@Autowired
	UserService userService;
	
	@RequestMapping(value = "/", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<List<UserDTO>> getAll() {
		logger.debug("User - getAll()");
		return new ResponseEntity<List<UserDTO>>(userService.getAll(), HttpStatus.OK);
	}
	
	@RequestMapping(value = "/{uuid}", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<UserDTO> get(@PathVariable String uuid) {
		logger.debug("User - get({})", uuid);
		return new ResponseEntity<UserDTO>(userService.getByUuid(uuid), HttpStatus.OK);
	}
	
	@RequestMapping(value = "/", method = RequestMethod.POST, consumes = MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<UserDTO> save(@Valid @RequestBody UserDTO dto) {
		logger.debug("User - save({})", dto.getEmail());
		return new ResponseEntity<UserDTO>(userService.saveFromDTO(dto), HttpStatus.OK);
	}
	
	@RequestMapping(value = "/{uuid}", method = RequestMethod.PUT, consumes = MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<UserDTO> update(@Valid @RequestBody UserDTO dto, @PathVariable String uuid) {
		logger.debug("User - update({})", uuid);
		return new ResponseEntity<UserDTO>(userService.updateFromDTO(dto, uuid), HttpStatus.OK);
	}
	
	@RequestMapping(value = "/{uuid}", method = RequestMethod.DELETE, produces = MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<Long> delete(@PathVariable String uuid) {
		logger.debug("User - delete({})", uuid);
		return new ResponseEntity<Long>(userService.deleteByUuid(uuid), HttpStatus.OK);
	}

}