(function () {
    'use strict';

    angular
        .module('app')
        .controller('Signup.Controller', ['$log', Controller]);

    function Controller($log) {
        var vm = this;

        vm.firstName = '';
        vm.email = '';
        vm.password = '';
        vm.passwordCheck = '';
        vm.errorMessage = '';
        vm.error = false;

        /*##### Call-Functions #####*/
        vm.signup = signup;

        function signup() {
            if(vm.email == null) {
                console.dir('null');
            }
            if (vm.email == undefined) {
                console.dir('undefined');
                return;
            }
            $log.debug(vm.email);
            $log.debug(vm.password);
            $log.debug(vm.passwordCheck);
        };

        function initController() {

        };

        initController();

    };

})();