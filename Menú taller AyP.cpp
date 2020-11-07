#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "FuncionesListasCS.h"
#include "FuncionesListasSimple.h"

short MENU(){
	short opc;
	system("cls");
	system("color 20");
	cout << "\n\t*****************************************************" << endl;
	cout << "\t|                    MENU LISTAS                    |" << endl;
	cout << "\t*****************************************************" << endl;
	cout << "\t|  (1)  |  EJERCICIO NUMERO 1                       |" << endl;
	cout << "\t|  (2)  |  EJERCICIO NUMERO 11                      |" << endl;
	cout << "\t|  (3)  |  TERMINAR                                 |" << endl;
	cout << "\t*****************************************************" << endl;
	cout << "\n";
	cout << "\tIngrese la opcion deseada: ";
	cin >> opc;
	while(opc < 1 || opc > 3)
	{
		cout << "\a";
		cout << "\n\tValor no valido, ingrese otra vez la opcion: ";
		cin >> opc;
	}
	return opc;
}

short menuPunto1(){
	short opc;
	system("cls");
	system("color 20");
	cout << "\n\t****************************************************************************" << endl;
	cout << "\t|                             MENU EJERCICIO 1                             |" << endl;
	cout << "\t****************************************************************************" << endl;
	cout << "\t|  (1)  |  INSERTAR DATOS EN LA LISTA                                      |" << endl;
	cout << "\t|  (2)  |  CANTIDAD DE VECES QUE ESTA [X] Y [Y]                            |" << endl;
	cout << "\t|  (3)  |  INTERCAMBIAR INFORMACION DE DOS NODOS                           |" << endl;
	cout << "\t|  (4)  |  POSICIONES EN LAS QUE SE ENCUENTRA LAS DOS INFORMACIONES DADAS  |" << endl;
	cout << "\t|  (5)  |  TERMINAR                                                        |" << endl;
	cout << "\t****************************************************************************" << endl;
	cout << "\n";
	cout << "\tIngrese la opcion deseada: ";
	cin >> opc;
	while(opc < 1 || opc > 5)
	{
		cout << "\a";
		cout << "\n\tValor no valido, ingrese otra vez la opcion: ";
		cin >> opc;
	}
	return opc;	
}

short menuPunto2(){
	short opc;
	system("cls");
	system("color 20");
	cout << "\n\t***********************************************************" << endl;
	cout << "\t|                    MENU EJERCICIO 11                    |" << endl;
	cout << "\t***********************************************************" << endl;
	cout << "\t|  (1)  |  INSERTAR ORDENADO                              |" << endl;
	cout << "\t|  (2)  |  BUSCAR CONTACTO                                |" << endl;
	cout << "\t|  (3)  |  BORRAR CONTACTO                                |" << endl;
	cout << "\t|  (4)  |  MOSTRAR CONTACTOS POR TIPO DE CONTACTO         |" << endl;
	cout << "\t|  (5)  |  TERMINAR Y GUARDAR                             |" << endl;
	cout << "\t***********************************************************" << endl;
	cout << "\n";
	cout << "\tIngrese la opcion deseada: ";
	cin >> opc;
	while(opc < 1 || opc > 5)
	{
		cout << "\a";
		cout << "\n\tValor no valido, ingrese otra vez la opcion: ";
		cin >> opc;
	}
	return opc;	
}

int main(int argc, char** argv) {
	short opcion;
	int i;
	short opcionPunto2;
	struct nodo *cabeza = NULL; 
	struct informacion datos;
	long numb;
	string TP;
	struct Nodo *lista = NULL;
	short opcionPunto1;
	int x, y;
	
	do{
		opcion = MENU();
			switch(opcion){
				case 1:
					do{
						opcionPunto1 = menuPunto1();
						switch(opcionPunto1){
							case 1:
								if(lista != NULL){
									mostrarLista(lista);
								}
								cout<<"\nIngrese el dato: ";
								cin>>x;
								lista = crearLista(lista, x);
								mostrarLista(lista);
							    system("pause");
								break;
							case 2: 
								mostrarLista(lista);
								cout<<"\nIngrese el numero 1(X): ";
								cin>>x;
								cout<<"\nIngrese el numero 2(Y): ";
								cin>>y;
								contarIguales(lista, x, y);
								mostrarLista(lista);
								system("pause");
								break;
							case 3: 
								mostrarLista(lista);
								cout<<"\nPosicion 1: ";
								cin>>x;
								cout<<"\nPosicion 2: ";
								cin>>y;
								lista = interPos(lista, x, y);
								mostrarLista(lista);
								system("pause");
								break;
							case 4:
								mostrarLista(lista); 
								cout<<"\nInformacion 1 a buscar: ";
								cin>>x;
								cout<<"\nInformacion 2 a buscar: ";
								cin>>y;
								buscarInfor(lista, x, y);
								mostrarLista(lista);
								system("pause");
								break;		
							case 5:
								cout<<"\nProceso de lista terminado"<<endl;
								break;
						}
					} while(opcionPunto1 != 5);
					system("pause");
					break;
				case 2: 
					cabeza = crearLista();
					cargarArchivo(cabeza);
					do{
						opcionPunto2 = menuPunto2();
						if (opcionPunto2 == 2 || opcionPunto2 == 3){
							cout<<"Numero de contacto: ";
							cin>>numb;
						}	
						switch(opcionPunto2){
							case 1:
								mostrarLista(cabeza);
								cout<<"\nIngrese Los datos del Contacto en el siguiente orden:	\n1. Nombre  \n2.Numero \n3. Tipo de contacto (Trabajo,Estudio,Familia,Amigos) ";
								cin>>datos.nombre>>datos.numero>>datos.tipoContacto;
								insertarOrdenado(cabeza,datos);
								mostrarLista(cabeza);
								system("pause"); 
								break;
							case 2: 
								mostrarLista(cabeza);
								buscarNumero(cabeza,numb);
								mostrarLista(cabeza);
								system("pause"); 
								break;
							case 3: 
								mostrarLista(cabeza);
								eliminarElementoInfo(cabeza,numb);
								mostrarLista(cabeza);
								system("pause"); 
								break;
							case 4: 
								mostrarLista(cabeza);
								cout<<"\nTipo de contacto que desea ver(Trabajo,estudio,familia,amigos): ";
								cin>>TP;
								for(i=0;i<TP.length();i++){
									TP[i]=toupper(TP[i]);
								}
								mostrarListaTC(cabeza,TP);
								mostrarLista(cabeza);
								system("pause"); 
								break;
							case 5:
								guardarLista(cabeza);
								system("pause"); 
								break;
							}
					} while(opcionPunto2 != 5);
					system("pause");
					break;
				case 3: 
					cout<<"\n **************************************************";
					cout<<"\n |           PROCESO DE LISTAS TERMINADO          |";
					cout<<"\n |               HASTA LA PROXIMA!!               |";
					cout<<"\n **************************************************"<<endl;
					break;	
			}
	} while(opcion != 3);
	return 0;
}
