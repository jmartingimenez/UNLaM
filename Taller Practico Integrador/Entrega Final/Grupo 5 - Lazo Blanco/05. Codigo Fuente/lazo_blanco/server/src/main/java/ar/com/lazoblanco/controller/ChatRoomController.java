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

import ar.com.lazoblanco.entity.dto.ChatRoomDTO;
import ar.com.lazoblanco.entity.dto.LinkageDTO;
import ar.com.lazoblanco.service.ChatRoomService;

@RestController
@RequestMapping(REST_URI + "/chat-room")
public class ChatRoomController extends BaseController {
	
	private final Logger logger = LoggerFactory.getLogger(this.getClass());
	
	@Autowired
	ChatRoomService chatRoomService;
	
	@RequestMapping(value = "/", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<List<ChatRoomDTO>> getAll() {
		logger.debug("ChatRoom - getAll()");
		return new ResponseEntity<List<ChatRoomDTO>>(chatRoomService.getAll(), HttpStatus.OK);
	}
	
	@RequestMapping(value = "/{uuid}", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<ChatRoomDTO> get(@PathVariable String uuid) {
		logger.debug("ChatRoom - get({})", uuid);
		return new ResponseEntity<ChatRoomDTO>(chatRoomService.getByUuid(uuid), HttpStatus.OK);
	}
	
	@RequestMapping(value = "/", method = RequestMethod.POST, consumes = MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<ChatRoomDTO> save(@Valid @RequestBody ChatRoomDTO dto) {
		logger.debug("ChatRoom - save({} - {})", dto.getVictim(), dto.getProfessional());
		return new ResponseEntity<ChatRoomDTO>(chatRoomService.saveFromDTO(dto), HttpStatus.OK);
	}
	
	@RequestMapping(value = "/{uuid}", method = RequestMethod.PUT, consumes = MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<ChatRoomDTO> update(@Valid @RequestBody ChatRoomDTO dto, @PathVariable String uuid) {
		logger.debug("ChatRoom - update({})", uuid);
		return new ResponseEntity<ChatRoomDTO>(chatRoomService.updateFromDTO(dto, uuid), HttpStatus.OK);
	}
	
	@RequestMapping(value = "/{uuid}", method = RequestMethod.DELETE, produces = MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<Long> delete(@PathVariable String uuid) {
		logger.debug("ChatRoom - delete({})", uuid);
		return new ResponseEntity<Long>(chatRoomService.deleteByUuid(uuid), HttpStatus.OK);
	}
	
	@RequestMapping(value = "/user/{uuid}", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<List<ChatRoomDTO>> getAllByUserUuid(@PathVariable String uuid) {
		logger.debug("ChatRoom - getAllByUserUuid({})", uuid);
		return new ResponseEntity<List<ChatRoomDTO>>(chatRoomService.getAllByUserUuid(uuid), HttpStatus.OK);
	}
	
	@RequestMapping(value = "/create/", method = RequestMethod.POST, consumes = MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<ChatRoomDTO> createRoom(@Valid @RequestBody LinkageDTO dto) {
		logger.debug("ChatRoom - createRoom()");
		return new ResponseEntity<ChatRoomDTO>(chatRoomService.createRoom(dto), HttpStatus.OK);
	}

}