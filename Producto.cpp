#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include "Producto.h"

using namespace std;

/// DESARROLLO DE LOS METODOS DE LA CLASE 'Producto'
// CONSTRUCTOR POR DEFECTO
Producto::Producto(){
    _idProducto = 0;
    strcpy(_nombreProducto, "");
    _tipoProducto = 0;
    _stock = 0;
    _precioUnitario = 0;
    strcpy(_nombreProveedor, "");
    _estado = false;
}
// CONSTRUCTO POR PARAMETROS
Producto::Producto(int idProducto, string nombreProducto, int tipoProdcuto, int stock, float precioUnitario, string nombreProveedor, bool estado){
    setIdProducto(idProducto);
    setNombreProducto(nombreProducto);
    setTipoProducto(tipoProdcuto);
    setStock(stock);
    setPrecioUnitario(precioUnitario);
    setNombreProveedor(nombreProveedor);
    setEstado(estado);
}
// SETTERS Y GETTERS
void Producto::setIdProducto(int idProducto){
    _idProducto = idProducto;
}
int Producto::getIdProducto(){
    return _idProducto;
}

void Producto::setNombreProducto(string nombreProducto){
    if (nombreProducto.size() <= 29){
        strcpy(_nombreProducto, nombreProducto.c_str());
    } else {
        strcpy(_nombreProducto, "SIN DATOS");
    }
}
string Producto::getNombreProducto(){
    return _nombreProducto;
}

void Producto::setTipoProducto(int tipoProducto){
    _tipoProducto = tipoProducto;
}
int Producto::getTipoProducto(){
    return _tipoProducto;
}

void Producto::setStock(int stock){
    _stock = stock;
}
int Producto::getStock(){
    return _stock;
}

void Producto::setPrecioUnitario(float precioUnitario){
    _precioUnitario = precioUnitario;
}
float Producto::getPrecioUnitario(){
    return _precioUnitario;
}

void Producto::setNombreProveedor(string nombreProveedor){
    if (nombreProveedor.size() <= 29){
        strcpy(_nombreProveedor, nombreProveedor.c_str());
    } else {
        strcpy(_nombreProveedor, "SIN DATOS");
    }
}
string Producto::getNombreProveedor(){
    return _nombreProveedor;
}

void Producto::setEstado(bool estado){
    _estado = estado;
}
bool Producto::getEstado(){
    return _estado;
}

// METODOS
// CREAMOS EL PRODUCTO
Producto Producto::crearProducto(){
    int idProducto, tipoProducto, stock;
    float precioUnitario;
    string nombreProducto, nombreProveedor;
    cout << "INGRESE EL ID DEL PRODUCTO: ";
    cin >> idProducto;
    cin.ignore();
    cout << "INGRESE EL NOMBRE DEL PRODUCTO: ";
    getline(cin, nombreProducto);
    cout << "INGRESE EL TIPO DEL PRODUCTO: ";
    cin >> tipoProducto;
    cout << "INGRESE EL STOCK DEL PRODUCTO: ";
    cin >> stock;
    cout << "INGRESE EL PRECIO UNITARIO DEL PRODUCTO: ";
    cin >> precioUnitario;
    cin.ignore();
    cout << "INGRESE EL NOMBRE DEL PROVEEDOR: ";
    getline(cin, nombreProveedor);
    return Producto(idProducto, nombreProducto, tipoProducto, stock, precioUnitario, nombreProveedor, true);
}
// RECIBE UN OBJETO TIPO PRODUCO Y LO MUESTRA EL PRODUCTO
void Producto::mostrarProducto(Producto producto){
    cout << "ID DEL PRODUCTO: " << producto.getIdProducto() << endl;
    cout << "NOMBRE DEL PRODUCTO: " << producto.getNombreProducto() << endl;
    cout << "TIPO DEL PRODUCTO: " << producto.getTipoProducto() << endl;
    cout << "STOCK DEL PRODUCTO: " << producto.getStock() << endl;
    cout << "PRECIO UNITARIO DEL PRODUCTO: " << producto.getPrecioUnitario() << endl;
    cout << "NOMBRE DEL PROVEEDOR: " << producto.getNombreProveedor() << endl;
    cout << "DISPONIBILIDAD DEL PRODUCTO: " << (producto.getEstado() ? "DISPONIBLE" : "NO DISPONIBLE") << endl;
}
