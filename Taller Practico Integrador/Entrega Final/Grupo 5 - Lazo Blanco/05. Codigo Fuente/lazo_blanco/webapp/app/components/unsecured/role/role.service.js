(function() {
    'use strict';

    angular
        .module('app')
        .factory('RoleService', ['$state', '$log', 'PermissionService', Service]);

    function Service($state, $log, PermissionService) {
        var service = {};

        var permissionList;
        var length;
        var actual;
        var role = '';

        service.isCompanyAdmin = isCompanyAdmin;
        service.create = create;
        service.goHome = goHome;

        function isCompanyAdmin() {
            return role === 'ADMINISTRATOR';
        };

        function create(permissionsParam, roleParam) {
            role = roleParam;
            permissionList = permissionsParam;
            length = permissionsParam.length;
            actual = 0;
            PermissionService.setPermissions([permissionList[0]]);
        };

        function goHome() {
            if(PermissionService.hasPermission('allow-administrator')) {
                $state.go('index.admin.home');
            } else if (PermissionService.hasPermission('allow-professional')) {
                $state.go('index.prof.home');
            } else if (PermissionService.hasPermission('allow-victim')) {
                $state.go('index.user.home');
            } else {
                $state.go('landing');
            }
        };
       
        return service;
    };

})();