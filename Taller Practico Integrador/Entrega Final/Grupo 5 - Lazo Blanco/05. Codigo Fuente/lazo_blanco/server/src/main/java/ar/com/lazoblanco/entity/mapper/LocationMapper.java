package ar.com.lazoblanco.entity.mapper;

import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Component;

import ar.com.lazoblanco.entity.Location;
import ar.com.lazoblanco.entity.dto.LocationDTO;

/*
 * Component to update {@link Location} or to transform it into {@link LocationDTO} and viceversa.
 * 
 * @author RAndreoli
 * @version 1.0.0
 * @since 1.0.0
 */
@Component
public class LocationMapper {

	private final Logger logger = LoggerFactory.getLogger(this.getClass());
	
	public Location map(Location oldEntity, Location newEntity) {
		logger.debug("map()");
		oldEntity.setZipCode(newEntity.getZipCode());
		oldEntity.setAddressNumber(newEntity.getAddressNumber());
		oldEntity.setAddressStreet(newEntity.getAddressStreet());
		oldEntity.setCity(newEntity.getCity());
		oldEntity.setProvince(newEntity.getProvince());
		oldEntity.setApartment(newEntity.getApartment());
		return oldEntity;
	}
	
	public LocationDTO toDTO(Location entity) {
		logger.debug("toDTO()");
		LocationDTO dto = new LocationDTO();
		dto.setUuid(entity.getUuid());
		dto.setZipCode(entity.getZipCode());
		dto.setAddressNumber(entity.getAddressNumber());
		dto.setAddressStreet(entity.getAddressStreet());
		dto.setCity(entity.getCity());
		dto.setProvince(entity.getProvince());
		dto.setApartment(Optional
				.ofNullable(entity.getApartment())
				.orElse("--")
		);
		return dto;
	}
	
	public Location fromDTO(LocationDTO dto) {
		logger.debug("fromDTO()");
		Location entity = new Location();
		entity.setUuid(dto.getUuid());
		entity.setZipCode(dto.getZipCode());
		entity.setAddressNumber(dto.getAddressNumber());
		entity.setAddressStreet(dto.getAddressStreet());
		entity.setCity(dto.getCity());
		entity.setProvince(dto.getProvince());
		entity.setApartment(dto.getApartment());
		return entity;
	}
	
	public List<LocationDTO> toDTOList(List<Location> list) {
		return list
				.stream()
				.map(this::toDTO)
				.collect(Collectors.toList());
	}
	
	public List<Location> fromDTOList(List<LocationDTO> dtoList) {
		return dtoList
				.stream()
				.map(this::fromDTO)
				.collect(Collectors.toList());
	}
	
}