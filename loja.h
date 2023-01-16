/* CONJUNTO DE OPERACOES */



/*-------------*
 * estrutura   *
 *-------------*/
typedef struct{
	int matricula;
	//marca
    char nome[50];
    int qtd;
    int tipo;
    int qtdVendida;
    float preco;
}Produto;

//estrutura do no
typedef struct no{
    Produto produto;
    struct no *direita;
    struct no *esquerda;
}NoArv;



//funcao menus
void menu();
void menuTipos();



/*-------------*
 * estrutura
 * controle de
 * acesso
 *-------------*/
typedef struct{
    char usuario[10];
    char senha[10];
}Login;

//leitura daddos login
Login lerDadosLogin();
//validando o login
int loginValida(Login l);


/*---------------------------*
 * --> 1 - Cadastrar produto *
 *---------------------------*/
Produto lerProduto();
void cadastrarProduto(NoArv **raiz, Produto p);
//NoArv* cadastrarProduto2(NoArv *raiz, Produto p);


/*--------------*
 * Listar Todos *
 *--------------*/
void imprimirProduto(Produto p);
void imprimir(NoArv *raiz);

/* -->[2] */
/*-----------------*
 * Alterar produto *
 *-----------------*/
//nome, qtd, tudo menos matricula, preco
//void alterando(NoArv *raiz, int matricula);
//void alterar(NoArv *raiz, int matricula);

NoArv* alterar(NoArv *raiz, int matricula);
//Produto* alterando(NoArv *raiz, int matricula);
//void alterando(NoArv *raiz, int matricula);
//void alterar(NoArv *raiz, int matricula);

/* -->[3] */
/*----------------------*
 * ---> Remover produto *
 *---------------------*/
NoArv* excluirProduto(NoArv *raiz, int chave);


/* -->[4] */
/*--------------------*
 * --> Buscar produto *
 *--------------------*/
NoArv* buscar(NoArv *raiz, int matricula);



/* -->[5] */
/*----------------*
 * Vender produto *
 *----------------*/
//vendas
void imprimirVenda(NoArv *raiz);
void titulo();
void nada(Produto p);

NoArv* venderProduto(NoArv *raiz, int matricula, int qtd);

/* -->[8] */
/*-------------------*
 * Relatorio por TIPO*
 *-------------------*/
void imprimirTipo(NoArv *raiz);
void imprimirRelatorioTipo(Produto p);

/* -->[9] */
/*--------------------*
 * Relatorio de VENDA *
 *--------------------*/

void imprimirRelatorioVendas(Produto p);
void imprimirVendas(NoArv *raiz);

