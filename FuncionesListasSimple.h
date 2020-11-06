#include <iostream>

using namespace std;

struct Nodo{
       int dato; 
       struct Nodo *sgte;
       struct Nodo *lista = NULL;
};

struct Nodo *constList(Nodo *lista){
	
	int dato;
	
	cout<<"\nDigite el dato: ";
	cin>>dato;
	
	struct Nodo *p,*nuevo;
	nuevo = new Nodo;
	nuevo->dato = dato;
	
	if(lista == NULL){
		nuevo->sgte = NULL;
		lista = nuevo;
		cout<<"\nLista creada correctamente ";
	}
	else{
		nuevo->sgte = lista;
		lista = nuevo;
		cout<<"\nElemento ingresado correctamente ";
	}
	
	return (lista);
	
}

void contarIguales(Nodo *lista,int x, int y){
	
	struct Nodo *p;
	int i = 1;
	int contadorx,contadory = 0;
	bool band = false;
	
	if(lista == NULL){
		cout<<"\nNo hay ninguna lista ";
	}
	else{
	
		p = lista;
		
		while(p != NULL){
		
			if(p->dato == x){
				cout<<"\nElemento "<<x<<" encontrado en la posicion "<<i;
				contadorx ++;
				band = true;
			}
		
			if(p->dato == y){
				cout<<"\nElemento "<<y<<" encontrado en la posicion "<<i;
				contadory ++;
				band = true;
			}
		
			p = p->sgte;
			i++;
		}	
	
		if(band == false){
			cout<<"\nNo se ha encontrado el valor "<<x<<" ni el valor "<<y<<" en la lista ";
		}else{
			cout<<"\nEl elemento "<<x<<" se encontro "<<contadorx<<" veces en la lista ";
			cout<<"\nEl elemento "<<y<<" se encontro "<<contadory<<" veces en la lista ";
		}
	
	
	}
	
}

struct Nodo interPos(Nodo *lista,int pos1, int pos2, int info1, int info2){
	
	struct Nodo *p,*q,*r;
	int i = 1;
	int aux1 = 0;
	bool band1,band2 = false;
	
	
	if(lista == NULL){
		cout<<"\nNo hay ninguna lista ";
	}
	else{
		
		cout<<"\nDigite la posicion 1: ";
		cin>>pos1;
		
		cout<<"\nDigite la posicion 2: ";
		cin>>pos2;
		
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
			
			p=p->sgte;
			i++;
		}
		
		if((band1 == true) && (band2 == true)){
			aux1 = q->dato;
			q->dato = r->dato;
			r->dato = aux1;
			cout<<"\nLa informacion de los nodos se ha cambiado ";
		}
		else{
			cout<<"\nEl procedimiento no se pudo realizar, posicion no encontrada ";
		}
		
	}


}

struct Nodo *buscarInfor(Nodo *lista, int info1, int info2){
	
	struct Nodo *p;
	int i = 1;
	
		p = lista;
		while(p!=NULL){
			
			if(p->dato == info1){
				cout<<"\nLa informacion 1 ("<<info1<<") fue encontrada en la posicion "<<i;
			}
			
			if(p->dato == info2){
				cout<<"\nLa informacion 2 ("<<info2<<") fue encontrada en la posicion "<<i;
			}
			
			
			p=p->sgte;
			i++;
		}
	
	
	return (lista);
}

