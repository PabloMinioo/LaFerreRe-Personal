#pragma once
#include <string>
#include "Venta.h"
#include "Archivo.h"
#include "Clientes.h"
#include "ClientesArchivo.h"

class VentasArchivo: public Archivo{
private:
    Clientes cliente;
    ClientesArchivo clienteArchivo;
public:
    // CONSTRUCTOR POR DEFECTO
    VentasArchivo();
    // CONSTRUCTO POR PARAMETROS
    VentasArchivo(std::string fileName);

    // METODOS
    void guardarVenta();
    void listarVentas();
    void listarVentasID();
    void eliminarVenta();
    void modificarFechaVenta();

    // METODOS RELACIONADOS A REGISTROS
    bool guardarRegistro(Venta venta);
    bool guardarRegistroModificado(int index, Venta venta);
    Venta leerRegistro(int index);
    int buscarRegistro(int idVenta);
    int getCantidadRegistros();
    bool eliminarRegistro(int idVenta);
    bool modificarRegistro(int index, Venta venta);

    // MENU
    void menu();
};
