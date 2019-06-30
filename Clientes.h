#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

/********* Cargar Cliente **********/
bool Clientes::Cargar(){
clrscr();
int est;
cout<<"Ingrese DNI de cliente: ";
cin>>DNI;
if(DNI<=0) return false;

if(existeCliente(DNI)){
    cout<<endl<<endl<<"El DNI ya existe";
    return false;
}

cin.ignore();
cout<<"Nombre: ";
cin.getline(nombre, 30);
cout<<"Apellido: ";
cin.getline(apellido, 30);

cout<<"Anio de nacimiento: ";
cin>>anioNacimiento;
if((anioNacimiento<1900)||(anioNacimiento>2016)) return false;
cout<<"Telefono: ";
cin>>telefono;
if(telefono<1) return false;

//??

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

/********* Grabar o modificar en Disco **********/
void Clientes::grabarDisco(int pos){

FILE *p;
if(pos >= 0){
    //MODIFICACION
p = fopen("Archivos/Clientes.dat", "rb+");
    if (p == NULL) exit(1);
    fseek(p, pos*sizeof *this, SEEK_SET); // ????????????????????????????????????????
}
else{ //Entra acà cuando la funcion Guardar producto envía -1
    //ALTA
    p = fopen("Archivos/Clientes.dat", "ab");
    if (p == NULL) exit(1);

    fseek(p, 0, SEEK_END);
}
  fwrite(this, sizeof *this, 1, p);
  fclose(p);
  return;
}

/********* Mostrar cliente **********/
void Clientes::Mostrar(int est){
cout<<endl;
cout<<"DNI Cliente: "<<DNI<<endl;
cout<<"Nombre: "<<nombre<<endl;
cout<<"Apellido: "<<apellido<<endl;
cout<<"Anio de Nac.: "<<anioNacimiento<<endl;
cout<<"Telefono: "<<telefono<<endl;
//
if(est>=0){
cout<<"Estado: ";
if(estado==1) cout<<"Activo";
if(estado==0) cout<<"Inactivo";
cout<<endl<<endl;
/**si se recibe en "est" un 1 es porque quiero mostrar ESTADO, si se recibe un -1, no quiero mostrarlo **/
}
}

/*************** Leer Disco **************/

int Clientes::leerDisco(int pos){
int x;
FILE *p;
p = fopen("Archivos/Clientes.dat", "rb");
if (p==NULL){
    cout << "No hay clientes cargados";
    pausa();
    return 0;
}
    fseek(p,pos*sizeof *this,0);
    x=fread(this, sizeof *this, 1, p);
    fclose(p);
    return x;
}

/************* Buscar cliente ************/

int buscarCliente(int id){
int pos=0;
Clientes obj;
while(obj.leerDisco(pos)==1){
    if(obj.getDNI()==id) return pos;
    pos++;
}
return -1;
}

/************* Existe cliente ************/

bool existeCliente(int id){
int pos=0;
pos=buscarCliente(id);
if(pos!=-1){
return true;
}
return false;
}




/****************************************************************************
*****************************************************************************
****************************************************************************/

/***************** Nuevo cliente ****************/

void menu_2_1(){
clrscr();
Clientes obj;
if(obj.Cargar()){
    obj.grabarDisco(-1);
    cout<<endl<<"Cliente cargado correctamente";
    volver();
    return;
}
else{
    cout<<endl<<"No se pudo cargar cliente";
    volver();
    return;
}
}

/***************** Modificar cliente ****************/

void menu_2_2(){
clrscr();
int id, pos=0,opc, DNIN;
char nombreN[30], apellidoN[30];

Clientes obj;
cout<<"Ingrese DNI del cliente: ";
cin>>id;
pos=buscarCliente(id);

if(pos!=-1){
obj.leerDisco(pos);
obj.Mostrar(1); // Muestro los datos que tiene el registro
cout<<"Que desea modificar?"<<endl;
cout<<"1) DNI"<<endl;
cout<<"2) Nombre"<<endl;
cout<<"3) Apellido"<<endl;
cout<<"0) Volver"<<endl;

while(true){
cout<<"Opcion: ";
cin>>opc;

switch(opc){
    case 1:
    cout<<"Ingrese nuevo DNI: ";
    cin>>DNIN;
    if(DNIN<1){
            cout<<endl<<"Valor invalido";
    }

    if(existeCliente(DNIN)){
    cout<<endl<<endl<<"El DNI ingresado ya existe";
    pausa();
    return;
    }


    obj.leerDisco(pos); // Carga todos los datos que tiene la clase en la posicion pos
    obj.setDNI(DNIN); // reemplaza el valor
    obj.grabarDisco(pos); // lo guarda
    cout<<"Modificacion con exito"<<endl;
    pausa();
    return;
    //--------------------
    case 2:
    cout<<"Ingrese nombre nuevo: ";
    cin.ignore();
    cin.getline(nombreN,30);
    obj.leerDisco(pos); /**/ obj.setNombre(nombreN); /**/ obj.grabarDisco(pos);
    cout<<"Modificacion con exito"<<endl;
    pausa();
    return;
    //--------------------
    case 3:
    cout<<"Ingrese apellido nuevo: ";
    cin.ignore();
    cin.getline(apellidoN,30);
    obj.leerDisco(pos); /**/ obj.setApellido(apellidoN); /**/ obj.grabarDisco(pos);
    cout<<"Modificacion con exito"<<endl;
    pausa();
    return;
    //--------------------
    case 0: return;
    //--------------------
    /*default:
    cout<<"* OPCION INCORRECTA *"<<endl;
    pausa();
    break;*/
}
}
}
else{
    cout<<"DNI de cliente no registrado";
    pausa();
}
}

/***************** Eliminar Cliente ****************/

void menu_2_3(){
clrscr();
Clientes obj;
int id, pos;
char opc;
bool est;

cout<<"Ingrese DNI de cliente a eliminar: ";
cin>>id;

pos=buscarCliente(id);
if(pos!=-1){
obj.leerDisco(pos);

est=obj.getEstado(); //guardo en est el estado de ese dato
if(est==false){ // Verifica si ya estaba eliminado
    cout<<endl<<"El cliente ya se encuentra eliminado";
    pausa();
    return;
}

obj.Mostrar(1);
do{
cout << "Confirmar (S/N): ";
cin>>opc;
}while(opc != 'S' && opc != 'N');

    if (opc=='S'){
      obj.setEstado(0);
      obj.grabarDisco(pos); // Se envia pos, en ves de -1 por que es una modificacion
      cout<<"Cliente Eliminado";
      pausa();
      return;
    }
    else{
    cout<<"Solicitud anulada";
    pausa();
    return;
    }
}
cout<<endl<<"No se encontro cliente";
pausa();
return;
}

/***************** Mostrar Cliente ****************/

void menu_2_4(){
clrscr();
Clientes obj;
int id, pos;
//char opc;

cout<<"Ingrese DNI: ";
cin>>id;

pos=buscarCliente(id);
if(pos!=-1){
obj.leerDisco(pos);
obj.Mostrar(1);
pausa();
return;
}
cout<<endl<<"No se encontro Cliente";
pausa();
return;
}

/***************** Mostrar todos los Clientes ****************/
void menu_2_5(){
clrscr();
int pos=0;
bool est;
Clientes obj;
cout<<endl<<"* Mostrar Clientes *"<<endl;
cout<<"--------------------------------"<<endl;


    while(obj.leerDisco(pos)==1){
        est=obj.getEstado();
        if(est==true) obj.Mostrar(-1);
        cout<<endl;
    pos++;
    }

volver();
}



#endif // CLIENTES_H_INCLUDED
