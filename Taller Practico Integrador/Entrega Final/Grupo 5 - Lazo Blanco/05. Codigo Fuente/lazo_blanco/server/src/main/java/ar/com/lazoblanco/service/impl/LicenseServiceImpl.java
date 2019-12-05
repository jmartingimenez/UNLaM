package ar.com.lazoblanco.service.impl;

import java.util.List;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import ar.com.lazoblanco.entity.License;
import ar.com.lazoblanco.entity.dto.LicenseDTO;
import ar.com.lazoblanco.entity.mapper.LicenseMapper;
import ar.com.lazoblanco.repository.BaseRepository;
import ar.com.lazoblanco.repository.LicenseRepository;
import ar.com.lazoblanco.service.LicenseService;

@Service
public class LicenseServiceImpl extends BaseServiceImpl<License, String> implements LicenseService {

    private final Logger logger = LoggerFactory.getLogger(this.getClass());

    @Autowired
    LicenseRepository licenseRepository;
    
    @Autowired
    LicenseMapper licenseMapper;

	@Override
	public BaseRepository<License, String> getRepository() {
		logger.debug("getRepository()");
		return licenseRepository;
	}

	@Override
	public List<LicenseDTO> getAll() {
		return licenseMapper.toDTOList(findAll());
	}

	@Override
	public LicenseDTO getByUuid(String uuid) {
		return licenseMapper.toDTO(findByUuid(uuid));
	}

	@Override
	public LicenseDTO saveFromDTO(LicenseDTO dto) {
		return licenseMapper.toDTO(save(licenseMapper.fromDTO(dto)));
	}

	@Override
	public LicenseDTO updateFromDTO(LicenseDTO dto, String uuid) {
		return licenseMapper.toDTO(update(findByUuid(uuid), licenseMapper.fromDTO(dto)));
	}

	@Override
	public Long deleteByUuid(String uuid) {
		return delete(uuid);
	}
    
}