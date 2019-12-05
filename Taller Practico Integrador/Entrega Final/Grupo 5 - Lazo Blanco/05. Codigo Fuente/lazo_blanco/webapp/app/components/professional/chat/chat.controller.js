(function () {
    'use strict';

    angular
        .module('app')
        .controller('Chat.Prof.Controller', ['$scope', '$log', '$interval', 'AuthenticationService', 'ChatService', Controller]);
    
    function Controller($scope, $log, $interval, AuthenticationService, ChatService) {
        var vm = this;

        vm.timer;

        vm.chatRooms = {};
        vm.selectedRoom = {};
        vm.messageLog = {};
        vm.messageInput = "";
        
        vm.selectRoom = selectRoom;
        vm.submitMessage = submitMessage;

        function submitMessage() {
            let toSubmit = {
                'uuid': null,
                'timestamp': new Date().toISOString(),
                'room': vm.selectedRoom,
                'content': vm.messageInput,
                'sender': 'Profesional'
            };
            ChatService.saveMessage(toSubmit)
                .then(response => {
                    getMessages();
                })
                .catch(response => {
                    $log.error(response);
                });
            vm.messageInput = "";
        };

        function selectRoom(uuid) {
            ChatService.getRoomByUuid(uuid)
                .then(response => {
                    vm.selectedRoom = response.data;
                    getMessages();
                })
                .catch(response => {
                    $log.error(response);
                });
        };

        function getMessages() {
            let messages = [];
            ChatService.getAllMessagesByRoom(vm.selectedRoom.uuid)
                .then(response => {
                    _.each(response.data, function forEach(item) {
                        messages.push(item);
                    });
                    vm.messageLog = messages;
                })
                .catch(response => {
                    $log.error(response);
                });
        };

        function getAllChatRooms() {
            AuthenticationService.me()
                .then(response => {
                    ChatService.getAllRoomsByUser(response.userUuid)
                        .then(response => {
                            vm.chatRooms = response.data;
                            selectRoom(response.data[0].uuid);
                        })
                        .catch(response => {
                            $log.error(response);
                        });
                })
        };

        function initController() {
            getAllChatRooms();
            vm.timer = $interval(function setTimer() { 
                getMessages(); 
            }, 1000); 
        };

        initController();

        $scope.$on('$destroy', function() {
            $interval.cancel(vm.timer);
        });

    };

})();