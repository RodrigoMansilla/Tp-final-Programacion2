#ifndef DETALLE_COMPRAS_H_INCLUDED
#define DETALLE_COMPRAS_H_INCLUDED


/********* Grabar o modificar en Disco **********/
void Detalle_Compras::grabarDisco(int pos){

FILE *p;
if(pos >= 0){
    //MODIFICACION
p = fopen("Archivos/DetalleCompras.dat", "rb+");
    if (p == NULL) exit(1);
    fseek(p, pos*sizeof *this, SEEK_SET); // ????????????????????????????????????????
}
else{ //Entra acà cuando la funcion Guardar producto envía -1
    //ALTA
    p = fopen("Archivos/DetalleCompras.dat", "ab");
    if (p == NULL) exit(1);

    fseek(p, 0, SEEK_END);
}
  fwrite(this, sizeof *this, 1, p);
  fclose(p);
  return;
}

/*************** Leer Disco **************/

int Detalle_Compras::leerDisco(int pos){
int x;
FILE *p;
p = fopen("Archivos/DetalleCompras.dat", "rb");
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


/*****************************************/

/*bool cargarProductoNoReg(int id){
clrscr();
Productos obj;
if(obj.Cargar()){
    obj.grabarDisco(-1);
    cout<<endl<<"Producto cargado correctamente";
    cout<<endl<<"Pulse ENTER para volver";
    pausa();
    return;
}
else{
    cout<<endl<<"No se pudo cargar producto";
    cout<<endl<<"Pulse ENTER para volver";
    pausa();
    return;
}
}*/







/**************Cargar detalle de compra**************/
int Detalle_Compras::Cargar(int posdetalle){
Productos aux;
int pos=0;
textcolor(cAZUL_CLARO,cBLANCO);
gotoxy(6,posdetalle); cin>>IDproducto;

if(IDproducto==0){
        if(posdetalle==21){
                return 3;
        }
        else{
            return 2;
        }
}

if(existeProducto(IDproducto)==false){
    cuadro(5, posdetalle, 7, 0, cBLANCO, cBLANCO); //cuadro para limpiar el valor ingresado en Articulo
    //posdetalle-=1;
    textcolor(cROJO_CLARO,cBLANCO);
    gotoxy(28,69); cout<<"No existe producto"<<endl;
    textcolor(cVERDE, cBLANCO);
    gotoxy(17,70); cout<<"Pulse una tecla para ingresar un nuevo producto";
    pausa();
    return 0;
}

while(aux.leerDisco(pos)==1){
    if(aux.getIDproducto()==IDproducto){
        if(aux.getEstado()==false){ // si el producto ingresado está inactivo, muestra mensaje y se puede ingresar un nuevo articulo
        cuadro(5, posdetalle, 7, 0, cBLANCO, cBLANCO); //cuadro para limpiar el valor ingresado en Articulo

        textcolor(cROJO_CLARO,cBLANCO);
        gotoxy(24,69); cout<<"El producto se encuentra eliminado"<<endl;
        textcolor(cVERDE, cBLANCO);
        gotoxy(17,70); cout<<"Pulse una tecla para ingresar un nuevo producto";
        pausa();
        return 0;
        }
    gotoxy(17,posdetalle); cout<<aux.getNombre();
    //precioUnitario=aux.getPrecio(); // se pone manualmente porque el valor lo pone el dueño
    gotoxy(49,posdetalle); cin>>precioUnitario;
    gotoxy(60,posdetalle); cin>>cantidad;

    if(cantidad<1){
    textcolor(cROJO_CLARO,cBLANCO);
    gotoxy(22,69); cout<<"Valor invalido";
    textcolor(cVERDE, cBLANCO);
    gotoxy(17,71); cout<<"Pulse una tecla para ingresar un nuevo producto";
    pausa();

    cuadro(6, posdetalle, 7, 0, cBLANCO, cBLANCO); //cuadro para limpiar los valores ingresados, Articulo
    cuadro(17, posdetalle, 16, 0, cBLANCO, cBLANCO); //cuadro para limpiar los valores ingresados, descrp
    cuadro(49, posdetalle, 7, 0, cBLANCO, cBLANCO); //cuadro para limpiar los valores ingresados, importe
    cuadro(59, posdetalle, 6, 0, cBLANCO, cBLANCO); //cuadro para limpiar los valores ingresados, cant

    return 0;
    }

// aca hay que valida que exita antes de obtener el precio!!!


    importeCompra=precioUnitario*cantidad;
    gotoxy(69,posdetalle); cout<<importeCompra;
    return 1;
    }
    pos++;
}
}


/********* Mostrar compra **********/
void Detalle_Compras::Mostrar(int est){
cout<<endl;
cout<<"ID compra: "<<IDcompra<<endl;
cout<<"ID producto: "<<IDproducto<<endl;
cout<<"Cantidad: "<<cantidad<<endl;
cout<<"Importe unitario: "<<precioUnitario<<endl;
/**si se recibe en "est" un 1 es porque quiero mostrar ESTADO, si se recibe un -1, no quiero mostrarlo **/

}

/********* agregar stock **********/

void agregarStock(int prod, int cant){
Productos obj;
int pos=0, stock;
while(obj.leerDisco(pos)==1){
    if(obj.getIDproducto()==prod){
        stock=obj.getStock();
        stock+=cant;
        //cout<<"Stock disponible: "<<stock<<endl;
        obj.setStock(stock);
        obj.grabarDisco(pos);
        return;
    }
    pos++;
}
}



/****************************************************************************
*****************************************************************************
****************************************************************************/

/********** Alta detalle de compra **********/

bool altaDetalleCompra(int id){
Detalle_Compras obj;
int opc=1, posdetalle=20, prod=0, cant=0;

while(opc){
posdetalle++;
obj.setIDcompra(id);

switch(obj.Cargar(posdetalle)){
    case 1:
    obj.grabarDisco(-1);
    prod=obj.getIDproducto();
    cant=obj.getCantidad();
    agregarStock(prod,cant);
    break;
    //
    case 2:
    return true;
    break;
    //
    case 3:
        textcolor(cROJO_CLARO,cBLANCO);
        gotoxy(26,69); cout<<"No se ingreso ningun articulo"<<endl;
        return false;
    break;
    case 0: // no se pone nada asì continua con el ingreso, ya la limpieza esta antes de mandar el 0
    cuadro(16, 69, 48, 2, cBLANCO, cBLANCO); // limpia cuadro de alertas
    posdetalle--;
    break;

}
}

}



#endif // DETALLE_COMPRAS_H_INCLUDED
