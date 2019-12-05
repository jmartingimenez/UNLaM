package ar.com.lazoblanco.service.impl;

import java.io.IOException;
import java.io.InputStream;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Locale;

import javax.annotation.PostConstruct;

import org.springframework.stereotype.Service;

import com.fasterxml.jackson.annotation.JsonInclude;
import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.ObjectWriter;
import com.fasterxml.jackson.databind.ser.FilterProvider;
import com.fasterxml.jackson.databind.ser.impl.SimpleBeanPropertyFilter;
import com.fasterxml.jackson.databind.ser.impl.SimpleFilterProvider;

import ar.com.lazoblanco.service.JsonService;

@Service
public class JsonServiceImpl implements JsonService {

	private ObjectMapper oMapper;

	public String toJSONString(Object object) throws JsonProcessingException {
		return toJSONString(object, "");
	}

	@Override
	public String toJSONString(Object object, String filter) throws JsonProcessingException {
		if (filter == null)
			filter = "";
		FilterProvider filters = new SimpleFilterProvider().addFilter("filter" + object.getClass().getName(),
				SimpleBeanPropertyFilter.serializeAllExcept(filter.split(",")));

		ObjectWriter writer = oMapper.writer(filters);

		return writer.writeValueAsString(object);
	}

	@Override
	public <T> T deserialize(String rowData, Class<T> objectClass) throws IOException {

		T object;
		object = oMapper.readValue(rowData, objectClass);

		return object;
	}

	@Override
	public <T> T deserialize(InputStream rowData, Class<T> objectClass) throws IOException {

		T object;
		object = oMapper.readValue(rowData, objectClass);

		return object;
	}

	@PostConstruct
	public void init() {
		oMapper = new ObjectMapper();
		DateFormat df = new SimpleDateFormat("yyyy-MM-dd", Locale.US);
		oMapper.setDateFormat(df);
		oMapper.setSerializationInclusion(JsonInclude.Include.NON_NULL);
	}

}