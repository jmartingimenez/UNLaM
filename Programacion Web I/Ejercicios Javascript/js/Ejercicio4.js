function check_form()

	{
		check_user(usuario);
		check_pass(pass1,pass2);
	}

function check_user(usuario)

	{
		var get_user;
		var count;
		get_user=document.getElementById("usuario");
		count=get_user.value.length;
		if(count>1)
			{
				return 1;
			}
		else
			{
				return 0;
			}	
	}
	
function check_pass(pass1,pass2)

	{
		var get_pass1;
		var get_pass2;
		var testpass1;
		var testpass2;
		get_pass1=document.getElementById("pass1");
		get_pass2=document.getElementById("pass2");
		testpass1=get_pass1.value;
		testpass2=get_pass2.value;
		if(testpass1==testpass2)
			{
				check_mayuscula(get_pass1);
			}
		else
			{
				return 0;
			}
	}	
	
function check_mayuscula(get_pass1)	

	{
		var contador;
		var aux=get_pass1.split("");
		var i;
		for(i;i<get_pass1.length;i++)
			{
				if(aux[i]==aux[i].toUpperCase)
					{
						contador++;
					}
			}
		return contador;	
	}