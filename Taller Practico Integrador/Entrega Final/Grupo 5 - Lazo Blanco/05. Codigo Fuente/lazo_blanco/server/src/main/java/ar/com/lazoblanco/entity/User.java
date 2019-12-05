package ar.com.lazoblanco.entity;

import java.util.Date;
import java.util.List;

import javax.persistence.CascadeType;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.EnumType;
import javax.persistence.Enumerated;
import javax.persistence.ForeignKey;
import javax.persistence.JoinColumn;
import javax.persistence.JoinTable;
import javax.persistence.ManyToMany;
import javax.persistence.OneToMany;
import javax.persistence.OneToOne;
import javax.persistence.Table;
import javax.persistence.Temporal;
import javax.persistence.TemporalType;
import javax.persistence.UniqueConstraint;

import com.fasterxml.jackson.annotation.JsonIgnore;

import lombok.Data;
import lombok.EqualsAndHashCode;

/*
 * Entity that persists an user.
 * 
 * @author RAndreoli
 * @version 1.0.0
 * @since 1.0.0
 */
@Data
@Entity
@EqualsAndHashCode(callSuper = true, exclude = {"chatAsVictim", "chatAsProfessional"})
@Table(name = "user", uniqueConstraints = { @UniqueConstraint(columnNames = {"email"}, name = "UK_user__email"), @UniqueConstraint(columnNames = {"id_number"}, name = "UK_user__id_number") })
public class User extends AbstractEntity {
	
	private static final long serialVersionUID = -1120545664996007280L;

	@Column(name = "`email`", nullable = false)
	private String email;
	
	@Column(name = "`email_confirmed`")
	private Boolean emailConfirmed = Boolean.FALSE;
	
	@Column(name = "`password`", nullable = false)
	private String password;
	
	@Column(name = "`role`", columnDefinition = "varchar(255) NOT NULL DEFAULT 'VICTIM'")
	@Enumerated(value = EnumType.STRING)
	private UserRoleEnum role;
	
	@Column(name = "`status`", columnDefinition = "varchar(255) NOT NULL DEFAULT 'PENDING'")
	@Enumerated(value = EnumType.STRING)
	private UserStatusEnum status;
	
	@Column(name = "`first_name`", nullable = false)
	private String firstName;
	
	@Column(name = "`valid`")
	private Boolean valid = Boolean.FALSE;
	
	@Column(name = "`id_number`", nullable = true)
	private String idNumber;
	
	@Column(name = "`sex`", columnDefinition = "varchar(255) DEFAULT NULL")
	@Enumerated(value = EnumType.STRING)
	private UserSexEnum sex;
	
	@Column(name = "`last_name`", nullable = true)
	private String lastName;
	
	@Column(name = "`birth_date`", nullable = true)
	@Temporal(TemporalType.TIMESTAMP)
	private Date birthDate;
	
	@Column(name = "`phone_number`", nullable = true)
	private String phoneNumber;
	
	@Column(name = "`secondary_email`", nullable = true)
	private String secondaryEmail;
	
	@OneToOne(cascade = CascadeType.ALL)
	@JoinColumn(name = "`license_uuid`", nullable = true, referencedColumnName = "uuid", foreignKey = @ForeignKey(name = "FK_user__license"))
	private License license;
	
	@OneToOne(cascade = CascadeType.ALL)
	@JoinColumn(name = "`location_uuid`", nullable = true, referencedColumnName = "uuid", foreignKey = @ForeignKey(name = "FK_user__location"))
	private Location location;
	
	@JsonIgnore
    @Column(nullable = true)
    private String passwordToken;

    @JsonIgnore
    @Temporal(TemporalType.TIMESTAMP)
    private Date tokenExpirationDate;

    @ManyToMany(cascade = CascadeType.ALL)
    @JoinTable(name = "user_permission", foreignKey = @ForeignKey(name = "FK_User__User_permission"), joinColumns = { @JoinColumn(name = "user_uuid", referencedColumnName = "uuid") }, inverseJoinColumns = { @JoinColumn(name = "permission_uuid", referencedColumnName = "uuid") })
    private List<Permission> permissions;
    
    @OneToMany(mappedBy="victim")
    private List<ChatRoom> chatAsVictim;
    
    @OneToMany(mappedBy="professional")
    private List<ChatRoom> chatAsProfessional;
	
}