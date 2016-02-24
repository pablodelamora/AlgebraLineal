/*
 * =====================================================================================
 *
 *       Filename:  segundo.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  23/02/16 16:33:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Daniel Monzalvo (A01021514), danielmonr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


#include <iostream>
#include <math.h>
#include <stdlib.h>

#define N 9

using namespace std;

int modulo(int x, int m);
int inversoMultiplicativo(int x, int m);
void restarVectores(int* x, int* y, int m);
void gaussJordan(int A[][N], int* b, int mod);
void intercambiarRenglones(int* x, int* y, int n);
void escalarRenglon(int* x, int alfa, int mod, int n);
void sumarRenglon(int* x, int* y, int alfa, int mod, int n);

int main()
{
    // Matriz de transformaciones originales
    int A[N][N] = {
        {1, 1, 0, 1, 0, 0, 0, 0, 0},
        {1, 1, 1, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 1, 0, 1},
        {0, 0, 1, 0, 1, 1, 0, 0, 1},
        {0, 0, 0, 1, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 1, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 1, 0, 1, 1}
    };

    // Matriz de transformaciones definidas por nosotros
    int A2[N][N] = {
        {0, 1, 0, 1, 1, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 1, 1, 1, 0, 0},
        {1, 0, 0, 0, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 1, 0, 1},
        {0, 0, 1, 1, 0, 0, 0, 0, 1},
        {0, 0, 1, 1, 1, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 1, 1, 0, 1, 0}
    };

    int inicial[N]; //Configuración inicial
    int fin[N]; // Objetivo
    int mod, transformaciones;

    cout << "Módulo: ";
    cin >> mod; // Operaciones en módulo 2 o 3
    cout << "Transformaciones (0 = originales | 1 = nuevas): ";
    cin >> transformaciones; // Matriz a utilizar

    // Obtener los elementos del vector inicial y el final
    cout << "Configuración inicial:" << endl;
    for (int i = 0; i < N; ++i)
        cin >> inicial[i];

    cout << "\nConfiguración final:" << endl;
    for (int i = 0; i < N; ++i)
        cin >> fin[i];

    // Obtener los movimientos que faltan
    restarVectores(fin, inicial, mod);

    // Ejecutar Gauss-Jordan, el resultado estará en el vector fin
    if (transformaciones == 1)
        gaussJordan(A2, fin, mod);
    else
        gaussJordan(A, fin, mod);

	for (int h = 0; h < N;++h){

	}

    // Imprimir el resultado
    cout << "\nOprimir" << endl;
    for (int i = 0; i < N; ++i) {
        if (fin[i] == 1)
            cout << "Botón " << i+1 << ": " << fin[i] << " vez\n";
        else
            cout << "Botón " << i+1 << ": " << fin[i] << " veces\n";
    }

    return 0;
}

// Regresa x mod m
int modulo (int x, int m) {
    // Si es positivo se puede usar la función de C++
    if (x >= 0)
        return x % m;
    // Si es negativo se suma m hasta que sea un número positivo
    else {
        int k = floor((x+0.0) / m);
        return x - (k * m);
    }
}

// Regresa el inverso multiplicativo de x mod m
int inversoMultiplicativo(int x, int m) {
    // Recorrer todos los números posibles
    for (int i = 1; i < m; ++i)
        if ((x * i) % m == 1)
            return i; // Si xy = 1 mod m, y es el inverso
    return -1; // Significa que no tiene inverso
}

// Regresa (x - y) mod m
void restarVectores(int* x, int* y, int m) {
    for (int i = 0; i < N; ++i)
        x[i] = modulo(x[i] - y[i], m);
}

// Intercambiar el renglón i y el renglon j de la A
void intercambiarRenglones(int* x, int* y, int n) {
    int temp;
    // Swap de cada elemento del renglón
    for (int i = 0; i < n; ++i) {
        temp = x[i];
        x[i] = y[i];
        y[i] = temp;
    }
}

// Multiplicar todos los elementos del renglon por un escalar
void escalarRenglon(int* x, int alfa, int mod, int n) {
    for (int i = 0; i < n; ++i)
        x[i] = modulo(x[i] * alfa, mod);
}

// Sumar al renglón x el renglon y multiplicado por un escalar
void sumarRenglon(int* x, int* y, int alfa, int mod, int n) {
    for (int i = 0; i < n; ++i)
        x[i] = modulo(x[i] + (alfa * y[i]), mod);
}

// Algoritmo Gauss-Jordan con aritmética modular. A es la matriz y b es el vector de soluciones.
void gaussJordan(int A[][N], int* b, int mod) {
    int inverso, alfa;

    // i es el renglón pivote
    for (int i = 0; i < N; ++i) {
        // Si el elemento pivote no es invertible
        if (inversoMultiplicativo(A[i][i], mod) == -1) {
            int j = i + 1;
            // Recorrer los siguientes renglones hasta encontrar un elemento invertible
            while (j < N && inversoMultiplicativo(A[j][i], mod) == -1)
                ++j;

            // Si se encontró el elemento, intercambiar los renglones en A y b.
            if (j != N) {
                intercambiarRenglones(A[i], A[j], N);
                intercambiarRenglones(b+i, b+j, 1);
            }

            // Si no hay ningún elemento invertibles, la matriz no es invertible
            else {
                cout << "La matriz A no es invertible" << endl;
                exit(-1);
            }
        }

        // Obtener el inverso multiplicativo del elemento pivote
        inverso = inversoMultiplicativo(A[i][i], mod);

        // Multiplicar el renglón por el inverso (equivalente a dividir) para que el elemento pivote sea 1
        escalarRenglon(A[i], inverso, mod, N);
        escalarRenglon(b+i, inverso, mod, 1);

        // Recorrer todos los renglones
        for (int j = 0; j < N; ++j) {
            // Si no es el renglón pivote
            if (j != i) {
                // Restar al elemento de la columna i para hacerlo igual a 0.
                alfa = -1 * A[j][i];

                // Hacer la suma de renglones en A y b
                sumarRenglon(A[j], A[i], alfa, mod, N);
                sumarRenglon(b+j, b+i, alfa, mod, 1);
            }
        }
    }
}
