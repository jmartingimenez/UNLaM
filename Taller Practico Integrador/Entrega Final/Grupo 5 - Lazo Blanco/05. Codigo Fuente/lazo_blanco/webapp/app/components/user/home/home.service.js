(function () {
    'use strict';

    angular
        .module('app')
        .factory('HomeService', ['$log', '$http', '$q', 'config', Service]);

    function Service($log, $http, $q, config) {
        var service = {};

        service.fetchCommonIncidents = function() {
            return $http.get("/resources/data/common-incidents.json")
                .then(res => res.data);
        };

        return service;
    };

})();