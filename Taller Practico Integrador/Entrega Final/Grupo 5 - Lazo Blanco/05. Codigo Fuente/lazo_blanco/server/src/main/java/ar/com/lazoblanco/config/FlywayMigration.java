package ar.com.lazoblanco.config;

import org.flywaydb.core.Flyway;
import org.springframework.boot.autoconfigure.flyway.FlywayMigrationStrategy;
import org.springframework.context.annotation.Configuration;

@Configuration
public class FlywayMigration implements FlywayMigrationStrategy{

	@Override
	public void migrate(Flyway flyway) {
		flyway.migrate();
	}

}
