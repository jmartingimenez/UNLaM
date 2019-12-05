package ar.com.lazoblanco.service;

import java.util.List;

import ar.com.lazoblanco.entity.Location;
import ar.com.lazoblanco.entity.dto.LocationDTO;

public interface LocationService extends BaseService<Location, String> {
	
	List<LocationDTO> getAll();
	
	LocationDTO getByUuid(String uuid);
	
	LocationDTO saveFromDTO(LocationDTO dto);
	
	LocationDTO updateFromDTO(LocationDTO dto, String uuid);
	
	Long deleteByUuid(String uuid);

}