//Probar con esto despues..

/*
$(document).ready(function controlTecla(){
	console.log("ready");
});
*/

function controlTecla(letra){
	$("#cajita").keyup(function (){
		$.ajax({
			type: "GET",
			url: "../index.php",
			success: function()
				{
					$("#cajita").removeClass();
					if(letra.length>3)
						{
							$("#cajita").addClass("ok")
							$("#letraIngresada").html("Caracteres suficientes.");
						}
						
					else
						{
							$("#cajita").addClass("mal")
							$("#letraIngresada").html("Pocos caracteres.");
						}
						
				;}
		});
	})
}