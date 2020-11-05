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

void eliminarElementoInfo(nodo *cabeza,long num){
	
    if(cabeza->sgte == NULL){
        cout<<"\n **";
        cout<<"\n |          LA LISTA ESTA VACIA          |";
        cout<<"\n *"<<endl;
    }
    else{
        struct nodo *p, *ant = NULL, *q;
        p = cabeza->sgte;
        if(p->info.numero == num && p->sgte == NULL){
            cabeza->sgte = NULL;
            delete p;
            cout<<"\n **";
            cout<<"\n |          DATO ELIMINADO          |";
            cout<<"\n **"<<endl;
        }
            else if(cabeza->sgte != NULL){
                while((p->info.numero != num) && (p->sgte != NULL)){
                    ant = p;
                    p = p->sgte;
                }

	if(p->sgte == NULL && p->info.numero != num){
                    cout<<"\n **";
                    cout<<"\n |          DATO NO ENCONTRADO PARA ELIMINAR          |";
                    cout<<"\n **"<<endl;
                }
                    else if(ant == NULL){ //si es el primer nodo
                        cabeza->sgte = p->sgte;
                        q = p->sgte;
                        delete p;
                        cout<<"\n **";
                        cout<<"\n |          DATO ELIMINADO          |";
                        cout<<"\n **"<<endl;
                    }
                        else{
                            ant->sgte = p->sgte;
                            if(p->sgte != NULL){
                                q = p->sgte;
        
                            }
                            delete p;
                            cout<<"\n **";
                            cout<<"\n |          DATO ELIMINADO          |";
                            cout<<"\n **"<<endl;
                        }
            }
    }
}
void BuscarNumero(nodo *cabeza,  long Num){
	
	nodo *Recorre=cabeza->sgte;
	long Copia=Num;
	int cifras,pos=1;
	
	while(Copia>=10){
		Copia = Copia/10;
		cifras++;	 
	}	
	
	if (cifras != 10){
		cout<<"\nIngrese un numero valido";
	}else{
		
		 while(recorre != NULL){
		 		
		 		if(recorre->info.numero == Num){
		 			
		 			cout<<"\nEl numero: "<<Num<<" Fue encontrado en la posicion:"<<pos;
		 			break;
				 }
				recorre=recorre->sgte;	
				pos++;	 	
		 }
		 if (recorre==NULL){
		 	cout<<"\nEl contacto no fue encontrado";
		 }
		 
		
	}
				
}


void MostrarListaTC(nodo *cabeza, string TpContacto){
	
	nodo *mostrar=cabeza->sgte;
	
	cout<<"\n Los Contactos De" <<TpContacto<< " son:";
	
	while(mostrar != NULL){
		
		if(TpContacto == mostrar->info.tipoContacto){
						
			cout<<" "<< mostrar->info.nombre<<" "<<mostrar->info.numero<<"\n"; 
			}
	
		mostrar=mostrar->sgte;
					
	}
				
}
	
void MostrarLista(nodo *cabeza){
	
	nodo *mostrar =cabeza->sgte;
	
	cout<<"\nMostrando Lista...";
	
	 while(mostrar != NULL){
	 	
	 	cout<<" "<<mostrar->info.nombre<<" "<<mostrar->info.tipoContacto<<" "<<mostrar->info.numero<<"\n"; 
	 }
}	

void GuardarLista(nodo *cabeza){
	
	ofstream ArchContactos;
	nodo *p=cabeza->sgte;
	
	archivo.open("Contactos.txt ");
	
	int i = 1;
	
	if(p->sgte == NULL){
		cout<<"\nLa lista esta vacia";
	}
	
	if (ArchContactos.is_open()){
		
		while(p != NULL){
			
			ArchContactos<<p->info.nombre<<" "<<p->info.tipoContacto<<" "<<p->info.numero;
			p=p->sgte;
			i++;						
		}
		
	ArchContactos.close();
		
	}else {
		cout<<"\nNo fue posible abrir el archivo";
	}
	

}	



