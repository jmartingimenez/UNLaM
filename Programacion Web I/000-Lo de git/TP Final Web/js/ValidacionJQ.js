$(document).ready
	(
		function validar_formulario()
			{
				$("#send").click
					(
						function validar_campos()
						{
							$(".error").remove();
							if($("#name").val()=="")				
								{
									$("#name").focus().after("<span class='error'>Ingrese su nombre</span>");
									return false;
								}							
							if($("#provincia").val()=="Default")				
								{
									$("#provincia").focus().after("<span class='error'>Ingrese su provincia</span>");
									return false;
								}	
							if($("#city").val()=="")				
								{
									$("#city").focus().after("<span class='error'>Ingrese su ciudad</span>");
									return false;
								}							
							if($("#mail").val()=="")					
								{
									$("#mail").focus().after("<span class='error'>Ingrese su mail</span>");
									return false;
								}								
							var regexp=/^[0-9a-zA-Z._.-]+\@[0-9a-zA-Z._.-]+\.[0-9a-zA-Z]+$/
							if(regexp.test($("#mail").val())==0)		
								{
									$("#mail").focus().after("<span class='error'>Ingrese un mail real</span>");
									return false;
								}	
							if($("#datepicker").val()=="")				
								{				
									$("#datepicker").focus().after("<span class='error'>Ingrese su fecha de nacimiento</span>");														
									return false;
								}
							return true;	
						}
					);
			}
	);