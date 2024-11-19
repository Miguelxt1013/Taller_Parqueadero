#include <iostream>

using namespace std;

string Nombre;
struct nodo {
    int Codigo; 
    nodo* sig; 
    int op; 
    int Destino; 
};

nodo* cab = NULL; 
nodo* aux;
nodo* aux2;

void registrarEnvios() {
    aux = (struct nodo*)malloc(sizeof(struct nodo));
    cout << "Nombre del destinatario: ";
    cin >> Nombre;
    cout << "Codigo unico del envio: ";
    cin >> aux->Codigo;
    cout << "Prioridad del envio (1: Alta, 2: Media, 3: Baja): ";
    cin >> aux->op;
    while (aux->op < 1 || aux->op > 3) {
        cout << "Prioridad invalida. Ingrese nuevamente (1, 2, o 3): ";
        cin >> aux->op;
    }
    cout << "Destino del envio:\n1: Nacional\n2: Internacional\nIngrese el numero correspondiente: ";
    cin >> aux->Destino;
    while (aux->Destino < 1 || aux->Destino > 2) {
        cout << "Destino invalido. Ingrese nuevamente (1 o 2): ";
        cin >> aux->Destino;
    }
    aux->sig = NULL;

    if (cab == NULL) {
        cab = aux;
    } else {
        aux2 = cab;
        while (aux2->sig != NULL) {
            aux2 = aux2->sig;
        }
        aux2->sig = aux;
    }
}


int main() {
    int opcion;
    do {
        cout << "----------------MENU-----------"<<endl;
        cout << "1) Registrar envio"<<endl;
        cout << "2) Mostrar envios"<<endl;
        cout << "3) Ordenar envios"<<endl;
        cout << "4) Salir"<<endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarEnvios();
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente. "<<endl;
        }
    } while (opcion != 4);

    return 0;
}
