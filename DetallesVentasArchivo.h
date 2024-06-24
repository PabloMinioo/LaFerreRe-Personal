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
    DetallesVentas guardarDetalleVenta();
    void listar();
    void listarDetalleVentaID();

    // METODOS RELACIONADO A REGRISTROS
    bool guardarRegistro(DetallesVentas detalleVenta);
    DetallesVentas leerRegistro(int index);
    int buscarRegistro(int idVenta);
    int getCantidadRegistros();
};
