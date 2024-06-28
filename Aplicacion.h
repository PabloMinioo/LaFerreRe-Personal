#pragma once
#include "InventarioArchivo.h"
#include "VentasArchivo.h"
#include "DetallesVentasArchivo.h"

class Aplicacion{
private:
    VentasArchivo ventasArchivo;
    InventarioArchivo inventarioArchivo;
<<<<<<< HEAD
=======
    DetallesVentasArchivo detalleVentas;
    ClientesArchivo cliente;
>>>>>>> 8c44adb45899e486dcb3be4a5609453bcfde2feb
public:
    void menu();
};
