#include <string>
#include <iostream>
#include "Aplicacion.h"

using namespace std;

#include <cstring>

/// MENU PRINCIPAL
void Aplicacion::menu() {
    int opcion;
    do {
        system("cls");
        cout << "--------- FERRETERIA LA FERRE RE -------" << endl;
        cout << "-------------------------------" << endl;
        cout << "1- MENU VENTAS" << endl;
        cout << "2- MENU INVENTARIO" << endl;
        cout << "-------------------------------" << endl;
        cout << "0- SALIR " << endl;
        cout << "-------------------------------" << endl;
        cout << "INGRESE LA OPCION: ";
        cin >> opcion;

        switch(opcion) {
        case 1:
            system("cls");
            ventasArchivo.menu();
            break;
        case 2:
            system("cls");
            inventarioArchivo.menu();
            break;
        case 3:
            system("cls");
            detalleVentas.listar();
            break;
        case 0:
            system("cls");
            cout << "GRACIAS POR USAR LA APLICACION" << endl;
            break;
        default:
            system("cls");
            cout<< "OPCION INVALIDA, INGRESE NUEVAMENTE"<<endl;
            break;
        }
        system("pause");
    } while(opcion != 0);
}
