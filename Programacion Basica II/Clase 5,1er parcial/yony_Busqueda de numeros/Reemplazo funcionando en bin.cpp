#include<stdio.h>
#include<conio.h>

int main()

	{
		
								/*INGRESO*/
										
		FILE *arch;
		arch=fopen("numeron.bin","wb");
		int num,leido;
		printf("Ingrese numeros, con cero terminara la carga\n");
		scanf("%d",&num);
		while(num!=0)
			{
				fwrite(&num,sizeof(num),1,arch);
				scanf("%d",&num);
			}
		fclose(arch);	
		
								/*LECTURA*/	
								
		arch=fopen("numeron.bin","rb");
		rewind(arch);
		printf("\nLectura del archivo\n===============\n\n");
		fread(&leido,sizeof(leido),1,arch);
		while(!feof(arch))
			{
				printf("%d ",leido);
				fread(&leido,sizeof(leido),1,arch);
			}		
		fclose(arch);
		
								/*BUSQUEDA*/	
								
		printf("\nIngrese el numero a buscar: ");
		scanf("%d",&num);
		arch=fopen("numeron.bin","rb");
		rewind(arch);
		fread(&leido,sizeof(leido),1,arch);
		while(!feof(arch) and num!=leido)
			{
				fread(&leido,sizeof(leido),1,arch);
			}
		if(feof(arch))
			{
				printf("\n\n\t\tERROR!!: No se encontro el numero\n\n");
			}	
		else
			{
				printf("\n\n\t\tSe encontro el numero\n\n");
			}			
		fclose(arch);						
					
								/*REEMPLAZO*/
													
		int leido2,num2;//Solo para probar con otras variables..
		printf("\nIngrese el numero a reemplazar: ");
		scanf("%d",&num2);
		arch=fopen("numeron.bin","rb+");
		rewind(arch);
		fread(&leido2,sizeof(leido2),1,arch);
		while(!feof(arch) and num2!=leido2)
			{
				fread(&leido2,sizeof(leido2),1,arch);
			}
		if(feof(arch))
			{
				printf("\n\n\t\tERROR!!: No se encontro el numero\n\n");
			}	
		else
			{
				printf("\n\nIngrese el nuevo numero: ");
				scanf("%d",&num2);
				fseek(arch,(-1)*sizeof(leido2),SEEK_CUR);
				fwrite(&num2,sizeof(num2),1,arch);
			}			
		fclose(arch);	
		
								/*LECTURA*/	
								
		arch=fopen("numeron.bin","rb");
		rewind(arch);
		printf("\nLectura del archivo\n===============\n\n");
		fread(&leido2,sizeof(leido2),1,arch);
		while(!feof(arch))
			{
				printf("%d ",leido2);
				fread(&leido2,sizeof(leido2),1,arch);
			}		
		fclose(arch);											
		getch();
		return 0;
	}
