(function() {
    'use strict';

    angular
        .module('app')
        .directive('hasPermission', ['$log', 'AuthenticationService', Directive]);

    function Directive($log, AuthenticationService) {
        return {
            link: function link(scope, element, attrs) {
                if(!_.isString(attrs.hasPermission)) {
                    $log.error('Permission is empty.');
                } else {
                    AuthenticationService.me()
                        .then(response => {
                            if (response.role === attrs.hasPermission) {
                                element.show();
                            } else {
                                element.hide();
                            }
                        });
                }
            }
        };
    };

})();