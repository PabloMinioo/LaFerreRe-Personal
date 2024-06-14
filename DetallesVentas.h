#pragma once
#include "Venta.h"
#include "Producto.h"
#include "Clientes.h"

class DetallesVentas{
private:
    // PROPIEDADES
    int _idVenta;
    int _idCliente;
    int _idProducto;
    int _cantidadProductoVendido;
    float _precioUnitario;
    bool _estado;
public:
    // CONSTRUCTOR POR DEFECTO
    DetallesVentas();
    // CONSTRUCTOR POR PARAMETROS
    DetallesVentas(int idVenta, int idCliente, int idProducto, int cantidadProductoVendido, float precioUnitario, bool estado);

    // SET Y GET
    void setIdVenta(int idVenta);
    int getIdVenta();

    void setIdCliente(int idcliente);
    int getIdCliente();

    void setIdProducto(int idProducto);
    int getIdProducto();

    void setCantidadProductoVendido(int cantidadProductoVendido);
    int getCantidadProductoVendido();

    void setPrecioUnitario(float precioUnitario);
    float getPrecioUnitario();

    void setEstado(bool estado);
    bool getEstado();

    // METODOS
    DetallesVentas cargarDetalleVenta();
    void mostrarDetalleVenta(DetallesVentas detalleVenta);

};
