#include <iostream>
#include <string>
using namespace std;

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
	





