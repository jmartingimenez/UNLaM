package ar.com.lazoblanco.entity;

import org.apache.commons.lang3.text.WordUtils;

import lombok.Getter;

/*
 * Enumerator for statuses of users.
 * 
 * @author RAndreoli
 * @version 1.0.0
 * @since 1.0.0
 */
public enum UserStatusEnum {
	
	ACTIVE (1L, "Activo"),
	PENDING (2L, "Pendiente"),
	INACTIVE (3L, "Desactivado");
	
	@Getter
	public final Long id;
	
	@Getter
	public final String name;
	
	private UserStatusEnum(Long id, String name) {
		this.id = id;
		this.name = name;
	}
	
	public static UserStatusEnum getByName(String name) {
		name = WordUtils.capitalizeFully(name);
    	for (UserStatusEnum entity : UserStatusEnum.values()) {
    		if (entity.getName().equals(name)) {
    			return entity;
    		}
    	}
    	return null;
    }

}