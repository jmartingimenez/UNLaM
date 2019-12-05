package ar.com.lazoblanco.entity;

import java.util.List;

import javax.persistence.Entity;
import javax.persistence.ForeignKey;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.OneToMany;
import javax.persistence.Table;

import lombok.Data;
import lombok.EqualsAndHashCode;

/*
 * Entity that persists the room in which a professional has a chat with a victim to provide assistance.
 * 
 * @author RAndreoli
 * @version 1.0.0
 * @since 1.0.0
 */
@Data
@Entity
@Table(name = "chat_room")
@EqualsAndHashCode(callSuper = true)
public class ChatRoom extends AbstractEntity {

	private static final long serialVersionUID = 630228113995644068L;

	@ManyToOne
	@JoinColumn(name = "`victim_uuid`", nullable = false, foreignKey = @ForeignKey(name = "FK_chat_room__victim"))
	private User victim;
	
	@ManyToOne
	@JoinColumn(name = "`professional_uuid`", nullable = false, foreignKey = @ForeignKey(name = "FK_chat_room__professional"))
	private User professional;
	
	@OneToMany(mappedBy="room")
    private List<ChatMessage> messages;
	
}