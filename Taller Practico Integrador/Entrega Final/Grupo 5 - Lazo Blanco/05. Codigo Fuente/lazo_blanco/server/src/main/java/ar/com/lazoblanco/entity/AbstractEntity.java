package ar.com.lazoblanco.entity;

import java.io.Serializable;
import java.util.Date;

import javax.persistence.Column;
import javax.persistence.Id;
import javax.persistence.MappedSuperclass;
import javax.persistence.Temporal;
import javax.persistence.TemporalType;

import com.fasterxml.jackson.annotation.JsonIgnoreProperties;

import lombok.Data;
import lombok.EqualsAndHashCode;

/*
 * Entity to be extended by each main object class.
 * 
 * @author RAndreoli
 * @version 1.0.0
 * @since 1.0.0
 */
@Data
@MappedSuperclass
@EqualsAndHashCode
@JsonIgnoreProperties({"hibernateLazyInitializer", "handler"})
public class AbstractEntity implements Serializable {

	private static final long serialVersionUID = -8119003546682564175L;

	@Id
	private String uuid;
	
	@Column(nullable = false)
	@Temporal(TemporalType.TIMESTAMP)
	private Date createdAt;
	
	@Column(nullable = false)
	@Temporal(TemporalType.TIMESTAMP)
	private Date updatedAt;
	
	@Column(nullable = false)
	private String updatedBy;
	
}