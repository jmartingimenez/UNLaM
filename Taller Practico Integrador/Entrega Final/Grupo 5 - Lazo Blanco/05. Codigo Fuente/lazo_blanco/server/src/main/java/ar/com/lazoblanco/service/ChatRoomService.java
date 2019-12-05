package ar.com.lazoblanco.service;

import java.util.List;

import ar.com.lazoblanco.entity.ChatRoom;
import ar.com.lazoblanco.entity.dto.ChatRoomDTO;
import ar.com.lazoblanco.entity.dto.LinkageDTO;

public interface ChatRoomService extends BaseService<ChatRoom, String> {
	
	List<ChatRoomDTO> getAll();
	
	ChatRoomDTO getByUuid(String uuid);
	
	ChatRoomDTO saveFromDTO(ChatRoomDTO dto);
	
	ChatRoomDTO updateFromDTO(ChatRoomDTO dto, String uuid);
	
	Long deleteByUuid(String uuid);
	
	List<ChatRoomDTO> getAllByUserUuid(String userUuid);

	ChatRoomDTO createRoom(LinkageDTO dto);
	
}