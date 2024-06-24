#pragma once
#include "Fecha.h"

class Venta{
private:
    // PROPIEDADES
    int _idVenta;
    int _tipoVenta;
    int _formaPago;
    float _precioTotal;
    int _idCliente;
    Fecha _fechaVenta;
    bool _estado;
public:
    // CONSTRUCTOR POR DEFECTO
    Venta();
    // CONSTRUCTOR POR PARAMTETROS
    Venta(int idVenta, int tipoVenta, int formaPago, float precioTotal, int idCliente, Fecha fechaVenta,bool estado);

    // SET Y GET
    void setIdVenta(int idVenta);
    int getIdVenta();

    void setTipoVenta(int tipoVenta);
    int getTipoVenta();

    void setFormaPago(int formaPago);
    int getFormaPago();

    void setPrecioTotal(float precioTotal);
    float getPrecioTotal();

    void setIdCliente(int idcliente);
    int getIdCliente();

    void setFechaVenta(Fecha fechaVenta);
    Fecha getFechaVenta();

    void setEstado(bool estado);
    bool getEstado();

    // METODOS
    Venta cargarVenta();
    void mostrarVenta(Venta venta);
};
