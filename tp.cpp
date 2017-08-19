//==============================================================================
// Tema: Trabajo Practico 01
// Curso: k1030
// Grupo: Karina Andrea Franco , Leonardo Martín Hanashiro y Lucas Oliver Cornero
//===============================================================================

#include <iostream>
#include "generico.h"
#include <stdio.h>
#include <string.h>

using namespace std;

const int CANTIDAD=100;

struct Dato{

	int patente;
	char marca[23];
	char modelo[23];
	int anoPatentamiento;
	char apellido[23] ;
	char nombre[23];
};

Dato ingresarDato();
void ingresarMostrar(Dato [] ,int  ,int);
void mostrar(Dato );
bool criterio1(Dato  , Dato );
bool criterio2(Dato , Dato );
bool criterio3(Dato , Dato );
void corteDeControl(Dato [], int );

int main() {

		Dato dato[CANTIDAD];
		int ano=0;
		int tamanio=0;

		ingresar<Dato>(dato,&tamanio,ingresarDato,CANTIDAD);

		ordenar<Dato>(dato,tamanio,criterio1);

		cout << "----------------------------------------------" << endl;
		cout << "*Ordenados por patente de menor a mayor: " << endl << endl;

		mostrarV<Dato>(dato,tamanio,mostrar);
		getchar();
		cout << "--------Presione Enter para continuar---------";
		getchar();

		cout << endl << "*Segun el ano ingresado con el ano de patentamiento" << endl ;
		cout <<"  ordenados de menor a mayor: "<<endl<<endl;
		ingresarMostrar(dato,tamanio,ano);
		getchar();
		cout << "--------Presione Enter para continuar---------";
		getchar();



		cout << endl << "*Ordenado por cantidad de autos segun la marca. " << endl;
		cout << "De menor a mayor:" << endl << endl;

		ordenar<Dato>(dato,tamanio,criterio2);
		ordenar<Dato>(dato,tamanio,criterio3);

		corteDeControl(dato,tamanio);

		cout << endl <<"--------Presione Enter para salir---------";
		getchar();


	return 0;
}

Dato ingresarDato(){

		Dato d;
		int aux;
		char tipoError;

	do{
			aux=0;

			cout << "Ingresar patente: ";
			cin >> d.patente;

		if(!cin){

				cin.clear();
				cin.ignore(1024,'\n');
				tipoError='a';
		}
		else
			 aux+=1;

			cout << "Ingresar marca: ";
			cin >> d.marca;

			cout << "Ingresar modelo: ";
			cin >> d.modelo;

			cout << "Ingresar año patentamiento: ";
			cin >> d.anoPatentamiento;

		if(!cin){

				cin.clear();
				cin.ignore(1024,'\n');
				tipoError='b';
		}
		else
			 aux+=1;

				cout << "Ingresar apellido: ";
				cin  >> d.apellido;

				cout << "Ingresar el nombre: ";
				cin >> d.nombre;

				cout << endl;

		switch(aux){

			case 0:	cout<<"Datos invalidos en : PATENTE y PATENTEAMINETO .Vuelva a intentar"<<endl<<endl;break;
			case 1: {

				if(tipoError=='a')
					cout<<"Datos invalidos en la PATENTE.Vuelva a intentar"<<endl<<endl;

					else
						cout<<"Datos invalidos en el PATENTEAMINETO.Vuelva a intentar"<<endl<<endl;

				}break;
			}
	} while(aux!=2);

	return d;
}

void ingresarMostrar(Dato v[], int p , int ano){

	int cont=0;
	int error;

	do{
		error=0;
		cout << endl << "ingrese el ano de patentamiento: ";
		cin >> ano;
		cout << endl;

			if(!cin){
				cin.clear();
				cin.ignore(1024,'\n');
				cout<<endl<<"Error al introducir datos... Vuelve a intentar"<<endl<<endl;
				error=1;
			}

				else{
					for(int i=0;i<p;i++){

						if(ano == v[i].anoPatentamiento)

							mostrar(v[i]);
						else

							cont++;
					}
				}
	}while(error==1);

	if(p==cont)
		cout<<endl<<"No hay patentamiento en ese ano."<<endl<<endl;

}

void mostrar(Dato v){


        cout << "El numero de patente: "<< v.patente << endl;
        cout << "Marca: "<< v.marca << endl;
        cout << "Modelo: "<< v.modelo << endl;
        cout << "Año de patentamiento: " << v.anoPatentamiento << endl;
        cout << "Apellido: " << v.apellido << endl;
        cout << "Nombre: " << v.nombre << endl;;
        cout << endl << endl;


}

bool criterio1(Dato d1 , Dato d2){


	if(d1.patente > d2.patente)

		return true;

	else

		return false;

	}

bool criterio2(Dato d1,Dato d2){

	if ( strcmp(d1.marca,d2.marca)<0)

		return true;

	else

		return false;

}

bool criterio3(Dato d1,Dato d2){

	if ( strcmp(d1.marca,d2.marca)==0)

		return true;

	else

		return false;

}


void corteDeControl(Dato dato[], int n){

	int i = 0 , cont;
	char marca[23];

	while(i<n){

		strcpy(marca,dato[i].marca);
		cont=0;

		do{

			cont++;
			i++;

		}while((i<n) && (strcmp(dato[i].marca,marca)==0));

			cout<<"marca: "<< marca <<" cantidad: "<< cont << endl;
	}
}
