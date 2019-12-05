package ar.com.lazoblanco.entity.dto;

import java.util.Date;

import lombok.Data;

/*
 * Data transfer object of {@link ChatMessage}.
 * 
 * @author RAndreoli
 * @version 1.0.0
 * @since 1.0.0
 */
@Data
public class ChatMessageDTO {

	private String uuid;
	private Date timestamp;
	private ChatRoomDTO room;
	private String content;
	private String sender;
	
}