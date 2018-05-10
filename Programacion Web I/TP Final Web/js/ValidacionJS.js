function validacion_formulario()

	{
		if (document.getElementById("name").value.length==0)
			{
				alert("Tiene que escribir su nombre");
				document.getElementById("name").focus();
				return false;
			}
		if(document.getElementById("provincia").value=="Default")
			{
				alert("Tiene que seleccionar una provincia");
				document.getElementById("provincia").focus();
				return false;
			}
		if (document.getElementById("city").value.length==0)
			{
				alert("Tiene que escribir su ciudad");
				document.getElementById("city").focus();
				return false;
			}			
		var regexp=/^[0-9a-zA-Z._.-]+\@[0-9a-zA-Z._.-]+\.[0-9a-zA-Z]+$/
		if((regexp.test(document.getElementById("mail").value)==0)		
		||																 			
		(document.getElementById("mail").value.length==0))				
			{
				alert("Ingrese una direccion de mail valida");
				document.getElementById("mail").focus();
				return false;
			}
		if (document.getElementById("datepicker").value.length==0)
			{
				alert("Tiene que seleccionar su fecha de nacimiento");
				document.getElementById("datepicker").focus();
				return false;
			}	
		document.getElementByID("contacto").submit();	
	}
	