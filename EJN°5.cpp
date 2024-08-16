#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class CRaices {
	private:
    	int c1;
    	int c2;
    	int c3;
	public:
    	CRaices(int, int, int);
    	void obtenerRaices();
    	void obtenerRaiz();
    	double getDiscriminante();
    	bool tieneRaices();
    	bool tieneRaiz();
    	void calcular();
};

CRaices::CRaices(int a, int b, int c) {
    c1 = a;
    c2 = b;
    c3 = c;
}

void CRaices::obtenerRaices(){
	double discriminante = getDiscriminante();
	double raiz1 = (-c2 + discriminante) / (2 * c1);
	double raiz2 = (-c2 - discriminante) / (2 * c1);
	cout << "Las raices son: "<< raiz1 << " y " << raiz2 << endl;
}
	
void CRaices::obtenerRaiz(){
	double raizunica = -c2 / (2 * c1);
	cout << "La raiz es "<< raizunica << endl;
}
	
double CRaices::getDiscriminante(){
	double discriminante = c2 * c2 - 4 * c1 * c3;
    double raiz = sqrt(abs(discriminante));
    return raiz;
}

bool CRaices::tieneRaices(){
	bool flag = false;
	double discriminante = getDiscriminante();
	if (discriminante > 0){
		flag = true;
	}
	return flag;
}

bool CRaices::tieneRaiz(){
	bool flag = false;
	double discriminante = getDiscriminante();
	if (discriminante == 0){
		flag = true;
	}
	return flag;
}

void CRaices::calcular(){
    if (tieneRaices()) {
        obtenerRaices();
    } else if (tieneRaiz()) {
        obtenerRaiz();
    } else {
    	cout << "No tiene solución" <<endl;
	}
}

int main() {
	double a, b, c;
	cout << "Ingrese primer coeficiente: ";
	cin >> a;
	cout << "Ingrese segundo coeficiente: ";
	cin >> b;
	cout << "Ingrese tercer coeficiente: ";
	cin >> c;
    CRaices calculo1(a, b, c);
    calculo1.calcular();
    return 0;
}
