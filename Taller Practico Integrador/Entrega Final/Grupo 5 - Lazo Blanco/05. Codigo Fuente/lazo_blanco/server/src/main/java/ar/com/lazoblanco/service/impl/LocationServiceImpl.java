package ar.com.lazoblanco.service.impl;

import java.util.List;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import ar.com.lazoblanco.entity.Location;
import ar.com.lazoblanco.entity.dto.LocationDTO;
import ar.com.lazoblanco.entity.mapper.LocationMapper;
import ar.com.lazoblanco.repository.BaseRepository;
import ar.com.lazoblanco.repository.LocationRepository;
import ar.com.lazoblanco.service.LocationService;

@Service
public class LocationServiceImpl extends BaseServiceImpl<Location, String> implements LocationService {

    private final Logger logger = LoggerFactory.getLogger(this.getClass());

    @Autowired
    LocationRepository locationRepository;
    
    @Autowired
    LocationMapper locationMapper;

	@Override
	public BaseRepository<Location, String> getRepository() {
		logger.debug("getRepository()");
		return locationRepository;
	}

	@Override
	public List<LocationDTO> getAll() {
		return locationMapper.toDTOList(findAll());
	}

	@Override
	public LocationDTO getByUuid(String uuid) {
		return locationMapper.toDTO(findByUuid(uuid));
	}

	@Override
	public LocationDTO saveFromDTO(LocationDTO dto) {
		return locationMapper.toDTO(save(locationMapper.fromDTO(dto)));
	}

	@Override
	public LocationDTO updateFromDTO(LocationDTO dto, String uuid) {
		return locationMapper.toDTO(update(findByUuid(uuid), locationMapper.fromDTO(dto)));
	}

	@Override
	public Long deleteByUuid(String uuid) {
		return delete(uuid);
	}
    
}