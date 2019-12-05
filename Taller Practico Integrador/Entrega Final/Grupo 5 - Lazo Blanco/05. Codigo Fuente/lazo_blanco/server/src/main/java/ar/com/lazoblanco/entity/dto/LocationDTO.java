package ar.com.lazoblanco.entity.dto;

import lombok.Data;

/*
 * Data transfer object of {@link Location}.
 * 
 * @author RAndreoli
 * @version 1.0.0
 * @since 1.0.0
 */
@Data
public class LocationDTO {

	private String uuid;
	private Integer zipCode;
	private Integer addressNumber;
	private String addressStreet;
	private String city;
	private String province;
	private String apartment;
	
}