#include <iostream>
#include<stdlib.h>
#include <time.h>

using namespace std;


// Declaracion de funciones
void generaMatriz(int[9][1], int);
void escogeMatriz(int[9][1], int);
void resuelveProblema(int[9][1], int[9][1], int[9][1], int[9][1], int);
void multiplicaMatrices(int[9][1], int[9][1], int mod);



int main(){


	srand(time(NULL));

	// Matrices de apoyo para la resolucion del problema
	int matInicial[9][1];
	int matFinal[9][1];
	int restaMatInicialFinal[9][1];
	int matResultado[9][1];

	// Matriz de la suma inicializada en 0
	for (int i = 0; i < 9; i++){
		matResultado[i][0] = 0;
	}

	cout << "Escribe el numero del modulo que se desea aplicar (2 o 3)" << endl;
	int mod;
	cin >> mod;

	while (mod != 2 && mod != 3){
		cout << "Opcion no valida, por favor entra 2 o 3" << endl;
		cin >> mod;
	}

	// Menu de opciones y sus acciones
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
			resuelveProblema(restaMatInicialFinal, matInicial, matFinal, matResultado, mod);
			break;

		case 2: cout << "\t\t\tCrear la matriz inicial\n\n";
			generaMatriz(matInicial, mod);
			cout << "\t\t\tCrear la matriz final\n\n";
			generaMatriz(matFinal, mod);
			resuelveProblema(restaMatInicialFinal, matInicial, matFinal, matResultado, mod);
			break;

		case 3: cout << "Adios" << endl;
			break;
		default: cout << "El valor ingresado no esta en el menu" << endl;
		}

	for (int i = 0; i < 9; i++){
		matResultado[i][0] = 0;
		restaMatInicialFinal[i][0]=0;
	
}

		cout << endl << "Selecciona una opcion: \n";
		cout << "1  Introducir Matriz Inicial y Final\n";
		cout << "2  Generar Matriz Inicial y Final\n";
		cout << "3  Salir\n\n";
		cin >> m;
	}


	system("pause");
	return 0;
}

//funcion que genera aleatoriamente una matriz segun el modulo seleccionado
void generaMatriz(int matInicial[9][1], int mod){
	for (int i = 0; i < 9; i++){
		matInicial[i][0] = rand() % mod;
		if (i != 0 && i % (3) == 0){
			cout << endl;
		}
		cout << matInicial[i][0] << " ";
	}
	cout << endl;
}

// Funcion que ayuda al usuario a generar la matriz inicial
void escogeMatriz(int matInicial[9][1], int mod){
	cout << "Siguiendo el esquema: " << endl << "1 2 3" << endl << "4 5 6" << endl << "7 8 9" << endl;
	cout << "Si su numero no va de acuerdo con el modulo que escogio, se le hara automaticamente el modulo";
	for (int i = 0; i < 9; i++){
		cout << endl << "Dame la posicion:  " << i + 1 << endl;
		cin >> matInicial[0][i];
		matInicial[i][0] = matInicial[i][0] % mod;
	}
	cout << endl << endl;
	for (int i = 0; i < 9; i++){
		if (i != 0 && i % (3) == 0){
			cout << endl;
		}
		cout << matInicial[i][0] << " ";
	}
	cout << endl;
}

// Funcion que resuleve el problema.
void resuelveProblema(int restaMatInicialFinal[9][1], int matInicial[9][1], int matFinal[9][1], int matResultado[9][1], int mod){
	for (int i = 0; i < 9; i++){
		// GEneracion de la matriz suma
		if ((matInicial[i][0] + matFinal[i][0]) < 0){
			restaMatInicialFinal[i][0] = ((matInicial[i][0] - matFinal[i][0]) + mod);
		}
		else{
			restaMatInicialFinal[i][0] = (matInicial[i][0] - matFinal[i][0]) % mod;
		}
		//cout << restaMatInicialFinal[i][0] << endl;
	}
	// Llamada a la funcion que genera la multiplicacion de la inversa de A y la matriz suma
	multiplicaMatrices(restaMatInicialFinal, matResultado, mod);


}

void multiplicaMatrices(int restaMatInicialFinal[9][1], int matResultados[9][1], int mod){
	// Declaracion de la matriz de 9x9, A inversa (A matriz de las diferentes transformaciones que puede sufrir la matriz)
	int Ainv[9][9];
	/*columna 1*/
	Ainv[0][0] = 1;	Ainv[1][0] = 1;	Ainv[2][0] = 1;	Ainv[3][0] = 1;	Ainv[4][0] = 1;	Ainv[5][0] = 0;	Ainv[6][0] = 1;	Ainv[7][0] = 0;
	Ainv[8][0] = 0;
	/*columna 2*/	
	Ainv[0][1] = 0;	Ainv[1][1] = 1;	Ainv[2][1] = 0;	Ainv[3][1] = 1;	Ainv[4][1] = 0;	Ainv[5][1] = 1;	Ainv[6][1] = 1;	Ainv[7][1] = 0;
	Ainv[8][1] = 1;
	/*columna 3*/
	Ainv[0][2] = 1;	Ainv[1][2] = 1;	Ainv[2][2] = 1;	Ainv[3][2] = 0;	Ainv[4][2] = 1;	Ainv[5][2] = 1;	Ainv[6][2] = 0;	Ainv[7][2] = 0;
	Ainv[8][2] = 1;
	/*columna 4*/
	Ainv[0][3] = 0;	Ainv[1][3] = 1;	Ainv[2][3] = 1;	Ainv[3][3] = 1;	Ainv[4][3] = 0;	Ainv[5][3] = 0;	Ainv[6][3] = 0;	Ainv[7][3] = 1;
	Ainv[8][3] = 1;
	/*columna 5*/
	Ainv[0][4] = 0;	Ainv[1][4] = 1;	Ainv[2][4] = 0;	Ainv[3][4] = 1;	Ainv[4][4] = 1;	Ainv[5][4] = 1;	Ainv[6][4] = 0;	Ainv[7][4] = 1;
	Ainv[8][4] = 0;
	/*columna 6*/
	Ainv[0][5] = 1;	Ainv[1][5] = 1;	Ainv[2][5] = 0;	Ainv[3][5] = 0;	Ainv[4][5] = 0;	Ainv[5][5] = 1;	Ainv[6][5] = 1;	Ainv[7][5] = 1;
	Ainv[8][5] = 0;
	/*columna 7*/
	Ainv[0][6] = 1;	Ainv[1][6] = 0;	Ainv[2][6] = 0;	Ainv[3][6] = 1;	Ainv[4][6] = 1;	Ainv[5][6] = 0;	Ainv[6][6] = 1;	Ainv[7][6] = 1;
	Ainv[8][6] = 1;
	/*columna 8*/
	Ainv[0][7] = 1;	Ainv[1][7] = 0;	Ainv[2][7] = 1;	Ainv[3][7] = 1;	Ainv[4][7] = 0;	Ainv[5][7] = 1;	Ainv[6][7] = 0;	Ainv[7][7] = 1;
	Ainv[8][7] = 0;
	/*columna 9*/
	Ainv[0][8] = 0;	Ainv[1][8] = 0;	Ainv[2][8] = 1;	Ainv[3][8] = 0;	Ainv[4][8] = 1;	Ainv[5][8] = 1;	Ainv[6][8] = 1;	Ainv[7][8] = 1;
	Ainv[8][8] = 1;

	// Guardar el resultado de la multimplicacion entre la inversa de A y la matriz suma.
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			//cout << "Acum = " << matResultados[i][0] << endl << "Ainv = " << Ainv[i][j] << endl << "SumaMats = " << restaMatInicialFinal[j][0];
			matResultados[i][0] = (matResultados[i][0] + (Ainv[i][j] * restaMatInicialFinal[j][0])) % mod;
		}
	}


	// entero de ayuda para la impresino del vector como matriz de 3x3
	int conta = 0;
	cout << "Matriz Resultados\n";
	for (int i = 0; i < 9; i++){
		if (conta == 3){
			cout << endl;
			conta = 0;
		}

		// Impresion de la matriz resultado
		cout << matResultados[i][0];
		conta++;
	}

	cout << endl << endl <<"Para resolver esa matriz basta con presionar las casillas señaladas el numero de veces que aparece (1 o 2)\n";


}
