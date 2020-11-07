#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "FuncionesListasCS.h"
#include "FuncionesListasSimple.h"
using namespace std;

int main(){
	struct Nodo *lista;
	int opm,op, x, y, z, v,dato,i,espacios;
	long Numb;
	string TP;
	struct informacion datos;
	do{
	system ("color 3B");
	
	cout<<"\n*******************************";
	cout<<"\n|      MENU PRINCIPAL"<<"         |";
	cout<<"\n*******************************";
	cout<<"\n| 1. Ejercicio Numero 1"<<"       |";
	cout<<"\n*******************************";
	cout<<"\n| 2. Ejercicio Numero 11"<<"      |";
	cout<<"\n*******************************";
	cout<<"\n| 3. Terminar"<<"                 |";
	cout<<"\n*******************************";
	cout<<"\n|    Elija una opcion:";cin>>opm;
	cout<<"*******************************";
	
	
	
	switch (opm){
		
		case 1 :
			do{
				cout<<"\n\n\n*******************************";
				cout<<"	\n|   EJERCICIO NUMERO 1"<<"        |";
				cout<<"\n*******************************";
				cout<<"\n| 1. Crear Lista" <<"              |";
				cout<<"\n*******************************";
				cout<<"\n| 2. Cantidad de veces de X, Y" <<"|";
				cout<<"\n*******************************";
				cout<<"\n| 3. Intercambiar Posiciones" <<"  |";
				cout<<"\n*******************************";
				cout<<"\n| 4. Terminar" <<"                 |";
				cout<<"\n*******************************";
				cout<<"\n|    Elija una opcion:";cin>>op;
				cout<<"*******************************";
				
				switch (op){
					
					case 1:
						cout<<"\n\n Ingrese El Dato: ";
						cin>>dato;
						lista = crearLista(lista,dato);
					    system("pause");break;

					case 2: cout<<"\nIngrese el Numero 1(X): ";
							cin>>x;
							cout<<"\nIngrese el Numero 2(Y): ";
							cin>>y;
							contarIguales(lista,x,y);
							system("pause");break;
				
					
					case 3: cout<<"\nPosicion 1 (z): ";
							cin>>z;
							cout<<"\nPosicion 2 (v): ";
							cin>>v;
							lista=interPos(lista,z,v);
							system("pause");break;
							
							
				}
			}while(op>0 && op<4);system("pause");break;
	
		
		
		case 2: 
			do{
				struct nodo *cabeza;
				/*cabeza = crearLista();
				cargarArchivo(cabeza);*/
				
				cout<<"\n\n\n*******************************";
				cout<<"	\n|   EJERCICIO NUMERO 11"<<"       |";
				cout<<"\n*******************************";
				cout<<"\n| 1. Insertar Ordenado" <<"        |";
				cout<<"\n*******************************";
				cout<<"\n| 2. Buscar Contacto" <<"          |";
				cout<<"\n*******************************";
				cout<<"\n| 3. Borrar Contacto" <<"          |";
				cout<<"\n*******************************";
				cout<<"\n| 4. Mostrar contactos por tipo"<<"|"
						 "(Trabajo,Estudio,Familia,amigos)  |";
				cout<<"\n*******************************";
				cout<<"\n| 5. Terminar" <<"                 |";
				cout<<"\n*******************************";
				cout<<"\n|    Elija una opcion:";cin>>op;
				cout<<"*******************************";
				
				if (op == 2 || op == 3){
					cout<<"Numero de contacto: ";
					cin>>Numb;
				}	
				
				switch (op){
					
					case 1:
					cout<<"\nIngrese Los datos del Contacto en el siguiente orden:	\n1. Nombre  \n2.Numero \n3. Tipo de contacto (Trabajo,Estudio,Familia,Amigos) ";
					cin>>datos.nombre>>datos.numero>>datos.tipoContacto;
					insertarOrdenado(cabeza,datos);
					system("pause"); break;
					
					case 2: BuscarNumero(cabeza,Numb);
					system("pause"); break;
					
					case 3: eliminarElementoInfo(cabeza,Numb);
					system("pause"); break;
					
					case 4: 
					
					cout<<"\nTipo de contacto que desea ver(Trabajo,estudio,familia,amigos): ";
					cin>>TP;
					
					
					for(i=0;i<TP.length();i++){
						TP[i]=toupper(TP[i]);
					}
					mostrarListaTC(cabeza,TP);
					system("pause"); break;
				
				
				}
		}while(op>0 && op<5);system("pause");break;
		
	case 3: cout <<"Gracias Por Revisar El Proyecto"; system("pause");break;			
	}
		system ("cls");
}while (opm>=0 && opm<3);
cout<<"\nEl proyecto ha finalizado";


return 0;
}
