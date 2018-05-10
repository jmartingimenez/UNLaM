/*CLASE GERENTE: Esta clase es una extension de Empleado, pero ademas de tener los
tres atributos que se le envian al constructor de Empleado, tiene un puntero de
tipo Departamento. Este puntero accede a los métodos de la instancia de tipo
Departamento iniciada dentro de esta clase. Lo hice de esta manera para probar
que me saliera el tema de Composicion. El cuarto argumento que recibe el
constructor, es un objeto de tipo Departamento que sera usado para asignarse
al puntero '*departamento' correspondiente a la instancia de la clase Gerente.
Al inicializarse con 'new Departamento(d)', se esta llamando al constructor de
la clase Departamento para asignar lo que se trajo como argumento.
Tambien existe un metodo limpieza() que arme de prueba, debería eliminar la
asignación hecha con 'new' para liberar memoria. Este método es llamado en una
función que itera sobre el vector de objetos creado en la función 'menuPrincipal()'.*/

//Atributos: n=nombreDado,s=salarioDado,e=edadDada,d=departamentoDado
class Gerente: public Empleado{
	public:
		Gerente(std::string n,float s,int e,Departamento d):Empleado(n,s,e){
			departamento=new Departamento(d);
		}
			
		Departamento* getDepartamento(){
			return departamento;
		}
			
		Departamento* setDepartamento(Departamento d){
			departamento->setNombre(d.getNombreDep());
		}
		
		Departamento* limpieza(){
			delete departamento;
		}	
	private:
		Departamento* departamento;
};
