#pragma once
#include <string>

class Clientes{
private:
    // PROPIEDAES
    int _idCliente;
    char _nombreCliente[30];
    char _apellidoCliente[30];
    char _direccionCliente[50];
    int _telefonoCliente;
    bool _estado;
public:
    // CONSTRUCTOR POR DEFECTO
    Clientes();
    // CONSTRUCTOR POR PARAMETROS
    Clientes(int idCliente, std::string nombreCliente, std::string apellidoCliente, std::string direccionCliente, int telefonoCliente, bool estado);

    // SET Y GET
    void setIdCliente(int idCliente);
    int getIdCliente();

    void setNombreCliente(std::string nombreCliente);
    std::string getNombreCliente();

    void setApellidoCliente(std::string apellidoCliente);
    std::string getApellidoCliente();

    void setDireccionCliente(std::string direccionCliente);
    std::string getDireccionCliente();

    void setTelefonoCliente(int telefonoCliente);
    int getTelefonoCliente();

    void setEstado(bool estado);
    bool getEstado();

    // METODOS
    Clientes crearCliente();
    void mostrarCliente(Clientes cliente);
};
