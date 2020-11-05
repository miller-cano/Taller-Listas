#include <fstream>
#include <string>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct informacion
{
		string nombre; 
        long numero;
        string tipoContacto;
};

struct nodo
{
       struct informacion info; 						    
       struct nodo *sgte;
};
////////////////////////////////////////////////////////////////////////
struct nodo * crearLista()
{
	struct nodo *cabeza;
    cabeza = new(struct nodo);
    cabeza->sgte = cabeza;
    cabeza->info.nombre="Soy el Nodo cabecera";
    return cabeza;
}
///////////////////////////////////////////////////////////////////////
void insertarInicio(struct nodo *cabeza, struct informacion datos)
{
    struct nodo *nuevo, *p;
    nuevo = new(struct nodo);
    nuevo->info = datos;
    nuevo->sgte = cabeza->sgte;
    cabeza->sgte=nuevo;
}
///////////////////////////////////////////////////////////////////////
void cargarArchivo(struct nodo *cabeza)
{
	struct informacion datos;
    ifstream archivo;
    archivo.open("agendaTelefonica.txt");
	if (archivo.is_open()){
		while(!archivo.eof()){
			archivo>>datos.nombre>>datos.numero>>datos.tipoContacto;
			insertarInicio(cabeza, datos); 			
		}
		archivo.close();
	//	mostrarLista(cabeza);	
	}
	else {
	    cout<<"*************  archivo no encontrado **** "<<endl;
	}
}
//////////////////////////////////////////////////////////////////////
void ordenarLista(struct nodo *cabeza)
{
	struct nodo *p;
	p = cabeza->sgte;
	if(p != cabeza && p->sgte != cabeza){
		struct nodo *q = NULL, *t = NULL;
		q = p;
		string auxNombre;
		string auxTipoContacto;
		long auxNumero;
		while(q->sgte != cabeza){
			t = q->sgte;
			while(t != cabeza){
				if(t->info.numero < q->info.numero){
					auxNumero = q->info.numero;
					auxNombre = q->info.nombre;
					auxTipoContacto = q->info.tipoContacto;
					q->info.nombre = t->info.nombre;
					q->info.numero = t->info.numero;
					q->info.tipoContacto = t->info.tipoContacto;
					t->info.nombre = auxNombre;
					t->info.numero = auxNumero;
					t->info.tipoContacto = auxTipoContacto;
				}
				t = t->sgte;
			}
			q = q->sgte;
		}
		cout<<"\n ************************************";
		cout<<"\n |          LISTA ORDENADA          |";
		cout<<"\n ************************************"<<endl;	
	}
	else{
		cout<<"\n **********************************************";
		cout<<"\n |          NO HAY DATOS EN LA LISTA          |";
		cout<<"\n **********************************************"<<endl;
	}
}
///////////////////////////////////////////////////////////////////////////

void insertarOrdenado(struct nodo *cabeza, struct informacion datos)
{
	ordenarLista(cabeza);
	struct nodo *nuevo , *p = NULL, *a = NULL;
	nuevo = new(struct nodo);
	nuevo->info = datos;
	if(cabeza->sgte == cabeza){
		cabeza->sgte = nuevo;
		nuevo->sgte = cabeza;
	}
	else{
		p = cabeza->sgte;
		if(datos.numero < p->info.numero){
			nuevo->sgte = p;
			cabeza->sgte = nuevo;
		}
				else{
					while(datos.numero > p->info.numero){
						a = p;
						p = p->sgte;
					}
					a->sgte = nuevo;
					nuevo->sgte = p;
				}
	}
	cout<<"\n ************************************";
	cout<<"\n |          DATO INSERTADO          |";
	cout<<"\n ************************************"<<endl;
}
/////////////////////////////////////////////////////////////////////////////




