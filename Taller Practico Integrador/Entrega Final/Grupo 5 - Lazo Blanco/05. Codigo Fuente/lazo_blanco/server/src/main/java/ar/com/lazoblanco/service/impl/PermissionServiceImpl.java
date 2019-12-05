package ar.com.lazoblanco.service.impl;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import ar.com.lazoblanco.entity.Permission;
import ar.com.lazoblanco.repository.BaseRepository;
import ar.com.lazoblanco.repository.PermissionRepository;
import ar.com.lazoblanco.service.PermissionService;

@Service
public class PermissionServiceImpl extends BaseServiceImpl<Permission, String> implements PermissionService {

	@Autowired
	PermissionRepository permissionRepository;

	@Override
	public BaseRepository<Permission, String> getRepository() {
		return permissionRepository;
	}

}