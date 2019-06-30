#ifndef CUADROS_H_INCLUDED
#define CUADROS_H_INCLUDED

int ContarProductosActivos();
int ContarRegistrosVentas();
int ContarRegistrosCompras();

/*********************** Remito 1 *************************/

void Remito1(void){
clrscr();

textcolor(0,0);
cuadro(3, 3, 75, 0, cGRIS_CLARO, cGRIS_CLARO); // Cuandro de mensaje art=0
textcolor(cROJO_CLARO,cGRIS_CLARO);
gotoxy(3,3); cout<<"      >> Para finalizar la venta, ingrese un articulo con valor 0 <<";
//
cuadro(3, 5, 75, 60, cNEGRO, cBLANCO); // Cuandro general
cuadro(38, 5, 5, 3, cNEGRO, cBLANCO); // Cuadrado chico, factura tipo
lineav(41, 9, 8, cNEGRO, cBLANCO); // linea del medio abajo de cuadrado chico
lineah(4, 18, 73, cNEGRO, cBLANCO);
//
gotoxy(48,6); cout<<"Factura Num.:";
gotoxy(48,7); cout<<"Fecha:    /   /";
gotoxy(48,9); cout<<"DNI:";
gotoxy(48,10); cout<<"Nombre:";
gotoxy(48,11); cout<<"Telefono:";
gotoxy(48,13); cout<<"Forma de Pago:";
gotoxy(48,14); cout<<"1)Efectivo 2)Debito 3)Credito";
//
cuadro(4, 19, 73, 1, cNEGRO, cNEGRO); // Barra negra de menues
lineav(14, 19, 42, cNEGRO, cBLANCO); // linea que divide cada campo
gotoxy(5,19); textcolor(cBLANCO,cNEGRO); cout<<"Articulo";
//
lineav(46, 19, 42, cNEGRO, cBLANCO); // linea que divide cada campo
gotoxy(17,19); textcolor(cBLANCO,cNEGRO); cout<<"Descripcion";
//
lineav(57, 19, 42, cNEGRO, cBLANCO); // linea que divide cada campo
gotoxy(49,19); textcolor(cBLANCO,cNEGRO); cout<<" p/u";
//
lineav(66, 19, 42, cNEGRO, cBLANCO); // linea que divide cada campo
gotoxy(59,19); textcolor(cBLANCO,cNEGRO); cout<<"Cant.";
//
gotoxy(68,19); textcolor(cBLANCO,cNEGRO); cout<<" Importe";

lineah(4, 62, 73, cNEGRO, cBLANCO); // Linea arriba de total
//
cuadro(57, 63, 9, 1, cNEGRO, cNEGRO); // cuadro negro de total
gotoxy(57,63); textcolor(cBLANCO,cNEGRO); cout<<" Total $:";

}

/*********************** Remito 2 *************************/

void Remito2(void){
clrscr();

textcolor(0,0);
cuadro(3, 3, 75, 0, cGRIS_CLARO, cGRIS_CLARO); // Cuandro de mensaje art=0
textcolor(cROJO_CLARO,cGRIS_CLARO);
gotoxy(3,3); cout<<"      >> Ingrese el numero de factura, para realizar la busqueda <<";
//
cuadro(3, 5, 75, 60, cNEGRO, cBLANCO); // Cuandro general
cuadro(38, 5, 5, 3, cNEGRO, cBLANCO); // Cuadrado chico, factura tipo
lineav(41, 9, 8, cNEGRO, cBLANCO); // linea del medio abajo de cuadrado chico
lineah(4, 18, 73, cNEGRO, cBLANCO);
//
gotoxy(48,6); cout<<"Factura Num.:";
gotoxy(48,7); cout<<"Fecha:    /   /";
gotoxy(48,9); cout<<"DNI:";
gotoxy(48,10); cout<<"Nombre:";
gotoxy(48,11); cout<<"Telefono:";
gotoxy(48,13); cout<<"Forma de Pago:";
//
cuadro(4, 19, 73, 1, cNEGRO, cNEGRO); // Barra negra de menues
lineav(14, 19, 42, cNEGRO, cBLANCO); // linea que divide cada campo
gotoxy(5,19); textcolor(cBLANCO,cNEGRO); cout<<"Articulo";
//
lineav(46, 19, 42, cNEGRO, cBLANCO); // linea que divide cada campo
gotoxy(17,19); textcolor(cBLANCO,cNEGRO); cout<<"Descripcion";
//
lineav(57, 19, 42, cNEGRO, cBLANCO); // linea que divide cada campo
gotoxy(49,19); textcolor(cBLANCO,cNEGRO); cout<<" p/u";
//
lineav(66, 19, 42, cNEGRO, cBLANCO); // linea que divide cada campo
gotoxy(59,19); textcolor(cBLANCO,cNEGRO); cout<<"Cant.";
//
gotoxy(68,19); textcolor(cBLANCO,cNEGRO); cout<<" Importe";

lineah(4, 62, 73, cNEGRO, cBLANCO); // Linea arriba de total
//
cuadro(57, 63, 9, 1, cNEGRO, cNEGRO); // cuadro negro de total
gotoxy(57,63); textcolor(cBLANCO,cNEGRO); cout<<" Total $:";

}

/*********************** Remito 11 (Para compras) *************************/

void Remito11(void){
clrscr();

textcolor(0,0);
cuadro(3, 3, 75, 0, cGRIS_CLARO, cGRIS_CLARO); // Cuandro de mensaje art=0
textcolor(cROJO_CLARO,cGRIS_CLARO);
gotoxy(3,3); cout<<"      >> Para finalizar la compra, ingrese un articulo con valor 0 <<";
//
cuadro(3, 5, 75, 60, cNEGRO, cBLANCO); // Cuandro general
cuadro(38, 5, 5, 3, cNEGRO, cBLANCO); // Cuadrado chico, factura tipo
lineav(41, 9, 8, cNEGRO, cBLANCO); // linea del medio abajo de cuadrado chico
lineah(4, 18, 73, cNEGRO, cBLANCO);
//
gotoxy(48,6); cout<<"Factura Num.:";
gotoxy(48,7); cout<<"Fecha:    /   /";
gotoxy(48,9); cout<<"Proveedor:";

//
cuadro(4, 19, 73, 1, cNEGRO, cNEGRO); // Barra negra de menues
lineav(14, 19, 42, cNEGRO, cBLANCO); // linea que divide cada campo
gotoxy(5,19); textcolor(cBLANCO,cNEGRO); cout<<"Articulo";
//
lineav(46, 19, 42, cNEGRO, cBLANCO); // linea que divide cada campo
gotoxy(17,19); textcolor(cBLANCO,cNEGRO); cout<<"Descripcion";
//
lineav(57, 19, 42, cNEGRO, cBLANCO); // linea que divide cada campo
gotoxy(49,19); textcolor(cBLANCO,cNEGRO); cout<<" p/u";
//
lineav(66, 19, 42, cNEGRO, cBLANCO); // linea que divide cada campo
gotoxy(59,19); textcolor(cBLANCO,cNEGRO); cout<<"Cant.";
//
gotoxy(68,19); textcolor(cBLANCO,cNEGRO); cout<<" Importe";

lineah(4, 62, 73, cNEGRO, cBLANCO); // Linea arriba de total
//
cuadro(57, 63, 9, 1, cNEGRO, cNEGRO); // cuadro negro de total
gotoxy(57,63); textcolor(cBLANCO,cNEGRO); cout<<" Total $:";

}


/*********************** Remito 22 (Para detalle de compra) *************************/

void Remito22(void){
clrscr();

textcolor(0,0);
cuadro(3, 3, 75, 0, cGRIS_CLARO, cGRIS_CLARO); // Cuandro de mensaje art=0
textcolor(cROJO_CLARO,cGRIS_CLARO);
gotoxy(3,3); cout<<"      >> Ingrese el numero de factura, para realizar la busqueda <<";
//
cuadro(3, 5, 75, 60, cNEGRO, cBLANCO); // Cuandro general
cuadro(38, 5, 5, 3, cNEGRO, cBLANCO); // Cuadrado chico, factura tipo
lineav(41, 9, 8, cNEGRO, cBLANCO); // linea del medio abajo de cuadrado chico
lineah(4, 18, 73, cNEGRO, cBLANCO);
//
gotoxy(48,6); cout<<"Factura Num.:";
gotoxy(48,7); cout<<"Fecha:    /   /";
gotoxy(48,9); cout<<"Proveedor:";
//
cuadro(4, 19, 73, 1, cNEGRO, cNEGRO); // Barra negra de menues
lineav(14, 19, 42, cNEGRO, cBLANCO); // linea que divide cada campo
gotoxy(5,19); textcolor(cBLANCO,cNEGRO); cout<<"Articulo";
//
lineav(46, 19, 42, cNEGRO, cBLANCO); // linea que divide cada campo
gotoxy(17,19); textcolor(cBLANCO,cNEGRO); cout<<"Descripcion";
//
lineav(57, 19, 42, cNEGRO, cBLANCO); // linea que divide cada campo
gotoxy(49,19); textcolor(cBLANCO,cNEGRO); cout<<" p/u";
//
lineav(66, 19, 42, cNEGRO, cBLANCO); // linea que divide cada campo
gotoxy(59,19); textcolor(cBLANCO,cNEGRO); cout<<"Cant.";
//
gotoxy(68,19); textcolor(cBLANCO,cNEGRO); cout<<" Importe";

lineah(4, 62, 73, cNEGRO, cBLANCO); // Linea arriba de total
//
cuadro(57, 63, 9, 1, cNEGRO, cNEGRO); // cuadro negro de total
gotoxy(57,63); textcolor(cBLANCO,cNEGRO); cout<<" Total $:";

}


/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*********************** Mostrar producto con estado *************************/

void cuadroProductos(void){

clrscr();
textcolor(0,0);
cuadro(3, 3, 75, 0, cGRIS_CLARO, cGRIS_CLARO); // Cuandro de mensaje art=0
textcolor(cROJO_CLARO,cGRIS_CLARO);
gotoxy(3,3); cout<<"      >> Ingrese ID de producto, para realizar la busqueda <<";

cuadro(3, 5, 90, 5, cNEGRO, cBLANCO); // cuadro general

cuadro(4, 6, 88, 1, cNEGRO, cNEGRO); // Barra negra de menues
lineav(14, 6, 3, cNEGRO, cBLANCO); // linea que divide cada campo
gotoxy(5,6); textcolor(cBLANCO,cNEGRO); cout<<"Articulo";
//
lineav(46, 6, 3, cNEGRO, cBLANCO); // linea que divide cada campo
gotoxy(17,6); textcolor(cBLANCO,cNEGRO); cout<<"Descripcion";
//
lineav(61, 6, 3, cNEGRO, cBLANCO); // linea que divide cada campo
gotoxy(51,6); textcolor(cBLANCO,cNEGRO); cout<<"Tipo";
//
lineav(71, 6, 3, cNEGRO, cBLANCO); // linea que divide cada campo
gotoxy(63,6); textcolor(cBLANCO,cNEGRO); cout<<"Precio";
//

lineav(81, 6, 3, cNEGRO, cBLANCO); // linea que divide cada campo
gotoxy(73,6); textcolor(cBLANCO,cNEGRO); cout<<"Stock";
//
gotoxy(84,6); textcolor(cBLANCO,cNEGRO); cout<<"Estado";
//
cuadro(15, 14, 50, 4, cROJO, cBLANCO);
}

/*********************** Editar producto *************************/

void cuadroProductos3(void){

//textcolor(0,0);

cuadro(3, 5, 90, 5, cNEGRO, cBLANCO); // cuadro general

cuadro(4, 6, 88, 1, cNEGRO, cNEGRO); // Barra negra de menues
lineav(14, 6, 3, cNEGRO, cBLANCO); // linea que divide cada campo
gotoxy(5,6); textcolor(cBLANCO,cNEGRO); cout<<"Articulo";
//
lineav(46, 6, 3, cNEGRO, cBLANCO); // linea que divide cada campo
gotoxy(17,6); textcolor(cBLANCO,cNEGRO); cout<<"Descripcion";
//
lineav(61, 6, 3, cNEGRO, cBLANCO); // linea que divide cada campo
gotoxy(51,6); textcolor(cBLANCO,cNEGRO); cout<<"Tipo";
//
lineav(71, 6, 3, cNEGRO, cBLANCO); // linea que divide cada campo
gotoxy(63,6); textcolor(cBLANCO,cNEGRO); cout<<"Precio";
//

lineav(81, 6, 3, cNEGRO, cBLANCO); // linea que divide cada campo
gotoxy(73,6); textcolor(cBLANCO,cNEGRO); cout<<"Stock";
//
gotoxy(84,6); textcolor(cBLANCO,cNEGRO); cout<<"Estado";
//
}

/*********************** Mostrar todos los productos*************************/

void cuadroProductos2(void){
int altocuadro, linea;
clrscr();
textcolor(0,0);
altocuadro=ContarProductosActivos();
altocuadro+=3;
linea=altocuadro-2;
textcolor(cVERDE, cBLANCO);

cuadro(3, 3, 75, 0, cGRIS_CLARO, cGRIS_CLARO); // Cuandro de mensaje art=0
textcolor(cROJO_CLARO,cGRIS_CLARO);
gotoxy(3,3); cout<<"      >> Muestra de todos los productos <<";
//
cuadro(3, 5, 78, altocuadro, cNEGRO, cBLANCO); // cuadro general
//
cuadro(20, altocuadro+6, 40, 2, cNEGRO, cBLANCO); //Muerstra el mensaje de volver
textcolor(cVERDE, cBLANCO);
gotoxy(28,altocuadro+7); cout<<"Pulse ENTER para volver";

//
cuadro(4, 6, 76, 1, cNEGRO, cNEGRO); // Barra negra de menues
lineav(14, 6, linea, cNEGRO, cBLANCO); // linea que divide cada campo
gotoxy(5,6); textcolor(cBLANCO,cNEGRO); cout<<"Articulo";
//
lineav(46, 6, linea, cNEGRO, cBLANCO); // linea que divide cada campo
gotoxy(17,6); textcolor(cBLANCO,cNEGRO); cout<<"Descripcion";
//
lineav(61, 6, linea, cNEGRO, cBLANCO); // linea que divide cada campo
gotoxy(51,6); textcolor(cBLANCO,cNEGRO); cout<<"Tipo";
//
lineav(71, 6, linea, cNEGRO, cBLANCO); // linea que divide cada campo
gotoxy(63,6); textcolor(cBLANCO,cNEGRO); cout<<"Precio";
//
gotoxy(73,6); textcolor(cBLANCO,cNEGRO); cout<<"Stock";
//
}

/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/


/*********************** Mostrar todas las compras *************************/

void cuadroCompras(void){
int altocuadro=0, linea;
textcolor(0,0);
altocuadro=ContarRegistrosCompras();
linea=altocuadro;
altocuadro+=2;

textcolor(cVERDE, cBLANCO);

cuadro(3, 3, 75, 0, cGRIS_CLARO, cGRIS_CLARO); // Cuandro de mensaje art=0
textcolor(cROJO_CLARO,cGRIS_CLARO);
gotoxy(3,3); cout<<"                >> Muestra de todas las compras realizadas <<";
//
cuadro(3, 5, 69, altocuadro, cNEGRO, cBLANCO); // cuadro general
//
cuadro(20, altocuadro+6, 40, 2, cNEGRO, cBLANCO); //Muerstra el mensaje de volver
textcolor(cVERDE, cBLANCO);
gotoxy(28,altocuadro+7); cout<<"Pulse ENTER para volver";

//
cuadro(4, 6, 67, 1, cNEGRO, cNEGRO); // Barra negra de menues
//
gotoxy(5,6); textcolor(cBLANCO,cNEGRO); cout<<"N. de Compra";
lineav(19, 6, linea, cNEGRO, cBLANCO); // linea que divide cada campo
//
gotoxy(22,6); textcolor(cBLANCO,cNEGRO); cout<<"Proveedor";
lineav(42, 6, linea, cNEGRO, cBLANCO); // linea que divide cada campo
//
gotoxy(47,6); textcolor(cBLANCO,cNEGRO); cout<<"Fecha";
lineav(57, 6, linea, cNEGRO, cBLANCO); // linea que divide cada campo
//
gotoxy(60,6); textcolor(cBLANCO,cNEGRO); cout<<"Importe";
//
}

/*********************** Mostrar una compra *************************/

void cuadroCompras2(void){

textcolor(0,0);
textcolor(cVERDE, cBLANCO);

cuadro(3, 3, 75, 0, cGRIS_CLARO, cGRIS_CLARO); // Cuandro de mensaje art=0
textcolor(cROJO_CLARO,cGRIS_CLARO);
gotoxy(3,3); cout<<"      >> Ingrese numero de compra a buscar <<";
//
cuadro(3, 5, 69, 5, cNEGRO, cBLANCO); // cuadro general
//
cuadro(15, 14, 50, 4, cROJO, cBLANCO); // Cuadro de alertas

//
cuadro(4, 6, 67, 1, cNEGRO, cNEGRO); // Barra negra de menues
//
gotoxy(5,6); textcolor(cBLANCO,cNEGRO); cout<<"N. de Compra";
lineav(19, 6, 3, cNEGRO, cBLANCO); // linea que divide cada campo
//
gotoxy(22,6); textcolor(cBLANCO,cNEGRO); cout<<"Proveedor";
lineav(42, 6, 3, cNEGRO, cBLANCO); // linea que divide cada campo
//
gotoxy(47,6); textcolor(cBLANCO,cNEGRO); cout<<"Fecha";
lineav(57, 6, 3, cNEGRO, cBLANCO); // linea que divide cada campo
//
gotoxy(60,6); textcolor(cBLANCO,cNEGRO); cout<<"Importe";
//
}


/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*********************** Mostrar todas las ventas *************************/

void cuadroVentas(void){
int altocuadro=0, linea;
textcolor(0,0);
altocuadro=ContarRegistrosVentas();
linea=altocuadro;
altocuadro+=2;

textcolor(cVERDE, cBLANCO);

cuadro(3, 3, 75, 0, cGRIS_CLARO, cGRIS_CLARO); // Cuandro de mensaje art=0
textcolor(cROJO_CLARO,cGRIS_CLARO);
gotoxy(3,3); cout<<"                >> Muestra de todas las ventas realizadas <<";
//
cuadro(3, 5, 78, altocuadro, cNEGRO, cBLANCO); // cuadro general
//
cuadro(20, altocuadro+6, 40, 2, cNEGRO, cBLANCO); //Muerstra el mensaje de volver
textcolor(cVERDE, cBLANCO);
gotoxy(28,altocuadro+7); cout<<"Pulse ENTER para volver";

//
cuadro(4, 6, 76, 1, cNEGRO, cNEGRO); // Barra negra de menues
//
gotoxy(5,6); textcolor(cBLANCO,cNEGRO); cout<<"N. de Venta";
lineav(17, 6, linea, cNEGRO, cBLANCO); // linea que divide cada campo
//
gotoxy(20,6); textcolor(cBLANCO,cNEGRO); cout<<"DNI Cliente";
lineav(34, 6, linea, cNEGRO, cBLANCO); // linea que divide cada campo
//
gotoxy(37,6); textcolor(cBLANCO,cNEGRO); cout<<"Forma de Pago";
lineav(52, 6, linea, cNEGRO, cBLANCO); // linea que divide cada campo
//
gotoxy(57,6); textcolor(cBLANCO,cNEGRO); cout<<"Fecha";
lineav(67, 6, linea, cNEGRO, cBLANCO); // linea que divide cada campo
//
gotoxy(70,6); textcolor(cBLANCO,cNEGRO); cout<<"Importe";
//
}

/*********************** Mostrar una venta *************************/

void cuadroVentas2(void){

textcolor(0,0);
textcolor(cVERDE, cBLANCO);

cuadro(3, 3, 75, 0, cGRIS_CLARO, cGRIS_CLARO); // Cuandro de mensaje art=0
textcolor(cROJO_CLARO,cGRIS_CLARO);
gotoxy(3,3); cout<<"      >> Ingrese numero de venta a buscar <<";
//
cuadro(3, 5, 78, 5, cNEGRO, cBLANCO); // cuadro general
//
cuadro(15, 14, 50, 4, cROJO, cBLANCO); // Cuadro de alertas

//
cuadro(4, 6, 76, 1, cNEGRO, cNEGRO); // Barra negra de menues
//
gotoxy(5,6); textcolor(cBLANCO,cNEGRO); cout<<"N. de Venta";
lineav(17, 6, 3, cNEGRO, cBLANCO); // linea que divide cada campo
//
gotoxy(20,6); textcolor(cBLANCO,cNEGRO); cout<<"DNI Cliente";
lineav(34, 6, 3, cNEGRO, cBLANCO); // linea que divide cada campo
//
gotoxy(37,6); textcolor(cBLANCO,cNEGRO); cout<<"Forma de Pago";
lineav(52, 6, 3, cNEGRO, cBLANCO); // linea que divide cada campo
//
gotoxy(57,6); textcolor(cBLANCO,cNEGRO); cout<<"Fecha";
lineav(67, 6, 3, cNEGRO, cBLANCO); // linea que divide cada campo
//
gotoxy(70,6); textcolor(cBLANCO,cNEGRO); cout<<"Importe";
}




/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/








#endif // CUADROS_H_INCLUDED
