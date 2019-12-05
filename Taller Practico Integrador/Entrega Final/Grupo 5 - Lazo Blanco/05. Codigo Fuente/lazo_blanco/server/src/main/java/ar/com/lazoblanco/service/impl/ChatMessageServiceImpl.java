package ar.com.lazoblanco.service.impl;

import java.util.List;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import ar.com.lazoblanco.entity.ChatMessage;
import ar.com.lazoblanco.entity.dto.ChatMessageDTO;
import ar.com.lazoblanco.entity.mapper.ChatMessageMapper;
import ar.com.lazoblanco.repository.BaseRepository;
import ar.com.lazoblanco.repository.ChatMessageRepository;
import ar.com.lazoblanco.service.ChatMessageService;

@Service
public class ChatMessageServiceImpl extends BaseServiceImpl<ChatMessage, String> implements ChatMessageService {

    private final Logger logger = LoggerFactory.getLogger(this.getClass());

    @Autowired
    ChatMessageRepository chatMessageRepository;
    
    @Autowired
    ChatMessageMapper chatMessageMapper;

	@Override
	public BaseRepository<ChatMessage, String> getRepository() {
		logger.debug("getRepository()");
		return chatMessageRepository;
	}

	@Override
	public List<ChatMessageDTO> getAll() {
		return chatMessageMapper.toDTOList(findAll());
	}

	@Override
	public ChatMessageDTO getByUuid(String uuid) {
		return chatMessageMapper.toDTO(findByUuid(uuid));
	}

	@Override
	public ChatMessageDTO saveFromDTO(ChatMessageDTO dto) {
		return chatMessageMapper.toDTO(save(chatMessageMapper.fromDTO(dto)));
	}

	@Override
	public ChatMessageDTO updateFromDTO(ChatMessageDTO dto, String uuid) {
		return chatMessageMapper.toDTO(update(findByUuid(uuid), chatMessageMapper.fromDTO(dto)));
	}

	@Override
	public Long deleteByUuid(String uuid) {
		return delete(uuid);
	}
	
	@Override
	public List<ChatMessageDTO> getAllByChatRoomUuid(String chatRoomUuid) {
		return chatMessageMapper.toDTOList(chatMessageRepository.findByRoomUuidOrderBySentAtAsc(chatRoomUuid));
	}
    
}