#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodo
{
	int dato;
	struct nodo *sig;
};

typedef struct nodo *lista;

void menu();
void insertarCabeza(lista &cabeza, int num);
void eliminarCabeza(lista &cabeza);
void insertarCola(lista &cabeza, int num);
void eliminarCola(lista &cabeza);
void mostrarNodos(lista aux);
int contarnodos(lista aux);
void insertarPosicion(lista &cabeza, int num, int pos);
void espejo(lista &cabeza);
void duplicadora(lista &cabeza);
void amplificadora(lista &cabeza, int num);

int main()
{
	int opcion, numero, posicion, num;
	lista cabeza=NULL;
	do
	{
		menu();
		cin>>opcion;
		
		switch(opcion)
		{
			case 1:
				cout<<"ingrese un numero:";
				cin>>numero;
				insertarCabeza(cabeza, numero);
				system("pause");
				break;
			case 2:
				eliminarCabeza(cabeza);
				system("pause");
				break;
			case 3:
				cout<<"ingrese un numero:";
				cin>>numero;
				insertarCola(cabeza, numero);
				system("pause");
				break;
			case 4:
				eliminarCola(cabeza);
				system("pause");
				break;
			case 5:
				mostrarNodos(cabeza);
				system("pause");
				break;
			case 6:
				cout<<"ingrese un numero:";
				cin>>numero;
				cout<<"ingrese una posicion:";
				cin>>posicion;
				insertarPosicion(cabeza, numero, posicion);
				system("pause");
				break;
			case 8:
				espejo(cabeza);
				system("pause");
				break;	
			case 9:
				amplificadora(cabeza, num);
				system("pause");
				break;	
			
		}
		system("cls");	
	}
	while(opcion!=20);	
}

void duplicadora(lista &cabeza)
{
	lista aux;
	aux=cabeza;
	while(aux!=NULL)
	{
		for(int i=1; i<=aux->dato; i++ )
		{
			cout<<aux->dato;
		}
		aux=aux->sig;
	}
	
	}

void amplificadora(lista &cabeza, int num)
{
	lista aux;
	aux=cabeza;
	duplicadora(cabeza);

		for(int i=1; i<=aux->dato;i++)
		{
		int actu=aux->dato;
		aux = new (struct nodo);
		aux->dato=actu;
		aux->sig=cabeza;
		cabeza=aux;
		}
		
}

void espejo(lista &cabeza)
{
	int posicion=contarnodos(cabeza)+1;
	int numeroNodos=contarnodos(cabeza);
	
	lista aux;
	aux=cabeza;
	
	for(int i=1;i<=numeroNodos;i++)
	{
		insertarPosicion(cabeza,aux->dato,posicion);
		aux=aux->sig;		
	}
}

void insertarPosicion(lista &cabeza, int num, int pos)
{
	if(cabeza==NULL)
	{
		cout<<"No hay nodos";	
	}
	else
	{
		if(pos==1)
		{
			insertarCabeza(cabeza, num);
		}
		else
		{
			if(pos==(contarnodos(cabeza)+1))
			{
				insertarCola(cabeza, num);	
			}
			else
			{
				if(pos>contarnodos(cabeza))
				{
					cout<<"no existen tantos nodos";
				}
				else
				{
					lista aux;
					aux=cabeza;
					for(int i=1;i<=(pos-2);i++)
					{
						aux=aux->sig;	
					}
					lista temp;
					temp=new(struct nodo);
					temp->dato=num;
					temp->sig = aux->sig;
					aux->sig=temp;
					aux=NULL;
					temp=NULL;
				}	
			}	
		}	
	}	
}

int contarnodos(lista aux)
{
	int cont=0;
	while (aux!=NULL){
		cont++;
		aux=aux->sig;
	}
	return cont;
}

void eliminarCola(lista &cabeza)
{
	lista aux;
	aux=cabeza;
	
	if(cabeza==NULL)
	{
		cout<<"No hay nodos para eliminar";	
	}
	else
	{
		while(aux->sig->sig!=NULL)
		{
			aux=aux->sig;
		}
		aux->sig=NULL;
	}
}

void insertarCola(lista &cabeza, int num)
{
	lista aux=new (struct nodo);
	aux->dato=num;
	aux->sig=NULL;	
	
	if(cabeza==NULL)
	{
		cabeza=aux;
		aux=NULL;
	}
	else
	{
		lista temp;
		temp=cabeza;
		while(temp->sig!=NULL)
		{
			temp=temp->sig;
		}
		temp->sig=aux;
		aux=NULL;
		temp=NULL;	
	}
}

void eliminarCabeza(lista &cabeza)
{
	lista aux;
	if(cabeza==NULL)
	{
		cout<<"No hay nodos para eliminar";	
	}
	else
	{
		aux=cabeza;
		cabeza=cabeza->sig;
		aux->sig=NULL;
		aux=NULL;
	}	
}

void mostrarNodos(lista aux)
{
	while(aux!=NULL)
	{
		cout<<aux->dato;
		aux=aux->sig;
		cout<<endl;
	}
}

void insertarCabeza(lista &cabeza, int num)
{
	lista aux;
	aux = new (struct nodo);
	aux->dato=num;
	aux->sig=cabeza;
	cabeza=aux;
	aux=NULL;	
}

void menu()
{
	cout<<"Menu principal"<<endl;
	cout<<"--------------"<<endl;
	cout<<"1. Agregar por la cabeza"<<endl;
	cout<<"2. Eliminar por la cabeza"<<endl;
	cout<<"3. Agregar por la cola"<<endl;
	cout<<"4. Eliminar por la cola"<<endl;
	cout<<"5. Mostrar nodos"<<endl;
	cout<<"6. Agregar en posicion"<<endl;
	cout<<"8. Espejo"<<endl;
	cout<<"9. Duplicadora"<<endl;
	cout<<"20. salir"<<endl;
	cout<<"Ingrese una opcion:"<<endl;
}