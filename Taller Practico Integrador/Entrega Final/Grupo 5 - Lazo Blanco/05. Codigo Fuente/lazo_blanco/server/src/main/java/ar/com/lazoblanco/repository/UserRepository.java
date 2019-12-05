package ar.com.lazoblanco.repository;

import java.util.Date;
import java.util.List;

import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;

import ar.com.lazoblanco.entity.User;
import ar.com.lazoblanco.entity.UserStatusEnum;

public interface UserRepository extends BaseRepository<User, String> {
	
	@Query("SELECT U FROM User AS U WHERE U.status = 'ACTIVE' AND U.email = :value AND U.password = :password ")
    User findByCredentials(@Param("value") String value, @Param("password") String password);
		
	User findByEmailAndStatus(String email, UserStatusEnum status);
	
	User findByPasswordToken(String token);
	
	List<User> findByPermissions_Name(String permissionName);
	
	List<User> findByPasswordTokenIsNotNullAndTokenExpirationDateAfter(Date date);

}