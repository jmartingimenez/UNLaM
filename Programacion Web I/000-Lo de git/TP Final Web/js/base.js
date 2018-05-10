$(document).ready
	(
		function ()
			{
			$("#barra_pie_de_banner img").mouseenter
					(
						function ()
						{
							$(this).css('height','80px');
						}
					);
			$("#barra_pie_de_banner img").mouseleave
					(
						function ()
						{
							$(this).css('height','1.2em');
						}
					);
					
    //Para flecha que va al inicio
		$(window).scroll(function() {
			if ($(this).scrollTop() > 300) {
				$('#btnArriba').fadeIn();
				} else {
				$('#btnArriba').fadeOut();
				}
			});
    //Crea la animacion al dar clic sobre el boton
    $('#btnArriba').click(function() {
        $("html, body").animate({scrollTop: 0}, 600);
        return false;
    });	
	
			

			
			
			}		
	);