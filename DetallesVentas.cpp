#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include "DetallesVentas.h"
#include "VentasArchivo.h"


using namespace std;

/// DESARROLLO DE LOS METODOS DE LA CLASE 'DetallesVentas'
// CONSTRUCTOR POR DEFECTO
DetallesVentas::DetallesVentas() {
    _idVenta = 0;
    _idProducto = 0;
    _cantidadProductoVendido = 0;
    _importeVenta = 0;
    _estado = false;
}
// CONSTRUCTOR POR PARAMETROS
DetallesVentas::DetallesVentas(int idVenta, int idProducto, int cantidadProductoVendido, float importeVenta, bool estado) {
    setIdVenta(idVenta);
    setIdProducto(idProducto);
    setCantidadProductoVendido(cantidadProductoVendido);
    setImporteVenta(importeVenta);
    setEstado(estado);
}
// SET Y GET
void DetallesVentas::setIdVenta(int idVenta){
    _idVenta = idVenta;
}
int DetallesVentas::getIdVenta(){
    return _idVenta;
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

void DetallesVentas::setImporteVenta(float importeVenta){
    _importeVenta = importeVenta;
}
float DetallesVentas::getImporteVenta(){
    return _importeVenta;
}

void DetallesVentas::setEstado(bool estado){
    _estado = estado;
}
bool DetallesVentas::getEstado(){
    return _estado;
}

// METODOS
DetallesVentas DetallesVentas::cargarDetalleVenta(){
    // DECLARAMOS LAS VARIABLES
    int idVenta, idProducto, cantidadProductoVendido;
    float importeVenta = 0.0;

    // USAMOS LOS OBJETOS 'InventarioArchivo' y 'VentasArchivo'
    InventarioArchivo inventario;
    VentasArchivo ventaArchivo;

    // NUMERO ID DE VENTA AUTONUMERICO
    idVenta = ventaArchivo.getCantidadRegistros() + 1;
    cout << "NUMERO ID DE LA VENTA: " << idVenta << endl;

    // INGRESAMOS EL NUMERO ID DEL PRODUCTO
    cout << "INGRESE EL ID DEL PRODUCTO: ";
    cin >> idProducto;

    // INGRESAMOS LA CANTIDAD DE PRODUCTO A VENDER
    cout << "INGRESE LA CANTIDAD DE PRODUCTO VENDIDO: ";
    cin >> cantidadProductoVendido;
    inventario.restarStock(idProducto, cantidadProductoVendido);

    // LLAMAMOS A LA FUNCION 'calcularImporteVenta' PARA CALCULAR EL IMPORTE DE LA VENTA
    importeVenta += inventario.calcularImporteVenta(idProducto, cantidadProductoVendido);
    cout << "IMPORTE DE LA VENTA: " << importeVenta << endl;

    // DEVOLVEMOS EL OBJETO
    return DetallesVentas(idVenta, idProducto, cantidadProductoVendido, importeVenta, true);
}
void DetallesVentas::mostrarDetalleVenta(DetallesVentas detalleVenta){
    cout << "NUMERO ID DE LA VENTA: " << detalleVenta.getIdVenta() << endl;
    cout << "NUMERO ID DEL PRODUCTO: " << detalleVenta.getIdProducto() << endl;
    cout << "CANTIDAD DE PRODUCTO VENDIDO: " << detalleVenta.getCantidadProductoVendido() << endl;
    cout << "IMPORTE DE LA VENTA: " << detalleVenta.getImporteVenta() << endl;
    cout << "ESTADO VENTA: " << (detalleVenta.getEstado() ? "DISPONIBLE" : "NO DISPONIBLE") << endl;
}


