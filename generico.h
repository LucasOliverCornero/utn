
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

template<typename T> void ingresar(T a[], int *i ,T (*ingresarD)(),int cantida){

        char seleccion[1];
        string auxSeleccion;
        bool flag1,flag2;
        
      do{
				flag1=false;
                flag2=false;
                
                a[*i]=ingresarD();
				
				do{
				
                cout<<"Ingrese \"S\" para seguir o \"N\" para salir.(S/N): ";
                cin>>auxSeleccion;
				strncpy(seleccion,auxSeleccion.c_str(),1);	
				
				cout<<endl;
				
				if(seleccion[0]=='s'||seleccion[0]=='S'){
					flag1=true;
				}
					else if(seleccion[0]=='n'||seleccion[0]=='N'){
						flag1=true;
						flag2=true;
						
						}
							else{			
								flag1=false;
								cout<<endl<<"Error al introducir datos... Vuelve a intentar"<<endl<<endl;
							 }
				
				}while(flag1==false);
				
                (*i)++;
     
        }while ( flag2==false && *i<cantida);

}


template<typename T> void ordenar(T v[], int t,bool (*criterio)(T,T)){

        T aux;

        for(int i=1; i<t; i++) {
                for (int j=0; j<t-i; j++) {

                        if(criterio(v[j],v[j+1])==true) {
                                aux = v[j];
                                v[j] = v[j+1];
                                v[j+1] = aux;
                        }
                }
        }
}


template<typename T> void mostrarV(T v[], int t,void (*mostrar)(T)){
   
   for(int i=0;i<t;i++){

	   mostrar(v[i]);
	}

}
