package ar.com.lazoblanco.service;

import java.util.List;

import ar.com.lazoblanco.entity.License;
import ar.com.lazoblanco.entity.dto.LicenseDTO;

public interface LicenseService extends BaseService<License, String> {
	
	List<LicenseDTO> getAll();
	
	LicenseDTO getByUuid(String uuid);
	
	LicenseDTO saveFromDTO(LicenseDTO dto);
	
	LicenseDTO updateFromDTO(LicenseDTO dto, String uuid);
	
	Long deleteByUuid(String uuid);

}