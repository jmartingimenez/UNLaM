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

import ar.com.lazoblanco.entity.dto.LocationDTO;
import ar.com.lazoblanco.service.LocationService;

@RestController
@RequestMapping(REST_URI + "/location")
public class LocationController extends BaseController {
	
	private final Logger logger = LoggerFactory.getLogger(this.getClass());
	
	@Autowired
	LocationService locationService;
	
	@RequestMapping(value = "/", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<List<LocationDTO>> getAll() {
		logger.debug("Location - getAll()");
		return new ResponseEntity<List<LocationDTO>>(locationService.getAll(), HttpStatus.OK);
	}
	
	@RequestMapping(value = "/{uuid}", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<LocationDTO> get(@PathVariable String uuid) {
		logger.debug("Location - get({})", uuid);
		return new ResponseEntity<LocationDTO>(locationService.getByUuid(uuid), HttpStatus.OK);
	}
	
	@RequestMapping(value = "/", method = RequestMethod.POST, consumes = MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<LocationDTO> save(@Valid @RequestBody LocationDTO dto) {
		logger.debug("Location - save({} {})", dto.getAddressStreet(), dto.getAddressNumber());
		return new ResponseEntity<LocationDTO>(locationService.saveFromDTO(dto), HttpStatus.OK);
	}
	
	@RequestMapping(value = "/{uuid}", method = RequestMethod.PUT, consumes = MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<LocationDTO> update(@Valid @RequestBody LocationDTO dto, @PathVariable String uuid) {
		logger.debug("Location - update({})", uuid);
		return new ResponseEntity<LocationDTO>(locationService.updateFromDTO(dto, uuid), HttpStatus.OK);
	}
	
	@RequestMapping(value = "/{uuid}", method = RequestMethod.DELETE, produces = MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<Long> delete(@PathVariable String uuid) {
		logger.debug("Location - delete({})", uuid);
		return new ResponseEntity<Long>(locationService.deleteByUuid(uuid), HttpStatus.OK);
	}

}