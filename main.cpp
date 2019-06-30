#include <iostream>
using namespace std;
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <exception>
#include <stdexcept>
#include <conio.h>

#include "Fecha.h"

Fecha fsistema;
#include "clases.h"
#include "funciones.h"
#include "Cuadros.h"
#include "submenus.h"
#include "Productos.h"
#include "Clientes.h"
#include "Compras.h"
#include "Detalle_Compras.h"
#include "Ventas.h"
#include "Detalle_Ventas.h"
#include "Configuracion.h"
#include "Reportes.h"

void menu_1();
void menu_2();
void menu_3();
void menu_4();
void menu_5();
void menu_6();
void menu_7();



int main(){


while(true){

textcolor(0,0);
clrscr();

recuadro(8, 1, 35, 19, cAZUL_CLARO, cBLANCO);

textcolor(cROJO_CLARO, cBLANCO);
gotoxy(33,2);
cout<<fsistema.getDia()<<"/"<<fsistema.getMes()<<"/"<<fsistema.getAnio();

textcolor(cAZUL_CLARO, cBLANCO);

gotoxy(10,3);  cout<<"Menu principal";
gotoxy(10,4);  cout<<"---------------";
gotoxy(10,5);  cout<<"1) Productos";
gotoxy(10,6);  cout<<"2) Clientes";
gotoxy(10,7);  cout<<"3) Compras";
gotoxy(10,8);  cout<<"4) Ventas";
gotoxy(10,9);  cout<<"5) Reportes";
gotoxy(10,10); cout<<"6) Configuracion";
gotoxy(10,11); cout<<"---------------";
gotoxy(10,12); cout<<"0) Salir";
int opc;
gotoxy(10,14); cout<<"Ingrese opcion: ";
cin>>opc;
    switch(opc){
    case 1: menu_1(); break;
    case 2: menu_2(); break;
    case 3: menu_3(); break;
    case 4: menu_4(); break;
    case 5: menu_5(); break;
    case 6: menu_6(); break;
    case 0:
        textcolor(cNEGRO);
        gotoxy(15, 21);
        exit(1);
    default:
    gotoxy(13,17);
    textcolor(cBLANCO,cROJO_CLARO);
    cout<<"* OPCION INCORRECTA *";
    pausa();
    break;
    }
}
}
