$(document).ready (function()
	{
		$("#formulario").submit(function(event)
			{
				if(!confirm("Estas seguro?"))
					event.preventDefault();
			}
		);
	}
);