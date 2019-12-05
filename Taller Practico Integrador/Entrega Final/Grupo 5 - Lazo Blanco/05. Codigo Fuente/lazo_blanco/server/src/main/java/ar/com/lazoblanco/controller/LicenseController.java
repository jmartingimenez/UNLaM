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

import ar.com.lazoblanco.entity.dto.LicenseDTO;
import ar.com.lazoblanco.service.LicenseService;

@RestController
@RequestMapping(REST_URI + "/license")
public class LicenseController extends BaseController {
	
	private final Logger logger = LoggerFactory.getLogger(this.getClass());
	
	@Autowired
	LicenseService licenseService;
	
	@RequestMapping(value = "/", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<List<LicenseDTO>> getAll() {
		logger.debug("License - getAll()");
		return new ResponseEntity<List<LicenseDTO>>(licenseService.getAll(), HttpStatus.OK);
	}
	
	@RequestMapping(value = "/{uuid}", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<LicenseDTO> get(@PathVariable String uuid) {
		logger.debug("License - get({})", uuid);
		return new ResponseEntity<LicenseDTO>(licenseService.getByUuid(uuid), HttpStatus.OK);
	}
	
	@RequestMapping(value = "/", method = RequestMethod.POST, consumes = MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<LicenseDTO> save(@Valid @RequestBody LicenseDTO dto) {
		logger.debug("License - save({})", dto.getCode());
		return new ResponseEntity<LicenseDTO>(licenseService.saveFromDTO(dto), HttpStatus.OK);
	}
	
	@RequestMapping(value = "/{uuid}", method = RequestMethod.PUT, consumes = MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<LicenseDTO> update(@Valid @RequestBody LicenseDTO dto, @PathVariable String uuid) {
		logger.debug("License - update({})", uuid);
		return new ResponseEntity<LicenseDTO>(licenseService.updateFromDTO(dto, uuid), HttpStatus.OK);
	}
	
	@RequestMapping(value = "/{uuid}", method = RequestMethod.DELETE, produces = MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<Long> delete(@PathVariable String uuid) {
		logger.debug("License - delete({})", uuid);
		return new ResponseEntity<Long>(licenseService.deleteByUuid(uuid), HttpStatus.OK);
	}

}