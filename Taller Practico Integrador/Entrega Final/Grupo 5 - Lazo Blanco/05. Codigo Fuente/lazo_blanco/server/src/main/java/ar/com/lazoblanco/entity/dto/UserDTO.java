package ar.com.lazoblanco.entity.dto;

import java.util.Date;

import lombok.Data;

/*
 * Data transfer object of {@link User}.
 * 
 * @author RAndreoli
 * @version 1.0.0
 * @since 1.0.0
 */
@Data
public class UserDTO {

	private String uuid;
	private String email;
	private Boolean emailConfirmed;
	private String password;
	private String firstName;
	private Boolean valid;
	private String idNumber;
	private String sex;
	private String lastName;
	private Date birthDate;
	private String phoneNumber;
	private String secondaryEmail;
	private LicenseDTO license;
	private LocationDTO location;
	
}