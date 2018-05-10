$(document).ready(function(){
	$("#boton").click(function() {
		var texto = $("#texto").val();
		fetchData(texto);
	})
});

function fetchData(data){
	 $.ajax({
		data: "string="+data,
		url: "/lunes3/validar.php",
		type: 'GET',
		success: function(respuesta) {
			var texto = $("#texto");
			if(respuesta === true){
				texto.css("border", "1px solid green");
			}
			else{
				texto.css("border", "1px solid red");
			}
		}
	 })
};