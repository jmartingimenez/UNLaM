(function () {
    'use strict';

    angular
        .module('app')
        .controller('Login.Controller', ['$log', '$location', 'BasketService', 'AuthenticationService', 'RoleService', 'ChatbotService', Controller]);

    function Controller($log, $location, BasketService, AuthenticationService, RoleService, ChatbotService) {
        var vm = this;

        vm.username = '';
        vm.password = '';
        vm.errorMessage = '';
        vm.error = false;
        vm.rememberMe = false;

        /*##### Call-Functions #####*/
        vm.login = login;

        function login() {
            clearErrors();
            AuthenticationService.login(vm.username, vm.password)
                .then(user => {
                    ChatbotService.clearChat();
                    var requestedPage = BasketService.getItem(0);
                    if (requestedPage) {
                        $location.path(requestedPage);
                    } else {
                        RoleService.goHome();
                    }
                }).catch(logError);
        };

        function clearErrors() {
            vm.errorMessage = "";
            vm.error = false;
        }

        function logError(data) {
            if (data.error === 'invalid_grant' || data.error_description === 'Bad credentials') {
                vm.errorMessage = 'La cuenta no existe o la contraseña es incorrecta';
            } else if (data.error === 'unauthorized' && data.error_description === 'login.badcredentials.error') {
                vm.errorMessage = 'La cuenta no existe o la contraseña es incorrecta'
            } else if (data.error_description === 'login.disabled.error') {
                vm.errorMessage = 'Cuenta deshabilitada';
            } else {
                vm.errorMessage = 'Ocurrió un error';
            }
            vm.error = true;
        }

        function initController() {
            AuthenticationService.logout();
        };

        initController();

    };

})();