package ar.com.lazoblanco.entity.mapper;

import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import ar.com.lazoblanco.entity.PublicEntity;
import ar.com.lazoblanco.entity.PublicEntityTypeEnum;
import ar.com.lazoblanco.entity.dto.PublicEntityDTO;

/*
 * Component to update {@link PublicEntity} or to transform it into {@link PublicEntityDTO} and viceversa.
 * 
 * @author RAndreoli
 * @version 1.0.0
 * @since 1.0.0
 */
@Component
public class PublicEntityMapper {

	private final Logger logger = LoggerFactory.getLogger(this.getClass());
	
	@Autowired
	LocationMapper locationMapper;
	
	public PublicEntity map(PublicEntity oldEntity, PublicEntity newEntity) {
		logger.debug("map()");
		oldEntity.setName(newEntity.getName());
		oldEntity.setPhoneNumber(newEntity.getPhoneNumber());
		oldEntity.setType(newEntity.getType());
		oldEntity.setLocation(newEntity.getLocation());
		return oldEntity;
	}
	
	public PublicEntityDTO toDTO(PublicEntity entity) {
		logger.debug("toDTO()");
		PublicEntityDTO dto = new PublicEntityDTO();
		dto.setUuid(entity.getUuid());
		dto.setName(entity.getName());
		dto.setPhoneNumber(Optional
				.ofNullable(entity.getPhoneNumber())
				.orElse("--"));
		dto.setType(Optional
				.ofNullable(entity.getType())
				.map(PublicEntityTypeEnum::getName)
				.orElse("--"));
		dto.setLocation(Optional
				.ofNullable(entity.getLocation())
				.map(location -> locationMapper.toDTO(location))
				.orElse(null));
		return dto;
	}
	
	public PublicEntity fromDTO(PublicEntityDTO dto) {
		logger.debug("fromDTO()");
		PublicEntity entity = new PublicEntity();
		dto.setUuid(entity.getUuid());
		entity.setName(dto.getName());
		entity.setPhoneNumber(dto.getPhoneNumber());
		entity.setType(Optional
				.ofNullable(dto.getType())
				.map(name -> {
					return PublicEntityTypeEnum.getByName(name);
				})
				.orElse(null));
		entity.setLocation(Optional
				.ofNullable(dto.getLocation())
				.map(locationDTO -> locationMapper.fromDTO(locationDTO))
				.orElse(null)
		);
		return entity;
	}
	
	public List<PublicEntityDTO> toDTOList(List<PublicEntity> list) {
		return list
				.stream()
				.map(this::toDTO)
				.collect(Collectors.toList());
	}
	
	public List<PublicEntity> fromDTOList(List<PublicEntityDTO> dtoList) {
		return dtoList
				.stream()
				.map(this::fromDTO)
				.collect(Collectors.toList());
	}
	
}