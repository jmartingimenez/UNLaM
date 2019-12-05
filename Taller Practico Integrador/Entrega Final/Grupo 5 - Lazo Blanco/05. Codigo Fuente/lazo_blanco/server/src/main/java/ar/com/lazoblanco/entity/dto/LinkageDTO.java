package ar.com.lazoblanco.entity.dto;

import java.util.List;

import lombok.Data;

/*
 * Data transfer object to create a {@link ChatRoom}.
 * 
 * @author RAndreoli
 * @version 1.0.0
 * @since 1.0.0
 */
@Data
public class LinkageDTO {

	private List<ChatMessageDTO> messages;
	private List<ProblemEvaluationDTO> problemEvaluation;
	private String victimUuid;
	
}