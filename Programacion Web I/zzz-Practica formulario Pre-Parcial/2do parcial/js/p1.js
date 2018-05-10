function validacion()
	{
		//nombre ingresado?
		if(document.getElementById("name").value=="")
			{
				alert("Ingrese su nombre.");
				return false;
			}
		//pass ingresado	
		if(document.getElementById("pass").value.length==0)	
			{
				alert("Ingrese su password.");
				return false;
			}	
		//pass reingresado	
		if(document.getElementById("repass").value.length==0)	
			{
				alert("Reingrese su password.");
				return false;
			}
		//sexo seleccionado
		var sexo=0;
		if(document.getElementById("masculino").checked)		
			{
				sexo++;
			}
		else if(document.getElementById("femenino").checked)		
			{
				sexo++;
			}
		if(sexo==0)
			{
				alert("Seleccione su sexo");
				return false;
			}
		//generacion seleccionada
		if(document.getElementById("generacion").value=="0")
			{
				alert("Seleccione una generacion");
				return false;
			}
		//passwords iguales
		if(document.getElementById("pass").value!=document.getElementById("repass").value)
			{
				alert("Los password deben coincidir");
				return false;
			}
		//mail ingresado?
		if(document.getElementById("mail").value=="")
			{
				alert("Ingrese su mail.");
				return false;
			}
		//mail validado
		var regexp=/^[0-9a-zA-Z]+\@[a-zA-Z]+\.[a-zA-Z]+$/
		if(regexp.test(document.getElementById("mail").value)==0)
			{
				alert("Ingrese un mail valido");
				return false;
			}	
		//comprobando que los password tengan mas de 5 caracteres
		if(document.getElementById("pass").value.length<5)
			{
				alert("Los password deben tener 5 caracteres minimo");
				return false;
			}
		if(document.getElementById("repass").value.length<5)
			{
				alert("Los password deben tener 5 caracteres minimo");
				return false;
			}
		//comprobando que el primer caracter de los pass no sea un numero
		var primercaracter=document.getElementById("pass").value.charAt(0);
		if(!isNaN(primercaracter))
			{
				alert("La primer letra no del password no puede ser un numero");
				return false;
			}
		//comprobando que el password lleva al menos una letra en mayuscula
		var cantidad=document.getElementById("pass").value.length;
		var regmay=/^[A-Z]+$/
		var mayuscula=0;
		for(var i=0;i<cantidad;i++)
			{
				if(regmay.test(document.getElementById("pass").value.charAt(i))==1)
					{
						mayuscula++;
						break;
					}	
			}
		if(mayuscula==0)
			{
				alert("El password debe llevar al menos una letra en mayuscula");
				return false;
			}

	}

	function mostrar_nombre()
	
		{
			var vernombre=document.getElementById("abajo");
			vernombre.innerHTML+="<br/>Gimenez Jonatan";
		}
	