#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

void menu_5_1(){
clrscr();
Ventas obj;
int pos=0, total=0, anio;
cout<<"Ingrese anio para conocer la recaudacion: ";
cin>>anio;

if(anio>fsistema.getAnio() || anio<2000){
    textcolor(cROJO_CLARO,cBLANCO);
    cout<<"El anio ingresado es invalido";
    cout<<"No se pudo cargar venta";
    textcolor(cVERDE, cBLANCO);
    cout<<"Pulse ENTER para volver";
    pausa();
    return;
}

while(obj.leerDisco(pos)==1){ //solo busca una!!!!!!!!
        if(obj.getAnio()==anio){
        total+=obj.getimporteTotal();
        }
        pos++;

        }

        if(total==0){
            return;
        }


        cout<<"Total recaudado: "<<total;
    pausa();
}


#endif // REPORTES_H_INCLUDED
