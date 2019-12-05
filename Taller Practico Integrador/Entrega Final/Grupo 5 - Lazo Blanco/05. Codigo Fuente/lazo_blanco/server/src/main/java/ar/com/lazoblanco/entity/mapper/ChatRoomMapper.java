package ar.com.lazoblanco.entity.mapper;

import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import ar.com.lazoblanco.entity.ChatRoom;
import ar.com.lazoblanco.entity.dto.ChatRoomDTO;

/*
 * Component to update {@link ChatRoom} or to transform it into {@link ChatRoomDTO} and viceversa.
 * 
 * @author RAndreoli
 * @version 1.0.0
 * @since 1.0.0
 */
@Component
public class ChatRoomMapper {

	private final Logger logger = LoggerFactory.getLogger(this.getClass());
	
	@Autowired
	UserMapper userMapper;
	
	@Autowired
	ChatMessageMapper chatMessageMapper;
	
	public ChatRoom map(ChatRoom oldEntity, ChatRoom newEntity) {
		logger.debug("map()");
		oldEntity.setVictim(newEntity.getVictim());
		oldEntity.setProfessional(newEntity.getProfessional());
		oldEntity.setMessages(newEntity.getMessages());
		return oldEntity;
	}
	
	public ChatRoomDTO toDTO(ChatRoom entity) {
		logger.debug("toDTO()");
		ChatRoomDTO dto = new ChatRoomDTO();
		dto.setUuid(entity.getUuid());
		dto.setVictim(userMapper.toDTO(entity.getVictim()));
		dto.setProfessional(userMapper.toDTO(entity.getProfessional()));
		return dto;
	}
	
	public ChatRoom fromDTO(ChatRoomDTO dto) {
		logger.debug("fromDTO()");
		ChatRoom entity = new ChatRoom();
		entity.setUuid(dto.getUuid());
		entity.setVictim(userMapper.fromDTO(dto.getVictim()));
		entity.setProfessional(userMapper.fromDTO(dto.getProfessional()));
		return entity;
	}
	
	public ChatRoomDTO toFullDTO(ChatRoom entity) {
		logger.debug("toDTO()");
		ChatRoomDTO dto = new ChatRoomDTO();
		dto.setUuid(entity.getUuid());
		dto.setVictim(userMapper.toDTO(entity.getVictim()));
		dto.setProfessional(userMapper.toDTO(entity.getProfessional()));
		dto.setMessages(Optional
				.ofNullable(entity.getMessages())
				.map(list -> chatMessageMapper.toDTOList(list))
				.orElse(null));
		return dto;
	}
	
	public ChatRoom fromFullDTO(ChatRoomDTO dto) {
		logger.debug("fromDTO()");
		ChatRoom entity = new ChatRoom();
		entity.setUuid(dto.getUuid());
		entity.setVictim(userMapper.fromDTO(dto.getVictim()));
		entity.setProfessional(userMapper.fromDTO(dto.getProfessional()));
		entity.setMessages(Optional
				.ofNullable(dto.getMessages())
				.map(list -> chatMessageMapper.fromDTOList(list))
				.orElse(null));
		return entity;
	}
	
	public List<ChatRoomDTO> toDTOList(List<ChatRoom> list) {
		return list
				.stream()
				.map(this::toDTO)
				.collect(Collectors.toList());
	}
	
	public List<ChatRoom> fromDTOList(List<ChatRoomDTO> dtoList) {
		return dtoList
				.stream()
				.map(this::fromDTO)
				.collect(Collectors.toList());
	}
	
}