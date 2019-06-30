#ifndef COMPRAS_H_INCLUDED
#define COMPRAS_H_INCLUDED

/********* Grabar o modificar en Disco **********/
void Compras::grabarDisco(int pos){

FILE *p;
if(pos >= 0){
    //MODIFICACION
p = fopen("Archivos/Compras.dat", "rb+");
    if (p == NULL) exit(1);
    fseek(p, pos*sizeof *this, SEEK_SET); // ????????????????????????????????????????
}
else{ //Entra acà cuando la funcion Guardar producto envía -1
    //ALTA
    p = fopen("Archivos/Compras.dat", "ab");
    if (p == NULL) exit(1);

    fseek(p, 0, SEEK_END);
}
  fwrite(this, sizeof *this, 1, p);
  fclose(p);
  return;
}

/*************** Leer Disco **************/

int Compras::leerDisco(int pos){
int x;
FILE *p;
p = fopen("Archivos/Compras.dat", "rb");
if (p==NULL){
    cout << "No hay compras cargadas";
    pausa();
    return 0;
}
    fseek(p,pos*sizeof *this,0);
    x=fread(this, sizeof *this, 1, p);
    fclose(p);
    return x;
}


/********* Cargar compra **********/
bool Compras::Cargar(){

int dia,mes,anio;

IDcompra=ContarRegistrosCompras();
gotoxy(62,6); cout<<IDcompra<<endl;
gotoxy(56,7); cin>>dia;
if(dia>31 || dia<1){
    textcolor(cROJO_CLARO,cBLANCO);
    gotoxy(28,69);cout<<"El dia ingrsado es invalido";
    gotoxy(28,70); cout<<"No se pudo cargar compra";
    textcolor(cVERDE, cBLANCO);
    gotoxy(28,71); cout<<"Pulse ENTER para volver";
    pausa();
    return false;
}
gotoxy(60,7); cin>>mes;
if(mes>12 || mes<1){
    textcolor(cROJO_CLARO,cBLANCO);
    gotoxy(28,69);cout<<"El mes ingresado es invalido";
    gotoxy(28,70); cout<<"No se pudo cargar compra";
    textcolor(cVERDE, cBLANCO);
    gotoxy(28,71); cout<<"Pulse ENTER para volver";
    pausa();
    return false;
}
gotoxy(64,7); cin>>anio;
if(anio>fsistema.getAnio() || anio<2000){
    textcolor(cROJO_CLARO,cBLANCO);
    gotoxy(28,69);cout<<"El anio ingresado es invalido";
    gotoxy(28,70); cout<<"No se pudo cargar compra";
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
            gotoxy(28,70); cout<<"No se pudo cargar compra";
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
            gotoxy(28,70); cout<<"No se pudo cargar compra";
            textcolor(cVERDE, cBLANCO);
            gotoxy(28,71); cout<<"Pulse ENTER para volver";
            pausa();
            return false;
            }
    }
}

//
fechacompra.setDia(dia); fechacompra.setMes(mes); fechacompra.setAnio(anio); // si esta todo ok, setea la fecha
//

cin.ignore();
gotoxy(59,9); cin.getline(nombreProveedor, 30);

return true;
}



/************* Buscar Compra ************/

int buscarCompra(int id){
int pos=0;
Detalle_Compras obj;
while(obj.leerDisco(pos)==1){
    if(obj.getIDcompra()==id) return pos;
    pos++;
}
return -1;
}

/********* Buscar Detalle Compra **********/

int buscarDetalleCompra(int id){
int pos=0;
Detalle_Compras obj;
while(obj.leerDisco(pos)==1){
    if(obj.getIDcompra()==id) return pos;
    pos++;
}
return -1;
}



/********* Mostrar compra **********/
void Compras::Mostrar(int posdetalle){

gotoxy(8,posdetalle); cout<<IDcompra;
gotoxy(23,posdetalle); cout<<nombreProveedor;
gotoxy(45,posdetalle); cout<<fechacompra.getDia()<<"/"<<fechacompra.getMes()<<"/"<<fechacompra.getAnio();
gotoxy(62,posdetalle); cout<<importeTotal;
}


/********* Mostrar compra en remito **********/
void Compras::MostrarEnRemito(){
//cout<<"ID venta: "<<IDventa<<endl;
gotoxy(59,9); cout<<nombreProveedor;
gotoxy(56,7); cout<<fechacompra.getDia();
gotoxy(60,7); cout<<fechacompra.getMes();
gotoxy(64,7); cout<<fechacompra.getAnio();
gotoxy(69,63); cout<<importeTotal;
}

/********* Obtener importe **********/

float obtenerImporteC(int id){
    Detalle_Compras obj;
    float PrecioTotal=0;
	int pos=0;

	while(obj.leerDisco(pos)==1){
		if(obj.getIDcompra()==id){
            //buscar precio en productos!!!!!!!!!!!
			PrecioTotal+=obj.getimporteCompra();


        }
        pos++;
    }
	return PrecioTotal;
}

/********* Contar registros de compras **********/


int ContarRegistrosCompras(){
int cont,tam;
FILE *p;
p = fopen("Archivos/Compras.dat", "rb");
    if (p == NULL){
    return 1;
    }
fseek(p, 0, SEEK_END);
tam=ftell(p);
cont=tam/sizeof(Compras); // Se pone el Struct
fclose(p);
return cont+1;
}

/****************************************************************************
*****************************************************************************
****************************************************************************/


/********** Nueva compra **********/
void menu_3_1(){
Compras obj;
int id;
float imp;
textcolor(0,0);

Remito11(); // REMITOOOOOOOOOOOOOOOO
cuadro(15, 68, 50, 4, cROJO, cBLANCO); // cuadro de alertas
textcolor(cAZUL_CLARO,cBLANCO);

if(obj.Cargar()){
    id=obj.getIDcompra();
    if(altaDetalleCompra(id)==false){
    textcolor(cROJO_CLARO,cBLANCO);
    gotoxy(26,70); cout<<"No se pudo cargar compra"<<endl;
    textcolor(cVERDE, cBLANCO);
    gotoxy(26,71); cout<<"Pulse ENTER para volver";
    pausa();
    return;
    }
    else{
    imp=obtenerImporteC(id);
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


/********** Listar compra **********/
void menu_3_2(){
clrscr();
Compras obj;
int id, pos=0,posdetalle=8;

textcolor(0,0);
clrscr();

cuadroCompras2();
textcolor(cNEGRO,cBLANCO);

gotoxy(8,posdetalle); cin>>id;

while(obj.leerDisco(pos)==1){ //solo busca una!!!!!!!!
        if(obj.getIDcompra()==id){
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


/********** Listar detalle de compra **********/
void menu_3_3(){
clrscr();
Compras obj;
Detalle_Compras aux;
int id,pos,pos2,posdetalle=21;
char nom[15];

textcolor(0,0);
Remito22();
cuadro(15, 68, 50, 3, cROJO, cBLANCO); // cuadro de alertas
textcolor(cNEGRO,cBLANCO);
gotoxy(62,6); cin>>id;

pos=buscarCompra(id);

if(pos!=-1){
obj.leerDisco(pos);
obj.MostrarEnRemito();
            //
            pos2=buscarDetalleCompra(id);
        while(aux.leerDisco(pos2)){
            if(id==aux.getIDcompra()){
            gotoxy(6,posdetalle); cout<<aux.getIDproducto();
            strcpy(nom,obtenerNombre(aux.getIDproducto()));
            gotoxy(17,posdetalle); cout<<nom; // falta mostrar nombr
            gotoxy(49,posdetalle); cout<<aux.getPrecio();
            gotoxy(60,posdetalle); cout<<aux.getCantidad();
            gotoxy(69,posdetalle); cout<<aux.getimporteCompra();
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
gotoxy(26,69); cout<<"No se encontro numero de compra";
textcolor(cVERDE, cBLANCO);
gotoxy(26,70); cout<<"Pulse ENTER para volver";
pausa();
return;
}


/********** Listar todas las compras **********/
void menu_3_4(){
Compras obj;
int pos=0, posdetalle=8;

textcolor(0,0);
clrscr();

cuadroCompras();
textcolor(cNEGRO,cBLANCO);

while(obj.leerDisco(pos)==1){ //solo busca una!!!!!!!!
        obj.Mostrar(posdetalle);
        pos++;
        posdetalle++;
        }
    pausa();
}


#endif // COMPRAS_H_INCLUDED
