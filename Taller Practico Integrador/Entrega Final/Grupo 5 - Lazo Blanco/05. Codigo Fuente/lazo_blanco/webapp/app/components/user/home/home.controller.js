(function () {
    'use strict';

    angular
        .module('app')
        .controller('Home.User.Controller', ['$log', 'HomeService', 'IncidentService', 'AuthenticationService', 'ChatbotService', '$scope', Controller]);
    
    function Controller($log, HomeService, IncidentService, AuthenticationService, ChatbotService, $scope) {
        var vm = this;
        vm.commonIncidents = [];
        vm.customComment = "";
        vm.submitHelpRequest = submitHelpRequest;
        vm.disableSubmitButton = false;
        vm.incompleteWarningVisible = false;

        vm.chatbotData = {};
        vm.answerSelected = answerSelected;
        vm.submitChatbotRequest = submitChatbotRequest;

        function initController() {
            HomeService.fetchCommonIncidents()
                .then(incidents => { vm.commonIncidents = incidents });

            vm.chatbotData = ChatbotService.chatStatus;

            $scope.$on('chatbot-update', function(event, opt) {
                vm.chatbotData = opt.status;
            });
        };

        initController();

        function submitHelpRequest() {
            vm.incompleteWarningVisible = false;

            if (asLeastOneReasonSelected() || hasExtraComment()) {

                vm.disableSubmitButton = true;

                AuthenticationService.MyId().then(victimId => {
                    IncidentService.requestHelpWithIncidents(vm.commonIncidents, vm.customComment, victimId)
                        .then(res => {
                            toastr.success("Gracias! A la brevedad tendrás un chat disponible con un profesional capacitado");
                            cleanForm();
                        })
                        .catch(err => { 
                            toastr.error("Lo sentimos, pero ocurrió un problema. Por favor, refresca la página y vuelve a intentarlo");
                            vm.disableSubmitButton = false;
                        });
                });
            } else {
                vm.incompleteWarningVisible = true;
                setTimeout(() => {
                    let container = document.querySelector(".incident-category-cards-container");
                    container.scrollTo(0, container.scrollHeight);
                }, 100);
            }
        }
        
        function cleanForm() {
            vm.customComment = "";
            vm.disableSubmitButton = false;
            vm.commonIncidents.forEach(incidentType => {
                incidentType.possibleIncidents.forEach(incident => incident.happened = false);
            });
        }

        function asLeastOneReasonSelected() {
            return vm.commonIncidents.some(elem => {
                return elem.possibleIncidents.some(incident => incident.happened);
            });
        }

        function hasExtraComment() {
            return !!vm.customComment.trim();
        }

        function answerSelected(answer) {
            ChatbotService.appendMessage(answer, ChatbotService.SENDER_VICTIM);
        }

        function submitChatbotRequest() {

            vm.disableSubmitButton = true;

            AuthenticationService.MyId().then(victimId => {
                IncidentService.submitChatbotConversation(vm.chatbotData.messageLog, vm.customComment, victimId)
                    .then(res => {
                        toastr.success("Gracias! A la brevedad tendrás un chat disponible con un profesional capacitado");
                        cleanForm();
                    })
                    .catch(err => { 
                        toastr.error("Lo sentimos, pero ocurrió un problema. Por favor, refresca la página y vuelve a intentarlo");
                        vm.disableSubmitButton = false;
                    });
            });
        }
    };

})();