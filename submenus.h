#ifndef SUBMENUS_H_INCLUDED
#define SUBMENUS_H_INCLUDED



/************ PRODUCTOS ************/

void menu_1(){
int opc;
while(true){
textcolor(0,0);
clrscr();
recuadro(8, 1, 35, 19, cAZUL_CLARO, cBLANCO);

textcolor(cROJO_CLARO, cBLANCO);
gotoxy(33,2);
cout<<fsistema.getDia()<<"/"<<fsistema.getMes()<<"/"<<fsistema.getAnio();

textcolor(cAZUL_CLARO, cBLANCO);

gotoxy(10,3);  cout<<"Menu Productos";
gotoxy(10,4);  cout<<"---------------";
gotoxy(10,5);  cout<<"1) Nuevo producto";
gotoxy(10,6);  cout<<"2) Editar producto";
gotoxy(10,7);  cout<<"3) Eiminar producto";
gotoxy(10,8);  cout<<"4) Listar producto";
gotoxy(10,9);  cout<<"5) Listar todas los productos";
gotoxy(10,10);  cout<<"6) Activar producto";
gotoxy(10,11); cout<<"---------------";
gotoxy(10,12); cout<<"0) Volver";
gotoxy(10,14); cout<<"Ingrese opcion: ";
cin>>opc;

    switch(opc){
    case 1: menu_1_1(); break;
    case 2: menu_1_2(); break;
    case 3: menu_1_3(); break;
    case 4: menu_1_4(); break;
    case 5: menu_1_5(); break;
    case 6: menu_1_6(); break;
    case 0: return; break;
    default:
    gotoxy(13,17);
    textcolor(cBLANCO,cROJO_CLARO);
    cout<<"* OPCION INCORRECTA *";
    pausa();
    break;
    }
}
}

/************ CLIENTES ************/

void menu_2(){
int opc;
while(true){
textcolor(0,0);
clrscr();
recuadro(8, 1, 35, 19, cAZUL_CLARO, cBLANCO);

textcolor(cROJO_CLARO, cBLANCO);
gotoxy(33,2);
cout<<fsistema.getDia()<<"/"<<fsistema.getMes()<<"/"<<fsistema.getAnio();

textcolor(cAZUL_CLARO, cBLANCO);

gotoxy(10,3);  cout<<"Menu Clientes";
gotoxy(10,4);  cout<<"---------------";
gotoxy(10,5);  cout<<"1) Nuevo cliente";
gotoxy(10,6);  cout<<"2) Editar cliente";
gotoxy(10,7);  cout<<"3) Eliminar cliente";
gotoxy(10,8);  cout<<"4) Listar cliente";
gotoxy(10,9);  cout<<"5) Listar todos los clientes";
gotoxy(10,10); cout<<"---------------";
gotoxy(10,11); cout<<"0) Volver";
gotoxy(10,13); cout<<"Ingrese opcion: ";
cin>>opc;

    switch(opc){
    case 1: menu_2_1(); break;
    case 2: menu_2_2(); break;
    case 3: menu_2_3(); break;
    case 4: menu_2_4(); break;
    case 5: menu_2_5(); break;
    case 0: return; break;
    default:
    gotoxy(13,17);
    textcolor(cBLANCO,cROJO_CLARO);
    cout<<"* OPCION INCORRECTA *";
    pausa();
    break;
    }
}
}

/************ COMPRAS ************/

void menu_3(){
int opc;
while(true){
textcolor(0,0);
clrscr();
recuadro(8, 1, 35, 19, cAZUL_CLARO, cBLANCO);
gotoxy(10,3);  cout<<"Menu Compras";
gotoxy(10,4);  cout<<"---------------";
gotoxy(10,5);  cout<<"1) Nueva compra";
gotoxy(10,6);  cout<<"2) Listar compra";
gotoxy(10,7);  cout<<"3) Listar detalle de compra";
gotoxy(10,8);  cout<<"4) Listar todas las compras";
gotoxy(10,10); cout<<"---------------";
gotoxy(10,11); cout<<"0) Volver";
gotoxy(10,13); cout<<"Ingrese opcion: ";
cin>>opc;

    switch(opc){
    case 1: menu_3_1(); break;
    case 2: menu_3_2(); break;
    case 3: menu_3_3(); break;
    case 4: menu_3_4(); break;
    case 0: return; break;
    default:
        gotoxy(13,17);
        textcolor(cBLANCO,cROJO_CLARO);
        cout<<"* OPCION INCORRECTA *";
        pausa();
    break;
    }
}
}

/************ VENTAS ************/

void menu_4(){
int opc;
while(true){
textcolor(0,0);
clrscr();
recuadro(8, 1, 35, 19, cAZUL_CLARO, cBLANCO);

textcolor(cROJO_CLARO, cBLANCO);
gotoxy(33,2);
cout<<fsistema.getDia()<<"/"<<fsistema.getMes()<<"/"<<fsistema.getAnio();

textcolor(cAZUL_CLARO, cBLANCO);

gotoxy(10,3);  cout<<"Menu Ventas";
gotoxy(10,4);  cout<<"---------------";
gotoxy(10,5);  cout<<"1) Nueva venta";
gotoxy(10,6);  cout<<"2) Listar venta";
gotoxy(10,7);  cout<<"3) Listar detalle de venta";
gotoxy(10,8);  cout<<"4) Listar todas las ventas";
gotoxy(10,10); cout<<"---------------";
gotoxy(10,11); cout<<"0) Volver";
gotoxy(10,13); cout<<"Ingrese opcion: ";
cin>>opc;

    switch(opc){
    case 1: menu_4_1(); break;
    case 2: menu_4_2(); break;
    case 3: menu_4_3(); break; // va con el remito
    case 4: menu_4_4(); break;
    case 0: return; break;
    default:
        gotoxy(13,17);
        textcolor(cBLANCO,cROJO_CLARO);
        cout<<"* OPCION INCORRECTA *";
        pausa();
    break;
    }
}
}

/************ REPORTES ************/

void menu_5(){
int opc;
while(true){
textcolor(0,0);
clrscr();
recuadro(8, 1, 35, 19, cAZUL_CLARO, cBLANCO);

textcolor(cROJO_CLARO, cBLANCO);
gotoxy(33,2);
cout<<fsistema.getDia()<<"/"<<fsistema.getMes()<<"/"<<fsistema.getAnio();

textcolor(cAZUL_CLARO, cBLANCO);

gotoxy(10,3);  cout<<"Menu Reportes";
gotoxy(10,4);  cout<<"---------------";
gotoxy(10,5);  cout<<"1) Recaudacion en el anio elegido";
gotoxy(10,6);  cout<<"2) ";
gotoxy(10,7);  cout<<"3) ";
gotoxy(10,8);  cout<<"4) ";
gotoxy(10,9);  cout<<"5) ";
gotoxy(10,10); cout<<"---------------";
gotoxy(10,11); cout<<"0) Volver";
gotoxy(10,13); cout<<"Ingrese opcion: ";
cin>>opc;

    switch(opc){
    case 1: menu_5_1(); break;
    case 2: //menu_5_2(); break;
    case 3: //menu_5_3(); break;
    case 4: //menu_5_4(); break;
    case 5: //menu_5_5(); break;
    case 6: //menu_5_6(); break;
    case 0: return; break;
    default:
        gotoxy(13,17);
        textcolor(cBLANCO,cROJO_CLARO);
        cout<<"* OPCION INCORRECTA *";
        pausa();
    break;
    }
}
}

/************ CONFIGURACION ************/

void menu_6(){
int opc;
while(true){
textcolor(0,0);
clrscr();
recuadro(8, 1, 35, 19, cAZUL_CLARO, cBLANCO);

textcolor(cROJO_CLARO, cBLANCO);
gotoxy(33,2);
cout<<fsistema.getDia()<<"/"<<fsistema.getMes()<<"/"<<fsistema.getAnio();

textcolor(cAZUL_CLARO, cBLANCO);

gotoxy(10,3);  cout<<"Menu Configuracion";
gotoxy(10,4);  cout<<"---------------";
gotoxy(10,5);  cout<<"1) Establecer datos de inicio";
/*gotoxy(10,6);  cout<<"2) ";
gotoxy(10,7);  cout<<"3) ";
gotoxy(10,8);  cout<<"4) ";
gotoxy(10,9);  cout<<"5) ";
*/
gotoxy(10,10); cout<<"---------------";
gotoxy(10,11); cout<<"0) Volver";
gotoxy(10,13); cout<<"Ingrese opcion: ";
cin>>opc;

    switch(opc){
    case 1: menu_6_1(); break;
    case 2: //menu_6_2(); break;
    case 3: //menu_6_3(); break;
    case 4: //menu_6_4(); break;
    case 5: //menu_6_5(); break;
    case 6: //menu_6_6(); break;
    case 0: return;
    break;
    default:
        gotoxy(13,17);
        textcolor(cBLANCO,cROJO_CLARO);
        cout<<"* OPCION INCORRECTA *";
        pausa();
    break;
    }
}
}

#endif // SUBMENUS_H_INCLUDED
