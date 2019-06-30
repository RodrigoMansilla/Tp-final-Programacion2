#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <windows.h>

enum Color{
cNEGRO=0,
cAZUL=1,
cVERDE=2,
cCIAN=3,
cROJO=4,
cMAGENTA=5,
cMARRON=6,
cGRIS_CLARO=7,
cGRIS=8,
cAZUL_CLARO=9,
cVERDE_CLARO=10,
cCIAN_CLARO=11,
cROJO_CLARO=12,
cMAGENTA_CLARO=13,
cAMARILLO=14,
cBLANCO=15,
};

void clrscr(void){
    system("cls");
}
void pausa(void){
    system("pause >nul");
}

void gotoxy(short x, short y){
    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
void textcolor(short colorTexto=15, short colorFondo=0){
    short color = colorTexto + colorFondo * 16;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), color);
}
void recuadro(short iniX, short iniY, short ancho, short alto, short colorLinea=cBLANCO, short colorFondo=cNEGRO){
    int i, j;
    for(i=iniX; i<=iniX+ancho; i++){
        for(j=iniY; j<=iniY+alto; j++){
            gotoxy(i, j);
            textcolor(colorLinea, colorFondo);

            //Arriba izquierda
            if(i==iniX && j==iniY){
                cout << (char) 201;
            }
            //Arriba derecha
            else if(i==iniX+ancho && j==iniY){
                cout << (char) 187;
            }
            //Abajo izquierda
            else if(i==iniX && j==iniY+alto){
                cout << (char) 200;
            }
            //Abajo derecha
            else if(i==iniX+ancho && j==iniY+alto){
                cout << (char) 188;
            }

            //Lineas arriba y abajo
            else if(j==iniY || j==iniY+alto){
                cout << (char) 205;
            }
            //Lineas izquierda y derecha
            else if(i==iniX || i==iniX+ancho){
                cout << (char) 186;
            }

            //Dentro del recuadro
            else{
                cout << " ";
            }
        }
    }
}

void cuadro(short iniX, short iniY, short ancho, short alto, short colorLinea=cBLANCO, short colorFondo=cNEGRO){
    int i, j;
    for(i=iniX; i<=iniX+ancho; i++){
        for(j=iniY; j<=iniY+alto; j++){
            gotoxy(i, j);
            textcolor(colorLinea, colorFondo);

            //Arriba izquierda
            if(i==iniX && j==iniY){
                cout << (char) 218;
            }
            //Arriba derecha
            else if(i==iniX+ancho && j==iniY){
                cout << (char) 191;
            }
            //Abajo izquierda
            else if(i==iniX && j==iniY+alto){
                cout << (char) 192;
            }
            //Abajo derecha
            else if(i==iniX+ancho && j==iniY+alto){
                cout << (char) 217;
            }

            //Lineas arriba y abajo
            else if(j==iniY || j==iniY+alto){
                cout << (char) 196;
            }
            //Lineas izquierda y derecha
            else if(i==iniX || i==iniX+ancho){
                cout << (char) 179;
            }

            //Dentro del recuadro
            else{
                cout << " ";
            }
        }
    }
}

void lineah(short iniX, short iniY, short ancho, short colorLinea=cBLANCO, short colorFondo=cNEGRO){
    int i, j;
    j=iniY;
    for(i=iniX; i<=iniX+ancho; i++){
            gotoxy(i, j);
            textcolor(colorLinea, colorFondo);
            cout << (char) 249;
    }
}

void lineav(short iniX, short iniY, short alto, short colorLinea=cBLANCO, short colorFondo=cNEGRO){
    int i, j;
    i=iniX;
    for(j=iniY; j<=iniY+alto; j++){
            gotoxy(i, j);
            textcolor(colorLinea, colorFondo);
            cout << (char) 179;
    }
}





/***********************Sub menus*************************/

void menu_1_1();
void menu_1_2();
void menu_1_3();
void menu_1_4();
void menu_1_5();
void menu_1_6();
//--------------
void menu_2_1();
void menu_2_2();
void menu_2_3();
void menu_2_4();
void menu_2_5();
void menu_2_6();
//--------------
void menu_3_1();
void menu_3_2();
void menu_3_3();
void menu_3_4();
void menu_3_5();
void menu_3_6();
//--------------
void menu_4_1();
void menu_4_2();
void menu_4_3();
void menu_4_4();
void menu_4_5();
void menu_4_6();
//--------------
void menu_5_1();
void menu_5_2();
void menu_5_3();
void menu_5_4();
void menu_5_5();
void menu_5_6();
//--------------
void menu_6_1();
void menu_6_2();
void menu_6_3();
void menu_6_4();
void menu_6_5();
void menu_6_6();
//--------------



void volver(void){
textcolor(cBLANCO,cVERDE);
cout<<endl<<endl<<endl<<"Pulse ENTER para volver";
pausa();
}


#endif // FUNCIONES_H_INCLUDED
