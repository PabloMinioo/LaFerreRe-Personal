#pragma once
#include "InventarioArchivo.h"
#include "VentasArchivo.h"
#include "DetallesVentasArchivo.h"

class Aplicacion{
private:
    VentasArchivo ventasArchivo;
    InventarioArchivo inventarioArchivo;
    DetallesVentasArchivo detalleVentas;
public:
    void menu();
};
