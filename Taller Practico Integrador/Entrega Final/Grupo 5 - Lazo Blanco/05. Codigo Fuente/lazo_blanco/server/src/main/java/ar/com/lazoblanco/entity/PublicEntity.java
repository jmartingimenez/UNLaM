package ar.com.lazoblanco.entity;

import javax.persistence.CascadeType;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.EnumType;
import javax.persistence.Enumerated;
import javax.persistence.ForeignKey;
import javax.persistence.JoinColumn;
import javax.persistence.OneToOne;
import javax.persistence.Table;

import lombok.Data;
import lombok.EqualsAndHashCode;

/*
 * Entity that persists a public entity, like an institute, police, hospital, etc.
 * 
 * @author RAndreoli
 * @version 1.0.0
 * @since 1.0.0
 */
@Data
@Entity
@Table(name = "public_entity")
@EqualsAndHashCode(callSuper = true)
public class PublicEntity extends AbstractEntity {
	
	private static final long serialVersionUID = 5544489669545114672L;

	@Column(name = "`name`", nullable = false)
	private String name;
	
	@Column(name = "`phone_number`", nullable = true)
	private String phoneNumber;
	
	@Column(name = "`type`", nullable = true)
	@Enumerated(value = EnumType.STRING)
	private PublicEntityTypeEnum type;
	
	@OneToOne(cascade = CascadeType.ALL)
	@JoinColumn(name = "`location_uuid`", nullable = true, referencedColumnName = "uuid", foreignKey = @ForeignKey(name = "FK_public_entity__location"))
	private Location location;
	
}