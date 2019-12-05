package ar.com.lazoblanco.entity;

import org.apache.commons.lang3.text.WordUtils;

import lombok.Getter;

/*
 * Enumerator for types of public entities.
 * 
 * @author RAndreoli
 * @version 1.0.0
 * @since 1.0.0
 */
public enum PublicEntityTypeEnum {

	POLICE (1L, "Comisaría"),
	WOMENSPOLICE (2L, "Comisaría de la Mujer"),
	CLINIC (3L, "Clínica"),
	HOSPITAL (4L, "Hospital"),
	REFUGE (5L, "Refugio"),
	INSTITUTION (6L, "Institución"),
	ATTORNEY(7L, "Estudio jurídico"),
	PSICOLOGY(8L, "Centro de psicología"),
	ASSISTANCE(9L, "Centro de asistencia");
	
	@Getter
	public final Long id;
	
	@Getter
	public final String name;
	
	private PublicEntityTypeEnum(Long id, String name) {
		this.id = id;
		this.name = name;
	}
	
	public static PublicEntityTypeEnum getByName(String name) {
		name = WordUtils.capitalizeFully(name);
    	for (PublicEntityTypeEnum entity : PublicEntityTypeEnum.values()) {
    		if (entity.getName().equals(name)) {
    			return entity;
    		}
    	}
    	return null;
    }
	
}