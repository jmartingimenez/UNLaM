/*CLASE SECRETARIA: Esta clase es una extension de Empleado. De hecho, en su
constructor se llama al constructor de Empleado que usa los mismos atributos
(ACTUA IGUAL QUE 'Ingeniero'. Son clases distintas para hacer justamente la distinción).*/

//Atributos: n=nombreDado,s=salarioDado,e=edadDada
class Secretaria: public Empleado{
	public:
		Secretaria(std::string n,float s,int e):Empleado(n,s,e){};			
};
