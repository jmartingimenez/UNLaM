package ar.com.lazoblanco.repository;

import java.io.Serializable;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.JpaSpecificationExecutor;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.NoRepositoryBean;
import org.springframework.data.repository.query.Param;

import ar.com.lazoblanco.entity.AbstractEntity;

@NoRepositoryBean
public interface BaseRepository<T extends AbstractEntity, ID extends Serializable> extends JpaRepository<T, ID>, JpaSpecificationExecutor<T> {

	public <S extends T> S findByUuid(ID uuid);

	public Long deleteByUuid(String uuid);

	@Query("SELECT COUNT(E) > 0 FROM #{#entityName} AS E WHERE uuid = :uuid")
	public boolean existsByUuid(@Param("uuid") String uuid);
	
}