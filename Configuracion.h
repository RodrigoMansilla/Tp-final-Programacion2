#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED


void EstablecerInicioProductos(){
int cant=4;
FILE *fd;
Productos * vecdinamic;
vecdinamic = new Productos [cant];

 //--> pido memoria
if (vecdinamic==NULL){
    cout<<"NO HAY MEMORIA DISPONIBLE PARA CARGAR PRODUCTOS"<<endl;
    return;
    }

vecdinamic[0].setIDproducto(111);
vecdinamic[0].setNombre("Toner");
vecdinamic[0].setTipo(2);
vecdinamic[0].setPrecio(1);
vecdinamic[0].setStock(11);
vecdinamic[0].setEstado(true);

vecdinamic[1].setIDproducto(222);
vecdinamic[1].setNombre("Bandeja");
vecdinamic[1].setTipo(4);
vecdinamic[1].setPrecio(2);
vecdinamic[1].setStock(22);
vecdinamic[1].setEstado(true);

vecdinamic[2].setIDproducto(333);
vecdinamic[2].setNombre("Fusor");
vecdinamic[2].setTipo(3);
vecdinamic[2].setPrecio(3);
vecdinamic[2].setStock(33);
vecdinamic[2].setEstado(true);

vecdinamic[3].setIDproducto(444);
vecdinamic[3].setNombre("T654");
vecdinamic[3].setTipo(1);
vecdinamic[3].setPrecio(4);
vecdinamic[3].setStock(44);
vecdinamic[3].setEstado(true);

fd=fopen("Archivos/Productos.dat","wb");
if (fd==NULL){
    cout<<"ERROR EN ARCHIVO"<<endl;
    return;
}

fwrite(vecdinamic,sizeof(Productos),cant,fd);
delete vecdinamic;
fclose(fd);

}

/**********************/

void EstablecerInicioClientes(){
int cant=4;
FILE *fd;
Clientes * vecdinamic;
vecdinamic = new Clientes [cant];

 //--> pido memoria
if (vecdinamic==NULL){
    cout<<"NO HAY MEMORIA DISPONIBLE PARA CARGAR CLIENTES"<<endl;
    return;
    }

vecdinamic[0].setDNI(11111);
vecdinamic[0].setNombre("Juan");
vecdinamic[0].setApellido("Perez");
vecdinamic[0].setAnioNacimiento(1990);
vecdinamic[0].setTelefono(44441111);
vecdinamic[0].setEstado(true);

vecdinamic[1].setDNI(22222);
vecdinamic[1].setNombre("Pedro");
vecdinamic[1].setApellido("Torres");
vecdinamic[1].setAnioNacimiento(1991);
vecdinamic[1].setTelefono(44442222);
vecdinamic[1].setEstado(true);

vecdinamic[2].setDNI(33333);
vecdinamic[2].setNombre("Luis");
vecdinamic[2].setApellido("Martinez");
vecdinamic[2].setAnioNacimiento(1992);
vecdinamic[2].setTelefono(44443333);
vecdinamic[2].setEstado(true);

vecdinamic[3].setDNI(44444);
vecdinamic[3].setNombre("Ivan");
vecdinamic[3].setApellido("Sanchez");
vecdinamic[3].setAnioNacimiento(1993);
vecdinamic[3].setTelefono(44444444);
vecdinamic[3].setEstado(true);

fd=fopen("Archivos/Clientes.dat","wb");
if (fd==NULL){
    cout<<"ERROR EN ARCHIVO"<<endl;
    return;
}

fwrite(vecdinamic,sizeof(Clientes),cant,fd);
delete vecdinamic;
fclose(fd);

}





/****************************************************************************
*****************************************************************************
****************************************************************************/


void menu_6_1(){
clrscr();
char opc;

cout<<endl<<"DESEA ESTABLECER LOS DATOS DE INICIO? S/N: ";
cin>>opc;
switch (opc){
  case 's':
  case 'S':
    EstablecerInicioProductos();
    EstablecerInicioClientes();
    //EstablecerInicioCompras();
    //EstablecerInicioVentas();
cout<<endl<<"DATOS DE INICIO COMPLETOS"<<endl;
pausa();
break;

  case 'n':
  case 'N':
             return;

default:
        cout<<endl<<" Opcion invalida"<<endl;
        pausa();
        break;

}
}


#endif // CONFIGURACION_H_INCLUDED
