(function () {
    'use strict';

    angular
        .module('app')
        .factory('IncidentService', ['$http', 'config', Service]);

    function Service($http, config) {
        return {
            requestHelpWithIncidents : requestHelpWithIncidents,
            submitChatbotConversation : submitChatbotConversation
        };

        function requestHelpWithIncidents(incidents, customComment, victimId) {
            let report = buildIncidentReport(incidents, customComment, victimId);
            return $http.post(config.apiUrl + 'chat-room/create/', report);
        }

        function submitChatbotConversation(messageLog, customComment, victimId) {
            let report = buildChatLogReport(messageLog, customComment, victimId);
            return $http.post(config.apiUrl + 'chat-room/create/', report);
        }
    };

    function buildIncidentReport(incidents, customComment, victimId) {

        let currentTimestamp = new Date().toISOString();

        let report = buildBaseReport(victimId);
        
        incidents.forEach(incidentType => {
            let incidentTypeEntry = {
                violence : incidentType.title,
                valoration : 0
            };

            incidentType.possibleIncidents.forEach(incident => {
                if (incident.happened) {
                    let incidentEntry = buildIncidentEntry(incident.title);
                    incidentEntry.timestamp = currentTimestamp;
                    
                    report.messages.push(incidentEntry);
                    incidentTypeEntry.valoration++;
                }
            });

            report.problemEvaluation.push(incidentTypeEntry);
        });

        if (customComment) {
            let commentEntry = buildIncidentEntry(customComment);
            commentEntry.timestamp = currentTimestamp;
            report.messages.push(commentEntry);
        }

        return report;
    }

    function buildChatLogReport(messageLogEntries, customComment, victimId) {
        let report = buildBaseReport(victimId);

        messageLogEntries.forEach(entry => {
            let builtEntry = {
                uuid: null,
                room: null,
                sender: entry.sender,
                timestamp: entry.timestamp,
                content: entry.text
            }
            report.messages.push(builtEntry);

            let problemEvaluationEntry = {
                violence : entry.violenceType || "",
                valoration : entry.valoration || 0
            };
            report.problemEvaluation.push(problemEvaluationEntry);
        });

        if (customComment && customComment.trim()) {
            let builtEntry = buildIncidentEntry(customComment);
            builtEntry.timestamp = new Date().toISOString();
            report.messages.push(builtEntry);
        }

        return report;
    }

    function buildBaseReport(victimId) {
        return {
            messages : [],
            problemEvaluation : [],
            victimUuid : victimId
        };
    }

    function buildIncidentEntry(content) {
        return {
            uuid : null,
            room : null,
            sender : "Usuario",
            content : content
        };
    }

})();