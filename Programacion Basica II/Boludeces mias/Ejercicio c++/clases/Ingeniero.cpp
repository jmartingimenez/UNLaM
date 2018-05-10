/*CLASE INGENIERO: Esta clase es una extension de Empleado. De hecho, en su
constructor se llama al constructor de Empleado que usa los mismos atributos
(ACTUA IGUAL QUE 'Secretaria'. Son clases distintas para hacer justamente la distinción).*/

//Atributos: n=nombreDado,s=salarioDado,e=edadDada
class Ingeniero: public Empleado{
	public:
		Ingeniero(std::string n,float s,int e):Empleado(n,s,e){};	
};
