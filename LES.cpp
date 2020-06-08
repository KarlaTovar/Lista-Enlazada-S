//Karla Tovar

#include <iostream>
#include <stdlib.h>
using namespace std;
 
struct nodo{ //Nodo de una Lista Enlazada Simple
       int num;        
       struct nodo *sig;
};
 
typedef struct nodo *Tlista;//Conjunto de Nodos

void insertarInicio(Tlista &lista, int valor) {
    Tlista q;			 //Se crea una lista
    q = new(struct nodo);//Asigna un Nodo a la Lista vacia
    q->num = valor;      //Asigna un valor al elemento num del Nodo
    q->sig = lista;		 //Asigna la lista original al apuntador siguiente
    lista  = q;			 //La Lista original ahora tiene el Nodo al inicio
}

void insertarFinal(Tlista &lista, int valor) {
    //Se crea dos listas (Una para asignar el valor si la lista esta vacia 
	//y otra para ir corriendo los nodos)
	Tlista t, q = new(struct nodo);
    q->num = valor;//Asigna un valor al elemento num del Nodo
    q->sig = NULL; 
 
    if(lista==NULL) {//Si la lista está vacia q es la lista
        lista = q;
    } else {		 //Corre los Nodos hasta encontrar a NULL
        t = lista;
        while(t->sig!=NULL) {
            t = t->sig;
        }
        t->sig = q;  //Se encontró el final
    }
}

void insertarElemento(Tlista &lista, int valor, int pos) {
    //Se crea dos listas (Una para asignar el valor si la posicion es la primera 
    //y otra para ir corriendo los nodos hasta encontrar la posicion)	
    Tlista q, t;
    int i;
    q = new(struct nodo);
    q->num = valor;
 
    if(pos == 1) { //Si la posicion es la primera 
        q->sig = lista;
        lista = q;
    } else {
        t = lista;
        for(i = 1; t != NULL; i++) { //Recorre las lista hasta encontrar la posicion
            if(i == pos-1) {
                q->sig = t->sig;
                t->sig = q;
                return;
            }
            t = t->sig;
        }
    }
}

void eliminarElemento(Tlista &lista, int valor) {
    Tlista p, t;
    p = lista;
 
    if(lista!=NULL) { 			// Si la lista es NULL está vacia
        while(p!=NULL) {		// Corre la lista
            if(p->num==valor) { 
                if(p==lista){   // Desliga los apuntadores
				    lista = lista->sig;
                } else {
                    t->sig = p->sig;
				}
                delete(p);		// Borra el nodo
                return;
            }
            t = p;			   // Guarda la posición anterior
            p = p->sig;    
        }
    } else {
		cout<<" Lista vacia.";
	}       
}

void mostrarLista(Tlista lista) {
    int i = 0;
    while(lista != NULL) {
        cout <<' '<< i+1 <<") " << lista->num << endl;
        lista = lista->sig;
        i++;
    }
}

void buscarElemento(Tlista lista, int valor) {
    Tlista q = lista;
    int i = 1, encontrado = 0;
    
    while(q!=NULL) {
        if(q->num==valor) {
            cout<<endl<<" Encontrada en posicion "<< i <<endl;
            encontrado = 1;
        }
        q = q->sig;
        i++;
    }
    if(encontrado==0) {
        cout<<"\n\n Numero no encontrado."<< endl;
	}
}

void ordenarLista(Tlista &lista) {	
	Tlista p, aux; 
	int temp;
	p = lista;
	
	while(p->sig != NULL) {
		aux = p->sig;
		while(aux != NULL) {
  			if(p->num > aux->num) {
       			temp = aux->num;
       			aux->num = p->num;
       			p->num = temp;     		
       		}
			aux = aux->sig;
		}
		p = p->sig;
	}
}
    
int main() {
    Tlista lista = NULL;
    int dato, pos;
    cout<< "\n NUMERO A INSERTAR AL INICIO: "; 
	cin>> dato;   
	insertarInicio(lista, dato);
    cout<< "\n NUMERO A INSERTAR AL INICIO: "; 
	cin>> dato;   
	insertarInicio(lista, dato);
    cout<< "\n NUMERO A INSERTAR AL FINAL: "; 
	cin>> dato;
	insertarFinal(lista, dato);		 
	mostrarLista(lista);
	
    cout<< "\n NUMERO A INSERTAR POR POSICION : "; 	
	cin>> dato;	
    cout<<" POSICION: ";
    cin>>pos;
    insertarElemento(lista, dato, pos);
    mostrarLista(lista);
    
    cout<< "\n NUMERO A ELIMINAR: "; 	
	cin>> dato;	
    eliminarElemento(lista, dato);
    mostrarLista(lista);
    
    cout<< "\n NUMERO A BUSCAR: "; 	
	cin>> dato;	
    buscarElemento(lista, dato);
    mostrarLista(lista);
    
    ordenarLista(lista);
    mostrarLista(lista);
}

