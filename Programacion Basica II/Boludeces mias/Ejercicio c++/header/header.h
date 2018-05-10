//Prototipos de clases

class Departamento;
class Empleado;
class Ingeniero;
class Secretaria;
class Gerente;
class Director;

//Prototipos de funciones - Menu

void opcionesParaSeleccionar();
void menuPrincipal();

//Typedefs para achicar un poco la sintaxis				
typedef std::vector<Ingeniero> 	vecI;
typedef std::vector<Secretaria> vecS;
typedef std::vector<Gerente> 	vecG;
typedef std::vector<Director> 	vecD;

//Prototipos de funciones - Registro de empleados

void registrarIngeniero(vecI* listaIngenieros);
void registrarSecretaria(vecS* listaSecretarias);
void registrarGerente(vecG* listaGerentes);
void registrarDirector(vecD* listaDirectores);

//Prototipos de funciones - Visualizacion de empleados

void verListadoIngenieros(vecI* listaIngenieros);
void verListadoSecretarias(vecS* listaSecretarias);
void verListadoGerentes(vecG* listaGerentes);
void verListadoDirectores(vecD* listaDirectores);

//Prototipos de funciones - Limpieza de memoria (o intento, no estoy seguro de que funcione bien)

void limpiezaTest(vecG* listaGerentes, vecD* listaDirectores); 

//Prototipos de funciones - Salida y creacion de archivo
void generarTXT(vecI* listaIngenieros,vecS* listaSecretarias,vecG* listaGerentes,vecD* listaDirectores);								
