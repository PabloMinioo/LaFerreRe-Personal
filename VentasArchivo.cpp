#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include "VentasArchivo.h"
#include "DetallesVentasArchivo.h"
#include "Clientes.h"
#include "Archivo.h"

using namespace std;

/// DESARROLLO DE LOS METODOS DE 'VentasArchivo'
// CONSTRUCTOR POR DEFECTO
VentasArchivo::VentasArchivo() {
    _fileName = "historialVentas.dat";
}
// CONSTRUCTOR POR PARAMETROS
VentasArchivo::VentasArchivo(string fileName) {
    _fileName = fileName;
}

/// METODOS
// CARGA UNA VENTA Y LO GUARDA EN EL ARCHIVO
void VentasArchivo::guardarVenta() {
    Venta venta;
    venta = venta.cargarVenta();

    // VALIDACION TIPO DE VENTA
    if (venta.getTipoVenta() < 1 || venta.getTipoVenta() > 2){
        cout << endl << "LA VENTA NO SE PUDO REALIZAR. TIPO DE VENTA NO VALIDO" << endl;
        return;
    }
    // VALIDACION FORMA DE PAGO
    if (venta.getFormaPago() < 1 || venta.getFormaPago() > 3){
        cout << endl << "LA VENTA NO SE PUDO REALIZAR. FORMA DE PAGO NO VALIDO" << endl;
        return;
    }
    // VALIDACION ID DEL CLIENTE EXISTENTE
    if (clienteArchivo.isExist(venta.getIdCliente()) == false){
        cout << endl << "LA VENTA NO SE PUDO REALIZAR. NUMERO ID DEL CLIENTE NO VALIDO" << endl;
        return;
    }
    if (guardarRegistro(venta)) {
        cout << endl << "LA VENTA FUE REALIZADA CON EXITO" << endl;
    } else {
        cout << endl << "LA VENTA NO SE PUDO REALIZAR" << endl;
    }
}
// LISTA TODAS LAS VENTAS
void VentasArchivo::listarVentas() {
    int cantidad = getCantidadRegistros();
    for (int i = 0; i < cantidad; i++) {
        Venta venta = leerRegistro(i);
        if (venta.getEstado()) {
            cout << "**************************" << endl;
            venta.mostrarVenta(venta);
            cout << "**************************" << endl;
        }
    }
}
// SE INDICA EL NUMERO ID DE LA VENTA Y LO MUESTRA POR PANTALLA
void VentasArchivo::listarVentasID(){
    int index, idVenta;
    Venta venta;
    cout << "INGRESE EL ID DE LA VENTA A BUSCAR: ";
    cin >> idVenta;
    index = buscarRegistro(idVenta);
    if (index >= 0) {
        cout << "**************************" << endl;
        venta = leerRegistro(index);
        venta.mostrarVenta(venta);
        cout << "**************************" << endl;
    } else {
        cout << "EL NUMERO ID DE VENTA NO EXISTE" << endl;
    }
}
// SE INDICA EL NUMERO ID DE LA VENTA Y LE REALIZA UNA BAJA LOGICA
void VentasArchivo::eliminarVenta(){
    int indice, idVenta;
    cout << "INGRESAR EL NUMERO ID DE LA VENTA QUE SE DESEA ELIMINAR: ";
    cin >> idVenta;
    indice = buscarRegistro(idVenta);
    if (indice != -1) {
        Venta venta = leerRegistro(indice);
        venta.mostrarVenta(venta);
        bool eliminarProducto;
        cout << endl << "DESEA ELIMINAR LA VENTA ELEGIDA? (1- SI || 0-NO): ";
        cin >> eliminarProducto;
        if (eliminarProducto) {
            if (eliminarRegistro(idVenta)){
                cout << endl << "LA VENTA SE ELIMINO CORRECTAMENTE" << endl;
            } else {
                cout << endl << "NO SE PUDO ELIMINAR LA VENTA" << endl;
            }
        } else {
            cout << endl << "LA OPERACION FUE CANCELADA" << endl;
        }
    } else {
        cout << endl << "EL NUMERO ID INGRESADO NO EXISTE" << endl;
    }
}
// SE INDICA EL NUMERO ID DE LA VENTA Y MODIFICA LA FECHA DE VENTA
void VentasArchivo::modificarFechaVenta(){
    Venta venta;
    Fecha fecha;
    int idVenta, index, dia, mes, anio;
    cout << "INGRESE EL NUMERO ID DE LA VENTA QUE DESEA MODIFICAR: ";
    cin >> idVenta;
    index = buscarRegistro(idVenta);
    if (index >= 0){
        venta = leerRegistro(index);
        cout << "------------------------------------------" << endl;
        cout << "FECHA DE VENTA ANTIGUA: ";
        venta.getFechaVenta().mostrarFecha();
        cout << "------------------------------------------" << endl;
        cout << "*INGRESE LA NUEVA FECHA DE VENTA*" << endl;
        cout << "DIA: ";
        cin >> dia;
        cout << "MES: ";
        cin >> mes;
        cout << "ANIO: ";
        cin >> anio;
        Fecha nuevaFechaVenta(dia, mes, anio);
        venta.setFechaVenta(nuevaFechaVenta);
        if (nuevaFechaVenta.fechaValida(venta.getFechaVenta())){
            cout << "------------------------------------------" << endl;
            cout << "FECHA MODIFICADA CON EXITO" << endl;
            modificarRegistro(index, venta);
            venta.mostrarVenta(venta);
            cout << endl;
        } else {
            cout << "NO SE MODIFICO LA FECHA. FECHA DE VENTA NO VALIDA" << endl;
        }
    } else {
        cout << "EL NUMERO ID DE VENTA INGRESADO NO EXISTE" << endl;
    }
}

/// METODOS RELACIONADOS A REGISTROS
// RECIBE UN OBJETO TIPO VENTA Y LO GUARDA EN EL ARCHIVO
bool VentasArchivo::guardarRegistro(Venta venta) {
    int grabo;
    if (abrir("ab") == false) {
        return false;
    }
    grabo = fwrite(&venta, sizeof(Venta), 1, _pFile);
    cerrar();
    return grabo;
}
// RECIBE UNA POSICION Y UN OBJETO VENTA Y GUARDA EN EL ARCHIVO LOS CAMBIOS REALIZADOS
bool VentasArchivo::guardarRegistroModificado(int index, Venta venta) {
    int grabo;
    if (abrir("rb+") == false) {
        return false;
    }
    fseek(_pFile, index * sizeof(Venta), SEEK_SET);
    grabo = fwrite(&venta, sizeof(Venta), 1, _pFile);
    cerrar();
    return grabo;
}
// RECIBE UNA POSICION Y DEVUELVE EL REGISTRO DE DICHA POSICION
Venta VentasArchivo::leerRegistro(int index) {
    Venta venta;
    if (abrir("rb") == false) {
        return venta;
    }
    fseek(_pFile, index * sizeof(Venta), SEEK_SET);
    fread(&venta, sizeof(Venta), 1, _pFile);
    cerrar();
    return venta;
}
// RECIBE UN NUMERO ID DE VENTA Y DEVUELVE SU POSICION
int VentasArchivo::buscarRegistro(int idVenta) {
    int index = 0;
    Venta venta;
    if (abrir("rb+") == false) {
        return -1;
    }
    while (fread(&venta, sizeof(Venta), 1, _pFile)) {
        if (venta.getIdVenta() == idVenta) {
            break;
        }
        index++;
    }
    cerrar();
    if(venta.getIdVenta() == idVenta) {
        return index;
    } else {
        return -1;
    }
}
// DEVUELVE LA CANTIDAD DE REGISTROS DEL ARCHIVO
int VentasArchivo::getCantidadRegistros(){
    if (abrir("rb") == false){
        return 0;
    }
    fseek(_pFile, 0, SEEK_END);
    int tamanio = ftell(_pFile);
    cerrar();
    return tamanio / sizeof(Venta);
}
// RECICE UN NUMERO ID DE VENTA Y LE REALIZA UNA BAJA LOGICA
bool VentasArchivo::eliminarRegistro(int idVenta){
    int index;
    Venta venta;
    index = buscarRegistro(idVenta);
    venta = leerRegistro(index);
    venta.setEstado(0);
    return guardarRegistroModificado(index, venta);
}
// RECIBE UNA POSICION Y UN OBJETO VENTA Y LO MODIFICA
bool VentasArchivo::modificarRegistro(int index, Venta venta){
    int modifico;
    if (abrir("rb+") == false){
        return false;
    }
    fseek(_pFile, index * sizeof(Venta), SEEK_SET);
    modifico = fwrite(&venta, sizeof(Venta), 1, _pFile);
    cerrar();
    return modifico;
}

/// MENU DE VENTAS DE LA FERRETERIA
void VentasArchivo::menu() {
    DetallesVentasArchivo detalleVentaArchivo;
    int opcion, opcionListarVenta;
    do {
        system("cls");
        cout << "--------- MENU VENTAS -------" << endl;
        cout << "-------------------------------" << endl;
        cout << "1- CARGAR VENTA " << endl;
        cout << "2- CARGAR CLIENTE " << endl;
        cout << "3- LISTAR VENTAS " << endl;
        cout << "4- LISTAR VENTAS POR ID " << endl;
        cout << "5- LISTAR CLIENTES " << endl;
        cout << "6- ELIMINAR VENTA " << endl;
        cout << "7- MODIFICAR FECHA DE VENTA " << endl;
        cout << "-------------------------------" << endl;
        cout << "0- VOLVER AL MENU PRINCIPAL " << endl;
        cout << "-------------------------------" << endl;
        cout << "INGRESE LA OPCION: ";
        cin >> opcion;
        switch(opcion) {
        case 1:
            system("cls");
            guardarVenta();
            break;
        case 2:
            system("cls");
            clienteArchivo.guardarCliente();
            break;
        case 3:
            system("cls");
            listarVentas();
            cout << "------------------------------------------" << endl;
            cout << "DESEA VER LOS DETALLES DE LAS VENTAS? (1- SI || 2- NO): ";
            cin >> opcionListarVenta;
            cout << "------------------------------------------" << endl;
            if (opcionListarVenta == 2){
                break;
            } else {
                system("cls");
                detalleVentaArchivo.listarDetalleVentaID();
            }
            break;
        case 4:
            system("cls");
            listarVentasID();
            break;
        case 5:
            system("cls");
            clienteArchivo.listarCliente();
            break;
        case 6:
            system("cls");
            eliminarVenta();
            break;
        case 7:
            system("cls");
            modificarFechaVenta();
            break;
        case 0:
            return;
        default:
            system("cls");
            cout<< "OPCION INVALIDA, INGRESE NUEVAMENTE"<<endl;
        }
        system("pause");
    } while(opcion != 0);
}
