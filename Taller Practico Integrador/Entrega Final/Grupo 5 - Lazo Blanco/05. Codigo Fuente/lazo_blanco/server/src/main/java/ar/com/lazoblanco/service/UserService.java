package ar.com.lazoblanco.service;

import java.util.List;

import ar.com.lazoblanco.entity.User;
import ar.com.lazoblanco.entity.dto.UserDTO;

public interface UserService extends BaseService<User, String> {
	
	List<UserDTO> getAll();
	
	UserDTO getByUuid(String uuid);
	
	UserDTO saveFromDTO(UserDTO dto);
	
	UserDTO updateFromDTO(UserDTO dto, String uuid);
	
	Long deleteByUuid(String uuid);
	
	UserDTO getByEmail(String email);
	
}