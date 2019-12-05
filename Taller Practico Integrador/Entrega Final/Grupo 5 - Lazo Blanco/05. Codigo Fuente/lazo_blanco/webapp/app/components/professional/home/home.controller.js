(function () {
    'use strict';

    angular
        .module('app')
        .controller('Home.Prof.Controller', ['$log', '$state', Controller]);
    
    function Controller($log, $state) {
        var vm = this;

        function initController() {
            $state.go('index.prof.chat');
        };

        initController();

    };

})();