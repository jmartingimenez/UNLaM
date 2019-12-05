package ar.com.lazoblanco.entity;

import java.util.Date;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.OneToOne;
import javax.persistence.Table;
import javax.persistence.Temporal;
import javax.persistence.TemporalType;
import javax.persistence.UniqueConstraint;

import lombok.Data;
import lombok.EqualsAndHashCode;

/*
 * Entity that persists the license of a professional.
 * 
 * @author RAndreoli
 * @version 1.0.0
 * @since 1.0.0
 */
@Data
@Entity
@EqualsAndHashCode(callSuper = true, exclude = {"user"})
@Table(name = "license", uniqueConstraints = { @UniqueConstraint(columnNames = {"code"}, name = "UK_license__code") })
public class License extends AbstractEntity {

	private static final long serialVersionUID = -4767686742519014560L;

	@Column(name = "`code`", nullable = false)
	private String code;
	
	@Column(name = "`title`", nullable = false)
	private String title;
	
	@Column(name = "`institution`", nullable = false)
	private String institution;
	
	@Column(name = "`expedition_date`", nullable = true)
	@Temporal(TemporalType.TIMESTAMP)
	private Date expeditionDate;
	
	@Column(name = "`expiration_date`", nullable = true)
	@Temporal(TemporalType.TIMESTAMP)
	private Date expirationDate;
	
	@OneToOne(mappedBy = "license")
	private User user;
	
}