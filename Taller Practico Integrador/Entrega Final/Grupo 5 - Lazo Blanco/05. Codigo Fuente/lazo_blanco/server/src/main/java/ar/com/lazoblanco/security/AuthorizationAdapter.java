package ar.com.lazoblanco.security;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Configuration;
import org.springframework.security.authentication.AuthenticationManager;
import org.springframework.security.oauth2.config.annotation.configurers.ClientDetailsServiceConfigurer;
import org.springframework.security.oauth2.config.annotation.web.configuration.AuthorizationServerConfigurerAdapter;
import org.springframework.security.oauth2.config.annotation.web.configuration.EnableAuthorizationServer;
import org.springframework.security.oauth2.config.annotation.web.configurers.AuthorizationServerEndpointsConfigurer;

@Configuration
@EnableAuthorizationServer
public class AuthorizationAdapter extends AuthorizationServerConfigurerAdapter {

	private static final String clientId = "lazoBlancoOauth2";

	private static final String secret = "Xz6qgjhQ5i";

	@Autowired
	private AuthenticationManager authenticationManager;
	
	@Override
	public void configure(AuthorizationServerEndpointsConfigurer endpoints) throws Exception {
		endpoints.authenticationManager(authenticationManager);
	}

	@Override
	// TODO: Ver el beneficio de pasarlo a DB
	public void configure(ClientDetailsServiceConfigurer clients) throws Exception {
		// "Authorization: Basic " base64_encode('$username':'$password')
		// c29mdGFsZW50T0F1dGgyOlh6NnFnamhRNWk=
		clients
			.inMemory()
			.withClient(clientId)
			.secret(secret)
			.authorizedGrantTypes("password", "refresh_token")
			.scopes("global")
			.accessTokenValiditySeconds(60*60*12);
	}
	
}
