package ar.com.lazoblanco.controller.common;

import java.util.ArrayList;
import java.util.List;

import ar.com.lazoblanco.entity.AbstractEntity;
import lombok.Getter;
import lombok.Setter;

public class ListResultResponse<T extends AbstractEntity> extends Response {

	private static final long serialVersionUID = -2690777073688064812L;

	@Getter @Setter
	private List<T> results;

	public ListResultResponse(List<T> results) {
		this.results = new ArrayList<T>();
		this.results.addAll(results);
	}
}
