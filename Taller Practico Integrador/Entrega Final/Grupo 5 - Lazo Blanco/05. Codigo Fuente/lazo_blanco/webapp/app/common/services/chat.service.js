(function () {
    'use strict';

    angular
        .module('app')
        .factory('ChatService', ['$http', 'config', Service]);

    function Service($http, config) {
        return {
            getAllRoomsByUser: function getAllRoomsByUser(userUuid) {
                return $http.get(config.apiUrl + 'chat-room/user/' + userUuid);
            },

            getRoomByUuid: function getRoomByUuid(roomUuid) {
                return $http.get(config.apiUrl + 'chat-room/' + roomUuid);
            },
            
            getAllMessagesByRoom: function getAllMessagesByRoom(roomUuid) {
                return $http.get(config.apiUrl + 'chat-message/room/' + roomUuid);
            },

            saveMessage: function saveMessage(message) {
                return $http.post(config.apiUrl + 'chat-message/', message);
            },
        };
    };

})();