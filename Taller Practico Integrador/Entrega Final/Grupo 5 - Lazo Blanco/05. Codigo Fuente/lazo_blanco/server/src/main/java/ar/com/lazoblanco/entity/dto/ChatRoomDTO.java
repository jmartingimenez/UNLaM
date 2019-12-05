package ar.com.lazoblanco.entity.dto;

import java.util.List;

import lombok.Data;

/*
 * Data transfer object of {@link ChatRoom}.
 * 
 * @author RAndreoli
 * @version 1.0.0
 * @since 1.0.0
 */
@Data
public class ChatRoomDTO {

	private String uuid;
	private UserDTO victim;
	private UserDTO professional;
	private List<ChatMessageDTO> messages;
	
}