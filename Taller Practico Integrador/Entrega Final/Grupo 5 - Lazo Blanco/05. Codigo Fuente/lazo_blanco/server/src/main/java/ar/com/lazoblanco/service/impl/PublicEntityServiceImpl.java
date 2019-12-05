package ar.com.lazoblanco.service.impl;

import java.util.List;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import ar.com.lazoblanco.entity.PublicEntity;
import ar.com.lazoblanco.entity.dto.PublicEntityDTO;
import ar.com.lazoblanco.entity.mapper.PublicEntityMapper;
import ar.com.lazoblanco.repository.BaseRepository;
import ar.com.lazoblanco.repository.PublicEntityRepository;
import ar.com.lazoblanco.service.PublicEntityService;

@Service
public class PublicEntityServiceImpl extends BaseServiceImpl<PublicEntity, String> implements PublicEntityService {

    private final Logger logger = LoggerFactory.getLogger(this.getClass());

    @Autowired
    PublicEntityRepository publicEntityRepository;
    
    @Autowired
    PublicEntityMapper publicEntityMapper;

	@Override
	public BaseRepository<PublicEntity, String> getRepository() {
		logger.debug("getRepository()");
		return publicEntityRepository;
	}

	@Override
	public List<PublicEntityDTO> getAll() {
		return publicEntityMapper.toDTOList(findAll());
	}

	@Override
	public PublicEntityDTO getByUuid(String uuid) {
		return publicEntityMapper.toDTO(findByUuid(uuid));
	}

	@Override
	public PublicEntityDTO saveFromDTO(PublicEntityDTO dto) {
		return publicEntityMapper.toDTO(save(publicEntityMapper.fromDTO(dto)));
	}

	@Override
	public PublicEntityDTO updateFromDTO(PublicEntityDTO dto, String uuid) {
		return publicEntityMapper.toDTO(update(findByUuid(uuid), publicEntityMapper.fromDTO(dto)));
	}

	@Override
	public Long deleteByUuid(String uuid) {
		return delete(uuid);
	}
    
}