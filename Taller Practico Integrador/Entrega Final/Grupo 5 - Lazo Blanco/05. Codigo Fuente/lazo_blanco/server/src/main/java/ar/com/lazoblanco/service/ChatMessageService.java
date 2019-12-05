package ar.com.lazoblanco.service;

import java.util.List;

import ar.com.lazoblanco.entity.ChatMessage;
import ar.com.lazoblanco.entity.dto.ChatMessageDTO;

public interface ChatMessageService extends BaseService<ChatMessage, String> {
	
	List<ChatMessageDTO> getAll();
	
	ChatMessageDTO getByUuid(String uuid);
	
	ChatMessageDTO saveFromDTO(ChatMessageDTO dto);
	
	ChatMessageDTO updateFromDTO(ChatMessageDTO dto, String uuid);
	
	Long deleteByUuid(String uuid);
	
	List<ChatMessageDTO> getAllByChatRoomUuid(String chatRoomUuid);
	
}