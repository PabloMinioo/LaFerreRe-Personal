#pragma once
#include <string>
#include "Venta.h"
#include "Archivo.h"

class VentasArchivo: public Archivo{
private:
    // PROPIEDAES
    Venta venta;
public:
    // CONSTRUCTOR POR DEFECTO
    VentasArchivo();
    // CONSTRUCTO POR PARAMETROS
    VentasArchivo(std::string fileName);

    // METODOS
    void listarVentas();
    void listarVentasID();
    void buscarVenta();
    void modificarVenta();

    // METODOS RELACIONADOS A REGISTROS
    bool guardarRegistro(Venta venta);
    bool GuardarRegistroModificado(int index, Venta venta);
    Venta leerRegistro(int index);
    int buscarRegistro(int idVenta);
    int getCantidadRegistros();
    bool eliminarRegistro(int idVenta);
    bool modificarRegistro(int index, Venta venta);

    // MENU
    void menu();
};
