(function () {
    'use strict';

    angular
        .module('app.config', []);

    angular
        .module('app', ['ui.router', 'ngAnimate', 'ngAria', 'ngCookies', 'ngMessageFormat', 'ngMessages', 'ngParseExt', 'ngResource', 'ngSanitize', 'ngStorage', 'ngTouch', 'app.config', 'ngMap'])
        .config(['$stateProvider', '$urlRouterProvider', routesConfig])
        .config(['$logProvider', logConfig])
        .config(['$httpProvider', httpInterceptorConfig])
        .factory('sessionLoginInterceptor', ['$q', '$location', SessionLoginInterceptor])
        .run(['$log', '$rootScope', '$http', '$location', '$localStorage', '$cookies', 'BasketService', 'RoleService', 'PermissionService', 'config', run]);

    function routesConfig($stateProvider, $urlRouterProvider) {
        // Default route
        $urlRouterProvider.otherwise('');

        $stateProvider
            // Unsecured
            .state('landing', {
                url: '/landing',
                templateUrl: 'components/unsecured/landing/landing.view.html',
                controller: 'Landing.Controller',
                controllerAs: 'vm'
            })
            .state('login', {
                url: '/login',
                templateUrl: 'components/unsecured/login/login.view.html',
                controller: 'Login.Controller',
                controllerAs: 'vm'
            })
            .state('signup', {
                url: '/signup',
                templateUrl: 'components/unsecured/signup/signup.view.html',
                controller: 'Signup.Controller',
                controllerAs: 'vm'
            })
            .state('unauthorized', {
                url: '/unauthorized',
                templateUrl: 'common/error.html'
            })
                        
            // Secured
            .state('index', {
                url: '',
                templateUrl: 'common/dashboard.html',
                abstract: true
            })

            // Administrators
            .state('index.admin', {
                url: '/a',
                template: '<div class="h-100" ui-view></div>',
                abstract: true
            })
                .state('index.admin.home', {
                    url: '/',
                    templateUrl: 'components/administrator/home/home.view.html',
                    controller: 'Home.Admin.Controller',
                    controllerAs: 'vm'
                })
            
            // Professionals
            .state('index.prof', {
                url: '/p',
                template: '<div class="h-100" ui-view></div>',
                abstract: true
            })
                .state('index.prof.home', {
                    url: '/',
                    templateUrl: 'components/professional/home/home.view.html',
                    controller: 'Home.Prof.Controller',
                    controllerAs: 'vm'
                })
                .state('index.prof.profile', {
                    url: '/profile',
                    templateUrl: 'components/professional/profile/profile.view.html',
                    controller: 'Profile.Prof.Controller',
                    controllerAs: 'vm'
                })
                .state('index.prof.chat', {
                    url: '/chat',
                    templateUrl: 'components/professional/chat/chat.view.html',
                    controller: 'Chat.Prof.Controller',
                    controllerAs: 'vm'
                })
                .state('index.prof.calendar', {
                    url: '/calendar',
                    templateUrl: 'components/professional/calendar/calendar.view.html',
                    controller: 'Calendar.Prof.Controller',
                    controllerAs: 'vm'
                })
            
            // Victims - Users
            .state('index.user', {
                url: '/u',
                template: '<div class="h-100" ui-view></div>',
                abstract: true
            })
                .state('index.user.home', {
                    url: '/',
                    templateUrl: 'components/user/home/home.view.html',
                    controller: 'Home.User.Controller',
                    controllerAs: 'vm'
                })
                .state('index.user.profile', {
                    url: '/profile',
                    templateUrl: 'components/user/profile/profile.view.html',
                    controller: 'Profile.User.Controller',
                    controllerAs: 'vm'
                })
                .state('index.user.chat', {
                    url: '/chat',
                    templateUrl: 'components/user/chat/chat.view.html',
                    controller: 'Chat.User.Controller',
                    controllerAs: 'vm'
                })
                .state('index.user.entities', {
                    url: '/entities',
                    template: '<div class="h-100" ui-view></div>',
                    abstract: true
                })
                    .state('index.user.entities.home', {
                        url: '/',
                        templateUrl: 'components/user/entities/entities.view.html',
                        controller: 'Entities.User.Controller',
                        controllerAs: 'vm'
                    })
                    .state('index.user.entities.detail', {
                        url: '/detail/:type',
                        templateUrl: 'components/user/entities/detail/entities.detail.view.html',
                        controller: 'EntitiesDetail.User.Controller',
                        controllerAs: 'vm'
                    })
                .state('index.user.document-abuse', {
                    url: '/document-abuse',
                    templateUrl: 'components/user/documentAbuse/documentAbuse.view.html',
                    controller: 'DocumentAbuse.User.Controller',
                    controllerAs: 'vm'
                })

        ;
    };

    function logConfig($logProvider) {
        $logProvider.debugEnabled(true);
    };

    function httpInterceptorConfig($httpProvider) {
        $httpProvider.interceptors.push('sessionLoginInterceptor');
    };

    function SessionLoginInterceptor($q, $location) {
        var sessionRecoverer = {
            responseError: function (response) {
                // Session has expired
                if (response.data.error === 'invalid_token') {
                    $location.path('/login');
                } else {
                    if (response.status === 419) {
                        //console.log("SessionLoginInterceptor error");
                        return null;
                    }

                    if (response.status === 401 || response.status === 403) {
                        $location.path('/unauthorized');
                    }
                }
                return $q.reject(response);
            }
        };
        return sessionRecoverer;
    };

    function run($log, $rootScope, $http, $location, $localStorage, $cookies, BasketService, RoleService, PermissionService, config) {
        $log.debug('Iniciando app...');

        var appPath = $location.host().replace('lazoblanco.com.ar', '');

        if (appPath && appPath.indexOf('lazoblanco') != 0) {
            $http({
                method: 'GET',
                url: config.apiUrl + appPath.toLowerCase()
            }).then(
                function onSuccess(response) {
                    console.dir('Success! - ', response);
                },
                function onError(response) {
                    $log.error(response);
                    if(response.status == 404) {
                        location.href = 'http://www.lazoblanco.com.ar';
                    }
                }
            );
        }

        if ($localStorage.rememberedUser) {
            $cookies.putObject('currentUser', $localStorage.rememberedUser);
        }

        if ($cookies.get('currentUser')) {
            var currentUser = $cookies.get('currentUser');
            // Deslogueaba desde backend esta basoura
            // $http.defaults.headers.common.Authorization = 'Bearer ' + currentUser.token; 
            if(currentUser.permissions != null)
                RoleService.create(currentUser.permissions, currentUser.role);
            if ($location.path() !== '/login') {
                RoleService.goHome();
            }
        }

        $rootScope.$on('$locationChangeStart', function onChange(event, next, current) {
            var publicPages = ['/login', '/landing', '/signup', '/unauthorized'];
            var restrictedPage = publicPages.indexOf($location.path()) === -1;
            if (restrictedPage && !$cookies.get('currentUser')) {
                $log.error('Restricted Page');
                BasketService.addItem($location.path());
                $location.path('/landing');
            }
        });

        $rootScope.$on('$routeChangeStart', function onChange(event, next, current) {
            var permission = next.$$route.permission;
            if (_.isString(permission) && !PermissionService.hasPermission(permission)) {
                $location.path('/unauthorized');
            }
        });

        $log.debug('App iniciada!');
    };

})();