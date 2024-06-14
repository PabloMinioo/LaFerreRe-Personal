#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include "VentasArchivo.h"
#include "Archivo.h"

using namespace std;

/// DESARROLLO DE LOS METODOS DE 'VentasArchivo'
// CONSTRUCTOR POR DEFECTO
VentasArchivo::VentasArchivo(){
    _fileName = "historialVentas.dat";
}
// CONSTRUCTOR POR PARAMETROS
VentasArchivo::VentasArchivo(string fileName){
    _fileName = fileName;
}

// METODOS
//    void listarVentas();
//    void listarVentasID();
//    void buscarVenta();
//    void modificarVenta();
//    void menu();

// METODOS RELACIONADOS A REGISTROS
//    bool guardarRegistro(Venta venta);
//    bool GuardarRegistroModificado(int index, Venta venta);
//    Venta leerRegistro(int index);
//    int buscarRegistro(int idVenta);
//    int getCantidadRegistros();
//    bool eliminarRegistro(int idVenta);
//    bool modificarRegistro(int index, Venta venta);
