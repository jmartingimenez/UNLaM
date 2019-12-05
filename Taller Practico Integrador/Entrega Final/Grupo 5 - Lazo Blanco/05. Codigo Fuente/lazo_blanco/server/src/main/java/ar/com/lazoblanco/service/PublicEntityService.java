package ar.com.lazoblanco.service;

import java.util.List;

import ar.com.lazoblanco.entity.PublicEntity;
import ar.com.lazoblanco.entity.dto.PublicEntityDTO;

public interface PublicEntityService extends BaseService<PublicEntity, String> {

	List<PublicEntityDTO> getAll();
	
	PublicEntityDTO getByUuid(String uuid);
	
	PublicEntityDTO saveFromDTO(PublicEntityDTO dto);
	
	PublicEntityDTO updateFromDTO(PublicEntityDTO dto, String uuid);
	
	Long deleteByUuid(String uuid);
	
}