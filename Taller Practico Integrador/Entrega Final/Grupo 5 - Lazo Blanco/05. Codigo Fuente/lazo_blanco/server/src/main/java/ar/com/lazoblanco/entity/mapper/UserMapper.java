package ar.com.lazoblanco.entity.mapper;

import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import ar.com.lazoblanco.entity.User;
import ar.com.lazoblanco.entity.UserSexEnum;
import ar.com.lazoblanco.entity.dto.UserDTO;

/*
 * Component to update {@link User} or to transform it into {@link UserDTO} and viceversa.
 * 
 * @author RAndreoli
 * @version 1.0.0
 * @since 1.0.0
 */
@Component
public class UserMapper {

	private final Logger logger = LoggerFactory.getLogger(this.getClass());
	
	@Autowired
	LicenseMapper licenseMapper;
	
	@Autowired
	LocationMapper locationMapper;
	
	public User map(User oldEntity, User newEntity) {
		logger.debug("map()");
		oldEntity.setFirstName(newEntity.getFirstName());
		oldEntity.setSex(newEntity.getSex());
		oldEntity.setLastName(newEntity.getLastName());
		oldEntity.setBirthDate(newEntity.getBirthDate());
		oldEntity.setPhoneNumber(newEntity.getPhoneNumber());
		oldEntity.setSecondaryEmail(newEntity.getSecondaryEmail());
		oldEntity.setLicense(newEntity.getLicense());
		oldEntity.setLocation(newEntity.getLocation());
		return oldEntity;
	}
	
	public UserDTO toDTO(User entity) {
		logger.debug("toDTO()");
		UserDTO dto = new UserDTO();
		dto.setUuid(entity.getUuid());
		dto.setEmail(entity.getEmail());
		dto.setEmailConfirmed(entity.getEmailConfirmed());
		dto.setPassword(entity.getPassword());
		dto.setFirstName(entity.getFirstName());
		dto.setValid(entity.getValid());
		dto.setIdNumber(Optional
				.ofNullable(entity.getIdNumber())
				.orElse("--"));
		dto.setSex(Optional
				.ofNullable(entity.getSex())
				.map(UserSexEnum::getName)
				.orElse(null));
		dto.setLastName(Optional
				.ofNullable(entity.getLastName())
				.orElse("--"));
		// TODO: Posiblemente falte formatear la fecha que va a frontend.
		dto.setBirthDate(entity.getBirthDate());
		dto.setPhoneNumber(Optional
				.ofNullable(entity.getPhoneNumber())
				.orElse("--"));
		dto.setSecondaryEmail(Optional
				.ofNullable(entity.getSecondaryEmail())
				.orElse("--"));
		dto.setLicense(Optional
				.ofNullable(entity.getLicense())
				.map(license -> licenseMapper.toDTO(license))
				.orElse(null));
		dto.setLocation(Optional
				.ofNullable(entity.getLocation())
				.map(location -> locationMapper.toDTO(location))
				.orElse(null));
		return dto;
	}
	
	public User fromDTO(UserDTO dto) {
		logger.debug("fromDTO()");
		User entity = new User();
		entity.setUuid(dto.getUuid());
		entity.setEmail(dto.getEmail());
		entity.setEmailConfirmed(dto.getEmailConfirmed());
		entity.setPassword(dto.getPassword());
		entity.setFirstName(dto.getFirstName());
		entity.setValid(dto.getValid());
		entity.setIdNumber(dto.getIdNumber());
		entity.setSex(Optional
				.ofNullable(dto.getSex())
				.map(name -> {
					return UserSexEnum.getByName(name);
				})
				.orElse(null));
		entity.setLastName(dto.getLastName());
		// TODO: Posiblemente falte formatear la fecha que viene de frontend.
		entity.setBirthDate(dto.getBirthDate());
		entity.setPhoneNumber(dto.getPhoneNumber());
		entity.setSecondaryEmail(dto.getSecondaryEmail());
		entity.setLicense(Optional
				.ofNullable(dto.getLicense())
				.map(licenseDTO -> licenseMapper.fromDTO(licenseDTO))
				.orElse(null));
		entity.setLocation(Optional
				.ofNullable(dto.getLocation())
				.map(locationDTO -> locationMapper.fromDTO(locationDTO))
				.orElse(null));
		return entity;
	}
	
	public List<UserDTO> toDTOList(List<User> list) {
		return list
				.stream()
				.map(this::toDTO)
				.collect(Collectors.toList());
	}
	
	public List<User> fromDTOList(List<UserDTO> dtoList) {
		return dtoList
				.stream()
				.map(this::fromDTO)
				.collect(Collectors.toList());
	}
	
}