var dev_api_url = 'http://localhost:8080';
var dev = {
    config: {
        appName: 'Lazo Blanco',
        appVersion: '1.0.0',
        apiUrl: dev_api_url + '/rest/v1/',
        auth: {
            url: dev_api_url + '/oauth/token',
            recoverUrl: dev_api_url + '/rest/v1/security/forgot-password',
            resetUrl: dev_api_url + '/rest/v1/security/confirm-password',
            clientId: 'lazoblancoOAuth2',
            header: 'Basic c29mdGFsZW50T0F1dGgyOlh6NnFnamhRNWk=',
            grantType: 'password'
        }
    }
};

var prod_api_url = 'https://api.lazoblanco.com.ar';
var prod = {
    config: {
        appName: 'Lazo Blanco',
        appVersion: '1.0.0',
        apiUrl: prod_api_url + '/rest/v1/',
        auth: {
            url: prod_api_url + '/oauth/token',
            recoverUrl: prod_api_url + '/rest/v1/security/forgot-password',
            resetUrl: prod_api_url + '/rest/v1/security/confirm-password',
            clientId: 'lazoblancoOAuth2',
            header: 'Basic c29mdGFsZW50T0F1dGgyOlh6NnFnamhRNWk=',
            grantType: 'password'
        }
    }
};

module.exports = {
    dev: dev,
    prod: prod
};