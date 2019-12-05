package ar.com.lazoblanco.entity;

import org.apache.commons.lang3.text.WordUtils;

import lombok.Getter;

/*
 * Enumerator for types of biological sex.
 * 
 * @author RAndreoli
 * @version 1.0.0
 * @since 1.0.0
 */
public enum UserSexEnum {

	FEMALE (1L, "Femenino"),
	MALE (2L, "Masculino");
	
	@Getter
	public final Long id;
	
	@Getter
	public final String name;
	
	private UserSexEnum(Long id, String name) {
		this.id = id;
		this.name = name;
	}
	
	public static UserSexEnum getByName(String name) {
		name = WordUtils.capitalizeFully(name);
    	for (UserSexEnum entity : UserSexEnum.values()) {
    		if (entity.getName().equals(name)) {
    			return entity;
    		}
    	}
    	return null;
    }
	
}