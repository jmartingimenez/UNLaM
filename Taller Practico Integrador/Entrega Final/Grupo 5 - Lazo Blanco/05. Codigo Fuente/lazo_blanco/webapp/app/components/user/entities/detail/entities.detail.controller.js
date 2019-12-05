(function () {
    'use strict';

    angular
        .module('app')
        .controller('EntitiesDetail.User.Controller', ['$log', '$stateParams', 'EntityService', 'LocationService','NgMap', Controller]);
    
    function Controller($log, $stateParams, EntityService, LocationService, NgMap) {
        var vm = this;

        vm.type = {};
        vm.entities = {};
        vm.chosenEntity = {};
        vm.chosenLocation = {};
        vm.viewDetail = viewDetail;

        vm.searchByCity = '';

        function viewDetail(entity) {
            vm.chosenEntity = entity;
            LocationService
                .get(vm.chosenEntity.locationUuid)
                .then(data => {
                    vm.chosenLocation = data;
                })
                .catch(error => {
                    $log.error(error);
                });
        };

        function getEntities(typeUuid) {
            EntityService
                .getType(typeUuid)
                .then(data => {
                    vm.type = data;
                    EntityService
                        .getAllByType(data.name)
                        .then(data => {
                            vm.entities = data;
                            _.each(vm.entities, function forEach(entity) {
                                LocationService.get(entity.locationUuid)
                                    .then(data => {
                                        entity.location = data;
                                    })
                                    .catch(error => {
                                        $log.error(error);
                                    });
                            })
                            vm.viewDetail(vm.entities[0]);
                        });
                })
                .catch(error => {
                    $log.error(error)
                });
        };
        
        function initController() {
            getEntities($stateParams.type);
            NgMap.getMap().then(function(map) {
                console.log(map.getCenter());
                console.log('markers', map.markers);
                console.log('shapes', map.shapes);
              });
        };

        initController();

    };

})();