package ar.com.lazoblanco.service.impl;

import java.util.List;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import ar.com.lazoblanco.entity.ChatRoom;
import ar.com.lazoblanco.entity.dto.ChatMessageDTO;
import ar.com.lazoblanco.entity.dto.ChatRoomDTO;
import ar.com.lazoblanco.entity.dto.LinkageDTO;
import ar.com.lazoblanco.entity.dto.ProblemEvaluationDTO;
import ar.com.lazoblanco.entity.dto.UserDTO;
import ar.com.lazoblanco.entity.mapper.ChatRoomMapper;
import ar.com.lazoblanco.repository.BaseRepository;
import ar.com.lazoblanco.repository.ChatRoomRepository;
import ar.com.lazoblanco.service.ChatMessageService;
import ar.com.lazoblanco.service.ChatRoomService;
import ar.com.lazoblanco.service.UserService;

@Service
public class ChatRoomServiceImpl extends BaseServiceImpl<ChatRoom, String> implements ChatRoomService {

    private final Logger logger = LoggerFactory.getLogger(this.getClass());

    @Autowired
    ChatRoomRepository chatRoomRepository;
    
    @Autowired
    ChatRoomMapper chatRoomMapper;
    
    @Autowired
    UserService userService;
    
    @Autowired
    ChatMessageService chatMessageService;

	@Override
	public BaseRepository<ChatRoom, String> getRepository() {
		logger.debug("getRepository()");
		return chatRoomRepository;
	}

	@Override
	public List<ChatRoomDTO> getAll() {
		return chatRoomMapper.toDTOList(findAll());
	}

	@Override
	public ChatRoomDTO getByUuid(String uuid) {
		return chatRoomMapper.toDTO(findByUuid(uuid));
	}

	@Override
	public ChatRoomDTO saveFromDTO(ChatRoomDTO dto) {
		return chatRoomMapper.toDTO(save(chatRoomMapper.fromDTO(dto)));
	}

	@Override
	public ChatRoomDTO updateFromDTO(ChatRoomDTO dto, String uuid) {
		return chatRoomMapper.toDTO(update(findByUuid(uuid), chatRoomMapper.fromDTO(dto)));
	}

	@Override
	public Long deleteByUuid(String uuid) {
		return delete(uuid);
	}
	
	@Override
	public List<ChatRoomDTO> getAllByUserUuid(String userUuid) {
		return chatRoomMapper.toDTOList(chatRoomRepository.findByVictimUuidOrProfessionalUuidOrderByUpdatedAtDesc(userUuid, userUuid));
	}

	@Override
	public ChatRoomDTO createRoom(LinkageDTO linkage) {
		logger.debug("createChatRoom()");
		ChatRoomDTO chatRoom = new ChatRoomDTO();
		chatRoom.setProfessional(chooseProfessional(linkage));
		chatRoom.setVictim(userService.getByUuid(linkage.getVictimUuid()));
		
		chatRoom = saveFromDTO(chatRoom);
		
		chatRoom.setMessages(linkage.getMessages());
		createInitialMessages(chatRoom);
		
		return chatRoom;
	}
	
	private UserDTO chooseProfessional(LinkageDTO linkage) {
		Boolean economic = false;
		Boolean physical = false;
		Boolean psychological = false;
		Boolean sexual = false;
		Boolean symbolic = false;
		
		for(ProblemEvaluationDTO problemEvaluation : linkage.getProblemEvaluation()) {
			switch(problemEvaluation.getViolence()) {
				case "ViolenciaEconomica":
					if (problemEvaluation.getValoration() != 0) {
						economic = true;
					}
					break;
				case "ViolenciaFisica":
					if (problemEvaluation.getValoration() != 0) {
						physical = true;
					}
					break;
				case "ViolenciaPsicologica":
					if (problemEvaluation.getValoration() != 0) {
						psychological = true;
					}
					break;
				case "ViolenciaSexual":
					if (problemEvaluation.getValoration() != 0) {
						sexual = true;
					}
					break;
				case "ViolenciaSimbolica":
					if (problemEvaluation.getValoration() != 0) {
						symbolic = true;
					}
					break;
				default:
					// Do nothing
					break;
			}
		}
		
		UserDTO professional = null;

		if (economic || psychological || symbolic) {
			professional = userService.getByEmail("randreoli@lazoblanco.com.ar");
		}
		
		if (sexual || physical) {
			professional = userService.getByEmail("jmurano@lazoblanco.com.ar");
		}
		
		if (!economic && !psychological && !symbolic && !sexual && !physical) {
			professional = userService.getByEmail("randreoli@lazoblanco.com.ar");
		}
		
		if (economic && psychological && symbolic && sexual && physical) {
			professional = userService.getByEmail("randreoli@lazoblanco.com.ar");
		}
		
		if(professional == null) {
			professional = userService.getByEmail("jmurano@lazoblanco.com.ar");
		}
		
		return professional;
	}
    
	private void createInitialMessages(ChatRoomDTO chatRoom) {
		for (ChatMessageDTO message : chatRoom.getMessages()) {
			message.setRoom(getByUuid(chatRoom.getUuid()));
			chatMessageService.saveFromDTO(message);			
		}
	}
}