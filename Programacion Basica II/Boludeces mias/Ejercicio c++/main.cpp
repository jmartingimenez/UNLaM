/*NOTA: En el header.h hay 4 redefiniciones (typedef) para std::vector<>, por esto es que 
en el codigo se ven cosas como...
'vecI* listaIngenieros' en lugar de 'std::vector<Ingeniero>* listaIngenieros'.
No use ningún 'using namespace std/using std::cout', etc.*/

#include "header/listadoIncludes.h"

int main(){
	menuPrincipal();	//Main limpio. Todo lo maneja la funcion 'menuPrincipal()'	
	return 0;
}
