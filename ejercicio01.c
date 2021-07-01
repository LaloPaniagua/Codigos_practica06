#include<stdio.h>
#include<stdlib.h>
#include "ejercicio01.h"
NODO* crear_nodo(INFO info){
    NODO* t=(NODO*)malloc(sizeof(NODO));
    t->sig=NULL;
    t->info=info;
    return t;
}
LISTA* crear_lista(){
    LISTA* l=(LISTA*)malloc(sizeof(LISTA));
    l->head=l->tail=NULL;
    l->num=0;
    return l;
}
bool insertar_inicio(LISTA* l,INFO info){
    NODO* nuevo=crear_nodo(info);
    if(l->head==NULL  && l->tail==NULL){
        l->head=l->tail=nuevo;
        l->num++;
        return true;
    }
    else{
        nuevo->sig=l->head;
        l->head=nuevo;
        l->num++;
        return true;
    }
    return false;
}


void imprimir_conjunto(LISTA *l){
    for(NODO* t=l->head;t != NULL;t=t->sig){
        printf("%d ->",t->info);
    }
    printf("\n");
}

    
int cardinal_conjunto(LISTA* l){
    return l->num;
}

bool pertenece(LISTA* l,int n){
     for(NODO* t=l->head;t != NULL;t=t->sig){
        if(t->info==n) return false;
    }
    return true;
}

void agregar_elemento (LISTA* l, int n){
    if(pertenece(l,n)) insertar_inicio(l,n);
    else printf("Este elemento ya aparece en el conjunto y no puede volver a ser agregado\n");
    return;
}
int main(){
    
    LISTA* L1=crear_lista();

    int a,no_elementos;

    printf ("Ingresa la cantidad de números que deseas añadir al conjunto: \n");
    scanf("%i",&no_elementos);

    for(int i=0;i<no_elementos;i++){
        printf("Ingresa el elemento no. %i\n",i+1);
        scanf("%i",&a);
        agregar_elemento(L1,a);
    }

    no_elementos=cardinal_conjunto(L1);

    printf("El total de elementos en el conjunto es: %i\n",no_elementos);

    printf("Los elementos en el conjunto son:\n");

    imprimir_conjunto(L1);

    return(EXIT_SUCCESS);
}
