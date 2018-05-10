function check_length(id_user,id_pass)								//Tengo q pasar como argumento las id aca y en el html

	{
		var user_input=document.getElementById("id_user");			//Con esto obtenemos la cadena (lo que se ingreso)
		var pass_input=document.getElementById("id_pass");			//Igual que arriba
		var user_length=user_input.value.length;					//El tamaño del valor de la cadena
		var pass_length=pass_input.value.length;					//Igual que arriba
		if(user_length>=5 && pass_length>=5)
			{
				alert("Datos correctos!!");

			}
		else
			{
				alert("Los datos deben tener 5 caracteres minimos.");				
			}	
	}