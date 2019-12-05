package ar.com.lazoblanco.service.impl;

import java.io.Serializable;
import java.util.Date;
import java.util.List;
import java.util.UUID;

import org.springframework.security.core.Authentication;
import org.springframework.security.core.context.SecurityContextHolder;

import ar.com.lazoblanco.entity.AbstractEntity;
import ar.com.lazoblanco.security.UserSession;
import ar.com.lazoblanco.service.BaseService;

public abstract class BaseServiceImpl<T extends AbstractEntity, ID extends Serializable> implements BaseService<T, ID> {

	protected UserSession getUserSession() {
		Authentication auth = SecurityContextHolder.getContext().getAuthentication();
		return ((UserSession) auth.getPrincipal());
	}

	@Override
	public void initialize(T entity) {
		entity.setUuid(UUID.randomUUID().toString());
		entity.setCreatedAt(new Date());
		entity.setUpdatedAt(new Date());
//		entity.setUpdatedBy(getUserSession().getUsername());
		entity.setUpdatedBy("admin@lazoblanco.com.ar");
	}

	@Override
	public List<T> findAll() {
		return getRepository().findAll();
	}

	@Override
	public T findByUuid(ID uuid) {
		return getRepository().findByUuid(uuid);
	}

	@Override
	public T save(T entity) {
		initialize(entity);
		return getRepository().save(entity);
	}

	@Override
	public T update(T oldEntity, T newEntity) {
		oldEntity.setUpdatedAt(new Date());
//		oldEntity.setUpdatedBy(getUserSession().getUsername());
		oldEntity.setUpdatedBy("admin@lazoblanco.com.ar");
		return getRepository().save(oldEntity);
	}

	@Override
	public Long delete(ID uuid) {
		return getRepository().deleteByUuid(uuid.toString());
	}
	
}