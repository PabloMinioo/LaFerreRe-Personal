#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include "Venta.h"

using namespace std;

/// DESARROLLO DE LOS METODOS DE LA CLASE 'Ventas'
// CONSTRUCTOR POR DEFECTO
Venta::Venta() {
    _idVenta = 0;
    _tipoVenta = 0;
    _precioTotal = 0;
    _fechaVenta = Fecha();
    _formaPago = 0;
    _estado = false;
}
// CONSTRUCTOR POR PARAMETROS
Venta::Venta(int idVenta, int tipoVenta, float precioTotal, Fecha fechaVenta, int formaPago, bool estado) {
    setIdVenta(idVenta);
    setTipoVenta(tipoVenta);
    setPrecioTotal(precioTotal);
    setFechaVenta(fechaVenta);
    setFormaPago(formaPago);
    setEstado(estado);
}
// SET Y GET
void Venta::setIdVenta(int idVenta){
    _idVenta = idVenta;
}
int Venta::getIdVenta(){
    return _idVenta;
}

void Venta::setTipoVenta(int tipoVenta){
    _tipoVenta = tipoVenta;
}
int Venta::getTipoVenta(){
    return _tipoVenta;
}

void Venta::setPrecioTotal(float precioTotal){
    _precioTotal = precioTotal;
}
float Venta::getPrecioTotal(){
    return _precioTotal;
}

void Venta::setFechaVenta(Fecha fechaVenta){
    _fechaVenta = fechaVenta;
}
Fecha Venta::getFechaVenta(){
    return _fechaVenta;
}

void Venta::setFormaPago(int formaPago){
    _formaPago = formaPago;
}
int Venta::getFormaPago(){
    return _formaPago;
}

void Venta::setEstado(bool estado){
    _estado = estado;
}
bool Venta::getEstado(){
    return _estado;
}

// METODOS
//Venta Venta::cargarVenta(){
//    int idVenta, tipoVenta, formaPago;
//    float precioTotal;
//    Fecha fechaVenta;
//
//    cout << "INGRESE EL ID VENTA: ";
//    cin >> idVenta;
//    cout << "INGRESE EL TIPO DE VENTA: ";
//    cin >> tipoVenta;
//    cout
//}
//    void mostrarVenta(Ventas venta);
