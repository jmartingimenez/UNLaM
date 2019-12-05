(function () {
    'use strict';

    angular
        .module('app')
        .controller('Profile.User.Controller', ['$log', 'AuthenticationService', 'UserService', Controller]);

    function Controller($log, AuthenticationService, UserService) {
        var vm = this;

        vm.userData = {};

        function initController() {
            AuthenticationService.me()
                .then(response => {
                    UserService.getByUuid(response.userUuid)
                        .then(response => {
                            console.log(response.data);
                            vm.userData = response.data;
                        })
                })
                .catch(response => {
                    $log.error(response);
                })
        };

        initController();

    };

})();