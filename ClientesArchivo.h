#pragma once
#include <string>
#include "Clientes.h"
#include "Archivo.h"


class ClientesArchivo: public Archivo{
public:
    // CONSTRUCTOR POR DEFECTO
    ClientesArchivo();
    // CONSTRUCTOR POR PARAMETROS
    ClientesArchivo(std::string fileName);

    // METODOS
    void guardarCliente();
    void listarCliente();
    void listarClienteID();
    void eliminarCliente();

    // METODOS RELACIONADOS A LOS REGISTROS
    bool guardarRegistro(Clientes cliente);
    bool guardarRegistroModificado(int index, Clientes cliente);
    Clientes leerRegistro(int idCliente);
    int buscarRegistro(int idCliente);
    int getCantidadRegistros();
    bool eliminarRegistro(int idCliente);
    bool modificarRegistro(int index, Clientes cliente);
    bool isExist(int idCliente);
};
