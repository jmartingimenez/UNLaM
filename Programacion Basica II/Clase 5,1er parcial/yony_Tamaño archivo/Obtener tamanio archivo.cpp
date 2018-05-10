#include<stdio.h>
#include<conio.h>

main()

{
	int num;
	FILE *arch;
	arch=fopen("texto.txt","w");
	printf("Ingrese un numero: ");
	scanf("%d",&num);
	fprintf(arch,"%d",num);
	long int tam=ftell(arch);
	printf("%ld",tam);
	fclose(arch);
	getch();
	return 0;
}
