#include<stdio.h>
#include<conio.h>
#include<string.h>

char* string(char *str);
int main()
{
char* str=string(str);
printf("%s",str);

//printf("\n%s\n ",string(str));
getch();
return 0;
}
char* string(char *str) // the char should be char*
{
char str1[25]="How";
char str2[25] = " do I ";
char str3[25] = " return a string";
strcat(str1,str2); //append str2 to str and return str
strcat(str1,str3);
printf("%s",str1);
return str1;
}
