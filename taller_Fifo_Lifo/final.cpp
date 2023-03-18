#include <iostream>
#include <malloc.h>
using namespace std;
/*
    AUTORES  /  semestre 3 Diurno
    
    Jhon Neiver Valencia Grueso
    Jorge Enrique Segura Rodriguez 
    Juan Camilo Angulo Naboyan
*/
struct paciente{
    float vuelta =0.0;
    int val=0;
    float tiempo=0.0;
    char nombre[30];
    paciente *sig;
};

paciente *cab, *aux, *aux2;
int d,per;
float tiempo_vuelta =0.0;
int registrar(){
   
     cout<<"REGISTRADOR DE ATLETAS"<<endl;
     cout<<"--------------------------"<<endl;

    if(cab==NULL){
         cab=(struct paciente*)malloc(sizeof(struct paciente));
         cout<<"Introduzca el documento de atleta: ";  
         cin>>cab->val;
         cout<<"Introduzca el nombre del atleta: ";
         cin>>cab->nombre;
         cout<<endl;
         cout<<"REGISTRADOR DE VUELTAS"<<endl;
         cout<<"--------------------------"<<endl;
         cout<<"esciba cuantas vueltas son: ";
         cin>>d;
         for(int i = 0; i < d; i++) {
         cout << "Ingresa el tiempo de la vuelta " << i+1 << ": ";
         cin>>tiempo_vuelta;
         cab->tiempo += (tiempo_vuelta)/d; 
         }
         cab->vuelta = tiempo_vuelta;     
      
         cab->sig = NULL;
    }
    else
        {
            aux = (struct paciente*)malloc(sizeof(struct paciente));
            cout<<"introduzca el documento del atleta: ";
            cin>>aux->val;
            cout<<"Introduzca el nombre de atleta: ";
            cin>>aux->nombre;
            cout<<endl;
            cout<<"REGISTRADOR DE VUELTAS"<<endl;
            cout<<"--------------------------"<<endl;
              for(int i = 0; i < d; i++) {
              cout << "Ingresa el tiempo de la vuelta " << i+1 << ": ";
              cin>>tiempo_vuelta;
              aux->tiempo += (tiempo_vuelta)/d;
              }
              aux->vuelta = tiempo_vuelta;
           
            aux->sig=NULL;
            aux2=cab; 
            while (aux2->sig!=NULL)
            {
                aux2 = aux2->sig;
            }
            aux2->sig =aux;
            aux2=aux=NULL;
            free(aux);
            free(aux2);                    
        }
    per++;
    return 0;

    
}

int mostar(){
    
     cout<<"ATLETAS REGISTRADOS"<<endl;
     cout<<"-----------------------"<<endl;
    for(aux=cab; aux!=NULL; aux=aux->sig){
    cout<<"Documento: "<<aux->val<<endl;
    cout<<"Nombre: "<<aux->nombre<<endl;
    cout<<"ultima vuelta: "<<aux->vuelta<<endl;
    cout<<"Promedio de vueltas: "<<aux->tiempo<<endl;
    cout<<"-----------------------"<<endl;
  
    
    }
    
    cout<<"-----------------------"<<endl;
    cout<<" Numero de atletas: "<<per<<endl;
    cout<<"-----------------------"<<endl;
    return 0;
}
int posiciones(){
    
   
}
int main(){
    
    int opc=0;
     
    do{
        cout<<" BIENVENIDO AL MENU "<<endl;
        cout<<"----------------------"<<endl;
        cout<<" (1) registrar atletas"<<endl;
        cout<<" (2) ver atletas"<<endl;
        cout<<" (3) posiciones "<<endl;
        cout<<" (4) salir"<<endl;
        cout<<"--> ";
        cin>>opc;
        switch(opc){
            case 1: registrar();
            break;
            case 2: mostar();
            break;
            case 3: posiciones();
            break;
            case 4:
                   cout<<"SU SECION A ACABADO";
                   break;
            
            default:
            cout<<"opcion no validad";
            break;       
        }
        
    }while(opc != 4);
    {   
      
    }

    {
    
    }

    return 0;
}