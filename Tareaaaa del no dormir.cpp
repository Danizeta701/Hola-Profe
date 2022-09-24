// Fecha_.cpp :
#include <iostream>
#include<string>
#include<sstream>

using namespace std;


class Fecha {//Name's class
private:
	int dia;
	int mes;
	int anio;
	string fechaInstring;
public:
	Fecha(int _dia, int _mes, int _anio)
		:mes(_mes), dia(_dia), anio(_anio) {};

	void leer();
	void enero();
	void biciesto();
	int mesesMix();

	operator const char* () {
		ostringstream formmatedFecha;
			formmatedFecha << mes << "/" << dia << "/" << anio;
		
		fechaInstring = formmatedFecha.str();
		return fechaInstring.c_str();
	}
	
			

};
//Constructor inicializado 
Fecha::Fecha(int _dia, int _mes, int _anio) {
	dia = _dia;
	mes = _mes;
	anio = _anio;
}
void Fecha::leer() {
	cout << "Digite la fecha " << endl;
	cout << "Digite el dia: ";
	cin >> dia;
	cout << "Digite el mes: ";
	cin >> mes;
	cout << "Digite el anio: ";
	cin >> anio;
	if ((dia >= 1 && dia <= mesesMix()) && (mes >= 1 && mes <= 12) && (anio >= 1)) {
		cout << "Fecha ingresada correctamente: " << endl;
	}
	else {
		cout << "Fecha ingresada incorrectamente " << dia << "/" << mes << "/" << anio << endl;
	}
}
void Fecha::enero() {
	if (dia >= 1 || dia <= 31) {
	}
	else {
		cout << "El numero del dia que dijitaste es invalido" << endl;
	}

}

void Fecha::biciesto() {

	if (anio % 4 == 0 && anio % 100 != 0 || anio % 400 == 0)
		cout << "\nEste anio es biciesto" << endl;

}
int Fecha::mesesMix() {
	int limit = 31;//Meses que tenga 31 días

	switch (mes) {
	case 2:
		if (anio % 4 == 0) limit = 29;//Es bisiesto
		else limit = 28;//No es bisiesto
		break;
		//Meses que tengan máximo 30 días
	case 4:
	case 6:
	case 9:
	case 11:
		limit = 30;
		break;
	}

	return limit;
}

int main() {
	int dia = 0, mes = 0, anio = 0;
	Fecha press(dia, mes, anio);
	//cout << press;//aaaa/mm/dd
	

	press.leer();
	press.enero();
	press.biciesto();
	press.mesesMix();
	return 0;
}