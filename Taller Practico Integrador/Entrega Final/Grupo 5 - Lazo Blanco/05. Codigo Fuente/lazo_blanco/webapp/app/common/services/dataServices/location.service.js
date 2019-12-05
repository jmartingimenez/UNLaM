(function () {
    'use strict';

    angular
        .module('app')
        .factory('LocationService', ['$http', 'config', Service]);

        function Service($http, config) {
            return {
    
                get: function get(uuid) {
                    return $http
                        .get(config.apiUrl + 'location/' + uuid)
                        .then(response => {
                            return response.data;
                        });
                },
    
                getAll: function getAll() {
                    return $http
                        .get(config.apiUrl + 'location/')
                        .then(response => {
                            return response.data;
                        });
                }
    
            }
        };

})();