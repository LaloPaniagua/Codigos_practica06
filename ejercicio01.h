#ifndef ejercicio01_H
#define ejercicio01_H
#include <stdbool.h>
typedef struct _nodo NODO;
typedef int INFO;

struct _nodo{
    INFO info;
    NODO *sig;
};

typedef struct _lista LISTA;
struct _lista{
    NODO *head;
    NODO *tail;
    int num;
};

int cardinal_conjunto(LISTA* l);
NODO* crear_nodo(INFO info);
LISTA* crear_lista();
bool insertar_inicio(LISTA* l,INFO info);
void imprimir_conjunto(LISTA *l);
bool pertenece(LISTA* l,int n);
#endif