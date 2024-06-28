#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include "Venta.h"
#include "Clientes.h"
#include "ClientesArchivo.h"

using namespace std;

/// DESARROLLO DE LOS METODOS DE LA CLASE 'CLIENTES'
// CONSTRUCTOR POR DEFECTO
Clientes::Clientes() {
    _idCliente = 0;
    strcpy(_nombreCliente, "");
    strcpy(_apellidoCliente, "");
    strcpy(_direccionCliente, "");
    _telefonoCliente = 0;
    _estado = false;
}
// CONSTRUCTOR POR PARAMETROS
Clientes::Clientes(int idCliente, string nombreCliente, string apellidoCliente, string direccionCliente, int telefonoCliente, bool estado) {
    setIdCliente(idCliente);
    setNombreCliente(nombreCliente);
    setApellidoCliente(apellidoCliente);
    setDireccionCliente(direccionCliente);
    setTelefonoCliente(telefonoCliente);
    setEstado(estado);
}
// SET Y GET
void Clientes::setIdCliente(int idCliente) {
    _idCliente = idCliente;
}
int Clientes::getIdCliente() {
    return _idCliente;
}

void Clientes::setNombreCliente(string nombreCliente) {
    if (nombreCliente.size() <= 29) {
        strcpy(_nombreCliente, nombreCliente.c_str());
    } else {
        strcpy(_nombreCliente, "SIN DATOS");
    }
}
string Clientes::getNombreCliente() {
    return _nombreCliente;
}

void Clientes::setApellidoCliente(string apellidoCliente) {
    if (apellidoCliente.size() <= 29) {
        strcpy(_apellidoCliente, apellidoCliente.c_str());
    } else {
        strcpy(_apellidoCliente, "SIN DATOS");
    }
}
string Clientes::getApellidoCliente() {
    return _apellidoCliente;
}

void Clientes::setDireccionCliente(string direccionCliente) {
    if (direccionCliente.size() <= 49) {
        strcpy(_direccionCliente, direccionCliente.c_str());
    } else {
        strcpy(_direccionCliente, "SIN DATOS");
    }
}
string Clientes::getDireccionCliente() {
    return _direccionCliente;
}

void Clientes::setTelefonoCliente(int telefonoCliente) {
    _telefonoCliente = telefonoCliente;
}
int Clientes::getTelefonoCliente() {
    return _telefonoCliente;
}

void Clientes::setEstado(bool estado) {
    _estado = estado;
}
bool Clientes::getEstado() {
    return _estado;
}

// METODOS
Clientes Clientes::crearCliente(){
<<<<<<< HEAD
    // UTILIZAMOS EL OBJETO 'ClienteArchivo'
    ClientesArchivo clienteArchivo;
=======
>>>>>>> 8c44adb45899e486dcb3be4a5609453bcfde2feb
    // DECLARAMOS LAS VARIABLES QUE VAMOS A UTILIZAR
    int idCliente, telefonoCliente;
    string nombreCliente, apellidoCliente, direccionCliente;

<<<<<<< HEAD
    // NUMERO ID DEL CLIENTE AUTONUMERICO
    idCliente = clienteArchivo.getCantidadRegistros() + 1;
    cout << "NUMERO ID DEL CLIENTE: " << idCliente << endl;
=======
    // INGRESAMOS EL NUMERO ID DEL CLIENTE
    cout << "INGRESE EL ID DEL CLIENTE: ";
    cin >> idCliente;
>>>>>>> 8c44adb45899e486dcb3be4a5609453bcfde2feb

    // INGRESAMOS EL NOMBRE DEL CLIENTE
    cout << "INGRESE EL NOMBRE DEL CLIENTE: ";
    cin.ignore();
    getline(cin, nombreCliente);

    // INGRESAMOS EL APELLIDO DEL CLIENTE
    cout << "INGRESE EL APELLIDO DEL CLIENTE: ";
    getline(cin, apellidoCliente);

    // INGRESAMOS LA DIRECCION DEL CLIENTE
    cout << "INGRESE LA DIRECCION DEL CLIENTE: ";
    getline(cin, direccionCliente);

    // INGRESAMOS EL TELEFONO DEL CLIENTE
    cout << "INGRESE EL TELEFONO DEL CLIENTE: ";
    cin >> telefonoCliente;

    // DEVOLVEMOS EL OBJETO
    return Clientes(idCliente, nombreCliente, apellidoCliente, direccionCliente, telefonoCliente, true);
}
void Clientes::mostrarCliente(Clientes cliente){
    cout << "ID DEL CLIENTE: " << cliente.getIdCliente() << endl;
    cout << "NOMBRE DEL CLIENTE: " << cliente.getNombreCliente() << endl;
    cout << "APELLIDO DEL CLIENTE: " << cliente.getApellidoCliente() << endl;
    cout << "DIRECCION DEL CLIENTE: " << cliente.getDireccionCliente() << endl;
    cout << "TELEFONO DEL CLIENTE: " << cliente.getTelefonoCliente() << endl;
    cout << "ESTADO CLIENTE: " << (cliente.getEstado() ? "ACTIVO" : "NO ACTIVO") << endl;
}

