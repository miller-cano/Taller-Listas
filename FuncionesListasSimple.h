#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

/////////////////////////////////////////////
struct Nodo
{
    int dato; 
    struct Nodo *sgte;
};
///////////////////////////////////////////////////////////
void mostrarLista(struct Nodo *lista){
	int i = 1;
	struct Nodo *p;
	p = lista;
	if(p != NULL){
		cout<<"\n\t*****************************************";
		cout<<"\n\t|                 LISTA                 |";
		cout<<"\n\t*****************************************";
		while(p != NULL) {
			cout<<"\n\t|   "<<i<<") "<<p->dato;
			p = p->sgte;
			i++;
		}
		cout<<"\n\t*****************************************"<<endl;
	}
}
///////////////////////////////////////////////////////////////////
struct Nodo *crearLista(struct Nodo *lista, int dato)
{	
	struct Nodo *nuevo;
    nuevo = new(struct Nodo);
	nuevo->dato = dato;
	if(lista == NULL){
		nuevo->sgte = NULL;
		lista = nuevo;
		cout<<"\n ***************************************************";
		cout<<"\n |          LISTA CREADA Y DATO INSERTADO          |";
		cout<<"\n ***************************************************"<<endl;
	}
	else{
		nuevo->sgte = lista;
		lista = nuevo;
		cout<<"\n ************************************";
		cout<<"\n |          DATO INSERTADO          |";
		cout<<"\n ************************************"<<endl;
	}
	return lista;
}
/////////////////////////////////////////////////
void contarIguales(Nodo *lista,int x, int y)
{
	struct Nodo *p;
	int i = 1;
	int contX = 0, contY = 0;
	bool band = false;
	
	if(lista == NULL){
		cout<<"\n *****************************************";
		cout<<"\n |          LA LISTA ESTA VACIA          |";
		cout<<"\n *****************************************"<<endl;
	}
	else{
		p = lista;
		while(p != NULL){
			if(p->dato == x){
				cout<<"\n ************************************************************************";
				cout<<"\n |          ELEMENTO "<<x<<" ENCONTRADO EN LA POSICION ["<<i<<"]";
				cout<<"\n ************************************************************************"<<endl;
				contX++;
				band = true;
			}
			if(p->dato == y){
				cout<<"\n ************************************************************************";
				cout<<"\n |          ELEMENTO "<<y<<" ENCONTRADO EN LA POSICION ["<<i<<"]";
				cout<<"\n ************************************************************************"<<endl;
				contY++;
				band = true;
			}
			p = p->sgte;
			i++;
		}	
		if(band == false){
			cout<<"\n *************************************************************************************";
			cout<<"\n |          NO SE ENCONTRO EL VALOR DE "<<x<<" NI EL VALOR "<<y<<" EN LA LISTA";
			cout<<"\n *************************************************************************************"<<endl;
		}
		else{
			cout<<"\n *******************************************************************************";
			cout<<"\n |          EL ELEMENTO "<<x<<" SE ENCONTRO "<<contX<<" VECES EN LA LISTA";
			cout<<"\n *******************************************************************************"<<endl;
			cout<<"\n *******************************************************************************";
			cout<<"\n |          EL ELEMENTO "<<y<<" SE ENCONTRO "<<contY<<" VECES EN LA LISTA";
			cout<<"\n *******************************************************************************"<<endl;
		}
	}	
}
//////////////////////////////////////////////////////////////////////////
struct Nodo *interPos(struct Nodo *lista, int pos1, int pos2)
{
	struct Nodo *p,*q,*r;
	int i = 1, aux1 = 0;
	bool band1 = false ,band2 = false;
	if(lista == NULL){
		cout<<"\n *****************************************";
		cout<<"\n |          LA LISTA ESTA VACIA          |";
		cout<<"\n *****************************************"<<endl;
	}
	else{
		p = lista;
		while(p != NULL){
			if(pos1 == i){
				q = p;
				band1 = true;
			}
			if(pos2 == i){
				r = p;
				band2 = true;
			}
			p = p->sgte;
			i++;
		}
		if((band1 == true) && (band2 == true)){
			aux1 = q->dato;
			q->dato = r->dato;
			r->dato = aux1;
			cout<<"\n *********************************************************************";
			cout<<"\n |          LA INFORMACION DE LOS NODOS SE HA INTERCAMBIADO          |";
			cout<<"\n *********************************************************************"<<endl;
		}
		else{
			cout<<"\n ******************************************************";
			cout<<"\n |          LAS POSICIONES NO SE ENCONTRARON          |";
			cout<<"\n ******************************************************"<<endl;
		}	
	}
	return lista;
}
//////////////////////////////////////////////////////////////
void buscarInfor(Nodo *lista, int info1, int info2)
{
	struct Nodo *p;
	int i = 1;
	p = lista;
	while(p != NULL){	
		if(p->dato == info1){
			cout<<"\n *******************************************************************************";
			cout<<"\n |          LA INFORMACION 1 ["<<info1<<"] SE ENCONTRO EN LA POSICION "<<i;
			cout<<"\n *******************************************************************************"<<endl;
		}
		if(p->dato == info2){
			cout<<"\n *******************************************************************************";
			cout<<"\n |          LA INFORMACION 2 ["<<info2<<"] SE ENCONTRO EN LA POSICION "<<i;
			cout<<"\n *******************************************************************************"<<endl;
		}
		p = p->sgte;
		i++;
	}
}
//////////////////////////////////////////////////////////////
