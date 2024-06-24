#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include "Venta.h"
#include "Fecha.h"
#include "DetallesVentas.h"
#include "DetallesVentasArchivo.h"
#include "VentasArchivo.h"

using namespace std;

/// DESARROLLO DE LOS METODOS DE LA CLASE 'Ventas'
// CONSTRUCTOR POR DEFECTO
Venta::Venta() {
    _idVenta = 0;
    _tipoVenta = 0;
    _formaPago = 0;
    _precioTotal = 0;
    _idCliente = 0;
    _fechaVenta = Fecha();
    _estado = false;
}
// CONSTRUCTOR POR PARAMETROS
Venta::Venta(int idVenta, int tipoVenta, int formaPago, float precioTotal, int idCliente, Fecha fechaVenta, bool estado) {
    setIdVenta(idVenta);
    setTipoVenta(tipoVenta);
    setFormaPago(formaPago);
    setPrecioTotal(precioTotal);
    setIdCliente(idCliente);
    setFechaVenta(fechaVenta);
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

void Venta::setIdCliente(int idcliente){
    _idCliente = idcliente;
}
int Venta::getIdCliente(){
    return _idCliente;
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
Venta Venta::cargarVenta(){
    int idVenta, tipoVenta, formaPago, idCliente, agregarProducto;
    float precioTotal = 0.0;
    Fecha fechaVenta;
    DetallesVentasArchivo detalleVentaArchivo;
    VentasArchivo ventaArchivo;
    Clientes cliente;
    ClientesArchivo clienteArchivo;

    // NUMERO DE VENTA AUTONUMERICOS
    idVenta = ventaArchivo.getCantidadRegistros() + 1;
    cout << "NUMERO ID DE VENTA: " << idVenta << endl;
    cout << "INGRESE EL TIPO DE VENTA (1-LOCAL || 2-ENVIO): ";
    cin >> tipoVenta;
    cout << "INGRESE LA FORMA DE PAGO (1-DEBITO || 2- CREDITO || 3-EFECTIVO): ";
    cin >> formaPago;
    // LLAMAMOS A LA FUNCION 'cargarDetalleVenta' PARA LAS VENTAS DE CADA PRODUCTO
    cout << " **** INGRESE LOS DETALLES DE LA VENTA ****" << endl;
    detalleVentaArchivo.guardarDetalleVenta();
    cout << "DESEA AGREGAR OTRO PRODUCTO? (1-SI || 2-NO): ";
    cin >> agregarProducto;
    while (agregarProducto == 1){
        detalleVentaArchivo.guardarDetalleVenta();
        cout << endl << "DESEA AGREGAR OTRO PRODUCTO? (1-SI || 2-NO): ";
        cin >> agregarProducto;
        cout << endl << " *INGRESE LOS DETALLES DE LA VENTA* " << endl;
    }
    cout << "INGRESE LA FECHA DE VENTA" << endl;
    fechaVenta.cargarFecha();
    cout << endl << " * PRESIONE CUALQUIER TECLA PARA INGRESAR LOS DATOS DEL CLIENTE *" << endl;
    system("pause");
    // HACEMOS USO DEL OBJETO CLIENTE PARA INGRESAR LOS DATOS DE LOS CLIENTES
    system("cls");
    cout << " ** LISTA DE CLIENTES **" << endl;
    clienteArchivo.listarCliente();
    cout << endl << "INGRESE EL NUMERO ID DEL CLIENTE O 'O' PARA REGISTRAR UN NUEVO CLIENTE: ";
    cin >> idCliente;
    if (idCliente == 0){
        clienteArchivo.guardarCliente();
    }
    return Venta(idVenta, tipoVenta, formaPago, precioTotal, idCliente, fechaVenta, true);
}
void Venta::mostrarVenta(Venta venta){
    cout << "ID DE LA VENTA: " << venta.getIdVenta() << endl;
    cout << "TIPO DE VENTA: " << (venta.getTipoVenta() ? "LOCAL" : "ENVIO") << endl;
    cout << "FORMA DE PAGO: ";
    if (venta.getFormaPago() == 1){
        cout << "DEBITO" << endl;
    } else if (venta.getFormaPago() == 2){
        cout << "CREDITO" << endl;
    } else {
        cout << "EFECTIVO" << endl;
    }
    cout << "IMPORTE TOTAL DE LA VENTA " << venta.getPrecioTotal() << endl;
    cout << "ID DEL CLIENTE: " << venta.getIdCliente() << endl;
    cout << "ESTADO VENTA: " << (venta.getEstado() ? "DISPONIBLE" : "NO DISPONIBLE") << endl;
}

