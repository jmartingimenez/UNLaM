(function () {
    'use strict';

    angular
        .module('app')
        .factory('EntityService', ['$http', 'config', Service]);

    function Service($http, config) {
        return {

            get: function get(uuid) {
                return $http
                    .get(config.apiUrl + 'publicEntity/' + uuid)
                    .then(response => {
                        return response.data;
                    });
            },

            getAll: function getAll() {
                return $http
                    .get(config.apiUrl + 'publicEntity/')
                    .then(response => {
                        return response.data;
                    });
            },

            getAllByType: function getAllByType(type) {
                return $http
                    .get(config.apiUrl + 'publicEntity/type' + type)
                    .then(response => {
                        return response.data;
                    });
            },

            getType: function getType(typeUuid) {
                return $http
                    .get(config.apiUrl + 'entityType/' + typeUuid)
                    .then(response => {
                        return response.data;
                    });
            },

            getAllTypes: function getAllTypes() {
                return $http
                    .get(config.apiUrl + 'entityType/')
                    .then(response => {
                        return response.data;
                    });
            }

        }
    };

})();