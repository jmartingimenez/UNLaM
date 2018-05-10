function ValidarFormulario(formulario)	

{

//Usuario


	if(formulario.usuario.value.length ==0)
		{
			alert("Nombre de Usuario No puede estar vacio");
			return false;
		
		}	


	if(!TieneFormatoUsuario(formulario.usuario.value))	
	{
		alert("EL nombre del Usuario solo puede contener letras");
		return false;
	}

	if(!TieneMayuscula(formulario.usuario.value))
	{
		alert("El  Usuario debe contener una letra en Mayuscula")
		return false;
	}

//password


	if(formulario.password.value.length ==0)
		{
			alert("La password No puede estar vacio");
			return false;
		
		}

	if(formulario.password.value.length <5 || formulario.password.value.length >20)
	{
		alert("La password debe contener entre 5 y 10 caracteres");
		return false;
	}	

//repassword

	if(formulario.repassword.value.length ==0)
		{
			alert("La repassword No puede estar vacio");
			return false;
		
		}				

	if(formulario.password.value != formulario.repassword.value)
	{
		alert("No coincicen las password");
		return false;
	}

//sexo

	if(!formulario.femenino.checked && !formulario.masculino.checked)
	{
		alert("Seleccione el Sexo");
		return false;
	}


return true;

}

function TieneFormatoUsuario (palabra)
 {

	var caracteres = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZÁÉÍÓÚabcdefghijklmnopqrstuvwxyzñáéíóú." 

	var contador = 0  
	for (var i=0; i < palabra.length; i++) 
	{  
		letra = palabra.substring(i, i + 1)  
		if (caracteres.indexOf(letra) != -1) 
		{  
		  contador++  
		} 
		else 
		{  
		  return false  
		}  
	} 


	return true 
}

function TieneMayuscula(palabra)
 {

	var caracteres = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ" 

	var contador = 0  
	for (var i=0; i < palabra.length; i++) 
	{  
		letra = palabra.substring(i, i + 1)

		if (caracteres.indexOf(letra) != -1) 
		{ 

		  contador++  
		  
		} 
		else 
		{  
		  return false  
		}  
	} 


	return true 
}




