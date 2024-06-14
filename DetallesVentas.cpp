#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include "DetallesVentas.h"

using namespace std;

/// DESARROLLO DE LOS METODOS DE LA CLASE 'DetallesVentas'
// CONSTRUCTOR POR DEFECTO
DetallesVentas::DetallesVentas() {
    _idVenta = 0;
    _idCliente = 0;
    _idProducto = 0;
    _cantidadProductoVendido = 0;
    _precioUnitario = 0;
    _estado = false;
}
// CONSTRUCTOR POR PARAMETROS
DetallesVentas::DetallesVentas(int idVenta, int idCliente, int idProducto, int cantidadProductoVendido, float precioUnitario, bool estado) {
    setIdVenta(idVenta);
    setIdCliente(idCliente);
    setIdProducto(idProducto);
    setCantidadProductoVendido(cantidadProductoVendido);
    setPrecioUnitario(precioUnitario);
    setEstado(estado);
}
// SET Y GET
void DetallesVentas::setIdVenta(int idVenta){
    _idVenta = idVenta;
}
int DetallesVentas::getIdVenta(){
    return _idVenta;
}

void DetallesVentas::setIdCliente(int idcliente){
    _idCliente = idcliente;
}
int DetallesVentas::getIdCliente(){
    return _idCliente;
}

void DetallesVentas::setIdProducto(int idProducto){
    _idProducto = idProducto;
}
int DetallesVentas::getIdProducto(){
    return _idProducto;
}

void DetallesVentas::setCantidadProductoVendido(int cantidadProductoVendido){
    _cantidadProductoVendido = cantidadProductoVendido;
}
int DetallesVentas::getCantidadProductoVendido(){
    return _cantidadProductoVendido;
}

void DetallesVentas::setPrecioUnitario(float precioUnitario){
    _precioUnitario = precioUnitario;
}
float DetallesVentas::getPrecioUnitario(){
    return _precioUnitario;
}

void DetallesVentas::setEstado(bool estado){
    _estado = estado;
}
bool DetallesVentas::getEstado(){
    return _estado;
}

// METODOS
//DetallesVentas DetallesVentas::cargarDetalleVenta(){
//    Venta venta;
//    Producto producto;
//    int idCliente, cantidadProductoVendido;
//    float precioUnitario;
//
//    cout << "NUMERO ID DE LA VENTA: " << venta.getIdVenta() << endl;
//    cout << "INGRESE EL NUMERO ID DE CLIENTE: "
//}
//void mostrarDetalleVenta(DetallesVentas detalleVenta);
//

