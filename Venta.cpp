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
void Venta::setIdVenta(int idVenta) {
    _idVenta = idVenta;
}
int Venta::getIdVenta() {
    return _idVenta;
}

void Venta::setTipoVenta(int tipoVenta) {
    _tipoVenta = tipoVenta;
}
int Venta::getTipoVenta() {
    return _tipoVenta;
}

void Venta::setPrecioTotal(float precioTotal) {
    _precioTotal = precioTotal;
}
float Venta::getPrecioTotal() {
    return _precioTotal;
}

void Venta::setIdCliente(int idcliente) {
    _idCliente = idcliente;
}
int Venta::getIdCliente() {
    return _idCliente;
}

void Venta::setFechaVenta(Fecha fechaVenta) {
    _fechaVenta = fechaVenta;
}
Fecha Venta::getFechaVenta() {
    return _fechaVenta;
}

void Venta::setFormaPago(int formaPago) {
    _formaPago = formaPago;
}
int Venta::getFormaPago() {
    return _formaPago;
}

void Venta::setEstado(bool estado) {
    _estado = estado;
}
bool Venta::getEstado() {
    return _estado;
}

// METODOS
Venta Venta::cargarVenta() {
    // USAMOS LOS OBJETOS 'Fecha', 'VentasArchivo', 'DetallesVentas', 'DetallesVentasArchivo', 'Clientes', 'ClientesArchivo'
    Fecha fechaVenta;
    VentasArchivo ventaArchivo;
    DetallesVentas detalleVenta;
    DetallesVentasArchivo detalleVentaArchivo;
    Clientes cliente;
    ClientesArchivo clienteArchivo;

    // DECLARAMOS LAS VARIABLES QUE VAMOS A UTILIZAR
    int idVenta, idCliente, tipoVenta, formaPago, agregarProducto;
    float precioTotal = 0.0;
<<<<<<< HEAD
    const float descuento = 0.10; // DESCUENTO DE PAGA EN EFECTIVO
    const float costoEnvio = 1.20; // AUMENTO DE PRECIO POR ENVIO
=======
>>>>>>> 8c44adb45899e486dcb3be4a5609453bcfde2feb

    // CARGAMOS LOS DATOS DEL CLIENTE
    // LISTAMOS LOS DATOS DE TODOS LOS CLIENTES
    cout << " **** LISTA DE CLIENTES ****" << endl;
    clienteArchivo.listarCliente();

    // LLAMAMOS A LA FUNCION 'guardarCliente()' PARA CARGAR EL CLIENTE
    cout << endl << "INGRESE EL NUMERO ID DEL CLIENTE o '0' SI QUIERE REGISTRAR UN CLIENTE NUEVO: ";
    cin >> idCliente;
    if (idCliente == 0){
        cliente = clienteArchivo.guardarCliente();
        idCliente = cliente.getIdCliente();
    }
    cout << endl << " *PRESIONE CUALQUIER TECLA PARA CONTINUAR CON LA CARGA* " << endl;
    system("pause");
    system("cls");
    cout << "NUMERO DE CLIENTE: " << idCliente << endl;

    // NUMERO DE VENTA AUTONUMERICOS
    idVenta = ventaArchivo.getCantidadRegistros() + 1;
    cout << "NUMERO ID DE VENTA: " << idVenta << endl;

    // INGRESAMOS EL TIPO DE VENTA Y LA FORMA DE PAGO
    cout << "INGRESE EL TIPO DE VENTA (1-LOCAL || 2-ENVIO): ";
    cin >> tipoVenta;
    cout << "INGRESE LA FORMA DE PAGO (1-DEBITO || 2- CREDITO || 3-EFECTIVO): ";
    cin >> formaPago;

    // LLAMAMOS A LA FUNCION 'guardarDetalleVenta()' PARA LAS CARGAR LAS VENTAS DE CADA PRODUCTO
    cout << endl << " **** INGRESE LOS DETALLES DE LA VENTA ****" << endl;
    do {
        detalleVenta = detalleVentaArchivo.guardarDetalleVenta();
        precioTotal += detalleVenta.getImporteVenta();
        cout << endl << "--------------------------------------" << endl;
        cout << "DESEA AGREGAR OTRO PRODUCTO? (1-SI || 2-NO): ";
        cin >> agregarProducto;
        cout << "--------------------------------------" << endl;
<<<<<<< HEAD
    } while (agregarProducto != 2);
=======
    } while (agregarProducto != 0);
>>>>>>> 8c44adb45899e486dcb3be4a5609453bcfde2feb

    // CARGAMOS LA FECHA DE VENTA
    cout << "INGRESE LA FECHA DE VENTA" << endl;
    fechaVenta.cargarFecha();

<<<<<<< HEAD
    // APLICAMOS UN DESCUENTO DEL 10% SI SE PAGO EN 'Efectivo'
    if (formaPago == 3){
        precioTotal = precioTotal * (1- descuento);
    }

    // APLICAMOS UN AUMENTO DEL 20% SI EL TIPO DE VENTA ES 'Envio'
    if (tipoVenta == 2){
        precioTotal = precioTotal * costoEnvio;
    }
=======
>>>>>>> 8c44adb45899e486dcb3be4a5609453bcfde2feb
    // DEVOLVEMOS EL OBJETO
    return Venta(idVenta, tipoVenta, formaPago, precioTotal, idCliente, fechaVenta, true);
}

void Venta::mostrarVenta(Venta venta) {
    cout << "ID DE LA VENTA: " << venta.getIdVenta() << endl;
    if (venta.getTipoVenta() == 1){
        cout << "TIPO DE VENTA: LOCAL" << endl;
    } else {
        cout << "TIPO DE VENTA: ENVIO" << endl;
    }
    cout << "FORMA DE PAGO: ";
    if (venta.getFormaPago() == 1) {
        cout << "DEBITO" << endl;
    } else if (venta.getFormaPago() == 2) {
        cout << "CREDITO" << endl;
    } else {
        cout << "EFECTIVO" << endl;
    }
    cout << "IMPORTE TOTAL DE LA VENTA " << venta.getPrecioTotal() << endl;
    cout << "ID DEL CLIENTE: " << venta.getIdCliente() << endl;
    cout << "FECHA DE VENTA: ";
    venta.getFechaVenta().mostrarFecha();
    cout << "ESTADO VENTA: " << (venta.getEstado() ? "DISPONIBLE" : "NO DISPONIBLE") << endl;
}

