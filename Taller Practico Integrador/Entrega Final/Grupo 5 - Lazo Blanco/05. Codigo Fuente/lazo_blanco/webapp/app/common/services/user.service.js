(function () {
    'use strict';

    angular
        .module('app')
        .factory('UserService', ['$http', 'config', Service]);

    function Service($http, config) {
        return {
            getByUuid: function getByUuid(userUuid) {
                return $http.get(config.apiUrl + 'user/' + userUuid);
            },
        };
    };

})();