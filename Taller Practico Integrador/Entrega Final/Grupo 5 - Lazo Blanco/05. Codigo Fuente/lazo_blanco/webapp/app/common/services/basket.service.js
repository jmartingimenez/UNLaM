(function () {
    'use strict';

    angular
        .module('app')
        .factory('BasketService', ['$localStorage', Service]);

    function Service($localStorage) {
        var items = [];

        var map = {};

        var service = {};

        service.addItem = addItem;
        service.removeItem = removeItem;
        service.items = returnItems;
        service.getItem = getItem;
        service.putInMap = putInMap;
        service.getFromMap = getFromMap;

        function addItem(item) {
            items.push(item);
        }

        function removeItem(item) {
            var index = items.indexOf(item);
            items.splice(index, 1);
        }

        function getItem(item) {
            return items.splice(item, 1)[0];
        }

        function returnItems() {
            return items;
        }

        /*
            Implementation with the browsers storage.
        */
        function putInMap(key, value) {
            var basketMap = $localStorage.basketMap;

            if (!basketMap)
                basketMap = {};

            basketMap[key] = value;

            $localStorage.basketMap = basketMap;
        }

        function getFromMap(key) {
            return $localStorage.basketMap[key];
        }

        return service;
    }

})();