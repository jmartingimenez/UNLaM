package ar.com.lazoblanco.repository;

import java.util.List;

import ar.com.lazoblanco.entity.ChatRoom;

public interface ChatRoomRepository extends BaseRepository<ChatRoom, String> {
	
	List<ChatRoom> findByVictimUuidOrProfessionalUuidOrderByUpdatedAtDesc(String victimUuid, String professionalUuid);

}