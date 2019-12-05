package ar.com.lazoblanco.service.impl;

import java.util.List;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import ar.com.lazoblanco.entity.User;
import ar.com.lazoblanco.entity.UserStatusEnum;
import ar.com.lazoblanco.entity.dto.UserDTO;
import ar.com.lazoblanco.entity.mapper.UserMapper;
import ar.com.lazoblanco.repository.BaseRepository;
import ar.com.lazoblanco.repository.UserRepository;
import ar.com.lazoblanco.service.UserService;

@Service
public class UserServiceImpl extends BaseServiceImpl<User, String> implements UserService {

    private static final String MOCK_PASSWORD_VALUE = "123456";

    private final Logger logger = LoggerFactory.getLogger(this.getClass());

    @Autowired
    UserRepository userRepository;
    
    @Autowired
    UserMapper userMapper;

	@Override
	public BaseRepository<User, String> getRepository() {
		logger.debug("getRepository()");
		return userRepository;
	}

	@Override
	public List<UserDTO> getAll() {
		return userMapper.toDTOList(findAll());
	}

	@Override
	public UserDTO getByUuid(String uuid) {
		return userMapper.toDTO(findByUuid(uuid));
	}

	@Override
	public UserDTO saveFromDTO(UserDTO dto) {
		return userMapper.toDTO(save(userMapper.fromDTO(dto)));
	}

	@Override
	public UserDTO updateFromDTO(UserDTO dto, String uuid) {
		return userMapper.toDTO(update(findByUuid(uuid), userMapper.fromDTO(dto)));
	}

	@Override
	public Long deleteByUuid(String uuid) {
		return delete(uuid);
	}

	@Override
	public UserDTO getByEmail(String email) {
		return userMapper.toDTO(userRepository.findByEmailAndStatus(email, UserStatusEnum.ACTIVE));
	}
    
}