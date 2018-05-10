/*CLASE EMPLEADO: Es la clase mas importante, ya que ingenieros, secrearias, gerentes y
directores son extensiones de esta clase (herencia). Hay 3 atributos simples, que son
el nombre, el salario y la edad.*/

class Empleado{
	public:		
		Empleado(std::string nombreDado,float salarioDado,int edadDada){
			nombre=nombreDado;
			salario=salarioDado;
			edad=edadDada;
		}
		
		const float getSalario(){
			return salario;
		}
		
		const std::string getNombre(){
			return nombre;
		}
		
		const int getEdad(){
			return edad;
		}	
		
		void setSalario(float salarioDado){
			salario=salarioDado;
		}
		
		void setNombre(std::string nombreDado){
			nombre=nombreDado;
		}	
		
		void setEdad(int edadDada){
			edad=edadDada;
		}
	private:
		std::string nombre;
		float salario;
		int edad;
		
};
