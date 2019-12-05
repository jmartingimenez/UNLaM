(function () {
    'use strict';

    const SENDER_BOT = "Blanca";
    const SENDER_VICTIM = "Usuario";

    angular
        .module('app')
        .factory('ChatbotService', ['$http', 'config', '$rootScope', '$timeout', Service]);

    function Service($http, config, $rootScope, $timeout) {

        let chatStatus = {
            messageLog : [],
            lastMessage : null,
            availableAnswers : [],
            fullFlow : {}
        };

        let service = {
            appendMessage : appendMessage, 
            chatStatus : chatStatus,
            clearChat : clearChat,
            SENDER_VICTIM : SENDER_VICTIM
        };

        loadFlow().then(flow => {
            service.chatStatus.fullFlow = flow;
            clearChat();
        });

        return service;

        function clearChat() {
            service.chatStatus.messageLog = [];
            service.chatStatus.lastMessage = null;
            service.chatStatus.availableAnswers = [];
            messageSelectedById(service.chatStatus.fullFlow.initialQuestion, SENDER_BOT);
        }

        function messageSelectedById(messageId, sender) {
            sender = sender != null ? sender : SENDER_VICTIM;
            let message = service.chatStatus.fullFlow.messages[messageId];
            appendMessage(message, sender);
        }

        function appendMessage(message, sender) {
            message.sender = sender;
            message.timestamp = new Date().toISOString();
            service.chatStatus.lastMessage = message;
            let availableAnswers = message.answers ? message.answers : [];
            service.chatStatus.availableAnswers = availableAnswers.map(id => service.chatStatus.fullFlow.messages[id]);
            service.chatStatus.messageLog.push(message);

            if(message.autoAnswer && message.answers.length == 1) {
                $timeout( () => messageSelectedById(message.answers[0], SENDER_BOT) , 1000);
            }

            $rootScope.$broadcast('chatbot-update', {status : service.chatStatus});
        }

        function loadFlow() {
            return $http.get(config.dialogFlowApi.getFlow)
                .then(res => res.data);
        }
    };

})();