#pragma once
#include "Venta.h"
#include "VentasArchivo.h"
#include "Producto.h"
#include "InventarioArchivo.h"

class DetallesVentas{
private:
    // PROPIEDADES
    int _idVenta;
    int _idProducto;
    int _cantidadProductoVendido;
    float _importeVenta;
    bool _estado;

public:
    // CONSTRUCTOR POR DEFECTO
    DetallesVentas();
    // CONSTRUCTOR POR PARAMETROS
    DetallesVentas(int idVenta, int idProducto, int cantidadProductoVendido, float importeVenta, bool estado);

    // SET Y GET
    void setIdVenta(int idVenta);
    int getIdVenta();

    void setIdProducto(int idProducto);
    int getIdProducto();

    void setCantidadProductoVendido(int cantidadProductoVendido);
    int getCantidadProductoVendido();

    void setImporteVenta(float importeVenta);
    float getImporteVenta();

    void setEstado(bool estado);
    bool getEstado();

    // METODOS
    DetallesVentas cargarDetalleVenta();
    void mostrarDetalleVenta(DetallesVentas detalleVenta);
};
