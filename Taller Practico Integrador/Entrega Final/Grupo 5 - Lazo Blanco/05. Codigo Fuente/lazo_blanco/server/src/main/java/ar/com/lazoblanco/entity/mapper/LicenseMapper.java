package ar.com.lazoblanco.entity.mapper;

import java.util.List;
import java.util.stream.Collectors;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Component;

import ar.com.lazoblanco.entity.License;
import ar.com.lazoblanco.entity.dto.LicenseDTO;

/*
 * Component to update {@link License} or to transform it into {@link LicenseDTO} and viceversa.
 * 
 * @author RAndreoli
 * @version 1.0.0
 * @since 1.0.0
 */
@Component
public class LicenseMapper {

	private final Logger logger = LoggerFactory.getLogger(this.getClass());
	
	public License map(License oldEntity, License newEntity) {
		logger.debug("map()");
		oldEntity.setCode(newEntity.getCode());
		oldEntity.setTitle(newEntity.getTitle());
		oldEntity.setInstitution(newEntity.getInstitution());
		oldEntity.setExpeditionDate(newEntity.getExpeditionDate());
		oldEntity.setExpirationDate(newEntity.getExpirationDate());
		return oldEntity;
	}
	
	public LicenseDTO toDTO(License entity) {
		logger.debug("toDTO()");
		LicenseDTO dto = new LicenseDTO();
		dto.setUuid(entity.getUuid());
		dto.setCode(entity.getCode());
		dto.setTitle(entity.getTitle());
		dto.setInstitution(entity.getInstitution());
		// TODO: Posiblemente falte formatear la fecha que va a frontend.
		dto.setExpeditionDate(entity.getExpeditionDate());
		dto.setExpirationDate(entity.getExpirationDate());
		return dto;
	}
	
	public License fromDTO(LicenseDTO dto) {
		logger.debug("fromDTO()");
		License entity = new License();
		entity.setUuid(dto.getUuid());
		entity.setCode(dto.getCode());
		entity.setTitle(dto.getTitle());
		entity.setInstitution(dto.getInstitution());
		// TODO: Posiblemente falte formatear la fecha que viene de frontend.
		entity.setExpeditionDate(dto.getExpeditionDate());
		entity.setExpirationDate(dto.getExpirationDate());
		return entity;
	}
	
	public List<LicenseDTO> toDTOList(List<License> list) {
		return list
				.stream()
				.map(this::toDTO)
				.collect(Collectors.toList());
	}
	
	public List<License> fromDTOList(List<LicenseDTO> dtoList) {
		return dtoList
				.stream()
				.map(this::fromDTO)
				.collect(Collectors.toList());
	}
	
}