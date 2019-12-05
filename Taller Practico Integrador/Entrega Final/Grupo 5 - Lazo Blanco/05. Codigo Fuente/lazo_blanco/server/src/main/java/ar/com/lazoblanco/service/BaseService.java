package ar.com.lazoblanco.service;

import java.io.Serializable;
import java.util.List;

import ar.com.lazoblanco.entity.AbstractEntity;
import ar.com.lazoblanco.repository.BaseRepository;

public interface BaseService<T extends AbstractEntity, ID extends Serializable> {

	BaseRepository<T, ID> getRepository();
	
	void initialize(T entity);
	
	List<T> findAll();
	
	T findByUuid(ID uuid);
	
	T save(T entity);
	
	T update(T oldEntity, T newEntity);
	
	Long delete(ID uuid);

}