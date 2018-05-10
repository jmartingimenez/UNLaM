#include<stdio.h>
#include<conio.h>

int main()

	{
		
	/*=================================================================================================
												INGRESO
	=================================================================================================*/
										
		FILE *arch;//Se declara un puntero de tipo FILE llamado 'arch'
		arch=fopen("numeron.bin","wb");	//Se utiliza el puntero para abrir el archivo
									  	//Se abre en modo escritura-binaria
									   	//La extension '.bin' no influye en el modo de edicion
		
		int num,leido;				   	//'num' va guardar los numeros ingresados manualmente
										//'leido' va guardar los numeros leidos desde el archivo
		printf("Ingrese numeros, con cero terminara la carga\n");
		scanf("%d",&num);				//Pedido de numeros...
		while(num!=0)					//0 termina la carga
			{
				fwrite(&num,sizeof(num),1,arch);//leer abajo...
				scanf("%d",&num);
			}
		fclose(arch);					//Se cierra el archivo
		
/*
	EXPLICACION DEL: fwrite(&num,sizeof(num),1,arch);

-Nosotros vimos 2 formas de escribir/leer en archivos
		(fprintf/fscanf) 	=	Lee y escribe caracteres	 
		(fwrite/fread)		=	Lee y escribe bytes
		Por una complicacion que surge a la hora de reemplazar datos, al menos yo siempre me manejo con
		(fwrite/fread)
		
-¿Cual es la complicacion?
		Supongamos que escribimos un archivo de texto utilizando fprintf y el .txt originado al abrirlo
		se ve asi...
		
		--------------------------
		|25						 |		
		|307					 |	
		--------------------------	 
			
		A la hora de usar fprintf habremos puesto un "%d\n" para que haga el salto de linea.
		Supongamos que decidimos reemplazar el 25 por el 49. El archivo ahora se ve asi..	
				
		--------------------------
		|49						 |	
		|307					 |	
		--------------------------
				
		No hay problema a la vista, ahora... que tal si queremos reemplazar el 49 por el 100
				
		--------------------------
		|100307					 |	
		|						 |
		--------------------------
		
		Lo que se dice reemplazar, mas que nada seria sobreescribir (imaginate escribiendo en medio 
		de dos palabras con la tecla 'insert' activada)
		Lo que se ve ahi es que el 100 al tener un caracter mas sobreescribio el salto de linea.
		Por lo que podras imaginar que pasa si en vez de 100 queres poner 100000 (va quedar solo ese numero)
		
		Ahora volvamos al escenario original..
			
		--------------------------
		|25						 |	
		|307					 |	
		--------------------------
			
		Reemplacemos el 25 por el 7, el archivo se vera asi..
		
		--------------------------
		|75						 |	
		|307					 |	
		--------------------------	
			
		¿Se entiende lo que paso?, solo se sobreescribio un caracter, el del 2.
		
		Por lo que lei se puede hacer un reemplazo bien, jugando un poco con la cantidad de caracteres
		que entran por cada linea (80) y un vector auxiliar, pero es bardo y ademas no lo vimos. Asi
		que no voy a joder con eso..
			
		ESTO LO PUSE PARA ACLARAR EL POR QUE USO FWRITE/FREAD. AHORA VIENE LA EXPLICACION...
		
-fwrite(&num,sizeof(num),1,arch);

		fwrite 				=		(file write)
		&num				=		Variable que guarda el dato a escribirse en el archivo
		sizeof(num)			=		Esto es lo que hace que funcione bien. Como dije arriba 'fwrite/fread'
									Escriben y leen bytes. Con esto estas aclarando la cantidad de bytes
									que van a ser escritos y no los caracteres. El tamaño que le estamos
									indicando es el de la variable 'num', ¿Cual es su tamaño?, solo mira
									que tipo de dato es.. se trata de un 'int' asi que deberia ser 2 bytes.
									Osea yo en vez de poner 'sizeof(num)' podria haber puesto 'sizeof(int)'
									y se obtendria el mismo resultado.
									En el caso de una estructura con variables de diferentes tipos si ponemos
									sizeof(nombre_del_struct) estariamos escribiendo la suma de todos los
									bytes de cada variable (campo) de la misma. Osea, un registro
		1					=		Cantidad de desplazamientos, si pondria 2 supongo que avanzaria 4 bytes
							=		(SIEMPRE LO USE EN 1, ASI Q NO LE DES MUCHA BOLA A ESTE)
		arch				=		Puntero al archivo donde se va a escribir los datos
					
-Incoveniente:	 	Como no estamos escribiendo caracteres esto genera que el archivo de texto quede con
					'simbolos raros'. Pero es la forma mas sencilla de trabajar con esto
					
					Para el ejemplo de abajo vamos a suponer que el numero se escribe bien y que 'num'
					tiene almacenado el numero 10.
							
		--------------------------
		|10I					 |		
		--------------------------		
			
					¿Que quiere decir esa 'I'?
						
					Simplemente la puse para indicar donde queda posicionado el cursor despues de escribir
					ESTO ES IMPORTANTE A LA HORA DE LEER O REEMPLAZAR ARCHIVOS!!			  																				

*/		
		
		
	/*=================================================================================================
												LECTURA
	=================================================================================================*/
								
		arch=fopen("numeron.bin","rb");		//Se abre el archivo en modo lectura-binaria
		rewind(arch);						//El cursor vuelve al principio del archivo (mas explicado abajo)
		printf("\nLectura del archivo\n===============\n\n");
		fread(&leido,sizeof(leido),1,arch);	//se lee un registro (mas explicado abajo)
		while(!feof(arch))					//Mientras el cursor no se posicione al final.. (mas explicado abajo)
			{
				printf("%d ",leido);		//Se muestra el valor leido
				fread(&leido,sizeof(leido),1,arch);//Se vuelve a leer
			}		
		fclose(arch);//Se cierra el archivo
		
		
/*
		EXPLICACIONES
			
			
	rewind(arch)			=			¿Te acordas del ultimo ejemplo que mostraba donde quedaba el cursor?
										¿Que crees que se leeria si el fread comenzara desde el final?
										Obviamente nada.. necesitamos volver al principio para que pueda
										leer todos los bytes escritos.
fread(&leido,sizeof(leido),1,arch);			

	fread					=			(file read)
	&leido					=			Variable en la que se almacenaran los datos leidos desde el archivo
	sizeof(leido)			=			Bueno, esto es igual que antes, estamos delimitando cuantos bytes
										se van a leer. EL 'registro' al ser simplemente una variable indica
										que se leeran solo 2 bytes por ser del tipo entera. 
	1						=			IGUAL COMO PUSE ARRIBA
	arch					=			IGUAL COMO PUSE ARRIBA						
															
while(!feof(arch))			=			feof (file end of file)

	Este while indica que lo que esta dentro se ejecute siempre y cuando no se haya llegado al final del
	archivo. Si nosotros no hubiesemos usando el 'rewind' desde ya obviamente aca no entraria. La idea de
	tener un fread antes del while es por que se supone que 1 registro al menos ya debe haber..
	Nosotros leemos un registro, lo imprimimos (printf) y luego repetimos el proceso hasta feof

NOTA: OBVIAMENTE AL ESTAR LEYENDO, ESTAMOS HACIENDO UN RECORRIDO POR EL ARCHIVO, POR ENDE, EL CURSOR SE
DESPLAZA 'sizeof(tamaño)' POR CADA REGISTRO LEIDO...

		--------------------------
		|75I					 |	
		|307					 |	
		--------------------------	
			
		Este seria el escenario obtenido al usar el primer 'fread' (antes de entrar al while)
		Al volver a leer y dejar el cursor delante del 307 se comprobara que estamos en el final y el bucle
		no se repetira.	Como el cursor queda en el final, en operaciones posteriores que necesiten de la
		lectura (busqueda o reemplazo) necesitamos reposicionar el cursor en el comienzo nuevamente.
														
*/		
		
	/*=================================================================================================
												BUSQUEDA
	=================================================================================================*/	
								
		printf("\nIngrese el numero a buscar: ");			//Se pide el numero a ser buscado
		scanf("%d",&num);
		arch=fopen("numeron.bin","rb");						//Se abre el archivo en modo lectura-binaria
		rewind(arch);										//Se vuelve a posicionar el cursor al principio
		fread(&leido,sizeof(leido),1,arch);					//Se lee el primer registro
		while(!feof(arch) and num!=leido)					//Mientras no sea el final y el numero ingresado
															//no coincida con el numero leido desde el archivo
			{
				fread(&leido,sizeof(leido),1,arch);			//Que se siga leyendo...
			}
		if(feof(arch))										//Si efectivamente se leyo hasta feof
			{
				printf("\n\n\t\tERROR!!: No se encontro el numero\n\n");//Significa que no se encontro el num
													//Si prestas atencion al while de arriba, tiene 2 condiciones
													//Pudo haber llegado al final, pero si encontro coincidencia
													//este mensaje no se va mostrar	
			}	
		else
			{
				printf("\n\n\t\tSe encontro el numero\n\n");//Efectivamente se encontro el numero
			}			
		fclose(arch);										//Cerramos el archivo	
				
				
/*
while(!feof(arch) and num!=leido)

	Acordemonos que 'num' guarda el numero ingresado por nosotros y 'leido' guarda el numero leido desde
	el archivo. Mientras no exista coincidencia y no estemos al final se seguira leyendo.
	Si se llego al final y no existio coincidencia se da el mensaje de error, si la coincidencia si
	existio, se rompe una de las condiciones, por lo que se sale del while este el cursor o no al final
	y se da el mensaje de exito. La posicion del cursor quedara al final del ultimo registro leido.
*/					
	/*=================================================================================================
												REEMPLAZO
	=================================================================================================*/
													
		int leido2,num2;								//Solo para probar con otras variables..
														//Queria mostrar que simplemente son variables
														//auxiliares y que no necesitamos mantener guardados
														//los datos ingresados/leidos todo el tiempo
		printf("\nIngrese el numero a reemplazar: ");	//Se pide el numero a buscar
		scanf("%d",&num2);
		arch=fopen("numeron.bin","rb+");				//Se abre el archivo en modo lectura-escritura-binaria
		rewind(arch);									//Se vuelve a situar el cursor al principio
		fread(&leido2,sizeof(leido2),1,arch);			//Se lee el primero registro
		while(!feof(arch) and num2!=leido2)				//Misma condicion que antes (estamos buscando)
			{
				fread(&leido2,sizeof(leido2),1,arch);	//Que siga leyendo
			}
		if(feof(arch))
			{
				printf("\n\n\t\tERROR!!: No se encontro el numero\n\n");//Mensaje de error
			}	
		else
			{
				printf("\n\nIngrese el nuevo numero: ");//Pedimos un nuevo numero
														//Estamos guardandolo nuevamente en 'num2', como ya
														//encontramos la coincidencia no nos importa el numero
														//que buscamos, ahora solo necesitamos ingresar el
														//nuevo numero..	
				scanf("%d",&num2);
				fseek(arch,(-1)*sizeof(leido2),SEEK_CUR);//Posicionamos el cursor al comienzo del registro
														 //(explicado mas abajo)	
				fwrite(&num2,sizeof(num2),1,arch);		 //Escribimos un nuevo registro
			}			
		fclose(arch);									 //Cerramos el archivo
		
/*
fseek(arch,(-1)*sizeof(leido2),SEEK_CUR);

	fseek						=			(file seek)
	arch						=			Puntero al archivo
	(-1)*sizeof(leido2)			=			Estamos indicandole al cursor la cantidad de bytes que debe
											desplazarse.
					
					MIREMOS EL EJEMPLO DE ABAJO...	
						
		--------------------------
		|75I37					 |			
		--------------------------	
					
VAMOS A SUPONER QUE TENEMOS 2 NUMEROS EN EL ARCHIVO, 75 Y 37. RECORDEMOS QUE COMO
NOS MANEJAMOS CON 'fwrite/fread' ACA NO HAY FORMATO, NI SALTO DE LINEA NI NADA DE ESO
EN EL ARCHIVO. EL CURSOR TERMINO DE LEER EL PRIMER REGISTRO (75) Y OBVIAMENTE QUEDA AL
FINAL DEL MISMO. SI ESCRIBIR UN NUMERO NUEVO EN DONDE SE ENCUENTRA EL CURSOR (SUPONGAMOS
EL 400) TENDREMOS ESTE ESCENARIO..

		--------------------------
		|75I400					 |		
		--------------------------			

PERO OBVIAMENTE, NOSOTROS QUEREMOS REEMPLAZAR EL NUMERO LEIDO Y NO EL QUE LE SIGUE, ENTONCES ES
DONDE ENTRA EN JUEGO EL DESPLAZAMIENTO Y ESTA ECUACION..

		(-1)*sizeof(leido2)
			
VUELVO A REMARCAR QUE NOSOTROS NOS MANEJAMOS CON BYTES, POR ENDE SI CADA REGISTRO OCUPA 2 BYTES
(ES UNA VARIABLE ENTERA) NECESITAMOS MOVERNOS 2 BYTES HACIA ATRAS. ENTONCES, LO QUE ESA CUENTA
HACE ES DECIRLE AL PROGRAMA: MOVETE (-1)*EL TAMAÑO DE LA VARIABLE 'leido2' (2 BYTES). COMO EL
RESULTADO ES NEGATIVO (-2) SE MOVERA 2 BYTES HACIA ATRAS POR LO QUE EL CURSOR QUEDARA ASI...			

		--------------------------
		|I7537					 |	
		--------------------------		
						
DESPUES CON EL FWRITE SE VUELVE A INDICAR QUE SE ESCRIBIRAN 2 BYTES, POR LO QUE EL 37 QUEDARA INTACTO
ASI PONGAMOS UN 1 O UN 5000.						
													
	SEEK_CUR					=			Indicamos posicionamiento del cursor
*/		
		
	/*=================================================================================================
												LECTURA
	=================================================================================================*/
								
		arch=fopen("numeron.bin","rb");					//Igual que arriba, solo para mostrar los cambios
		rewind(arch);
		printf("\nLectura del archivo\n===============\n\n");
		fread(&leido2,sizeof(leido2),1,arch);
		actual->anterior=ultimo;						
		ultimo=actual;			
		while(!feof(arch))
			{
				printf("%d ",leido2);
				fread(&leido2,sizeof(leido2),1,arch);
			}		
		fclose(arch);											
		getch();
		return 0;
	}
