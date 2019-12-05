package ar.com.lazoblanco.entity;

import org.apache.commons.lang3.text.WordUtils;

import lombok.Getter;

/*
 * Enumerator for roles in the application.
 * 
 * @author RAndreoli
 * @version 1.0.0
 * @since 1.0.0
 */
public enum UserRoleEnum {
	
	ADMINISTRATOR (1L, "Administrador"),
	PROFESSIONAL (2L, "Profesional"),
	VICTIM (3L, "Víctima");
	
	@Getter
	public final Long id;
	
	@Getter
	public final String name;
	
	private UserRoleEnum(Long id, String name) {
		this.id = id;
		this.name = name;
	}
	
	public static UserRoleEnum getByName(String name) {
		name = WordUtils.capitalizeFully(name);
    	for (UserRoleEnum entity : UserRoleEnum.values()) {
    		if (entity.getName().equals(name)) {
    			return entity;
    		}
    	}
    	return null;
    }

}