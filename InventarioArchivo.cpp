#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include "InventarioArchivo.h"
#include "Producto.h"
#include "Archivo.h"
#include "Venta.h"

using namespace std;

/// DESARROLLO DE LOS METODOS DE LA CLASE 'InventarioArchivo'
// CONSTRUCTOR POR DEFECTO
InventarioArchivo::InventarioArchivo() {
    _fileName = "inventario.dat";
}
// CONSTRUCTOR POR PARAMETROS
InventarioArchivo::InventarioArchivo(string fileName) {
    _fileName = fileName;
}

/// METODOS
// CARGA UN PRODUCTO Y LO GUARDA EN EL ARCHIVO
void InventarioArchivo::guardarProducto() {
    Producto producto;
    producto = producto.crearProducto();
    // VALIDACION NUMERO DE ID POSITIVO
    if (producto.getIdProducto() <= 0) {
        cout << endl << "EL PRODUCTO NO SE PUDO GUARDAR. ID DEL PRODUCTO NO VALIDO" << endl;
        return;
    }
    // VALIDACION NUMERO DE ID EXISTENTE
    if (isExist(producto.getIdProducto())) {
        if (producto.getEstado() == false) {
            cout << endl << "EL PRODUCTO NO SE PUDO GUARDAR. ID DEL PRODUCTO EXISTENTE PERO DADO DE BAJA" << endl;
            return;
        } else {
            cout << endl << "EL PRODUCTO NO SE PUDO GUARDAR. ID DEL PRODUCTO EXISTENTE" << endl;
            return;
        }
    }
    // VALIDACION TIPO DE PRODUCTO
    if (producto.getTipoProducto() < 1 || producto.getTipoProducto() > 10) {
        cout << endl << "EL PRODUCTO NO SE PUDO GUARDAR. TIPO DE PRODUCTO NO VALIDO" << endl;
        return;
    }
    // VALIDACION STOCK
    if (producto.getStock() < 0) {
        cout << endl << "EL PRODUCTO NO SE PUDO GUARDAR. CANTIDAD DE STOCK NO VALIDO" << endl;
        return;
    }
    // VALIDACION PRECIO UNITARIO
    if (producto.getPrecioUnitario() < 0) {
        cout << endl << "EL PRODUCTO NO SE PUDO GUARDAR. PRECIO UNITARIO NO VALIDO" << endl;
        return;
    }
    if(guardarRegistro(producto)) {
        cout << endl << "EL PRODUCTO FUE GUARDADO CON EXITO" << endl;
    } else {
        cout << endl << "EL PRODUCTO NO SE PUDO GUARDAR" << endl;
    }
}
// LISTA TODOS LOS PRODUCTOS QUE TENGAN 'ESTADO DISPONIBLE'
void InventarioArchivo::listarStock() {
    int cantidad = getCantidadRegistros();
    for (int i = 0; i < cantidad; i++) {
        Producto producto = leerRegistro(i);
        if (producto.getEstado()) {
            cout << "**************************" << endl;
            producto.mostrarProducto(producto);
            cout << "**************************" << endl;
        }
    }
}
// SE INDICA EL NUMERO ID DEL PRODUCTO Y LO MUESTRA POR PANTALLA
void InventarioArchivo::listarProductoID() {
    int index, idProducto;
    Producto producto;
    cout << "INGRESE EL NUMERO ID DEL PRODUCTO A BUSCAR: ";
    cin >> idProducto;
    index = buscarRegistro(idProducto);
    if (index >= 0) {
        cout << "**************************" << endl;
        producto = leerRegistro(index);
        producto.mostrarProducto(producto);
        cout << "**************************" << endl;
    } else {
        cout << "EL NUMERO ID DEL PRODUCTO NO EXISTE" << endl;
    }
}
// SE INDICA EL NUMERO ID DEL PRODUCTO Y LE REALIZA UNA BAJA LOGICA
void InventarioArchivo::eliminarProducto() {
    int idProducto, indice;
    cout << "INGRESAR EL NUMERO ID DEL PRODUCTO QUE SE DESEA ELIMINAR: ";
    cin >> idProducto;
    indice = buscarRegistro(idProducto);
    if (indice != -1) {
        Producto producto = leerRegistro(indice);
        producto.mostrarProducto(producto);
        bool eliminarProducto;
        cout << endl << "DESEA ELIMINAR EL PRODUCTO ELEGIDO? (1- SI || 0-NO): ";
        cin >> eliminarProducto;
        if (eliminarProducto) {
            if (eliminarRegistro(idProducto)) {
                cout << endl << "EL PRODUCTO SE ELIMINO CORRECTAMENTE" << endl;
            } else {
                cout << endl << "NO SE PUDO ELIMINAR EL PRODUCTO" << endl;
            }
        } else {
            cout << endl << "LA OPERACION FUE CANCELADA" << endl;
        }
    } else {
        cout << endl << "EL NUMERO ID INGRESADO NO EXISTE" << endl;
    }
}
// SE INDICA UN NUMERO ID DE PRODCUTO Y SE LE AGREGA STOCK
void InventarioArchivo::sumarStock(){
    Producto producto;
    int idProducto, index, cantidadStock, nuevoStock = 0;
    cout << "INGRESE EL ID DEL PRODUCTO QUE DESEA MODIFICAR: ";
    cin >> idProducto;
    index = buscarRegistro(idProducto);
    if (index != -1){
        producto = leerRegistro(index);
        cout << "------------------------------------------" << endl;
        cout << "CANTIDAD DE STOCK ANTIGUA: " << producto.getStock() << endl;
        cout << "------------------------------------------" << endl;
        cout << "INGRESE LA CANTIDAD DE STOCK QUE DESEA AGREGAR: ";
        cin >> cantidadStock;
        if (cantidadStock > 0){
            nuevoStock += producto.getStock() + cantidadStock;
            producto.setStock(nuevoStock);
            cout << "------------------------------------------" << endl;
            cout << "LA CANTIDAD DE STOCK SE MODIFICO CON EXITO" << endl;
            modificarRegistro(index, producto);
            producto.mostrarProducto(producto);
        } else {
            cout << endl << "NO SE MODIFICO LA CANTIDAD DE STOCK. VALOR NO VALIDO" << endl;
        }
    } else {
        cout << endl << "EL NUMERO ID INGRESADO NO EXISTE " << endl;
    }
}
// MODIFICA EL PRECIO UNITARIO DEL PRODUCTO
void InventarioArchivo::modificarPrecioUnitario() {
    Producto producto;
    int idProducto, index;
    float nuevoPrecioUnitario;
    cout << "INGRESE EL ID DEL PRODUCTO QUE DESEA MODIFICAR: ";
    cin >> idProducto;
    index = buscarRegistro(idProducto);
    if (index != 1) {
        producto = leerRegistro(index);
        cout << "------------------------------------------" << endl;
        cout << "PRECIO UNITARIO ANTIGUO: " << producto.getPrecioUnitario() << endl;
        cout << "------------------------------------------" << endl;
        cout << endl << "INGRESE EL NUEVO PRECIO UNITARIO: ";
        cin >> nuevoPrecioUnitario;
        producto.setPrecioUnitario(nuevoPrecioUnitario);
        if (nuevoPrecioUnitario > 0) {
            cout << "------------------------------------------" << endl;
            cout << "EL PRECIO UNITARIO SE MODIFICO CON EXITO" << endl;
            modificarRegistro(index, producto);
            producto.mostrarProducto(producto);
        } else {
            cout << endl << "NO SE MODIFICO EL PRECIO UNITARIO. VALOR NO VALIDO" << endl;
        }
    } else {
        cout << endl << "EL NUMERO ID INGRESADO NO EXISTE " << endl;
    }
}
// RECIBE POR PARAMETRO EL NUMERO ID DE PRODUCTO Y LA CANTIDAD DE PRODUCTO VENDIDO. RESTA EL STOCK DEL PRODUCTO
void InventarioArchivo::restarStock(int idProducto, int cantidadVenta){
    Producto producto;
    int index = buscarRegistro(idProducto);
    int stockNuevo;
    if (index != -1){
        producto = leerRegistro(index);
        stockNuevo = producto.getStock() - cantidadVenta;
        producto.setStock(stockNuevo);
        modificarRegistro(index, producto);
    }
}
// RECIBE UN NUMERO ID DE PRODUCTO Y LA CANTIDAD DE PRODUCTO A VENDER. CALCULA EL IMPORTE DE LA VENTA
float InventarioArchivo::calcularImporteVenta(int idProducto, int cantidadVenta) {
    Producto producto;
    int index = buscarRegistro(idProducto);
    float importeTotal = 0;
    if (index != -1) {
        producto = leerRegistro(index);
        if (producto.getEstado() == false) {
            cout << "PRODUCTO NO DISPONIBLE" << endl;
            return -1;
        } else {
            importeTotal = producto.getPrecioUnitario() * cantidadVenta;
        }
    }
    return importeTotal;
}
// RECIBE UN NUMERO ID DE PRODUCTO Y DEVUELVE LA CANTIDAD DE STOCK
int InventarioArchivo::getStockPorID(int idProducto) {
    Producto producto;
    int index = buscarRegistro(idProducto);
    if (index != -1) {
        producto = leerRegistro(index);
        if (producto.getEstado() == false) {
            cout << "PRODUCTO NO DISPONIBLE" << endl;
            return -1;
        }
        return producto.getStock();
    }
}

/// METODOS RELACIONADOS A REGISTROS
// RECIBE UN OBJETO TIPO PRODUCTO Y LO GUARDA EN EL ARCHIVO
bool InventarioArchivo::guardarRegistro(Producto producto) {
    int grabo;
    if (abrir("ab") == false) {
        return false;
    }
    grabo = fwrite(&producto, sizeof (Producto), 1, _pFile);
    cerrar();
    return grabo;
}
// RECIBE UNA POSICION Y UN OBJETO PRODUCTO Y GUARDA EN EL ARCHIVO LOS CAMBIOS REALIZADOS
bool InventarioArchivo::guardarRegistroModificado(int index, Producto producto) {
    int grabo;
    if (abrir("rb+") == false) {
        return false;
    }
    fseek(_pFile, index * sizeof(Producto), SEEK_SET);
    grabo = fwrite(&producto, sizeof (Producto), 1, _pFile);
    cerrar();
    return grabo;
}
// RECIBE UNA POSICION Y LEE EL REGISTRO DE DICHA POSICION
Producto InventarioArchivo::leerRegistro(int index) {
    Producto producto;
    if (abrir("rb") == false) {
        return producto;
    }
    fseek(_pFile, index * sizeof(Producto), SEEK_SET);
    fread(&producto, sizeof(Producto), 1, _pFile);
    cerrar();
    return producto;
}
// RECIBE EL ID DEL PRODUCTO Y DEVUELVE SU POSICION EN EL ARCHIVO
int InventarioArchivo::buscarRegistro(int idProducto) {
    int index = 0;
    Producto producto;
    if (abrir("rb+") == false) {
        return -1;
    }
    while (fread(&producto, sizeof(Producto), 1, _pFile)) {
        if (producto.getIdProducto() == idProducto) {
            break;
        }
        index++;
    }
    cerrar();
    if(producto.getIdProducto() == idProducto) {
        return index;
    } else {
        return -1;
    }
}
// DEVUELVE LA CANTIDAD DE REGISTROS DEL ARCHIVO
int InventarioArchivo::getCantidadRegistros() {
    if (abrir("rb") == false) {
        return 0;
    }
    fseek(_pFile, 0, SEEK_END);
    int tamanio = ftell(_pFile);
    cerrar();
    return tamanio / sizeof(Producto);
}
// RECIBE EL ID DEL PRODUCTO Y LE REALIZA UNA BAJA LOGICA
bool InventarioArchivo::eliminarRegistro(int idProducto) {
    int index;
    Producto producto;
    index = buscarRegistro(idProducto);
    producto = leerRegistro(index);
    producto.setEstado(0);
    return guardarRegistroModificado(index, producto);
}
// RECIBE UNA POSICION Y UN OBJETO PRODUCTO Y LO MODIFICA
bool InventarioArchivo::modificarRegistro(int index, Producto producto) {
    int modifico;
    if (abrir("rb+") == false) {
        return false;
    }
    fseek(_pFile, index * sizeof(Producto), SEEK_SET);
    modifico = fwrite(&producto, sizeof(Producto), 1, _pFile);
    cerrar();
    return modifico;
}
// RECIBE EL ID DEL PRODUCTO Y VERIFICA SI EXISTE
bool InventarioArchivo::isExist(int idProducto) {
    return buscarRegistro(idProducto) != -1;
}
// MENU DEL INVENTARIO DE LA FERRETERIA
void InventarioArchivo::menu() {
    int opcion;
    do {
        system("cls");
        cout << "--------- MENU INVENTARIO -------" << endl;
        cout << "-------------------------------" << endl;
        cout << "1- CARGAR PRODUCTO  " << endl;
        cout << "2- LISTAR PRODUCTO POR ID  " << endl;
        cout << "3- LISTAR INVENTARIO" << endl;
        cout << "4- ELIMINAR PRODUCTO" << endl;
        cout << "5- MODIFICAR PRECIO UNITARIO " << endl;
        cout << "6- AGREGAR STOCK " << endl;
        cout << "-------------------------------" << endl;
        cout << "0- VOLVER AL MENU PRINCIPAL " << endl;
        cout << "-------------------------------" << endl;
        cout << "INGRESE LA OPCION: ";
        cin >> opcion;
        switch(opcion) {
        case 1:
            system("cls");
            guardarProducto();
            break;
        case 2:
            system("cls");
            listarProductoID();
            break;
        case 3:
            system("cls");
            listarStock();
            break;
        case 4:
            system("cls");
            eliminarProducto();
            break;
        case 5:
            system("cls");
            modificarPrecioUnitario();
            break;
        case 6:
            system("cls");
            sumarStock();
            break;
        case 0:
            return;
        default:
            system("cls");
            cout<< "OPCION INVALIDA, INGRESE NUEVAMENTE"<<endl;
        }
        system("pause");
    } while(opcion != 0);
}
