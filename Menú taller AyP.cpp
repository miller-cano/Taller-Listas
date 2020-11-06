#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main(){
	int op, x, y, z, v;
	long Numb;
	string TP;
	do{
	system ("color 7c");
	system ("cls");
	
	cout<<"	principal		"<<endl;
	cout<<"---------------------------";
	cout<<"\n1. ejercicio numero 1";
	cout<<"\n2. ejercicio numero 11";
	cout<<"\n3.	terminar";
	
	cout<<"\nElija una opcion:";
	cin>>op;
	
	
	switch (op){
			
		case 1 :
				cout<<"	Ejercicio numero 1		"<<endl;
				cout<<"---------------------------------";
				cout<<"\n1. crear la lista";
				cout<<"\n2. cuantas veces estan X y Y en la lista";
				cout<<"\n3. Intercambiar Valores";
				cout<<"\n4.	terminar";
				cout<<"\n	Elija una opcion:	";
				cin>>op;
				if (op == 1 || op == 3){
				switch (op){
					
					case 1:// crear lista
					      system("pause");break;

					case 2: cout<<"escriba valor de X";
							cin>>x;
							cout<<"escriba valor de Y";
							cin>>y;
							
							//contadordexy(punta,x,y);
							system("pause");break;
				
					
					case 3: cout<<"\nValor que desea cambiar en Z: ";
							cin>>z;
							cout<<"\nValor que desea cambiar en V: ";
							cin>>v;
							//intercambiar(punta,z,v); system("pause"); break;
					case 4: /**/system("pause");break;
				}
				cout<<endl;
				}
		
		case 2: 
				cout<<"	Ejercicio numero 11		"<<endl;
				cout<<"---------------------------------";
				cout<<"\n1.	Insertar ordenado";
				cout<<"\n2.	Buscar contacto";
				cout<<"\n3.	Borrar contacto";
				cout<<"\n4.	Mostrar la lista (Trabajo, Estudio, Familia, Amigos)";
				cout<<"\n5. Terminar"<<endl;
				cout<<"		Ingrese la opcion:	";
				cin>>op;
				
				if (op == 2 || op == 3){
					cout<<"Numero de contacto: ";
					cin>>Numb;
				}	switch (op){
					case 1: //insertarordenado(cabeza);
					system("pause"); break;
					
					case 2: //BuscarNumero(cabeza,Numb); 
					system("pause"); break;
					
					case 3: //eliminarElmentoInfo(cabeza,Numb);
					system("pause"); break;
					
					case 4: 
					
					cout<<"\nTipo de contacto que desea ver(Trabajo,estudio,familia,amigos): ";
					cin>>TP;
					//MostrarListaTC(cabeza,TP);
					system("pause"); break;
					
					case 5: //GuardarLista(cabeza);
							system("pause");break;
				}	
		case 3: cout <<"Gracias Por Revisar El Proyecto"; system("pause");break;			
	}
}while (op>=0 && op<=3);

return 0;
}
