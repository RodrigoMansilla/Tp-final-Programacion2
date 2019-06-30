#ifndef DETALLE_VENTAS_H_INCLUDED
#define DETALLE_VENTAS_H_INCLUDED


/********* Grabar o modificar en Disco **********/
void Detalle_Ventas::grabarDisco(int pos){

FILE *p;
if(pos >= 0){
    //MODIFICACION
p = fopen("Archivos/DetalleVentas.dat", "rb+");
    if (p == NULL) exit(1);
    fseek(p, pos*sizeof *this, SEEK_SET); // ????????????????????????????????????????
}
else{ //Entra acà cuando la funcion Guardar producto envía -1
    //ALTA
    p = fopen("Archivos/DetalleVentas.dat", "ab");
    if (p == NULL) exit(1);

    fseek(p, 0, SEEK_END);
}
  fwrite(this, sizeof *this, 1, p);
  fclose(p);
  return;
}

/*************** Leer Disco **************/

int Detalle_Ventas::leerDisco(int pos){
int x;
FILE *p;
p = fopen("Archivos/DetalleVentas.dat", "rb");
if (p==NULL){
    cout << "No hay verntas cargadas";
    pausa();
    return 0;
}
    fseek(p,pos*sizeof *this,0);
    x=fread(this, sizeof *this, 1, p);
    fclose(p);
    return x;
}


/**************Cargar detalle de venta**************/
int Detalle_Ventas::Cargar(int posdetalle){
Productos aux;
int pos=0, stock;
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
    precioUnitario=aux.getPrecio();
    gotoxy(49,posdetalle); cout<<precioUnitario;
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


    //?? Verificar si hay stock suficiente

    stock=obtenerStock(IDproducto);
    if(cantidad>stock){

    textcolor(cROJO_CLARO,cBLANCO);
    gotoxy(22,69); cout<<"No hay suficiente stock de ese producto"<<endl;
    textcolor(cAZUL_CLARO, cBLANCO);
    gotoxy(30,70); cout<<"Stock actual: "<<stock;
    textcolor(cVERDE, cBLANCO);
    gotoxy(17,71); cout<<"Pulse una tecla para ingresar un nuevo producto";
    pausa();
    cuadro(6, posdetalle, 7, 0, cBLANCO, cBLANCO); //cuadro para limpiar los valores ingresados, Articulo
    cuadro(17, posdetalle, 16, 0, cBLANCO, cBLANCO); //cuadro para limpiar los valores ingresados, descrp
    cuadro(49, posdetalle, 7, 0, cBLANCO, cBLANCO); //cuadro para limpiar los valores ingresados, importe
    cuadro(59, posdetalle, 6, 0, cBLANCO, cBLANCO); //cuadro para limpiar los valores ingresados, cant

    return 0;
    }

    //
    importeVenta=aux.getPrecio()*cantidad;
    gotoxy(69,posdetalle); cout<<importeVenta;
    return 1;
    }
    pos++;
}
}

/********** Quitar stock **********/

void quitarStock(int prod, int cant){
Productos obj;
int pos=0, stock;

while(obj.leerDisco(pos)==1){
    if(obj.getIDproducto()==prod){
        stock=obj.getStock();
        stock-=cant;
        //cout<<"Stock disponible: "<<stock<<endl;
        obj.setStock(stock);
        obj.grabarDisco(pos);
        return;
    }
    pos++;
}
}

/********** Consultar stock **********/

int obtenerStock(int prod){
Productos obj;
int pos=0, stock=0;

while(obj.leerDisco(pos)==1){
    if(obj.getIDproducto()==prod){
            stock=obj.getStock();
            return stock;
    }
    pos++;
}
}


/****************************************************************************
*****************************************************************************
****************************************************************************/

/********** Alta detalle de venta **********/

bool altaDetalleVenta(int id){
Detalle_Ventas obj;
int opc=1, posdetalle=20, prod=0, cant=0;

while(opc){
posdetalle++;
obj.setIDventa(id);

switch(obj.Cargar(posdetalle)){
    case 1:
    obj.grabarDisco(-1);
    prod=obj.getIDproducto();
    cant=obj.getCantidad();
    quitarStock(prod,cant);
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





#endif // DETALLE_VENTAS_H_INCLUDED
