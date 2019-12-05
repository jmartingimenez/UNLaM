(function () {
    'use strict';

    angular
        .module('app')
        .controller('Entities.User.Controller', ['$log', 'EntityService', Controller]);
    
    function Controller($log, EntityService) {
        var vm = this;

        vm.types = {};

        function getEntitiesTypes() {
            EntityService
                .getAllTypes()
                .then(data => {
                    vm.types = data;
                })
                .catch(error => {
                    $log.error(error);
                });
        };

        function initController() {
            getEntitiesTypes();
        };

        initController();

    };

})();