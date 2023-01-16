# Loja de conveniência :shopping_cart: - (Utlizando Árvore AVL)
Trabalho -Estrutura de Dadods e Algoritmos usando Árvores
Criar e utilizar o conceito de TAD (principalmente adotando o uso de biblioteca:
arvorebinaria.h  arvorebinaria.c) 

## :interrobang: Sobre o código

Foi utilizando os conceitos de TAD para criar uma estrutura do tipo Árvore Binária de Busca para armazenar produtos de uma loja de conveniência. 

A ordenação da árvore oi realizada de acordo com número de matrícula dos produtos

Estrutura do tipo produto:


```
typedef struct{
	int matricula;
    char nome[50];
    int qtd;
    int tipo;
    int qtdVendida;
    float preco;
}Produto;
```


##  :wrench: Instruções de Compilação

Execute o comando:

```
make all
```

E depois:

```
./main
```

###Funcionalidade

Funcionalidades:

* Controle de acesso - login (usuário e senha)
* Alteração de produtos
* Exclusão de produtos
* Busca produto 
* Venda de produtos    
* Relatório por tipo de produto 
* Relatórios de vendas 


##  :heavy_check_mark: Ferramentas Utlizadas

* Sistema Operacional (Linux KDE neon)
* Compilador GCC 

## :books: Referências:

-> material professor FONTESS

-> apostila ....(Estrutura de Dados,W. Celes e J. L. Rangel)


