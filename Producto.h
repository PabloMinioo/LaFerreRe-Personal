#pragma once
#include <string>

class Producto{
private:
    // PROPIEDADES
    int _idProducto;
    char _nombreProducto[30];
    int _tipoProducto;
    int _stock;
    float _precioUnitario;
    char _nombreProveedor[20];
    bool _estado;

public:
    // CONSTRUCTOR POR DEFECTO
    Producto();
    // CONSTRUCTOR POR PARAMETROS
    Producto(int idProducto, std::string nombreProducto, int tipoProdcuto, int stock, float precioUnitario, std::string nombreProveedor, bool estado);

    // SET Y GET
    void setIdProducto(int idProducto);
    int getIdProducto();

    void setNombreProducto(std::string nombreProducto);
    std::string getNombreProducto();

    void setTipoProducto(int tipoProducto);
    int getTipoProducto();

    void setStock(int stock);
    int getStock();

    void setPrecioUnitario(float precioUnitario);
    float getPrecioUnitario();

    void setNombreProveedor(std::string nombreProveedor);
    std::string getNombreProveedor();

    void setEstado(bool estado);
    bool getEstado();

    // METODOS
    Producto crearProducto();
    void mostrarProducto(Producto producto);
};
