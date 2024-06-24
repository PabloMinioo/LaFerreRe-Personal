#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include "DetallesVentasArchivo.h"
#include "InventarioArchivo.h"
#include "Archivo.h"

using namespace std;

/// DESARROLLO DE LOS METODOS DE LA CLASE 'DetallesVentasArchivo'
// CONSTRUCTOR POR DEFECTO
DetallesVentasArchivo::DetallesVentasArchivo(){
    _fileName = "detallesVentas.dat";
}
// CONSTRUCTOR POR PARAMETROS
DetallesVentasArchivo::DetallesVentasArchivo(string fileName){
    _fileName = fileName;
}

// METODOS
void DetallesVentasArchivo::guardarDetalleVenta() {
    DetallesVentas detalleVenta;
    InventarioArchivo inventario;

    detalleVenta = detalleVenta.cargarDetalleVenta();

    cout << "*************************************ID PRODUCTO: " << detalleVenta.getIdProducto() << endl;
    // VALIDACION SI EXISTE EL NUMERO ID DEL PRODUCTO
    if (inventario.isExist(detalleVenta.getIdProducto()) == false){
        cout << "LA CARGA DE LA VENTA DEL PRODUCTO NO SE PUDO REALIZAR. ID DEL PRODUCTO NO EXISTENTE" << endl;
        return;
    }
    // VALIDACION DE CANTIDAD DE PRODUCTO VENDIDO POSIBLE
    int stockProducto = inventario.getStockPorID(detalleVenta.getIdProducto());
    if (detalleVenta.getCantidadProductoVendido() <= 0 || detalleVenta.getCantidadProductoVendido() > stockProducto){
        cout << "LA CARGA DE LA VENTA DEL PRODUCTO NO SE PUDO REALIZAR. CANTIDAD DE PRODUCTO NO VALIDO" << endl;
        return;
    }
    if (guardarRegistro(detalleVenta)) {
        cout << "LA CARGA DE LA VENTA FUE REALIZADA CON EXITO" << endl;
    } else {
        cout << "LA CARGA DE LA VENTA NO SE PUDO REALIZAR" << endl;
    }
}

// LISTA TODAS LAS VENTAS
//void DetallesVentasArchivo::listar() {
//    int cantidad = getCantidadRegistros();
//    cout << "CANTIDAD DE REGISTROS: " << cantidad << endl;
//    for (int i = 0; i < cantidad; i++) {
//        cout << "Leído registro: " << i << endl;
//        DetallesVentas detalleVenta = leerRegistro(i);
//        cout << "ID VENTA: " << detalleVenta.getIdVenta() << " - ESTADO VENTA" << detalleVenta.getEstado() << endl;
//        if (detalleVenta.getEstado() && detalleVenta.getIdVenta() != 0) {
//            cout << "**************************" << endl;
//            detalleVenta.mostrarDetalleVenta();
//            cout << "**************************" << endl;
//        }
//    cout << "FIN DEL BUCLE" << endl;
//    }
//}
void DetallesVentasArchivo::listar(){
    int cantidad = getCantidadRegistros();
    for (int i = 0; i < cantidad; i++) {
        DetallesVentas detalleVenta = leerRegistro(i);
        if (detalleVenta.getEstado()) {
            cout << "**************************" << endl;
            cout << "NUMERO ID DE LA VENTA: " << detalleVenta.getIdVenta() << endl;
            cout << "NUMERO ID DEL PRODUCTO: " << detalleVenta.getIdProducto() << endl;
            cout << "CANTIDAD DE PRODUCTO VENDIDO: " << detalleVenta.getCantidadProductoVendido() << endl;
            cout << "IMPORTE DE LA VENTA: " << detalleVenta.getImporteVenta() << endl;
            cout << "ESTADO VENTA: " << (detalleVenta.getEstado() ? "DISPONIBLE" : "NO DISPONIBLE") << endl;
            cout << "**************************" << endl;
        }
        fseek(_pFile, (i+1) * sizeof(DetallesVentas), SEEK_SET); // Avanzar a la siguiente posición
    }
}


//// SE INDICA UN ID DE VENTA Y MUESTRA EL REGISTRO POR PANTALLA
//void DetallesVentasArchivo::listarDetalleVentaID(){
//    int index, idVenta;
//    DetallesVentas detalleVenta;
//    cout << "INGRESE EL ID DE LA VENTA A BUSCAR: ";
//    cin >> idVenta;
//    index = buscarRegistro(idVenta);
//    if (index >= 0){
//        cout << "**************************" << endl;
//        detalleVenta = leerRegistro(index);
//        detalleVenta.mostrarDetalleVenta();
//        cout << "**************************" << endl;
//    } else {
//        cout << "EL ID DE LA VENTA NO EXISTE" << endl;
//    }
//}


// METODOS RELACIONADO A REGRISTROS
// RECIBE UN OBJETO TIPO DETALLESVENTAS Y LO GUARDA EN EL ARCHIVO
bool DetallesVentasArchivo::guardarRegistro(DetallesVentas detalleVenta){
    int grabo;
    if (abrir("ab") == false) {
        cout << "Error al abrir el archivo." << endl;
        return false;
    }
    grabo = fwrite(&detalleVenta, sizeof (DetallesVentas), 1, _pFile);
    cerrar();
    if (grabo != 1) {
        cout << "Error al escribir el registro." << endl;
        return false;
    }
    return true;
}
// RECIBE UNA POSICION Y LEE EL REGISTRO DE DICHA POSICION
//DetallesVentas DetallesVentasArchivo::leerRegistro(int index) {
//    DetallesVentas detalleVenta;
//    if (abrir("rb") == false) {
//        return detalleVenta;
//    }
//    fseek(_pFile, index * sizeof(DetallesVentas), SEEK_SET);
//    fread(&detalleVenta, sizeof(DetallesVentas), 1, _pFile);
//    cerrar();
//    cout << "Leído registro: " << detalleVenta.getIdVenta() << endl; // Verificar la lectura
//    return detalleVenta;
//}

DetallesVentas DetallesVentasArchivo::leerRegistro(int index){
    DetallesVentas detalleVenta;
    if (abrir("rb") == false){
        cout << "Error al abrir el archivo" << endl;
        return detalleVenta;
    }
    cout << "Posición antes de fseek: " << ftell(_pFile) << endl;
    fseek(_pFile, index * sizeof (DetallesVentas), SEEK_SET);
    cout << "Posición después de fseek: " << ftell(_pFile) << endl;
    fread(&detalleVenta, sizeof (DetallesVentas), 1, _pFile);
    cout << "Posición después de fread: " << ftell(_pFile) << endl;
    cerrar();
    return detalleVenta;
}void DetallesVentasArchivo::leerRegistroXD(int index){
    DetallesVentas detalleVenta;
    if (abrir("rb") == false){
        return;
    }
    cout << "LEI EL ARCHIVO" << endl;
    cerrar();
    return;
}

// RECIBE EL ID DE LA VENTA Y DEVUELVE SU POSICION
int DetallesVentasArchivo::buscarRegistro(int idVenta) {
    int index = 0;
    DetallesVentas detallesVenta;
    if (abrir("rb+") == false) {
        return -1;
    }
    while (fread(&detallesVenta, sizeof(DetallesVentas), 1, _pFile)) {
        if (detallesVenta.getIdVenta() == idVenta) {
            break;
        }
        index++;
    }
    cerrar();
    if(detallesVenta.getIdVenta() == idVenta) {
        return index;
    } else {
        return -1;
    }
}


// DEVUELVE LA CANTIDAD DE REGISTROS DEL ARCHIVO
int DetallesVentasArchivo::getCantidadRegistros() {
    if (abrir("rb") == false) {
        return 0;
    }
    fseek(_pFile, 0, SEEK_END);
    int tamanio = ftell(_pFile);
    cerrar();
    return tamanio / sizeof(DetallesVentas);
}
