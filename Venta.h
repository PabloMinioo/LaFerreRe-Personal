#pragma once
#include "Fecha.h"

class Venta{
private:
    // PROPIEDADES
    int _idVenta;
    int _tipoVenta;
    float _precioTotal;
    Fecha _fechaVenta;
    int _formaPago;
    bool _estado;
public:
    // CONSTRUCTOR POR DEFECTO
    Venta();
    // CONSTRUCTOR POR PARAMTETROS
    Venta(int idVenta, int tipoVenta, float precioTotal, Fecha fechaVenta, int formaPago, bool estado);

    // SET Y GET
    void setIdVenta(int idVenta);
    int getIdVenta();

    void setTipoVenta(int tipoVenta);
    int getTipoVenta();

    void setPrecioTotal(float precioTotal);
    float getPrecioTotal();

    void setFechaVenta(Fecha fechaVenta);
    Fecha getFechaVenta();

    void setFormaPago(int formaPago);
    int getFormaPago();

    void setEstado(bool estado);
    bool getEstado();

    // METODOS
    Venta cargarVenta();
    void mostrarVenta(Venta venta);
};
