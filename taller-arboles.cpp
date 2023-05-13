#include <iostream>
#include <string>

using namespace std;

// Estructura nodo árbol pacientes
struct Nodo_paciente {
    string nombre;
    int anno;
    double valor_cop;
    Nodo_paciente* izquierda;
    Nodo_paciente* derecha;
    
};


void registrarPaciente(Nodo_paciente *&arbol, int anno, float cop) {
   
    if (arbol == NULL) {
        arbol = (Nodo_paciente*) malloc(sizeof(Nodo_paciente));
        arbol->anno = anno;
        arbol->valor_cop = cop;
        arbol->izquierda = NULL;
        arbol->derecha = NULL;
    } else {
        if (anno < arbol->anno) {
            registrarPaciente(arbol->izquierda, anno, cop);
        } else {
            registrarPaciente(arbol->derecha, anno, cop);
        }
    }
}

void Totalcop(Nodo_paciente*arbol, float &total) {
   
    if (arbol != NULL) {
        Totalcop(arbol->izquierda, total);
        total += arbol->valor_cop;
        Totalcop(arbol->derecha, total);
    }
}

float Promediocop(Nodo_paciente *arbol) {

    float total = 0;
    int i = 0;
    Totalcop(arbol, total);
    while (arbol != NULL) {
        i++;
        arbol = arbol->izquierda;
    }
    return total / i;
}

void PromedioCopaño(Nodo_paciente*arbol) {
   
    if (arbol != NULL) {
        PromedioCopaño(arbol->izquierda);
        float promedioaño = Promediocop(arbol);
        cout << "Promedio copago de pacientes nacidos en el ano " << arbol->anno << ": " << promedioaño << endl;
        PromedioCopaño(arbol->derecha);
    }
}





int main() {

    Nodo_paciente *arbol = NULL;
    int option = 0;



    do {
        cout <<"Menu:" << endl;
        cout << "1. registrar paciente" << endl;
        cout << "2. calcular valor cancelado por paciente" << endl;
        cout << "3. calcular promedio copago de pacientes por ano de nacimiento" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> option;


        switch (option) {
            case 1: {
                int anno;
                float copago;
                string nombre;

                cout<< "Ingrese el nombre del paciente: ";
                cin>> nombre;
                cout << "Ingrese el ano de nacimiento del paciente: ";
                cin >> anno;
                cout << "Ingrese el valor cancelado de copago: ";
                cin >> copago;
                registrarPaciente(arbol, anno, copago);
                break;
            }
            case 2: {
                float total = 0;
                Totalcop(arbol, total);
                cout << "El valor total cancelado por pacientes es: " << total << endl;
                break;
            }
            case 3: {
                PromedioCopaño(arbol);
                break;
            }
            case 4: {
                cout << "hasta luego..." << endl;
                break;
            }
            default: {
                cout << "Opcion no valida." << endl;
                break;
            }
        }
    } while (option != 4);
    return 0;
}
