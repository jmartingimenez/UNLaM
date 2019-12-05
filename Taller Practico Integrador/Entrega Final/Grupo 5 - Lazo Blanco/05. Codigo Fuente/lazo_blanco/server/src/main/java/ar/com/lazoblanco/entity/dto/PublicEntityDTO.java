package ar.com.lazoblanco.entity.dto;

import lombok.Data;

/*
 * Data transfer object of {@link PublicEntity}.
 * 
 * @author RAndreoli
 * @version 1.0.0
 * @since 1.0.0
 */
@Data
public class PublicEntityDTO {

	private String uuid;
	private String name;
	private String phoneNumber;
	private String type;
	private LocationDTO location;
	
}