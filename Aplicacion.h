#pragma once
#include "InventarioArchivo.h"
#include "VentasArchivo.h"

class Aplicacion{
private:
    VentasArchivo ventasArchivo;
    InventarioArchivo inventarioArchivo;
public:
    void menu();
};
