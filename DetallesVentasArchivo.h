#pragma once
#include <string>
#include "DetallesVentas.h"
#include "Archivo.h"

class DetallesVentasArchivo: public Archivo{
public:
    // CONSTRUCTOR POR DEFECTO
    DetallesVentasArchivo();
    // CONSTRUCTOR POR PARAMETROS
    DetallesVentasArchivo(std::string fileName);

    // METODOS
    void listarDetalleVenta();
    void listarDetalleIdVenta();
    void buscarDetalleVenta();
    void modificarDetalleVenta();

    // METODOS RELACIONADO A REGRISTROS
    bool guardarRegistro(DetallesVentas detalleVenta);
    bool GuardarRegistroModificado(int index, DetallesVentas detalleVenta);
    Venta leerRegistro(int index);
    int buscarRegistro(int idVenta);
    int getCantidadRegistros();
    bool eliminarRegistro(int idVenta);
    bool modificarRegistro(int index, DetallesVentas detalleVenta);
};
