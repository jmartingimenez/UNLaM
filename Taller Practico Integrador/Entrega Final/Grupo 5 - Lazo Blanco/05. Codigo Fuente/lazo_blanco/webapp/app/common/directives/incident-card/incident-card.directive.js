(function() {
    'use strict';

    angular
        .module('app')
        .directive('incidentCard', ['PermissionService', Directive]);

    function Directive(PermissionService) {

        return {
            restrict: 'E',
            scope: {
                incident: '='
            },
            templateUrl : "common/directives/incident-card/incident-card.directive.html"
        };
    }

})();