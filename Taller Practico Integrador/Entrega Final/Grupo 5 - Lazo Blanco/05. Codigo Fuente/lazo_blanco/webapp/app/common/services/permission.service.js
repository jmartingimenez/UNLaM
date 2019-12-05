(function() {
    'use strict';

    angular
        .module('app')
        .factory('PermissionService', ['$rootScope', Service]);

    function Service($rootScope) {
        var service = {};

        var permissionList;

        service.setPermissions = setPermissions;
        service.hasPermission = hasPermission;

        function setPermissions(permissions) {
            permissionList = permissions;
            $rootScope.$broadcast('permissionsChanged');
        };

        function hasPermission(permission) {
            permission = permission.trim();
            return _.some(permissionList, function(item) {
                if(_.isString(item)) {
                    return item.trim() === permission;
                }
            });
        };
       
        return service;
    };

})();