package ar.com.lazoblanco.entity;

import org.apache.commons.lang3.text.WordUtils;

import lombok.Getter;

/*
 * Enumerator for types of message senders.
 * 
 * @author RAndreoli
 * @version 1.0.0
 * @since 1.0.0
 */
public enum SenderTypeEnum {

	CHATBOT (1L, "Blanca"),
	VICTIM (2L, "Usuario"),
	PROFESSIONAL (3L, "Profesional");
	
	@Getter
	public final Long id;
	
	@Getter
	public final String name;
	
	private SenderTypeEnum(Long id, String name) {
		this.id = id;
		this.name = name;
	}
	
	public static SenderTypeEnum getByName(String name) {
		name = WordUtils.capitalizeFully(name);
    	for (SenderTypeEnum entity : SenderTypeEnum.values()) {
    		if (entity.getName().equals(name)) {
    			return entity;
    		}
    	}
    	return null;
    }
	
}