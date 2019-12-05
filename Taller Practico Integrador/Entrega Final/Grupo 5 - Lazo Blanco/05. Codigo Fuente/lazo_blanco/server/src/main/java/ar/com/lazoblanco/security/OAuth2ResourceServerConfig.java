package ar.com.lazoblanco.security;

import static ar.com.lazoblanco.controller.BaseController.REST_URI;

import org.springframework.context.annotation.Configuration;
import org.springframework.security.access.expression.method.MethodSecurityExpressionHandler;
import org.springframework.security.config.annotation.method.configuration.EnableGlobalMethodSecurity;
import org.springframework.security.config.annotation.method.configuration.GlobalMethodSecurityConfiguration;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.oauth2.config.annotation.web.configuration.EnableResourceServer;
import org.springframework.security.oauth2.config.annotation.web.configuration.ResourceServerConfigurerAdapter;
import org.springframework.security.oauth2.provider.expression.OAuth2MethodSecurityExpressionHandler;

@EnableGlobalMethodSecurity(prePostEnabled = true, proxyTargetClass = true)
public class OAuth2ResourceServerConfig extends GlobalMethodSecurityConfiguration {

	@Override
	protected MethodSecurityExpressionHandler createExpressionHandler() {
		return new OAuth2MethodSecurityExpressionHandler();
	}

	@Configuration
	@EnableResourceServer
	protected static class ResourceServer extends ResourceServerConfigurerAdapter {

		@Override
		public void configure(HttpSecurity http) throws Exception {
			// @formatter:off
			http.authorizeRequests().antMatchers("/oauth/**").permitAll()
			.antMatchers(REST_URI + "/unsecured/**").permitAll()
			.antMatchers(REST_URI + "/security/**").permitAll()
			.antMatchers(REST_URI + "/template/**").permitAll()
			.antMatchers(REST_URI + "/export/**").permitAll()
			.antMatchers(REST_URI + "/downloadFile").permitAll()
			.antMatchers("/mappings").permitAll()
			.anyRequest().authenticated();
            // @formatter:on
		}

	}
	
}