$(document).ready(
function()
	{
		$(send).click(
		function()
		{
			//Viendo si los campos estan vacios
			if($("#user").val()=="")
				{
					alert("Ingrese el usuario");
					return false;
				}
			if($("#pass").val()=="")
				{
					alert("Ingrese el password");
					return false;
				}
			if($("#repass").val()=="")
				{
					alert("Reingrese el password");
					return false;
				}
			if($("#mail").val()=="")
				{
					alert("Ingrese el E-Mail");
					return false;
				}
			
			//Viendo si se eligio el sexo
			
			var sexo=0;			
			if($("#masculino").is(":checked"))
				{
					sexo++;
				}
			if($("#femenino").is(":checked"))
				{
					sexo++;
				}				
			if(sexo==0)
				{
					alert("Seleccione el sexo");
					return false;
				}
			
			//Comprobando si se eligio generacion

			if($("#generacion").val()==0)
				{
					alert("Seleccione la generacion");
					return false;
				}	
			//password iguales
				
			if($("#pass").val()!=$("#repass").val())
				{
					alert("Los password deben ser iguales");
					return false;
				}
				
			//password mayor a 5 letras
			
			if($("#pass").val().length<5)
				{
					alert("El password debe tener 5 caracteres minimo");
					return false;
				}	
				
			//mail validado
			var regxp=/^[0-9a-zA-Z]+\@[a-zA-Z]+\.[a-zA-Z]+$/
			if(regxp.test($("#mail").val())==0)
				{
					alert("Ingrese un mail valido");
					return false;
				}
			//primer caracter del pass debe ser una letra
			
			if(!isNaN($("#pass").val().charAt(0)))
				{
					alert("El password debe comenzar con una letra");
					return false;
				}
				
			//Comprobando que el pass lleva al menos una letra en mayuscula

			var cant=$("#pass").val().length;
			var mayusculas=0;
			var regmay=/^[A-Z]+$/
			for(var i=0;i<cant;i++)
				{
					if(regmay.test($("#pass").val().charAt(i))==1)
						{
							mayusculas++;
							break;
						}
				}
			if(mayusculas==0)
				{
					alert("El password debe llevar una letra en mayuscula por lo menos");
					return false;
				}				
			
		}
		);
		
	
		
	}
);