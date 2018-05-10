function EnviarForm ()
{
	var validar = true;
	
	var formulario = document.getElementById ("formulario");
	var usuario = document.getElementById ("usuario");
	
	if (!usuario.value)
	{
		alert ("Por favor, ingrese su usuario");
		usuario.focus();
		validar = false;
	}
		
	if (validar)
	{
		formulario.submit();
		alert ("Validación exitosa");
	}
	
}

window.onload = function ()
{
	var enviar;
	
	enviar = document.getElementById ("enviar");
	enviar.onclick = EnviarForm;
}