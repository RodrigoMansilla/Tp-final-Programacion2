#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED


/********* Cargar Producto **********/
bool Productos::Cargar(){
clrscr();
int est;
cout<<"ID de producto: ";
cin>>IDproducto;
if(IDproducto<=0) return false;

if(existeProducto(IDproducto)){
    cout<<endl<<endl<<"El ID de producto ya existe";
    return false;
}

cin.ignore();
cout<<"Nombre: ";
cin.getline(nombre, 30);
cout<<"Tipo: 1)Equipo - 2)Insumo - 3)Parte - 4)Accesorio"<<endl;
cout<<"Opcion: ";
cin>>tipo;

if(tipo<1||tipo>4){
    cout<<"Tipo invalido"<<endl;
    return false;
}

cout<<"Precio: ";
cin>>precio;
if(precio<1){
        cout<<"Valor invalido"<<endl;
        return false;
}
cout<<"Stock: ";
cin>>stock;
if(stock<0) return false;

cout<<"Estado: 0) Inactivo | 1) Activo): ";
cin>>est;
switch(est){
case 1:
       estado=true;
       return true;
       break;
case 0:
    estado=false;
    return true;
    break;
default:
    cout<<"Estado invalido";
    return false;
    break;
}
//return true;
}

//*****************************************************************

/********* Grabar o modificar en Disco **********/
void Productos::grabarDisco(int pos){

FILE *p;
if(pos >= 0){
    //MODIFICACION
p = fopen("Archivos/Productos.dat", "rb+");
    if (p == NULL) exit(1);
    fseek(p, pos*sizeof *this, SEEK_SET); // ????????????????????????????????????????
}
else{ //Entra acà cuando la funcion Guardar producto envía -1
    //ALTA
    p = fopen("Archivos/Productos.dat", "ab");
    if (p == NULL) exit(1);

    fseek(p, 0, SEEK_END);
}
  fwrite(this, sizeof *this, 1, p);
  fclose(p);
  return;
}

//*****************************************************************

/********* Mostrar producto **********/
void Productos::Mostrar(int est,int posdetalle){
gotoxy(6,posdetalle); cout<<IDproducto;
gotoxy(17,posdetalle); cout<<nombre;
if(tipo==1) { gotoxy(48,posdetalle); cout<<"Impresora"; }
if(tipo==2) { gotoxy(48,posdetalle); cout<<"Insumo"; }
if(tipo==3) { gotoxy(48,posdetalle); cout<<"Parte"; }
if(tipo==4) { gotoxy(48,posdetalle); cout<<"Accesorio"; }
gotoxy(64,posdetalle); cout<<precio;
gotoxy(74,posdetalle); cout<<stock;
if(est>=0){
if(estado==1) { gotoxy(84,posdetalle); cout<<"Activo"; }
if(estado==0) { gotoxy(84,posdetalle); cout<<"Inactivo"; }
}
}


/*************** Leer Disco **************/

int Productos::leerDisco(int pos){
int x;
FILE *p;
p = fopen("Archivos/Productos.dat", "rb");
if (p==NULL){
    /*cout << "No hay productos cargados";
    pausa();*/
    return 0;
}
    fseek(p,pos*sizeof *this,0);
    x=fread(this, sizeof *this, 1, p);
    fclose(p);
    return x;
}

/************* Existe Producto? ************/

bool existeProducto(int id){
int pos=0;
pos=buscarProducto(id);
if(pos!=-1){
return true;
}
return false;
}


/************* Buscar Producto ************/

int buscarProducto(int id){
int pos=0;
Productos obj;
while(obj.leerDisco(pos)==1){
    if(obj.getIDproducto()==id) return pos;
    pos++;
}
return -1;
}


/********* contador de productos activos **********/

int ContarProductosActivos(){
int pos=0,tam=0, est;
Productos obj;

while(obj.leerDisco(pos)){
    est=obj.getEstado();
        if(est==true) tam++;
        pos++;
}

/*
FILE *p;
p = fopen("Archivos/Productos.dat", "rb");
    if (p == NULL){
    return 1;
    }
fseek(p, 0, SEEK_END);
tam=ftell(p);
cont=tam/sizeof(Productos);
fclose(p);
*/

return tam;
}


/****************************************************************************
*****************************************************************************
****************************************************************************/

/***************** Nuevo producto ****************/
void menu_1_1(){
clrscr();

Productos obj;

if(obj.Cargar()){
    obj.grabarDisco(-1);
    cout<<endl<<"Producto cargado correctamente";
    volver();
    return;
}
else{
    cout<<endl<<"No se pudo cargar producto";
    volver();
    return;
}
}

/***************** Mostrar todos los productos ****************/

void menu_1_5(){
clrscr();
int pos=0, posdetalle=8;
bool est;
Productos obj;

textcolor(0,0);
cuadroProductos2();
textcolor(cNEGRO,cBLANCO);

    while(obj.leerDisco(pos)==1){
        est=obj.getEstado();
        if(est==true) {
            obj.Mostrar(-1,posdetalle);
            posdetalle++;
        }
    pos++;
    }
pausa();
}

/***************** Modificar Producto ****************/

void menu_1_2(){
clrscr();
int id, pos=0,opc, IDproductoN, tipoN, precioN,posdetalle=8;
char nombreN[30];

Productos obj;
cout<<"Ingrese ID de producto a modificar: ";
cin>>id;
pos=buscarProducto(id);

if(pos!=-1){
obj.leerDisco(pos);

if(obj.getEstado()==false){
    cout<<"El producto se encuentra eliminado, no es posible modificarlo"<<endl;
    textcolor(cVERDE, cBLANCO);
    cout<<"Pulse ENTER para volver";
    pausa();
    return;
}
cuadroProductos3();
textcolor(cNEGRO,cBLANCO);
obj.Mostrar(1,posdetalle); // Muestro los datos que tiene el registro
cout<<endl<<endl<<endl<<"Que desea modificar?"<<endl;
cout<<"1) ID de producto"<<endl;
cout<<"2) Nombre"<<endl;
cout<<"3) Tipo"<<endl;
cout<<"4) Precio"<<endl;
cout<<"0) Volver"<<endl;

while(true){
cout<<"Opcion: ";
cin>>opc;

switch(opc){
    case 1:
    cout<<"Ingrese nuevo ID: ";
    cin>>IDproductoN;

    if(IDproductoN<1){
            cout<<endl<<"Valor invalido";
    }

    if(existeProducto(IDproductoN)){
    cout<<endl<<endl<<"El ID de producto ya existe";
    pausa();
    return;
    }

    obj.leerDisco(pos); // Carga todos los datos que tiene la clase en la posicion pos
    obj.setIDproducto(IDproductoN); // reemplaza el valor
    obj.grabarDisco(pos); // lo guarda
    cout<<endl<<"Modificacion con exito!";
    volver();
    return;
    //--------------------
    case 2:
    cout<<"Ingrese nombre nuevo: ";
    cin.ignore();
    cin.getline(nombreN,30);
    obj.leerDisco(pos); /**/ obj.setNombre(nombreN); /**/ obj.grabarDisco(pos);
    cout<<endl<<"Modificacion con exito!";
    volver();
    return;
    //--------------------
    case 3:
    cout<<"Ingrese nuevo tipo: "<<endl;
    cout<<"1) Impresora | 2) Insumo | 3) Parte | 4) Accesorio"<<endl;
    cout<<"Opcion: ";
    cin>>tipoN;
    if((tipoN<1) || (tipoN>4)){
        cout<<"Ocpion incorrecta"<<endl;
        cout<<"No se pudo modificar tipo";
        return;
    }
    obj.leerDisco(pos); /**/ obj.setTipo(tipoN); /**/ obj.grabarDisco(pos);
    cout<<endl<<"Modificacion con exito!";
    volver();
    return;
    //--------------------
    case 4:
    cout<<"Ingrese nuevo precio: ";
    cin>>precioN;
    if(precioN<1){
        cout<<"Precio invalido"<<endl;
        cout<<"No se pudo modificar precio";
        return;
    }
    obj.leerDisco(pos); /**/ obj.setPrecio(precioN); /**/ obj.grabarDisco(pos);
    cout<<endl<<"Modificacion con exito!";
    volver();
    return;
    //--------------------
    case 0: return;
    //--------------------
    /*default:
    cout<<"* OPCION INCORRECTA *";
    pausa();
    break;*/
}
}
}
else{
    cout<<endl<<"No existe ID de producto";
    volver();
    return;
}
}

/***************** Eliminar Producto ****************/


void menu_1_3(){
clrscr();
Productos obj;
int id, pos,posdetalle=8;
char opc;
bool est;
textcolor(0,0);
cuadroProductos();
textcolor(cNEGRO,cBLANCO);
gotoxy(6,8); cin>>id;

pos=buscarProducto(id);
if(pos!=-1){
obj.leerDisco(pos);

est=obj.getEstado(); //guardo en est el estado de ese dato
if(est==false){ // Verifica si ya estaba eliminado
        textcolor(cROJO_CLARO,cBLANCO);
        gotoxy(22,15);
        cout<<"El producto ya se encuentra eliminado";
        textcolor(cVERDE, cBLANCO);
        gotoxy(22,16); cout<<"Pulse ENTER para volver";
        pausa();
        return;
}
obj.Mostrar(1,posdetalle);

gotoxy(22,15); cout<<"Confirmar (S/N): ";
gotoxy(39,15); cin>>opc;

switch (opc){
    case 's':
    case 'S':
      obj.setEstado(0);
      obj.grabarDisco(pos); // Se envia pos, en ves de -1 por que es una modificacion
      textcolor(cVERDE, cBLANCO);
      gotoxy(22,16); cout<<"Producto Eliminado";
      textcolor(cVERDE, cBLANCO);
      gotoxy(22,17); cout<<"Pulse ENTER para volver";
      pausa();
      return;
    break;
    case 'n':
    case 'N':
    textcolor(cROJO_CLARO,cBLANCO);
    gotoxy(22,16); cout<<"Solicitud anulada";
    textcolor(cVERDE, cBLANCO);
    gotoxy(22,17); cout<<"Pulse ENTER para volver";
    pausa();
    return;
    break;
    default:
    textcolor(cROJO_CLARO,cBLANCO);
    gotoxy(22,16); cout<<"* OPCION INCORRECTA *";
    pausa();
    return;
    break;

}
//
}
textcolor(cROJO_CLARO,cBLANCO);
gotoxy(22,15); cout<<"No se encontro producto";
textcolor(cVERDE, cBLANCO);
gotoxy(22,16); cout<<"Pulse ENTER para volver";
pausa();
return;
}

/***************** Activar Producto ****************/

void menu_1_6(){
clrscr();
Productos obj;
int id, pos,posdetalle=8;
char opc;
bool est;
textcolor(0,0);
cuadroProductos();
textcolor(cNEGRO,cBLANCO);
gotoxy(6,8); cin>>id;

pos=buscarProducto(id);
if(pos!=-1){
obj.leerDisco(pos);

est=obj.getEstado(); //guardo en est el estado de ese dato
if(est==true){ // Verifica si ya estaba eliminado
        textcolor(cROJO_CLARO,cBLANCO);
        gotoxy(22,15);
        cout<<"El producto ya se encuentra activo";
        textcolor(cVERDE, cBLANCO);
        gotoxy(22,16); cout<<"Pulse ENTER para volver";
        pausa();
        return;
}
obj.Mostrar(1,posdetalle);

gotoxy(22,15); cout<<"Confirmar (S/N): ";
gotoxy(39,15); cin>>opc;

switch (opc){
    case 's':
    case 'S':
      obj.setEstado(1);
      obj.grabarDisco(pos); // Se envia pos, en ves de -1 por que es una modificacion
      textcolor(cVERDE, cBLANCO);
      gotoxy(22,16); cout<<"Producto Activado";
      textcolor(cVERDE, cBLANCO);
      gotoxy(22,17); cout<<"Pulse ENTER para volver";
      pausa();
      return;
    break;
    case 'n':
    case 'N':
    textcolor(cROJO_CLARO,cBLANCO);
    gotoxy(22,16); cout<<"Solicitud anulada";
    textcolor(cVERDE, cBLANCO);
    gotoxy(22,17); cout<<"Pulse ENTER para volver";
    pausa();
    return;
    break;
    default:
    textcolor(cROJO_CLARO,cBLANCO);
    gotoxy(22,16); cout<<"* OPCION INCORRECTA *";
    pausa();
    return;
    break;

}
//
}
textcolor(cROJO_CLARO,cBLANCO);
gotoxy(22,15); cout<<"No se encontro producto";
textcolor(cVERDE, cBLANCO);
gotoxy(22,16); cout<<"Pulse ENTER para volver";
pausa();
return;
}


/***************** Mostrar Producto ****************/


void menu_1_4(){
clrscr();
Productos obj;
int id, pos=0,posdetalle=8;
textcolor(0,0);
cuadroProductos();
textcolor(cNEGRO,cBLANCO);
gotoxy(6,8); cin>>id;
//
while(obj.leerDisco(pos)==1){
if(obj.getIDproducto()==id){
    obj.Mostrar(1,posdetalle);
    textcolor(cVERDE, cBLANCO);
    gotoxy(22,15); cout<<"Pulse ENTER para volver";
    pausa();
    return;
}
pos++;
}
//
textcolor(cROJO_CLARO,cBLANCO);
gotoxy(22,15); cout<<"No se encontro producto";
textcolor(cVERDE, cBLANCO);
gotoxy(22,16); cout<<"Pulse ENTER para volver";
pausa();
return;

}
#endif // PRODUCTOS_H_INCLUDED
