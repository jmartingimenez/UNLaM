package ar.com.lazoblanco.entity.mapper;

import java.util.List;
import java.util.stream.Collectors;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import ar.com.lazoblanco.entity.ChatMessage;
import ar.com.lazoblanco.entity.SenderTypeEnum;
import ar.com.lazoblanco.entity.dto.ChatMessageDTO;

/*
 * Component to update {@link ChatMessage} or to transform it into {@link ChatMessageDTO} and viceversa.
 * 
 * @author RAndreoli
 * @version 1.0.0
 * @since 1.0.0
 */
@Component
public class ChatMessageMapper {

	private final Logger logger = LoggerFactory.getLogger(this.getClass());
	
	@Autowired
	ChatRoomMapper chatRoomMapper;
	
	public ChatMessage map(ChatMessage oldEntity, ChatMessage newEntity) {
		logger.debug("map()");
		oldEntity.setRoom(newEntity.getRoom());
		oldEntity.setContent(newEntity.getContent());
		oldEntity.setSender(newEntity.getSender());
		oldEntity.setSentAt(newEntity.getSentAt());
		return oldEntity;
	}
	
	public ChatMessageDTO toDTO(ChatMessage entity) {
		logger.debug("toDTO()");
		ChatMessageDTO dto = new ChatMessageDTO();
		dto.setUuid(entity.getUuid());
		dto.setTimestamp(entity.getSentAt());
		dto.setRoom(chatRoomMapper.toDTO(entity.getRoom()));
		dto.setContent(entity.getContent());
		dto.setSender(entity.getSender().getName());
		return dto;
	}
	
	public ChatMessage fromDTO(ChatMessageDTO dto) {
		logger.debug("fromDTO()");
		ChatMessage entity = new ChatMessage();
		entity.setUuid(dto.getUuid());
		entity.setSentAt(dto.getTimestamp());
		entity.setRoom(chatRoomMapper.fromDTO(dto.getRoom()));
		entity.setContent(dto.getContent());
		entity.setSender(SenderTypeEnum.getByName(dto.getSender()));
		return entity;
	}
	
	public List<ChatMessageDTO> toDTOList(List<ChatMessage> list) {
		return list
				.stream()
				.map(this::toDTO)
				.collect(Collectors.toList());
	}
	
	public List<ChatMessage> fromDTOList(List<ChatMessageDTO> dtoList) {
		return dtoList
				.stream()
				.map(this::fromDTO)
				.collect(Collectors.toList());
	}
	
}