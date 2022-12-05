#include<stdio.h>
#include<stdlib.h>
#include"arvorebinaria.h"


/*-------------*
 * estrutura   *
 *-------------*/

struct arv{
    char info;
    struct arv* esq;
    struct arv* dir;


};
typedef struct arv Arv;

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


//####################################
//mulher melhore...
//####################################

/*-----------------------------*
 * verificar se arvore = vazia *
 *-----------------------------*/
int vazia(Arv* a){
    return a==NULL;
}

/*-------------------*
 * imprimindo arvore *
 *-------------------*/
void imprimir(Arv* a){
    //printf("<");
    if(!vazia(a)){
        printf("%c",a->info);//raiz
        //printf(">");
        imprimir(a->esq);
        //printf(">");
        imprimir(a->dir);
        //printf(">");
    }
   //printf(">");
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

int main(){

    
    printf("AAAAhhajsdkahds");

    return 0;
}
