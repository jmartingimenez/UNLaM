package ar.com.lazoblanco.entity;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.OneToOne;
import javax.persistence.Table;

import lombok.Data;
import lombok.EqualsAndHashCode;

/*
 * Entity that persists the ubication of a public entity, a victim's house or a professional's office.
 * 
 * @author RAndreoli
 * @version 1.0.0
 * @since 1.0.0
 */
@Data
@Entity
@Table(name = "location")
@EqualsAndHashCode(callSuper = true, exclude = {"publicEntity", "user"})
public class Location extends AbstractEntity {

	private static final long serialVersionUID = 1227703795874261988L;

	@Column(name = "`zip_code`", nullable = false)
	private Integer zipCode;
	
	@Column(name = "`address_number`", nullable = false)
	private Integer addressNumber;
	
	@Column(name = "`address_street`", nullable = false)
	private String addressStreet;
	
	@Column(name = "`city`", nullable = false)
	private String city;
	
	@Column(name = "`province`", nullable = false)
	private String province;
	
	@Column(name = "`apartment`", nullable = true)
	private String apartment;
	
	@OneToOne(mappedBy = "location")
	private PublicEntity publicEntity;
	
	@OneToOne(mappedBy = "location")
	private User user;
	
}