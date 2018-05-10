/*FUNCION QUE LISTA LA OPCIONES EN EL MENU: Simplemente para separar un poco el codigo*/

void opcionesParaSeleccionar(){
	std::cout<<	"Menu principal"					<<std::endl<<
				"1 - Registrar ingeniero"			<<std::endl<<
				"2 - Registrar secretaria"			<<std::endl<<
				"3 - Registrar gerente"				<<std::endl<<
				"4 - Registrar director"			<<std::endl<<
				"5 - Ver listado de empleados"		<<std::endl<<
				"6 - Salir"							<<std::endl<<
				"Seleccion: "						;	
}

/*FUNCION DEL MENU PRINCIPAL: Esta es la parte mas importante del programa, 
se crean vectores por cada tipo de empleado. Estos vectores se usaran para ir
guardando las instancias de cada clase para luego iterar y poder mostrar todos
los datos sin que nada se pierda. 'opcion' es una variable para controlar el
menu a traves del do-while, la funcion 'opcionesParaSeleccionar()' existe
simplemente para dividir un poco mas el codigo. Segun la opcion seleccionada,
se pasa la referencia del vector correspondiente a la funcion correspondiente.
Estas funciones crearan e instanciaran objetos que seran almacenados en el
vector*/

void menuPrincipal(){
	char opcion;
	vecI listaIngenieros;
	vecS listaSecretarias;
	vecG listaGerentes;
	vecD listaDirectores;
	do{
		opcionesParaSeleccionar();
		std::cin>>opcion;
		switch(opcion){
			case '1':
				registrarIngeniero(&listaIngenieros);
				break;
			case '2':
				registrarSecretaria(&listaSecretarias);				
				break;
			case '3':
				registrarGerente(&listaGerentes);
				break;
			case '4':
				registrarDirector(&listaDirectores);
				break;
			case '5':
				verListadoIngenieros(&listaIngenieros);
				verListadoSecretarias(&listaSecretarias);
				verListadoGerentes(&listaGerentes);
				verListadoDirectores(&listaDirectores);
				break;
			case '6':
				generarTXT(&listaIngenieros,&listaSecretarias,&listaGerentes,&listaDirectores);
				break;	
			default:
				std::cout<<"ERROR!!: Opcion incorrecta"<<std::endl;
		}			
	}while(opcion != '6');
}

/*FUNCIONES PARA REGISTRAR EMPLEADOS: Estas funciones traen la referencia al vector
correspondiente para que la instancia del objeto creado no se pierda. Primero se
piden los datos a traves de variable auxiliares. Luego, se crea el objeto y se le
dan los parametros para su constructor. Finalmente, se guarda el objeto recien
creado en el vector (push_back). El objeto desaparecera al finalizar la funcion,
pero el vector declarado en menuPrincipal() seguira existiendo hasta el fin del
programa.*/

void registrarIngeniero(vecI* listaIngenieros){
	std::string miNombre;
	float miSalario;
	int miEdad;
	std::cout<<"Ingrese nombre: ";
	std::cin>>miNombre;
	std::cout<<"Ingrese salario: ";
	std::cin>>miSalario;
	std::cout<<"Ingrese edad: ";
	std::cin>>miEdad;		
	Ingeniero ingeniero(miNombre,miSalario,miEdad);
	listaIngenieros->push_back(ingeniero);
}

void registrarSecretaria(vecS* listaSecretarias){
	std::string miNombre;
	float miSalario;
	int miEdad;
	std::cout<<"Ingrese nombre: ";
	std::cin>>miNombre;
	std::cout<<"Ingrese salario: ";
	std::cin>>miSalario;
	std::cout<<"Ingrese edad: ";
	std::cin>>miEdad;
	Secretaria secretaria(miNombre,miSalario,miEdad);
	listaSecretarias->push_back(secretaria);
}

void registrarGerente(vecG* listaGerentes){
	std::string miNombre;
	float miSalario;
	int miEdad;
	std::string miDepartamento;
	std::cout<<"Ingrese nombre: ";
	std::cin>>miNombre;
	std::cout<<"Ingrese salario: ";
	std::cin>>miSalario;
	std::cout<<"Ingrese edad: ";
	std::cin>>miEdad;
	std::cout<<"Ingrese el nombre del departamento: ";
	std::cin>>miDepartamento;
	Departamento objDepartamento(miDepartamento);
	Gerente gerente(miNombre,miSalario,miEdad,objDepartamento);
	listaGerentes->push_back(gerente);
}

void registrarDirector(vecD* listaDirectores){
	std::string miNombre;
	float miSalario;
	int miEdad,miCochera;
	std::string miDepartamento;
	std::cout<<"Ingrese nombre: ";
	std::cin>>miNombre;
	std::cout<<"Ingrese salario: ";
	std::cin>>miSalario;
	std::cout<<"Ingrese edad: ";
	std::cin>>miEdad;
	std::cout<<"Ingrese el nombre del departamento: ";
	std::cin>>miDepartamento;
	std::cout<<"Ingrese el numero de cochera: ";
	std::cin>>miCochera;
	Departamento objDepartamento(miDepartamento);
	Director director(miNombre,miSalario,miEdad,objDepartamento,miCochera);
	listaDirectores->push_back(director);	
}

/*FUNCIONES PARA VER LISTADOS: Se trae como referencia al vector correspondiente, se le
crea un iterador y se itera sobre el mismo para ir mostrando los datos de todos los
objetos que forman parte del vector*/

void verListadoIngenieros(vecI* listaIngenieros){
	vecI::iterator it;
	for (it=listaIngenieros->begin();it!=listaIngenieros->end();++it){
    	std::cout			<<	"INGENIERO - "				
							<<	it->getNombre()				<<". "	
							<<	"$"<<it->getSalario()		<<". "	
							<<	it->getEdad()				<<" anios."<<std::endl;	
	}
}

void verListadoSecretarias(vecS* listaSecretarias){
	vecS::iterator it;
	for (it=listaSecretarias->begin();it!=listaSecretarias->end();++it){
    	std::cout			<<	"SECRETARIA - "
							<<	it->getNombre()				<<". "	
							<<	"$"<<it->getSalario()		<<". "	
							<<	it->getEdad()				<<" anios."<<std::endl;	
	}
}

void verListadoGerentes(vecG* listaGerentes){
	vecG::iterator it;
	for (it=listaGerentes->begin();it!=listaGerentes->end();++it){
    	std::cout			<<	"GERENTE - "
							<<	it->getNombre()							<<". "	
							<<	"$"<<it->getSalario()					<<". "	
							<<	it->getEdad()							<<" anios. Departamento: "
							<<	it->getDepartamento()->getNombreDep()	<<std::endl;
	}
}

void verListadoDirectores(vecD* listaDirectores){
	vecD::iterator it;
	for (it=listaDirectores->begin();it!=listaDirectores->end();++it){
    	std::cout			<<	"DIRECTOR - "
							<<	it->getNombre()							<<". "	
							<<	"$"<<it->getSalario()					<<". "	
							<<	it->getEdad()							<<" anios. Departamento: "
							<<	it->getDepartamento()->getNombreDep()	<<". Cochera: "
							<<  it->getCochera()						<<std::endl;
	}
}

/*FUNCION limpiezaTest: Deberia liberar memoria. Itera y llama a la funcion 'limpieza()'
NOTA: Tengo dudas con el funcionamiento de esta funcion. En teoria va eliminando los punteros.
La razon de porque solo en Gerente y Director se debe a que son las dos clases que tienen
departamento. Se crea un new Departamento y es por eso que quiero saber borrar el vector de
punteros al final. No se si es correcto..*/

void limpiezaTest(vecG* listaGerentes, vecD* listaDirectores){
	vecG::iterator itG;
	vecD::iterator itD;
	for (itG=listaGerentes->begin();itG!=listaGerentes->end();++itG) delete (*itG).limpieza();	
	for (itD=listaDirectores->begin();itD!=listaDirectores->end();++itD) delete (*itD).limpieza();
}

/*FUNCION generarTXT: Esta función se encarga de generar un archivo TXT con los empleados
registrados que se guardara dentro de la carpeta 'output' con el nombre 'Lista de empleados.txt'.
Lo primero que esta función realiza es comprobar si hay ingresos en alguno de los 4 vectores.
De no existir, el programa finaliza. En caso contrario se crea y se escribe el archivo.
Si el archivo se crea, avisa cuantos registros existen*/

void generarTXT(vecI* listaIngenieros,vecS* listaSecretarias,vecG* listaGerentes,vecD* listaDirectores){
	if((listaIngenieros->size() + listaSecretarias->size() +
		listaGerentes->size()	+ listaDirectores->size())==0)	return;
										
	int cantidadRegistros=0;
	vecI::iterator itI;
	vecS::iterator itS;
	vecG::iterator itG;
	vecD::iterator itD;
				
	std::ofstream Archivo;								
	Archivo.open("output/Lista de empleados.txt");	
							
	for (itI=listaIngenieros->begin();itI!=listaIngenieros->end();++itI){
		cantidadRegistros++;
		Archivo	<<"INGENIERO: "			
				<<itI->getNombre()		<<", $"
				<<itI->getSalario()		<<", "
				<<itI->getEdad()		<<" anios."<<std::endl;
	}
	Archivo<<std::endl;				
	for (itS=listaSecretarias->begin();itS!=listaSecretarias->end();++itS){
		cantidadRegistros++;
		Archivo	<<"SECRETARIA: "			
				<<itS->getNombre()		<<", $"
				<<itS->getSalario()		<<", "
				<<itS->getEdad()		<<" anios."<<std::endl;
	}
	Archivo<<std::endl;		
	for (itG=listaGerentes->begin();itG!=listaGerentes->end();++itG){
		cantidadRegistros++;
		Archivo	<<"GERENTE: "			
				<<itG->getNombre()							<<", $"
				<<itG->getSalario()							<<", "
				<<itG->getEdad()							<<" anios, Departamento: "
				<<itG->getDepartamento()->getNombreDep()	<<"."<<std::endl;
	}
	Archivo<<std::endl;	
	for (itD=listaDirectores->begin();itD!=listaDirectores->end();++itD){
		cantidadRegistros++;
		Archivo	<<"DIRECTOR: "			
				<<itD->getNombre()							<<", $"
				<<itD->getSalario()							<<", "
				<<itD->getEdad()							<<" anios, Departamento: "
				<<itD->getDepartamento()->getNombreDep()	<<", Cochera: "
				<<itD->getCochera()							<<"."<<std::endl;
	}												
	Archivo.close();
	std::cout<<	"\n\tArchivo con "<<cantidadRegistros<<" registro/s guardado en "
				"'output/Lista de empleados.txt'"<<std::endl;
}
