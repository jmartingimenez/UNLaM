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

import ar.com.lazoblanco.entity.dto.PublicEntityDTO;
import ar.com.lazoblanco.service.PublicEntityService;

@RestController
@RequestMapping(REST_URI + "/publicEntity")
public class PublicEntityController extends BaseController {
	
	private final Logger logger = LoggerFactory.getLogger(this.getClass());
	
	@Autowired
	PublicEntityService publicEntityService;
	
	@RequestMapping(value = "/", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<List<PublicEntityDTO>> getAll() {
		logger.debug("PublicEntity - getAll()");
		return new ResponseEntity<List<PublicEntityDTO>>(publicEntityService.getAll(), HttpStatus.OK);
	}
	
	@RequestMapping(value = "/{uuid}", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<PublicEntityDTO> get(@PathVariable String uuid) {
		logger.debug("PublicEntity - get({})", uuid);
		return new ResponseEntity<PublicEntityDTO>(publicEntityService.getByUuid(uuid), HttpStatus.OK);
	}
	
	@RequestMapping(value = "/", method = RequestMethod.POST, consumes = MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<PublicEntityDTO> save(@Valid @RequestBody PublicEntityDTO dto) {
		logger.debug("PublicEntity - save({})", dto.getName());
		return new ResponseEntity<PublicEntityDTO>(publicEntityService.saveFromDTO(dto), HttpStatus.OK);
	}
	
	@RequestMapping(value = "/{uuid}", method = RequestMethod.PUT, consumes = MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<PublicEntityDTO> update(@Valid @RequestBody PublicEntityDTO dto, @PathVariable String uuid) {
		logger.debug("PublicEntity - update({})", uuid);
		return new ResponseEntity<PublicEntityDTO>(publicEntityService.updateFromDTO(dto, uuid), HttpStatus.OK);
	}
	
	@RequestMapping(value = "/{uuid}", method = RequestMethod.DELETE, produces = MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<Long> delete(@PathVariable String uuid) {
		logger.debug("PublicEntity - delete({})", uuid);
		return new ResponseEntity<Long>(publicEntityService.deleteByUuid(uuid), HttpStatus.OK);
	}

}