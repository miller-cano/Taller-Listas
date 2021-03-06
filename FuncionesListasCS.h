/********************************************************************************************
* -Funciones de listas circulares simplemente ligadas con nodo de emcabezamiento del punto  *
* 11 del taller de listas                                                                   *
* -Grupo de trabajo: MSCA y SAH                                                             *
* -Fecha de creaci�n: 05/11/2020                                                            *
* -�ltima modificaci�n: 07/11/2020                                                          *
* -Compilado usando TDM-GCC 4.9.2                                                           *                                                                                 *
*********************************************************************************************/

#include <fstream>
#include <string>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct informacion
{
	string nombre; 
    int long long numero;
    string tipoContacto;
};

struct nodo
{
    struct informacion info; 						    
    struct nodo *sgte;
};
/////////////////////////////////////////////////////////////////////
struct nodo * crearLista()
{
    struct nodo *cabeza;
    cabeza = new(struct nodo);
    cabeza->sgte = cabeza;
    cabeza->info.nombre="Soy el Nodo cabecera";
    return cabeza;
}
//////////////////////////////////////////////////////////////////////
void mostrarLista(struct nodo *cabeza)
{	
	int i = 1;
	struct nodo *p;
	p = cabeza->sgte;
	cout<<"\n\t*****************************************************************************";
	cout<<"\n\t|                 CONTACTOS";
	cout<<"\n\t*****************************************************************************";
	while(p != cabeza) {
		cout<<"\n\t|   "<<i<<") "<<p->info.nombre<<"\t\t"<<p->info.numero<<"\t\t"<<p->info.tipoContacto;
		i++;
		p = p->sgte;
	}
	cout<<"\n\t****************************************************************************"<<endl;	
}	
//////////////////////////////////////////////////////////////
void insertarFinal(struct nodo *cabeza, struct informacion  valores){
	struct nodo * nuevo;
	struct nodo *p;	
	nuevo = new(struct nodo);
	nuevo->info = valores;
	nuevo->sgte=cabeza;
	p = cabeza->sgte;
	while(p->sgte!=cabeza){
	      p=p->sgte;
	}
	p->sgte = nuevo;
}
///////////////////////////////////////////////////////////////////////
void cargarArchivo(struct nodo *cabeza)
{
    struct informacion datos;
    ifstream archivo;
    archivo.open("agendaContactos.txt", ios::in);
	if (archivo.is_open()){
		while(!archivo.eof()){
			archivo>>datos.numero>>datos.nombre>>datos.tipoContacto;
			insertarFinal(cabeza, datos); 			
		}
		archivo.close();
		mostrarLista(cabeza);
		system("pause");	
	}
	else {
	    cout<<"\n *******************************************";
		cout<<"\n |          ARCHIVO NO ENCONTRADO          |";
		cout<<"\n *******************************************"<<endl;
		system("pause");
	}
}
///////////////////////////////////////////////////
void ordenarLista(struct nodo *cabeza)
{
	struct nodo *p;
	p = cabeza->sgte;
	if(p != cabeza && p->sgte != cabeza){
		struct nodo *q = NULL, *t = NULL;
		q = p;
		string auxNombre;
		string auxTipoContacto;
		int long long auxNumero;
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
	struct nodo *nuevo , *p = NULL, *a = NULL;
	nuevo = new(struct nodo);
	nuevo->info = datos;
	if(cabeza->sgte == cabeza){
		cabeza->sgte = nuevo;
		nuevo->sgte = cabeza;
	}
	else{
		p = cabeza->sgte;
		if(nuevo->info.numero < p->info.numero){
			nuevo->sgte = p;
			cabeza->sgte = nuevo;
		}
			else{
				while(nuevo->info.numero > p->info.numero && p != cabeza){
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
void eliminarElementoInfo(struct nodo *cabeza, int long long num)
{
    if(cabeza->sgte == cabeza){
        cout<<"\n *****************************************";
        cout<<"\n |          LA LISTA ESTA VACIA          |";
        cout<<"\n *****************************************"<<endl;
    }
    else{
        struct nodo *p, *ant = NULL, *q;
        p = cabeza->sgte;
        if(p->info.numero == num && p->sgte == cabeza){
            cabeza->sgte = cabeza;
            delete p;
            cout<<"\n ************************************";
            cout<<"\n |          DATO ELIMINADO          |";
            cout<<"\n ************************************"<<endl;
        }
            else if(cabeza->sgte != cabeza){
                while((p->info.numero != num) && (p->sgte != cabeza)){
                    ant = p;
                    p = p->sgte;
                }
				if(p->sgte == cabeza && p->info.numero != num){
                    cout<<"\n ******************************************************";
                    cout<<"\n |          DATO NO ENCONTRADO PARA ELIMINAR          |";
                    cout<<"\n ******************************************************"<<endl;
                }
                    else if(ant == NULL){ //si es el primer nodo
                        cabeza->sgte = p->sgte;
                        delete p;
                        cout<<"\n ************************************";
                        cout<<"\n |          DATO ELIMINADO          |";
                        cout<<"\n ************************************"<<endl;
                    }
                        else{
                            ant->sgte = p->sgte;
                            delete p;
                            cout<<"\n ************************************";
                            cout<<"\n |          DATO ELIMINADO          |";
                            cout<<"\n ************************************"<<endl;
                        }
            }
    }
}
////////////////////////////////////////////////////////////////
void buscarNumero(struct nodo *cabeza, int long long num)
{
	struct nodo *p;
	int i = 1;
	p = cabeza->sgte;
	if(p->sgte == cabeza){
		cout<<"\n *****************************************";
        cout<<"\n |          LA LISTA ESTA VACIA          |";
        cout<<"\n *****************************************"<<endl;
	}
	else{
		while(p->sgte != cabeza && p->info.numero != num){
			p = p->sgte;	
			i++;	 	
		}
		if(p->info.numero == num){
			cout<<"\n *****************************************";
			cout<<"\n |          CONTACTO ENCONTRADO          |";
			cout<<"\n *****************************************"<<endl;
			cout<<"\n ************************************************************************************";
			cout<<"\n |          EL CONTACTO BUSCADO SE ENCUENTRA EN LA POSICION DE NODO [ "<<i<<" ]           |";
			cout<<"\n ************************************************************************************"<<endl;
		}
			else{
				cout<<"\n ********************************************";
				cout<<"\n |          CONTACTO NO ENCONTRADO          |";
				cout<<"\n ********************************************"<<endl;
			}
	}			
}
//////////////////////////////////////////////////////////////////////////
void mostrarListaTC(nodo *cabeza, string tpContacto)
{
	int i = 1;
	struct nodo *p;
	p = cabeza->sgte;
	cout<<"\n\t*****************************************************************************";
	cout<<"\n\t|                 CONTACTOS DE TIPO "<<tpContacto;
	cout<<"\n\t*****************************************************************************";
	while(p != cabeza) {
		if(tpContacto == p->info.tipoContacto){
			cout<<"\n\t|   "<<i<<") "<<p->info.nombre<<"\t\t"<<p->info.numero<<"\t\t"<<p->info.tipoContacto;
			i++;
		}
		p = p->sgte;
	}
	cout<<"\n\t****************************************************************************"<<endl;			
}
/////////////////////////////////////////////////////////////////
void guardarLista(nodo *cabeza)
{
	ofstream archContactos;
	struct nodo *p;
	p = cabeza->sgte;
	archContactos.open("Contactos.txt");
	int i = 1;
	if(p->sgte == cabeza){
		cout<<"\n *****************************************";
		cout<<"\n |          LA LISTA ESTA VACIA          |";
		cout<<"\n *****************************************"<<endl;
	}
	if(archContactos.is_open()){
		while(p != cabeza){
			archContactos<<p->info.numero<<" "<<p->info.nombre<<" "<<p->info.tipoContacto<<"\n";
			p=p->sgte;
			i++;						
		}
		archContactos.close();
		cout<<"\n *****************************************************";
		cout<<"\n |          LA LISTA FUE GUARDADA CON EXITO          |";
		cout<<"\n *****************************************************"<<endl;	
	}
	else{
		cout<<"\n **********************************************";
		cout<<"\n |          PROBLEMAS CON EL ARCHIVO          |";
		cout<<"\n **********************************************"<<endl;
	}
}	
/////////////////////////////////////////////////////////////////////////////////////////////////

