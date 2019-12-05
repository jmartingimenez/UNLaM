(function () {
    'use strict';

    const CURRENT_USER_COOKIE = "currentUser";

    angular
        .module('app')
        .factory('AuthenticationService', ['$log', '$http', '$q', '$localStorage', '$cookies', 'BasketService', 'RoleService', 'config', Service]);

    function Service($log, $http, $q, $localStorage, $cookies, BasketService, RoleService, config) {

        var service = {};

        service.login = Login;
        service.logout = Logout;
        service.recoverPassword = RecoverPassword;
        service.resetPassword = ResetPassword;
        service.me = Me;
        service.MyId = MyId;

        return service;

        function Login(username, password) {
            let params = {
                'grant_type': config.auth.grantType,
                'username': username,
                'password': password,
                'client_id': config.auth.clientId,
            };
            let headers = {
                'Authorization': config.auth.header
            };
            return $http.post(config.auth.grantType, params, headers)
                .then(response => {
                    if(user != null) {
                        return storeUserInSession(user);
                    } else return $q.reject({ "error" : "invalid_grant" });
                });
        };

        function storeUserInSession(userData) {
            if (userData.permissions) {
                RoleService.create(userData.permissions, userData.role);
            }
            var obj = {
                username: userData.email,
                email: userData.email,
                firstname: userData.firstName,
                lastname: userData.lastName,
                permissions: userData.permissions,
                role: userData.role,
                userUuid: userData.uuid
            };

            $cookies.putObject(CURRENT_USER_COOKIE, obj);
            $localStorage.rememberedUser = obj;

            return obj;
        };

        function Logout() {
            $cookies.remove(CURRENT_USER_COOKIE);
            delete $localStorage.rememberedUser;
            delete BasketService.requestedPage;
            $http.defaults.headers.common.Authorization = '';
        };

        function RecoverPassword() {
            console.dir('TODO - RecoverPassword()');
        };

        function ResetPassword() {
            console.dir('TODO - ResetPassword()');
        };

        function Me() {
            return $q.resolve($cookies.getObject(CURRENT_USER_COOKIE));
        };

        function MyId() {
            return Me().then(currentUserData => {
                return currentUserData != null ? currentUserData.userUuid : null
            });
        }

    };

})();