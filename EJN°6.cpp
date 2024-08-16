#include <iostream>
#include <string>

using namespace std;

class CEmpleado {
	private:
    	string nombre;
    	int edad;
    	double salario;

	public:
		const int PLUS = 30000;
    	CEmpleado(string nom, int ed, double sal) : nombre(nom), edad(ed), salario(sal) {}

    	string getNombre(){ 
			return nombre;
		}
    	int getEdad(){
			return edad;
		}
    	double getSalario(){
			return salario;
		}

    	void setNombre(string nombre) {
			this->nombre = nombre;
		}
    	void setEdad(int edad){ 
			this->edad = edad; 
		}
    	void setSalario(double salario){
			this->salario = salario;
		}

    	string toString() {
        	return "Nombre: " + nombre + "\nEdad: " + to_string(edad) + "\nSalario: " + to_string(salario);
    	}

    	void plus() {}
	};

class CComercial : public CEmpleado {
	private:
    	double comision;

	public:
    	CComercial(string nom, int ed, double sal, double _comision) : CEmpleado(nom, ed, sal), comision(_comision) {}

    	double getComision(){
			return comision;
		}
    	void setComision(double comision){
			this->comision = comision;
		}

    	void plus() {
        	if (getEdad() > 30 && comision > 200) {
            	setSalario(getSalario() + PLUS);
        	}
    	}

    	string toString() {
        	return CEmpleado::toString() + "\nComision: " + to_string(comision);
    	}
	};

class CRepartidor : public CEmpleado {
	private:
    	string zona;

	public:
    	CRepartidor(string nom, int ed, double sal, string _zona): CEmpleado(nom, ed, sal), zona(_zona) {}
		string getZona(){
			return zona;
		}
    	void setZona(string zona){
			this->zona = zona;
		}

    	void plus() {
        	if (getEdad() < 25 && zona == "zona 3") {
            	setSalario(getSalario() + PLUS);
        	}
    	}

    	string toString() {
        	return CEmpleado::toString() + "\nZona: " + zona;
    	}
};

int main() {
    CComercial comercial1("Carlos", 31, 5000, 300);
    CRepartidor repartidor1("Juan", 22, 2500, "zona 3");

    cout << "Antes de aplicar el plus:" << endl;
    cout << comercial1.toString() << endl;
    cout << repartidor1.toString() << endl;

	cout << "--------------------" << endl;

    comercial1.plus();
    repartidor1.plus();

    cout << "Despues de aplicar el plus:" << endl;
    cout << comercial1.toString() << endl;
    cout << repartidor1.toString() << endl;

    return 0;
}
