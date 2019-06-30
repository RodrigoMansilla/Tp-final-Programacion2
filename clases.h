#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED

int buscarProducto(int);
int buscarCliente(int);
int buscarCompra(int);
bool cargarProductoNoReg(int);
char *obtenerNombre(int);
//
bool altaDetalleCompra(int);
float obtenerImporteC(int);
void agregarStock(int, int);
bool existeProducto(int);
bool existeCliente(int);
//
bool altaDetalleVenta(int);
float obtenerImporteV(int);
int obtenerStock(int);

void quitarStock(int, int);

int ContarRegistrosVentas();
int ContarRegistrosCompras();
//int ContarProductos();

/****************************/
/*
class Fecha{
  private:
    int dia;
    int mes;
    int anio;
    //bool esbisiesto(int);
    //void NumeroSerieaFecha(int);
  public:
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}
    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;};
    void setAnio(int a){anio=a;}
    void MostrarFecha();
};

*/
/****************************/

class Productos{
private:
int IDproducto;
char nombre[15];
int tipo; //1) Impresora - 2) Insumo - 3) Parte"
float precio;
int stock;
bool estado;
//
public:
bool Cargar();
void Mostrar(int,int);
void grabarDisco(int);
int leerDisco(int);

int getIDproducto(){return IDproducto;}
bool getEstado(){return estado;}
void setNombre(char *nombreN){strcpy(nombre,nombreN);}
char *getNombre(){return nombre;}
void setIDproducto(int IDproductoN){IDproducto=IDproductoN;}
void setTipo(int tipoN){tipo=tipoN;}
void setPrecio(float precioN){precio=precioN;}
void setEstado(bool estadoN){estado=estadoN;}
float getPrecio(){return precio;}
int getStock(){return stock;}
void setStock(int stockN){stock=stockN;}
};

/****************************/

class Clientes{
private:
int DNI;
char nombre[30];
char apellido[30];
int anioNacimiento;
int telefono;
// fechaprimera compra
bool estado;
public:
bool Cargar();
void Mostrar(int);
void Mostrarenremito(); // solo sirve para mostrar en el remito un detalle breve del cliente
void grabarDisco(int);
int leerDisco(int);


bool getEstado(){return estado;}
void setNombre(char *nombreN){strcpy(nombre,nombreN);}
char *getNombre(){return nombre;}
void setApellido(char *apellidoN){strcpy(apellido,apellidoN);}
char *getApellido(){return apellido;}
void setDNI(int DNIN){DNI=DNIN;}
int getDNI(){return DNI;}
void setAnioNacimiento(int anioNacimientoN){anioNacimiento=anioNacimientoN;}
int getAnioNacimiento(){return anioNacimiento;}
void setTelefono(int telefonoN){telefono=telefonoN;}
int getTelefono(){return telefono;}
void setEstado(bool estadoN){estado=estadoN;}

};

/****************************/

class Compras{
private:
int IDcompra;
//Fecha fecha_compra;
char nombreProveedor[30];
float importeTotal;
Fecha fechacompra;
public:
int getIDcompra(){return IDcompra;}
bool Cargar();
void Mostrar(int);
void MostrarEnRemito();
void grabarDisco(int);
int leerDisco(int);
float getimporteTotal(){return importeTotal;}
void setimporteTotal(float importeTotalN){importeTotal=importeTotalN;}

//

int getDia(){return fechacompra.getDia();}
int getMes(){return fechacompra.getMes();}
int getAnio(){return fechacompra.getAnio();}
void setDia(int d){fechacompra.setDia(d);}
void setMes(int m){fechacompra.setMes(m);};
void setAnio(int a){fechacompra.setAnio(a);}

};

/****************************/

class Detalle_Compras{
private:
int IDcompra;
int IDproducto;
float precioUnitario;
int cantidad;
float importeCompra;
public:
int Cargar(int);
void Mostrar(int);
void grabarDisco(int);
int leerDisco(int);
void setIDcompra(int IDcompraN){IDcompra=IDcompraN;}
int getIDcompra(){return IDcompra;}
int getCantidad(){return cantidad;}
float getPrecio(){return precioUnitario;}
int getIDproducto(){return IDproducto;}
float getimporteCompra(){return importeCompra;}
};

/****************************/

class Ventas{
private:
int IDventa;
int DNIcliente;
float importeTotal;
int formaPago;
Fecha fechaventa;

public:
bool Cargar();
void Mostrar(int);
void MostrarEnRemito(); // muestra los datos generales de la venta, no el detalle
void grabarDisco(int);
int leerDisco(int);
float getimporteTotal(){return importeTotal;}
void setimporteTotal(float importeTotalN){importeTotal=importeTotalN;}
int getIDventa(){return IDventa;}
//Fecha getFecha(){return fechaventa;}
//void setFecha_venta(Fecha f){fechaventa=f;}

int getDia(){return fechaventa.getDia();}
int getMes(){return fechaventa.getMes();}
int getAnio(){return fechaventa.getAnio();}
void setDia(int d){fechaventa.setDia(d);}
void setMes(int m){fechaventa.setMes(m);};
void setAnio(int a){fechaventa.setAnio(a);}

//float getgananciaTotal(){return gananciaTotal;}
};
/****************************/
class Detalle_Ventas{
private:
int IDventa;
int IDproducto;
float precioUnitario;
float importeVenta;
int cantidad;

public:
int Cargar(int);
void Mostrar(int);
void grabarDisco(int);
int leerDisco(int);
void setIDventa(int IDventaN){IDventa=IDventaN;}
int getIDventa(){return IDventa;}
int getCantidad(){return cantidad;}
float getPrecio(){return precioUnitario;}
float getimporteVenta(){return importeVenta;}
int getIDproducto(){return IDproducto;}

};




/****************************/


#endif // CLASES_H_INCLUDED
