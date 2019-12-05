package ar.com.lazoblanco.entity;

import java.util.Date;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.EnumType;
import javax.persistence.Enumerated;
import javax.persistence.ForeignKey;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.Table;
import javax.persistence.Temporal;
import javax.persistence.TemporalType;

import lombok.Data;
import lombok.EqualsAndHashCode;

/*
 * Entity that persists the messages that fill up a chat room between a professional and a victim.
 * 
 * @author RAndreoli
 * @version 1.0.0
 * @since 1.0.0
 */
@Data
@Entity
@Table(name = "chat_message")
@EqualsAndHashCode(callSuper = true)
public class ChatMessage extends AbstractEntity {

	private static final long serialVersionUID = 4739838441364309460L;

	@ManyToOne
	@JoinColumn(name = "`room_uuid`", nullable = false, foreignKey = @ForeignKey(name = "FK_chat_message__room"))
	private ChatRoom room;
	
	@Column(name = "`content`", columnDefinition = "text", nullable = false)
	private String content;
	
	@Column(name = "`sender`", columnDefinition = "varchar(255) NOT NULL DEFAULT 'VICTIM'")
	@Enumerated(value = EnumType.STRING)
	private SenderTypeEnum sender;
	
	@Column(name = "`sent_at`", nullable = false)
	@Temporal(TemporalType.TIMESTAMP)
	private Date sentAt;
	
}