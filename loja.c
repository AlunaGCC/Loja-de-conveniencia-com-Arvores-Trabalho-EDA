#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loja.h"
#include "arvorebinaria.h"


/*--------------------*
 * controle de acesso
 *--------------------*/
Login lerDadosLogin(){

    printf("\n\n\tATENCAO !!!SENHA E USUARIO = 'fontes' ");
    Login l;
    printf("\n\t |========================|\n");
    printf("\n\t |   CONTROLE DE ACESSO   |\n");
    printf("\n\t |========================| \n");

    printf("\nInforme o Usuario : \n");
    scanf("%s",&l.usuario);
    getchar();

    printf("\nInforme a senha: \n");
    scanf("%s",&l.senha);
    getchar();

    return l;

}

//validando o login
int loginValida(Login l){
    char usuario1[10] = "fontes"; //usuario
    char senha1[10] = "fontes"; //senha

    if ((strcmp(l.usuario,usuario1) == 0) &&   (strcmp(l.senha,senha1) == 0) ){
        return 1;
    }else{
        return 0;
    }
}



//tipos - FOI DEFINIDO [8] TIPOS DE PRODUTOS
/*
    1  higiene
    2 - limpeza
    3 - Bebida
    4 - hortifruti
    5- nao-perecivel
    6- congelados
    7 - perecivel
*/
char tipos[8][20]={"Higiene","Limpeza","Bebida","hortifruti","nao-perecivel","congelados","perecivel"};

/*-------------------------------*
 * Funcao Auxiliar imprimir menu *
 *-------------------------------*/
void menuTipos(){
    for(int i=0;i<7;i++){
        printf("\t");
        printf("[%d]%s\n",i+1,tipos[i]);
    }
}


/*---------------------------------------*
 * Funcao Auxiliar para cadastrarProduto *
 *---------------------------------------*/
Produto lerProduto(){
    Produto p;
    int op=0;
    printf("Digite matricula :\n");
    scanf("%d",&p.matricula);
    //getchar();

    printf("Digite o nome do produto:\n");
    //fgets(p.nome, 49, stdin);
    //scanf("%c[^\n]",&p.nome);
    scanf("%s",&p.nome);
    //scanf("%d[^;]",&aux_carga);//carga horaria da discipli
    getchar();

    printf("Digite qtdProduto :\n");
    scanf("%d",&p.qtd);
    //getchar();
    printf("Informe o tipo do produto:\n");
    menuTipos();
    scanf("%d",&op);
    getchar();
    switch(op){
        case 1:
            p.tipo=1;
            break;
        case 2:
            p.tipo=2;
            break;
        case 3:
            p.tipo=3;
            break;
        case 4:
            p.tipo=4;
            break;
        case 5:
            p.tipo=5;
            break;
        case 6:
            p.tipo=6;
            break;
        case 7:
            p.tipo=7;
            break;
        default:
        //da para verificar...
            if(op > 7 || op <1 ){
                printf("\n\tOpcao invalida!!!\n");
            }
    }

    return p;
}

/*---------------------------*
 * --> 1 - Cadastrar produto *
 *---------------------------*/
void cadastrarProduto(NoArv **raiz, Produto p){
    NoArv *aux = *raiz;
    while(aux){
        if(p.matricula < aux->produto.matricula)
            raiz = &aux->esquerda;
        else
            raiz = &aux->direita;
        aux = *raiz;
    }
    aux = malloc(sizeof(NoArv));
    aux->produto = p;
    aux->esquerda = NULL;
    aux->direita = NULL;
    *raiz = aux;
}


/*---------------------------------------*
 * Funcao Auxiliar para Imprimir Produto *
 *---------------------------------------*/
void imprimirProduto(Produto p){
    printf("\n-----------\n");
    printf("Matricula: %d \nNome: %s \nquantidade: %d\nTIPO: %d", p.matricula, p.nome,p.qtd,p.tipo);
    printf("\n-----------\n");
}

/*---------------------------------------*
 * Funcao Auxiliar para Imprimir Produto *
 *---------------------------------------*/
//lista todos
// 2 --- vazia() ao inves de diferente de null
void imprimir(NoArv *raiz){
    if(raiz){//produto -tipo()
        imprimirProduto(raiz->produto);
        imprimir(raiz->esquerda);
        imprimir(raiz->direita);
    }
}

/*--------------------*
 * --> Buscar produto *
 *--------------------*/
NoArv* buscar(NoArv *raiz, int matricula){
    if(raiz){
        if(matricula == raiz->produto.matricula)
            return raiz;
        else if(matricula < raiz->produto.matricula)
            return buscar(raiz->esquerda,matricula);
        else
            return buscar(raiz->direita,matricula);
    }
    return NULL;
}

/*-------------------*
 * Relatorio por TIPO*
 *-------------------*/
void relatorioTipo(NoArv *raiz){
    for(int i=0;i<7;i++){
        printf("\t");
        printf("[%d]%s\n",i+1,tipos[i]);
    } //tipo
}

/*----------------------*
 * ---> Remover produto *
 *---------------------*/
NoArv* excluirProduto(NoArv *raiz, int valor) {
    if(raiz == NULL){
        printf("Valor nao encontrado!\n");
        return NULL;
    } else { // procura o nó a remover
        if(raiz->produto.matricula == valor) {
            if(raiz->esquerda == NULL && raiz->direita == NULL) {
                free(raiz);
                printf("Elemento [%d] removido:!\n", valor);
                return NULL;
            }
            else{
                // remover nós que possuem 2 filhos
                if(raiz->esquerda != NULL && raiz->direita != NULL){
                    Produto p;
                    NoArv *aux = raiz->esquerda;
                    while(aux->direita != NULL)
                        aux = aux->direita;
                    p = raiz->produto;
                    raiz->produto = aux->produto;
                    aux->produto = p;
                    raiz->esquerda = excluirProduto(raiz->esquerda, valor);
                    return raiz;
                }
                else{
                    // remover nós que possuem apenas 1 filho
                    NoArv *aux;
                    if(raiz->esquerda != NULL)
                        aux = raiz->esquerda;
                    else
                        aux = raiz->direita;
                    free(raiz);
                    return aux;
                }
            }
        } else {
            if(valor < raiz->produto.matricula)
                raiz->esquerda = excluirProduto(raiz->esquerda, valor);
            else
                raiz->direita = excluirProduto(raiz->direita, valor);
            return raiz;
        }
    }
}


/*-------------------------------*
 * Funcao Auxiliar imprimir menu *
 *-------------------------------*/

void menu(){
    printf("\n |===============================|\n");
    printf("\n |-- LOJINHA DE CONVENIENCIA ----|\n");
    printf("\n |===============================| \n");
    printf("\n ---> selecione uma das opcoes\n");
    printf("[0] - SAIR do programa\n");
    printf("1) - Cadastrar Produtos\n");
    printf("2) - listar Todos\n");
    printf("3) - Buscar Produtos\n");
    printf("4) - Excluir produto\n");
    printf("5) - Alterar produto\n");
    printf("6) - Vender produto\n");
    printf("7) - Relatorio - listar produto[tipo]\n");
    printf("8) - Relatorio -de vendas\n");


}

/*-----------------*
 * Alterar produto *
 *-----------------*/
NoArv* alterar(NoArv *raiz, int matricula){
    printf("oi");
    Produto* p;
    int op=0;
    if(raiz!=NULL){
        if(matricula == raiz->produto.matricula){
            printf("Digite o -Novo- nome do produto:\n");
            scanf("%s",&raiz->produto.nome);
            getchar();
            printf("Digite a -Nova- qtdProduto :\n");
            scanf("%d",&raiz->produto.qtd);
            printf("Informe o -Novo- tipo do produto:\n");
            menuTipos();
            scanf("%d",&op);
            switch(op){
                case 1:
                    raiz->produto.tipo=1;
                    //p->tipo=1;
                    break;
                case 2:
                    raiz->produto.tipo=2;
                    //p->tipo=2;
                    break;
                case 3:
                    raiz->produto.tipo=3;
                    break;
                case 4:
                    raiz->produto.tipo=4;
                    break;
                case 5:
                    raiz->produto.tipo=5;
                    break;
                case 6:
                    raiz->produto.tipo=6;
                    break;
                case 7:
                    raiz->produto.tipo=7;
                    break;
                default:
                    break;
            }
        }
        return raiz;
    }
}


/*-------------------*
 * Funcao Auxiliar   *
 *-------------------*/
// lista de produtos
void titulo (){
    printf("\n\t |=============================================|\n");
    printf("\n\t | Matricula  |    nome      |   quantidade    |\n");

}
void nada(Produto p){
    printf("\n\t |---------------------------------------------|\n");
    printf(" \t  |%-10d  |  %-10s  | %-15d |", p.matricula, p.nome,p.qtd);
    //printf("\n\t-----------\n");
}


/*------------------------------------*
 * Funcao Auxiliar imprimir relatorio *
 *------------------------------------*/
void imprimirVenda(NoArv *raiz){
    if(raiz){//produto -tipo()
        nada(raiz->produto);
        imprimirVenda(raiz->esquerda);
        imprimirVenda(raiz->direita);
    }
}
/*----------------*
 * Vender produto *
 *----------------*/
NoArv* venderProduto(NoArv *raiz, int matricula, int qtd){

    int valorVenda=0;
    valorVenda = qtd;

    if(raiz){

        if(matricula == raiz->produto.matricula){
            raiz->produto.qtdVendida = qtd;
            return raiz;
        }else if(matricula < raiz->produto.matricula){
            raiz->produto.qtdVendida = qtd;
            return venderProduto(raiz->esquerda,matricula,valorVenda);
        }else{
            raiz->produto.qtdVendida = qtd;
            return venderProduto(raiz->direita,matricula,valorVenda);
        }
    }
    return NULL;
}



/*------------------------------------*
 * Funcao Auxiliar imprimir relatorio *
 *------------------------------------*/
void imprimirRelatorioTipo(Produto p){
    printf("\n----------------------\n");
    printf("Nome: %s\nTIPO: %d", p.nome,p.tipo);
    printf("\n----------------------\n");
}

void imprimirTipo(NoArv *raiz){
    int vet[8]={1,2,3,4,5,6,7};
    int i=0;
    //if(raiz){//produto -tipo()
    while (raiz!=NULL){
        if (raiz->produto.tipo == vet[i+1]){
        imprimirRelatorioTipo(raiz->produto);
        imprimirTipo(raiz->esquerda);
        imprimirTipo(raiz->direita);
        i++;
        }

    }
}


/*------------------------------------*
 * Funcao Auxiliar imprimir relatorio *
 *------------------------------------*/

void imprimirRelatorioVendas(Produto p){
    printf("\n----------------------\n");
    printf("NOME: %s\nQTD VENDAS: %d", p.nome,p.qtdVendida);
    printf("\n----------------------\n");
}


/*--------------------*
 * Relatorio de VENDA *
 *--------------------*/
// 2 --- vazia() ao inves de diferente de null
void imprimirVendas(NoArv *raiz){
    //int vet[8]={1,2,3,4,5,6,7};
    int i=0;
    if(raiz){//produto -tipo()
        imprimirRelatorioVendas(raiz->produto);
        imprimirVendas(raiz->esquerda);
        imprimirVendas(raiz->direita);
    }

}






//#######################################################################
/* EXEMPLO DE ENTRADA VALIDAS

// 1  higiene
   2 - limpeza
   3 - Bebida
   4 - hortifruti
   5- nao-perecivel
    6- congelados
    7 - perecivel


//quantidade, maximo de caractere
// 1  higiene
   //xampu -> mat 50
    //sabonete -> mat
    //exeplos:
    //creme
    //hidratannte
    //desodorante....

   2 - limpeza
      -> detergente
      ->alcool
      outros exemplos :amaciante ,cloro
      ....

   3 - Bebida
      ->agua
      ->vinho
      outros exemplos: suco, refrigerant
   4 - hortifruti
    //alcool
    ->banana
    ->batata
   outros exemplos  cenoura,salsa....

   5- nao-perecivel
      ->arroz
      ->feijao
    outros exemplos macaraao, acucar,sal
    6- congelados
       -> frango
       -> lasanha
       outros exemplos, pizza, salsicha....
    7 - perecivel
       ->azeitona
       ->molho
       outros exemplos leite, requeijao ....


//

*/

//######################################################



