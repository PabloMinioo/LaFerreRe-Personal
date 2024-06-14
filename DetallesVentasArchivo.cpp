#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include "DetallesVentasArchivo.h"
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
//    void listarDetalleVenta();
//    void listarDetalleIdVenta();
//    void buscarDetalleVenta();
//    void modificarDetalleVenta();

// METODOS RELACIONADO A REGRISTROS
//    bool guardarRegistro(DetallesVentas detalleVenta);
//    bool GuardarRegistroModificado(int index, DetallesVentas detalleVenta);
//    Venta leerRegistro(int index);
//    int buscarRegistro(int idVenta);
//    int getCantidadRegistros();
//    bool eliminarRegistro(int idVenta);
//    bool modificarRegistro(int index, DetallesVentas detalleVenta);
