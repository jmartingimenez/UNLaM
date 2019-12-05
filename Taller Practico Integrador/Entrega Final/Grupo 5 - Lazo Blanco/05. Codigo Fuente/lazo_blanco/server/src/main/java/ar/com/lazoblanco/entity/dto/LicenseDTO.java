package ar.com.lazoblanco.entity.dto;

import java.util.Date;

import lombok.Data;

/*
 * Data transfer object of {@link License}.
 * 
 * @author RAndreoli
 * @version 1.0.0
 * @since 1.0.0
 */
@Data
public class LicenseDTO {
	
	private String uuid;
	private String code;
	private String title;
	private String institution;
	private Date expeditionDate;
	private Date expirationDate;
	
}