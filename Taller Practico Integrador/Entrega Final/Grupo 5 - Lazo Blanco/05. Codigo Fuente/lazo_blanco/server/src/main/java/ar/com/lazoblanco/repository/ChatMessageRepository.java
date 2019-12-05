package ar.com.lazoblanco.repository;

import java.util.List;

import ar.com.lazoblanco.entity.ChatMessage;

public interface ChatMessageRepository extends BaseRepository<ChatMessage, String> {
	
	List<ChatMessage> findByRoomUuidOrderBySentAtAsc(String chatRoomUuid);

}