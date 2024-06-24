#pragma once
#include <string>
#include "Producto.h"
#include "Archivo.h"

class InventarioArchivo: public Archivo {
private:
public:
    // CONSTRUCTOR POR DEFECTO
    InventarioArchivo();
    // CONSTRUCTO POR PARAMETROS
    InventarioArchivo(std::string fileName);

    // METODOS
    void guardarProducto();
    void listarStock();
    void listarProductoID();
    void eliminarProducto();
    void sumarStock();
    void restarStock();
    void modificarPrecioUnitario();

    int getStockPorID(int idProducto);
    float calcularImporteVenta(int idProducto, int cantidadVenta);

    // METODOS RELACIONADOS A REGISTROS
    bool guardarRegistro(Producto producto);
    bool guardarRegistroModificado(int index, Producto producto);
    Producto leerRegistro(int index);
    Producto leerRegistroPorID(int idProducto);
    int buscarRegistro(int idProducto);
    int getCantidadRegistros();
    bool eliminarRegistro(int idProducto);
    bool modificarRegistro(int index, Producto producto);
    bool isExist(int idProducto);

    // MENU
    void menu();
};
