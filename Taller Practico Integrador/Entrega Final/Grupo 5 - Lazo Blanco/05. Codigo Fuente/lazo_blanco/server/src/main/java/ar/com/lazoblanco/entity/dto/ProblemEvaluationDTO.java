package ar.com.lazoblanco.entity.dto;

import lombok.Data;

/*
 * Data transfer object to evaluate a victim's problem and create a {@link LinkageDTO}.
 * 
 * @author RAndreoli
 * @version 1.0.0
 * @since 1.0.0
 */
@Data
public class ProblemEvaluationDTO {

	private String violence;
	private Integer valoration;
	
}