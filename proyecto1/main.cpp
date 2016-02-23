#include <iostream>#
#include<stdlib.h>
#include <time.h>

using namespace std;

void generaMatriz(int [1][9], int);
void escogeMatriz(int matInicial[1][9], int mod);

int main(){


	srand(time(NULL));

	int matInicial[1][9];
	int matFinal[1][9];

	cout << "Escribe el numero del modulo que se desea aplicar (2,3 o 4)" << endl;
	int mod;
	cin >> mod;

	while (mod != 2 && mod != 3){
		cout << "Opcion no valida, por favor entra 2 o 3" << endl;
		cin >> mod;
	}

	int m;
	cout << "\t\t\tElija una opcion\n\n";
	cout << "1  Introducir Matriz Inicial y Final\n";
	cout << "2  Generar Matriz Inicial y Final\n";
	cout << "3  Salir\n\n";
	cin >> m;

	while (m != 3){
		switch (m)
		{
		case 1: cout << "\t\t\tCrear la matriz inicial\n\n";
				escogeMatriz(matInicial, mod);
				cout << "\t\t\tCrear la matriz final\n\n";
				escogeMatriz(matFinal, mod);
				break;

		case 2: cout << "\t\t\tCrear la matriz inicial\n\n";
				generaMatriz(matInicial, mod);
				cout << "\t\t\tCrear la matriz final\n\n";
				generaMatriz(matFinal, mod);
				break;

		case 3: cout << "Adios" << endl;
				break;
		default: cout << "El valor ingresado no esta en el menu" << endl;
		}
		cout <<endl << "Introduce otro valor: ";
		cin >> m;
	}


	system("pause");
	return 0;
}

//funcion que genera aleatoriamente una matriz segun el modulo seleccionado
void generaMatriz(int matInicial[1][9], int mod){
	for (int i = 0; i < 9; i++){
		matInicial[0][i] = rand() % mod;
		if (i != 0 && i % (3) == 0){
			cout << endl;
		}
		cout << matInicial[0][i]<<  " ";
	}
	cout << endl;
}


void escogeMatriz(int matInicial[1][9], int mod){
	cout << "Siguiendo el esquema: " << endl << "1 2 3" << endl << "4 5 6" << endl << "7 8 9" << endl;
	cout << "Si su numero no va de acuerdo con el modulo que escogio, se le hara automaticamente el modulo";
	for (int i = 0; i < 9; i++){
		cout  << endl << "Dame la posicion:  " << i << endl;
		cin >> matInicial[0][i];
		matInicial[0][i] = matInicial[0][i] % mod;
	}
	cout << endl << endl;
	for (int i = 0; i < 9; i++){
		if (i != 0 && i % (3) == 0){
			cout << endl;
		}
		cout << matInicial[0][i] << " ";
	}
	cout << endl;
}
