#include <stdio.h>
#include <stdlib.h>
#include "arvorebinaria.h"





/*-------------------------------*
 *inicializando uma arvore vazia *
 *-------------------------------*/

Arv* inicializa(void){
    return NULL;
}


/*-----------------------*
 *criar arvore nao-vazia *
 *-----------------------*/
Arv* criar(char c, Arv* sae, Arv* sad){
    Arv* p=(Arv*)malloc(sizeof(Arv));
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    return p;
}

/*-----------------------------*
 * verificar se arvore = vazia *
 *-----------------------------*/
int vazia(Arv* a){
    return a==NULL;
}



/*-------------------*
 * imprimindo arvore *
 *-------------------*/
void imprimindo(Arv* a){
    if(!vazia(a)){
        printf("%c",a->info);//raiz
        imprimir(a->esq);
        imprimir(a->dir);
    }
}

    
/*----------------*
 * liberar arvore *
 *----------------*/

Arv* libera(Arv* a){
    if(!vazia(a)){
        libera(a->esq);
        libera(a->dir);
        libera(a);
    }
    return NULL;
}


/*-------------------*
 * buscar ocorrencia *
 *-------------------*/

int busca(Arv* a, char c){
    if(vazia(a))
        return 0; //arvore vazia
    else
        return a->info==c || busca(a->esq,c) || busca(a->dir,c);
}

