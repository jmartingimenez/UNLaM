package ar.com.lazoblanco.service;

import java.io.IOException;
import java.io.InputStream;

import com.fasterxml.jackson.core.JsonProcessingException;

public interface JsonService {

    String EMPTY_STRING = "";

    /**
     * Serializes an Object.
     *
     * @param object the {@link java.lang.Object} to be serialized.
     * @return a JSON formatted string.
     * @throws JsonProcessingException
     */
    String toJSONString(Object object) throws JsonProcessingException;
    
    /**
     * Serializes the selected fields for an object.
     * @param object
     * @param filter
     * @return
     * @throws JsonProcessingException
     */
    String toJSONString(Object object, String filter) throws JsonProcessingException;

    /**
     * Deserializes an Object from a JSON String
     *
     * @param rowData     the String with JSON data
     * @param objectClass class of the desired object to return
     * @param <T>         result class
     * @return a java object filled with the JSON String
     * @throws IOException
     */
    <T> T deserialize(String rowData, Class<T> objectClass) throws IOException;

    /**
     * Deserializes an Object from a JSON inputStream
     *
     * @param rowData     the String with JSON data
     * @param objectClass class of the desired object to return
     * @param <T>         result class
     * @return a java object filled with the JSON String
     * @throws IOException
     */
    <T> T deserialize(InputStream rowData, Class<T> objectClass) throws IOException;
    
}