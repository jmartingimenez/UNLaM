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

import ar.com.lazoblanco.entity.dto.ChatMessageDTO;
import ar.com.lazoblanco.service.ChatMessageService;

@RestController
@RequestMapping(REST_URI + "/chat-message")
public class ChatMessageController extends BaseController {
	
	private final Logger logger = LoggerFactory.getLogger(this.getClass());
	
	@Autowired
	ChatMessageService chatMessageService;
	
	@RequestMapping(value = "/", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<List<ChatMessageDTO>> getAll() {
		logger.debug("ChatMessage - getAll()");
		return new ResponseEntity<List<ChatMessageDTO>>(chatMessageService.getAll(), HttpStatus.OK);
	}
	
	@RequestMapping(value = "/{uuid}", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<ChatMessageDTO> get(@PathVariable String uuid) {
		logger.debug("ChatMessage - get({})", uuid);
		return new ResponseEntity<ChatMessageDTO>(chatMessageService.getByUuid(uuid), HttpStatus.OK);
	}
	
	@RequestMapping(value = "/", method = RequestMethod.POST, consumes = MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<ChatMessageDTO> save(@Valid @RequestBody ChatMessageDTO dto) {
		logger.debug("ChatMessage - save({} - {})", dto.getSender(), dto.getTimestamp());
		return new ResponseEntity<ChatMessageDTO>(chatMessageService.saveFromDTO(dto), HttpStatus.OK);
	}
	
	@RequestMapping(value = "/{uuid}", method = RequestMethod.PUT, consumes = MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<ChatMessageDTO> update(@Valid @RequestBody ChatMessageDTO dto, @PathVariable String uuid) {
		logger.debug("ChatMessage - update({})", uuid);
		return new ResponseEntity<ChatMessageDTO>(chatMessageService.updateFromDTO(dto, uuid), HttpStatus.OK);
	}
	
	@RequestMapping(value = "/{uuid}", method = RequestMethod.DELETE, produces = MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<Long> delete(@PathVariable String uuid) {
		logger.debug("ChatMessage - delete({})", uuid);
		return new ResponseEntity<Long>(chatMessageService.deleteByUuid(uuid), HttpStatus.OK);
	}
	
	@RequestMapping(value = "/room/{uuid}", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_UTF8_VALUE)
	public ResponseEntity<List<ChatMessageDTO>> getAllByChatRoomUuid(@PathVariable String uuid) {
		logger.debug("ChatMessage - getAllByChatRoomUuid({})", uuid);
		return new ResponseEntity<List<ChatMessageDTO>>(chatMessageService.getAllByChatRoomUuid(uuid), HttpStatus.OK);
	}
	

}