// Laboratorio3_SergioCardona_1222419


#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cstring>
#include <stdio.h>



using namespace std;
using std::cout;
using std::endl;


// variables globales
const int ejercicio_uno = 1;
const int ejercicio_dos = 2;
const int ejercicio_tres = 3;
const int salir = 4;
int num1, num2;
vector<string> palabras_csv;
string word = "";
string line = "";
string palabra = "";
int i = 0;


int MENU(int menu) {
    
    switch (menu)
    {
        case ejercicio_uno:
          ejerciciomultiplicacion();
         break;
        case ejercicio_dos:
           palabraspalindromas();
         break;
        case ejercicio_tres:
            ejercicionumerobase();
         break;
        case salir:
            cout << "Saliendo del programa";
            break;
        default:
            cout << "Error de eleccion";
    }
    return menu;
}

// RECURSIVIDAD

int multiplicacion_con_suma( int multiplicando, int multiplicador) {
    int resultado;
    if (multiplicador == 0) {
        resultado = 0;
   }
    else
    {
        if (multiplicador == 1) {
            resultado = multiplicando;
        }
       
        resultado = multiplicando + multiplicacion_con_suma(multiplicando, multiplicador - 1);
    }
    return resultado;
}

int conversionMaN(int numero, int base) {
    int respuesta, convertir;
    convertir = numero % base;
    cout << convertir;
    if (numero >=1)
    {
        return conversionMaN(numero / base, base);
    }
}

// leer el archivo csv para las palabras palindromas
void leerArchivo() {
    ifstream infile("PalabrasPalindromas.csv");
    while (getline(infile, line))
    {
        stringstream strstr(line);
        while (getline(strstr, word, ','))
        {
            palabras_csv.push_back(word);
        }

    }
    for (i = 0; i < palabras_csv.size(); i++)
    {
        palabra = palabras_csv.at(i);
        cout << palabra;
    }
}

void palabraspalindromas() {

    string palabraresultante;
    int p = 0;
    for (p = palabra.size() - 1; p >= 0; p--)
    {
        cout << palabra[p] << endl;
        palabraresultante += palabra[p];
    }

    if (palabra == palabraresultante) {
        cout << "Palabra " << palabra << " es palindroma";
    }
    else
    {
        cout << "Palabra " << palabra << " no es palindroma";
    }

}
//Menus
void ejerciciomultiplicacion() {

      int num1, num2, menu;
    cout << "Ingrese un valor: ";
    cin >> num1;
    cout << "otro valor: ";
    cin >> num2;

    cout << "El resultado de la multiplicacion es: " << multiplicacion_con_suma(num1, num2);

}

void ejercicionumerobase() {

     int numero, base, menu;
    cout << "Ingrese un numero: ";
    cin >> numero;
    cout << "Ingrese la base a convertir: ";
    cin >> base;

    cout << "El resultado de la conversion es: ";
    conversionMaN(numero, base);

}

int inicio() {
    int menu;

    cout << "-------------Laboratorio #3: RECURSIVIDAD-----------------\n";
    cout << "1.Ejercicio #1\n" << "2.Ejercicio #2\n" << "3.Ejercicio #3\n";
    cout << "Ingrese el numero de ejercicio: ";
    cin >> menu;
    return menu;
}

int main()
{
    int menu;
  
    do
    {
        menu = inicio();
        menu = MENU(menu);
    } while (menu > 0);
    return 0;
}


