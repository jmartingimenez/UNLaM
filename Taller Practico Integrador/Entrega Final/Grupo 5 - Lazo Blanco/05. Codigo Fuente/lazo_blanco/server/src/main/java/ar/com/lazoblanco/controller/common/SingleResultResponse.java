package ar.com.lazoblanco.controller.common;

import ar.com.lazoblanco.entity.AbstractEntity;
import lombok.Getter;
import lombok.Setter;

public class SingleResultResponse<T extends AbstractEntity> extends Response {

	private static final long serialVersionUID = 3030972553137731534L;

	@Getter @Setter
	private T result;

	public SingleResultResponse(T result) {
		this.result = result;
	}
}
