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
DetallesVentas DetallesVentasArchivo::guardarDetalleVenta() {
    DetallesVentas detalleVenta;
    InventarioArchivo inventario;
    detalleVenta = detalleVenta.cargarDetalleVenta();
    // VALIDACION SI EXISTE EL NUMERO ID DEL PRODUCTO
    if (inventario.isExist(detalleVenta.getIdProducto()) == false){
        cout << "LA CARGA DE LA VENTA DEL PRODUCTO NO SE PUDO REALIZAR. ID DEL PRODUCTO NO EXISTENTE" << endl;
        return detalleVenta;
    }
    // VALIDACION DE CANTIDAD DE PRODUCTO VENDIDO POSIBLE
    int stockProducto = inventario.getStockPorID(detalleVenta.getIdProducto());
    if (detalleVenta.getCantidadProductoVendido() <= 0 || detalleVenta.getCantidadProductoVendido() > stockProducto){
        cout << "LA CARGA DE LA VENTA DEL PRODUCTO NO SE PUDO REALIZAR. CANTIDAD DE PRODUCTO NO VALIDO" << endl;
        return detalleVenta;
    }
    if (guardarRegistro(detalleVenta)) {
        cout << "LA CARGA DE LA VENTA FUE REALIZADA CON EXITO" << endl;
        return detalleVenta;
    } else {
        cout << "LA CARGA DE LA VENTA NO SE PUDO REALIZAR" << endl;
        return detalleVenta;
    }
}

// LISTA TODAS LAS VENTAS
void DetallesVentasArchivo::listar(){
    DetallesVentas detalleVenta;
    int cantidadRegistros = getCantidadRegistros();
    for (int i = 0; i < cantidadRegistros; i++) {
        detalleVenta = leerRegistro(i);
        if (detalleVenta.getEstado()) {
            cout << "**************************" << endl;
            detalleVenta.mostrarDetalleVenta(detalleVenta);
            cout << "**************************" << endl;
        }
    }
}

// SE INDICA UN ID DE VENTA Y MUESTRA EL REGISTRO POR PANTALLA
void DetallesVentasArchivo::listarDetalleVentaID(){
    int idVenta;
    bool encontro;
    DetallesVentas detalleVenta;
    cout << "INGRESE EL ID DE LA VENTA A BUSCAR: ";
    cin >> idVenta;
    int cantidadRegistros = getCantidadRegistros();
    for (int i = 0; i < cantidadRegistros; i++){
        detalleVenta = leerRegistro(i);
        if (detalleVenta.getIdVenta() == idVenta){
            cout << "**************************" << endl;
            detalleVenta.mostrarDetalleVenta(detalleVenta);
            encontro = true;
            cout << "**************************" << endl;
        }
    }
    if (encontro == false){
        cout << "EL ID DE LA VENTA NO EXISITE" << endl;
    }
}

// METODOS RELACIONADO A REGRISTROS
// RECIBE UN OBJETO TIPO DETALLESVENTAS Y LO GUARDA EN EL ARCHIVO
bool DetallesVentasArchivo::guardarRegistro(DetallesVentas detalleVenta){
    int grabo;
    if (abrir("ab") == false) {
        return false;
    }
    grabo = fwrite(&detalleVenta, sizeof (DetallesVentas), 1, _pFile);
    cerrar();
    return grabo;
}

// RECIBE UNA POSICION Y LEE EL REGISTRO DE DICHA POSICION
DetallesVentas DetallesVentasArchivo::leerRegistro(int index) {
    DetallesVentas detalleVenta;
    if (abrir("rb") == false) {
        return detalleVenta;
    }
    fseek(_pFile, index * sizeof(DetallesVentas), SEEK_SET);
    fread(&detalleVenta, sizeof(DetallesVentas), 1, _pFile);
    cerrar();
    return detalleVenta;
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
