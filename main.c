/*
  Obs1: Não utilizei comandos de limpar tela
para evitar problemas com diferentes sistemas operacionais

    ok - struct   [ 1,0 valor ]
    ok - Criar e utilizar o conceito de TAD
    (principalmente adotando o uso de biblioteca    arvorebinaria.h  arvorebinaria.c


Funcionalidades:
    ok - Controle de acesso - login (usuário e senha);[ 0,5 valor ]
    ok -Cadastro de produtos [ 0,5 valor ]
    Alteração de produtos [ 1,0 valor ]
    ok - Exclusão de produtos[ 1,0 valor ]
    ok - Busca produto [ 0,5 valor ]
    ok - Venda de produtos [ 1,0 valor ]
    Relatório por tipo de produto (listagem de produtos ordenados por tipo)  [ 0,5 valor]
    ok - Relatórios de vendas[ 1,0 valor ]
*/



#include<stdio.h>
#include<stdlib.h>
#include"loja.h"


int main(){

    Login l;
    int cadastro=2;
    int venda=0;

    //printf("ATENCAO !!!\nSENHA E USUARIO = 'FONTES'");

    while(cadastro!= 1){
        l = lerDadosLogin();
        cadastro = loginValida(l);

        if(cadastro != 1){ //=1
            system("clear");// linux
           // system("cls"); //win
            printf("\tTente novamente !!\n");
            printf("\tlogin invalido\n\n");
        }
    }

    NoArv *busca = NULL;
    NoArv *teste= NULL;
    NoArv *raiz = NULL;


    int opcao=1;
    int valor=0;

    do{
        menu();
        scanf("%d", &opcao);
        getchar();
        switch(opcao){
        case 1:
            cadastrarProduto(&raiz, lerProduto());
            break;
        case 2:
			printf("Lista de produtos: \n");
            imprimir(raiz);
            break;
        case 3:
            printf("\n\tDigite a matricula do produto a ser procurado: ");
            scanf("%d", &valor);
            busca = buscar(raiz, valor);

            if(busca){
                printf("\n\tValor encontrado:\n");
                imprimirProduto(busca->produto);
            }
            else
                printf("\n\tValor nao encontrado!\n");
            break;
        case 4:
            printf("\t");
            printf("\n\tDigite a matricula a ser removido: ");
            scanf("%d", &valor);
            raiz = excluirProduto(raiz, valor);
            break;
        case 5:
            printf("\t");
            printf("\n\tDigite a matricula do produto a ser alterada: ");
            scanf("%d", &valor);
            //teste = alterar(raiz,valor);
            //raiz = alterar(raiz,valor);
            alterar(raiz,valor);

            break;
        case 6:
            titulo();
            imprimirVenda(raiz);
            printf("\t");
            printf("\n\n\tDigite a matricula Para a venda do produto: ");
            scanf("%d", &valor);
            printf("\n\n\tDigite a quantidade da venda: ");
            scanf("%d", &venda);
            raiz = venderProduto(raiz,valor,venda);


            break;
        case 7:
            printf("\t");
            printf("\n\t ---> RELATORIO POR TIPO <---: ");
            imprimirTipo(raiz);
            break;
        case 8:
          //  printf("\t");
          //  printf("\n\t: ");
          //  scanf("%d", &valor);
          //  raiz = excluirProduto(raiz, valor);
            break;
        default:
            if(opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    }while(opcao != 0);

    return 0;
}
