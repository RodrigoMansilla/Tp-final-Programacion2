#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

/********* Grabar o modificar en Disco **********/
void Ventas::grabarDisco(int pos){

FILE *p;
if(pos >= 0){
    //MODIFICACION
p = fopen("Archivos/Ventas.dat", "rb+");
    if (p == NULL) exit(1);
    fseek(p, pos*sizeof *this, SEEK_SET); // ????????????????????????????????????????
}
else{ //Entra acà cuando la funcion Guardar producto envía -1
    //ALTA
    p = fopen("Archivos/Ventas.dat", "ab");
    if (p == NULL) exit(1);

    fseek(p, 0, SEEK_END);
}
  fwrite(this, sizeof *this, 1, p);
  fclose(p);
  return;
}

/*************** Leer Disco **************/

int Ventas::leerDisco(int pos){
int x;
FILE *p;
p = fopen("Archivos/Ventas.dat", "rb");
if (p==NULL){
    cout << "No hay ventas cargadas";
    pausa();
    return 0;
}
    fseek(p,pos*sizeof *this,0);
    x=fread(this, sizeof *this, 1, p);
    fclose(p);
    return x;
}

/********* Mostrar cliente en remito **********/

void Clientes::Mostrarenremito(){

gotoxy(56,10); cout<<nombre<<" "<<apellido; //endl provisional
gotoxy(58,11); cout<<telefono;
//cout<<"Fecha de nac.: "<<anioNacimiento<<endl; // creo que no va esto en remito
}

/********* Mostrar datos cliente **********/

void motrarDatosCliente(int id){
Clientes obj;
int pos=0;
pos=buscarCliente(id);
if(pos!=-1){
obj.leerDisco(pos);
obj.Mostrarenremito();
return;
}
}

/********* Cargar venta **********/
bool Ventas::Cargar(){

int pos=0, dia,mes,anio;
bool est;
Clientes aux;
IDventa=ContarRegistrosVentas();
gotoxy(62,6); cout<<IDventa<<endl;
gotoxy(56,7); cin>>dia;
if(dia>31 || dia<1){
    textcolor(cROJO_CLARO,cBLANCO);
    gotoxy(28,69);cout<<"El dia ingrsado es invalido";
    gotoxy(28,70); cout<<"No se pudo cargar venta";
    textcolor(cVERDE, cBLANCO);
    gotoxy(28,71); cout<<"Pulse ENTER para volver";
    pausa();
    return false;
}
gotoxy(60,7); cin>>mes;
if(mes>12 || mes<1){
    textcolor(cROJO_CLARO,cBLANCO);
    gotoxy(28,69);cout<<"El mes ingresado es invalido";
    gotoxy(28,70); cout<<"No se pudo cargar venta";
    textcolor(cVERDE, cBLANCO);
    gotoxy(28,71); cout<<"Pulse ENTER para volver";
    pausa();
    return false;
}
gotoxy(64,7); cin>>anio;
if(anio>fsistema.getAnio() || anio<2000){
    textcolor(cROJO_CLARO,cBLANCO);
    gotoxy(28,69);cout<<"El anio ingresado es invalido";
    gotoxy(28,70); cout<<"No se pudo cargar venta";
    textcolor(cVERDE, cBLANCO);
    gotoxy(28,71); cout<<"Pulse ENTER para volver";
    pausa();
    return false;
}

// aca valido que la fecha ingresada no sea superior a la actual (sistma)

if(anio==fsistema.getAnio()){
    if(mes==fsistema.getMes()){
        if(dia>fsistema.getDia()){
            textcolor(cROJO_CLARO,cBLANCO);
            gotoxy(24,69);cout<<"La fecha es superior a la actual";
            gotoxy(28,70); cout<<"No se pudo cargar venta";
            textcolor(cVERDE, cBLANCO);
            gotoxy(28,71); cout<<"Pulse ENTER para volver";
            pausa();
            return false;
        }
    }
    else{
            if((mes>fsistema.getMes())){
            textcolor(cROJO_CLARO,cBLANCO);
            gotoxy(24,69);cout<<"La fecha es superior a la actual";
            gotoxy(28,70); cout<<"No se pudo cargar venta";
            textcolor(cVERDE, cBLANCO);
            gotoxy(28,71); cout<<"Pulse ENTER para volver";
            pausa();
            return false;
            }
    }
}
//

fechaventa.setDia(dia); fechaventa.setMes(mes); fechaventa.setAnio(anio); // si esta todo ok, setea la fecha

//


gotoxy(53,9); cin>>DNIcliente;
if(existeCliente(DNIcliente)==false){
    textcolor(cROJO_CLARO,cBLANCO);
    gotoxy(28,69);cout<<"DNI inexistente";
    gotoxy(28,70); cout<<"No se pudo cargar venta";
    textcolor(cVERDE, cBLANCO);
    gotoxy(28,71); cout<<"Pulse ENTER para volver";
    pausa();
    return false;
}

while(aux.leerDisco(pos)==1){
        est=aux.getEstado();
        if(aux.getDNI()==DNIcliente){ // primero se compara que el DNI sea el mismo
        if(est==false) { // Si es el mismo, pregunta si està dado de baja
            textcolor(cROJO_CLARO,cBLANCO);
            gotoxy(28,69);cout<<"DNI se encuentra eliminado";
            gotoxy(28,70); cout<<"No se pudo cargar venta";
            textcolor(cVERDE, cBLANCO);
            gotoxy(28,71); cout<<"Pulse ENTER para volver";
            pausa();
            return false;
        }
        }
    pos++;
    }

motrarDatosCliente(DNIcliente); // si no está dado de baja muestra los datos

//cout<<"Forma de pago: ";
gotoxy(63,13); cin>>formaPago;
if(formaPago<1 || formaPago>3){
    textcolor(cROJO_CLARO,cBLANCO);
    gotoxy(28,69);cout<<"Tipo de pago invalido";
    gotoxy(28,70); cout<<"No se pudo cargar venta";
    textcolor(cVERDE, cBLANCO);
    gotoxy(28,71); cout<<"Pulse ENTER para volver";
    pausa();
    return false;

}

// no se tiene que repetir, podria hacerlo automàtico
return true;
}

/********* Mostrar venta **********/
void Ventas::Mostrar(int posdetalle){

gotoxy(8,posdetalle); cout<<IDventa;
gotoxy(21,posdetalle); cout<<DNIcliente;
switch(formaPago){
case 1: gotoxy(37,posdetalle); cout<<"Efectivo"; break;
case 2: gotoxy(37,posdetalle); cout<<"T. de debito"; break;
case 3: gotoxy(37,posdetalle); cout<<"T. de credito"; break;
}
gotoxy(54,posdetalle); cout<<fechaventa.getDia()<<"/"<<fechaventa.getMes()<<"/"<<fechaventa.getAnio();
gotoxy(71,posdetalle); cout<<importeTotal;
}

/********* Mostrar venta en remito **********/
void Ventas::MostrarEnRemito(){
//cout<<"ID venta: "<<IDventa<<endl;
gotoxy(53,9); cout<<DNIcliente<<endl;
motrarDatosCliente(DNIcliente);
switch(formaPago){
case 1: gotoxy(63,13); cout<<"Efectivo"; break;
case 2: gotoxy(63,13); cout<<"T. de debito"; break;
case 3: gotoxy(63,13); cout<<"T. de credito"; break;
}
gotoxy(56,7); cout<<fechaventa.getDia();
gotoxy(60,7); cout<<fechaventa.getMes();
gotoxy(64,7); cout<<fechaventa.getAnio();

gotoxy(69,63); cout<<importeTotal<<endl;
}



/********* Obtener importe **********/

float obtenerImporteV(int id){
    Detalle_Ventas obj;
    float PrecioTotal=0;
	int pos=0;

	while(obj.leerDisco(pos)==1){
		if(obj.getIDventa()==id){
            //buscar precio en productos!!!!!!!!!!!
			PrecioTotal+=obj.getimporteVenta();

        }
        pos++;
    }
	return PrecioTotal;
}

/********* Generador de numero de venta **********/

int ContarRegistrosVentas(){
int cont,tam;
FILE *p;
p = fopen("Archivos/Ventas.dat", "rb");
    if (p == NULL){
    return 1;
    }
fseek(p, 0, SEEK_END);
tam=ftell(p);
cont=tam/sizeof(Ventas); // Se pone el Struct
fclose(p);
return cont+1;
}

/********* Buscar Venta **********/

int buscarVenta(int id){
int pos=0;
Ventas obj;
while(obj.leerDisco(pos)==1){
    if(obj.getIDventa()==id) return pos;
    pos++;
}
return -1;
}

/********* Buscar Detalle Venta **********/

int buscarDetalleVenta(int id){
int pos=0;
Detalle_Ventas obj;
while(obj.leerDisco(pos)==1){
    if(obj.getIDventa()==id) return pos;
    pos++;
}
return -1;
}

/********** Obtener nombre **********/

char *obtenerNombre(int id){
    Productos obj;
    int pos=0;

	while(obj.leerDisco(pos)==1){
		if(obj.getIDproducto()==id){
            return obj.getNombre();

        }
        pos++;
    }

}


/****************************************************************************
*****************************************************************************
****************************************************************************/


/********** Nueva venta **********/
void menu_4_1(){
Ventas obj;
int id;
float imp;
textcolor(0,0);

Remito1(); // REMITOOOOOOOOOOOOOOOO
cuadro(15, 68, 50, 4, cROJO, cBLANCO); // cuadro de alertas
textcolor(cAZUL_CLARO,cBLANCO);

if(obj.Cargar()){
    id=obj.getIDventa();
    if(altaDetalleVenta(id)==false){
    textcolor(cROJO_CLARO,cBLANCO);
    gotoxy(26,70); cout<<"No se pudo cargar venta"<<endl;
    textcolor(cVERDE, cBLANCO);
    gotoxy(26,71); cout<<"Pulse ENTER para volver";
    pausa();
    return;
    }
    else{
    imp=obtenerImporteV(id);
    obj.setimporteTotal(imp);
    gotoxy(69,63); cout<<obj.getimporteTotal();

    obj.grabarDisco(-1);
    textcolor(cVERDE, cBLANCO);
    gotoxy(26,69); cout<<"Venta cargada correctamente";
    gotoxy(26,70); cout<<"Pulse ENTER para volver";
    pausa();
    return;
    }
}
}


/********** Listar venta **********/
void menu_4_2(){
clrscr();
Ventas obj;
int id, pos=0,posdetalle=8;

textcolor(0,0);
clrscr();

cuadroVentas2();
textcolor(cNEGRO,cBLANCO);

gotoxy(6,posdetalle); cin>>id;

while(obj.leerDisco(pos)==1){ //solo busca una!!!!!!!!
        if(obj.getIDventa()==id){
            obj.Mostrar(posdetalle); // ese 1 es provisorio, dsps mandarle posdetalle
            textcolor(cVERDE, cBLANCO);
            gotoxy(22,15); cout<<"Pulse ENTER para volver";
            pausa();
            return; // pongo return porque solo debería haber un ID de compra, no varios para mostrar.
        }
    pos++;
}


textcolor(cROJO_CLARO,cBLANCO);
gotoxy(22,15); cout<<"No se encontro venta";
textcolor(cVERDE, cBLANCO);
gotoxy(22,16); cout<<"Pulse ENTER para volver";
pausa();
return;
}



/********** Listar detalle de venta **********/
void menu_4_3(){
clrscr();
Ventas obj;
Detalle_Ventas aux;
int id,pos,pos2,posdetalle=21;
char nom[15];

textcolor(0,0);
Remito2();
cuadro(15, 68, 50, 3, cROJO, cBLANCO); // cuadro de alertas
textcolor(cNEGRO,cBLANCO);
gotoxy(62,6); cin>>id;

pos=buscarVenta(id);

if(pos!=-1){
obj.leerDisco(pos);
obj.MostrarEnRemito();
        //
        pos2=buscarDetalleVenta(id);
        while(aux.leerDisco(pos2)){
        if(id==aux.getIDventa()){
            gotoxy(6,posdetalle); cout<<aux.getIDproducto();
            strcpy(nom,obtenerNombre(aux.getIDproducto()));
            gotoxy(17,posdetalle); cout<<nom; // falta mostrar nombr
            gotoxy(49,posdetalle); cout<<aux.getPrecio();
            gotoxy(60,posdetalle); cout<<aux.getCantidad();
            gotoxy(69,posdetalle); cout<<aux.getimporteVenta();
        }
        posdetalle++;
        pos2++;
        }
        //
        textcolor(cVERDE, cBLANCO);
        gotoxy(26,69); cout<<"Pulse ENTER para volver";
pausa();
return;
}
textcolor(cROJO_CLARO,cBLANCO);
gotoxy(26,69); cout<<"No se encontro numero de venta";
textcolor(cVERDE, cBLANCO);
gotoxy(26,70); cout<<"Pulse ENTER para volver";
pausa();
return;
}

/********** Listar todas las ventas **********/

void menu_4_4(){
Ventas obj;
int pos=0, posdetalle=8;

textcolor(0,0);
clrscr();

cuadroVentas();
textcolor(cNEGRO,cBLANCO);

while(obj.leerDisco(pos)==1){ //solo busca una!!!!!!!!
        obj.Mostrar(posdetalle);
        pos++;
        posdetalle++;
        }
    pausa();
}
#endif // VENTAS_H_INCLUDED
