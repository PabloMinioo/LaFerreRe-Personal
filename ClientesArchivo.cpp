#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include "Clientes.h"
#include "ClientesArchivo.h"
#include "Archivo.h"

using namespace std;

/// DESARROLLO DE LOS METODOS DE LA CLASE 'ClientesArchivo'
// CONSTRUCTOR POR DEFECTO
ClientesArchivo::ClientesArchivo() {
    _fileName = "clientes.dat";
}
// CONSTRUCTOR POR PARAMETROS
ClientesArchivo::ClientesArchivo(string fileName) {
    _fileName = fileName;
}

/// METODOS
// CARGAMOS UN CLIENTE Y LO GUARDA EN EL ARCHIVO
void ClientesArchivo::guardarCliente() {
    Clientes cliente;
    cliente = cliente.crearCliente();
    if (cliente.getIdCliente() <= 0){
        cout << endl << "EL CLIENTE NO SE PUDO REGISTRAR. NUMERO DE ID DEL CLIENTE NO VALIDO" << endl;
        return;
    }
    if (guardarRegistro(cliente)) {
        cout << endl << "EL CLIENTE FUE REGISTRADO CON EXITO" << endl;
    } else {
        cout << endl << "EL CLIENTE NO SE PUDO REGISTRAR" << endl;
    }
}
// LISTA TODOS LOS CLIENTE QUE TENGAN 'ESTADO DISPONIBLE'
void ClientesArchivo::listarCliente() {
    int cantidad = getCantidadRegistros();
    for (int i = 0; i < cantidad; i++) {
        Clientes cliente = leerRegistro(i);
        if (cliente.getEstado()) {
            cout << "**************************" << endl;
            cliente.mostrarCliente(cliente);
            cout << "**************************" << endl;
        }
    }
}
// SE INDICA EL ID DEL CLIENTE Y LO MUESTRA POR PANTALLA
void ClientesArchivo::listarClienteID() {
    int index, idCliente;
    Clientes cliente;
    cout << "INGRESE EL ID DEL CLIENTE A BUSCAR: ";
    cin >> idCliente;
    index = buscarRegistro(idCliente);
    if (index >= 0) {
        cout << "**************************" << endl;
        cliente = leerRegistro(index);
        cliente.mostrarCliente(cliente);
        cout << "**************************" << endl;
    } else {
        cout << "EL PRODUCTO NO EXISTE" << endl;
    }
}
// SE INDICA EL ID DEL CLIENTE Y SE REALIZA UNA BAJA LOGICA
void ClientesArchivo::eliminarCliente() {
    int idCliente, indice;
    cout << "INGRESAR EL ID DEL CLIENTE QUE SE DESEA ELIMINAR: ";
    cin >> idCliente;
    indice = buscarRegistro(idCliente);
    if (indice != -1) {
        Clientes cliente = leerRegistro(indice);
        cliente.mostrarCliente(cliente);
        bool eliminarProducto;
        cout << endl << "DESEA ELIMINAR EL CLIENTE ELEGIDO? (1- SI || 0-NO): ";
        cin >> eliminarProducto;
        if (eliminarProducto) {
            if (eliminarRegistro(idCliente)) {
                cout << endl << "EL CLIENTE SE ELIMINO CORRECTAMENTE" << endl;
            } else {
                cout << endl << "NO SE PUDO ELIMINAR EL CLIENTE" << endl;
            }
        } else {
            cout << endl << "LA OPERACION FUE CANCELADA" << endl;
        }
    } else {
        cout << endl << "EL NUMERO ID INGRESADO NO EXISTE" << endl;
    }
}

/// METODOS RELACIONADOS A REGISTROS
// RECIBE UN OBJETO TIPO CLIENTE Y LO GUARDA EN EL ARCHIVO
bool ClientesArchivo::guardarRegistro(Clientes cliente) {
    int grabo;
    if (abrir("ab") == false) {
        return false;
    }
    grabo = fwrite(&cliente, sizeof (Clientes), 1, _pFile);
    cerrar();
    return grabo;
}
// RECIBE UNA POSICION Y UN OBJETO CLIENTE Y GUARDA LOS CAMBIOS REALIZADOS
bool ClientesArchivo::guardarRegistroModificado(int index, Clientes cliente) {
    int grabo;
    if (abrir("rb+") == false) {
        return false;
    }
    fseek(_pFile, index * sizeof(Clientes), SEEK_SET);
    grabo = fwrite(&cliente, sizeof (Clientes), 1, _pFile);
    cerrar();
    return grabo;
}
// RECIBE UNA POSICION Y LEE EL REGISTRO DE DICHA POSICION
Clientes ClientesArchivo::leerRegistro(int index) {
    Clientes cliente;
    if (abrir("rb") == false) {
        return cliente;
    }
    cout << "Posición antes de fseek: " << ftell(_pFile) << endl;
    fseek(_pFile, index * sizeof(Clientes), SEEK_SET);
    cout << "Posición antes de fseek: " << ftell(_pFile) << endl;
    fread(&cliente, sizeof(Clientes), 1, _pFile);
    cout << "Posición antes de fseek: " << ftell(_pFile) << endl;
    cerrar();
    return cliente;
}
// RECIBE EL ID DEL CLIENTE Y DEVUELVE SU POSICION
int ClientesArchivo::buscarRegistro(int idCliente) {
    int index = 0;
    Clientes cliente;
    if (abrir("rb+") == false) {
        return -1;
    }
    while (fread(&cliente, sizeof(Clientes), 1, _pFile)) {
        if (cliente.getIdCliente() == idCliente) {
            break;
        }
        index++;
    }
    cerrar();
    if(cliente.getIdCliente() == idCliente) {
        return index;
    } else {
        return -1;
    }
}
// DEVUELVE LA CANTIDAD DE REGISTROS DEL ARCHIVO
int ClientesArchivo::getCantidadRegistros() {
    if (abrir("rb") == false) {
        return 0;
    }
    fseek(_pFile, 0, SEEK_END);
    int tamanio = ftell(_pFile);
    cerrar();
    return tamanio / sizeof(Clientes);
}
// RECIBE EL ID DEL CLIENTE Y LE REALIZA UNA BAJA LOGICA
bool ClientesArchivo::eliminarRegistro(int idCliente) {
    int index;
    Clientes cliente;
    index = buscarRegistro(idCliente);
    cliente = leerRegistro(index);
    cliente.setEstado(0);
    return guardarRegistroModificado(index, cliente);
}
// RECIBE UNA POSICION Y UN OBJETO CLIENTE Y LO MODIFICA
bool ClientesArchivo::modificarRegistro(int index, Clientes cliente) {
    int modifico;
    if (abrir("rb+") == false) {
        return false;
    }
    fseek(_pFile, index * sizeof(Clientes), SEEK_SET);
    modifico = fwrite(&cliente, sizeof(Clientes), 1, _pFile);
    cerrar();
    return modifico;
}

// RECIBE EL ID DEL CLIENTE Y VERIFICA SI EXISTE
bool ClientesArchivo::isExist(int idCliente) {
    return buscarRegistro(idCliente) != -1;
}
