#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char letra;
    struct no *prox;
}tno;

typedef struct pilha {
    tno *topo;
}tpilha;

void iniciaPilha(tpilha *p);
int empilha(tpilha *p, char carac);
int desempilha(tpilha *p);
int pilhaVazia(tpilha *p);
void imprime(tpilha *p);
void desaloca(tpilha *p);

void iniciaPilha(tpilha *p) {
    p->topo = NULL;
}

int empilha(tpilha *p, char carac) {
    tno *novo = (tno *)malloc(sizeof(tno));
    if(!novo) {
        return -1;
    }

    novo->letra = carac;
    novo->prox = p->topo;
    p->topo = novo;

    return 1;
}

int desempilha(tpilha *p) {
    char dado;
    tno *aux;
    if(pilhaVazia(p)) {
        printf("Pilha Vazia!");
        return 0;
    }

    dado = p->topo->letra;
    aux = p->topo;
    p->topo = p->topo->prox;
    free(aux);

    return dado;
}

int pilhaVazia(tpilha *p) {
    if(p->topo == NULL)
        return 1;
    return 0;
}

void imprime(tpilha *p) {
    tno *aux = p->topo;
    while(aux) {
        if(aux->prox)
            printf("%c -> ", aux->letra);
        else
            printf("%c.", aux->letra);

        aux = aux->prox;
    }
}

void desaloca(tpilha *p) {
    tno *aux;
    while(p->topo) {
        aux = p->topo;
        p->topo = p->topo->prox;
        free(aux);
    }
}

bool isValid(char* s) {
    tpilha *p = (tpilha *)malloc(sizeof(tpilha));
    int i;

    iniciaPilha(p);

    for(i = 0; s[i] != '\0'; i++) {

        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            empilha(p, s[i]);
        }
        else {
            if(pilhaVazia(p)) {
                desaloca(p);
                return false;
            }

            if((p->topo->letra == '(' && s[i] == ')') ||
               (p->topo->letra == '{' && s[i] == '}') ||
               (p->topo->letra == '[' && s[i] == ']')) {

                desempilha(p);
            }
            else {
                desaloca(p);
                return false;
            }
        }
    }

    bool valido = pilhaVazia(p);
    desaloca(p);
    return valido;
}