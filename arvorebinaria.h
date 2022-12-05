/* CONJUNTO DE OPERACOES */

    
/*-------------------------------*
 *inicializando uma arvore vazia *
 *-------------------------------*/
Arv* inicializa(void);
    
    
/*-----------------------*
 *criar arvore nao-vazia *
 *-----------------------*/
Arv* criar(char c, Arv* sae, Arv* sad);
    

/*-----------------------------*
 * verificar se arvore = vazia *
 *-----------------------------*/
int vazia(Arv* a);


/*-------------------*
 * imprimindo arvore *
 *-------------------*/
void imprimir(Arv* a);    
    
    
/*----------------*
 * liberar arvore *
 *----------------*/
Arv* libera(Arv* a);
    

/*-------------------*
* buscar ocorrencia *
 *-------------------*/
int busca(Arv* a, char c);

