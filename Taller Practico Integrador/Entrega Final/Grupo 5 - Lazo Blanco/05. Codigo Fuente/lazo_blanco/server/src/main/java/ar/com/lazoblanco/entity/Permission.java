package ar.com.lazoblanco.entity;

import java.util.List;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.ManyToMany;
import javax.persistence.Table;
import javax.persistence.UniqueConstraint;

import com.fasterxml.jackson.annotation.JsonIgnore;

import lombok.Data;
import lombok.EqualsAndHashCode;
import lombok.ToString;

/*
 * Entity that persists the permissions.
 * 
 * @author RAndreoli
 * @version 1.0.0
 * @since 1.0.0
 */
@Data
@Entity
@ToString(exclude = { "users" })
@EqualsAndHashCode(callSuper = true, exclude = { "users" })
@Table(name = "permission", uniqueConstraints = { @UniqueConstraint(columnNames = { "name" }, name = "UK_permission__name") })
public class Permission extends AbstractEntity {

	private static final long serialVersionUID = 1119447930648873008L;

	@Column(name = "`name`", nullable = false)
	private String name;

	@ManyToMany(mappedBy="permissions")
	@JsonIgnore
	private List<User> users;

}