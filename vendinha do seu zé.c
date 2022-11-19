#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<stdbool.h>

struct produto {
	int codigo;
	char nome[30];
	double preco;
	int estoque;
};

struct produto produtos[200];

int sequencia=0;

int busca (int produto) {
	
	int x=produto, tem;
	
	if(produtos[x-1].codigo==x){
		tem=1;
	} else {
		tem=0;
	}
	
	return tem;
	
	system("Pause");
}

int verificaEstoque (int produto,int quantidade){
	int tem=0;
	
	if(busca(produto)==1){
		if(produtos[produto-1].estoque>=quantidade){
			tem=1;
		}else{
			tem=0;
		}
	}else{
		
	}
	return tem;
}

void cadastro () {
	
	system("cls");
	produtos[sequencia].codigo=sequencia+1;
	printf("\nDigite o nome do produto: ");
	fflush(stdin);
	gets(produtos[sequencia].nome);
	printf("\nDigite o preço do produto: ");
	scanf("%lf",&produtos[sequencia].preco);
	printf("\nDigite a quantidade inicial de %s: ",produtos[sequencia].nome);
	scanf("%d",&produtos[sequencia].estoque);
	
	sequencia++;
}

void listar () {
	
	int x;
	
	system("cls");
	for(x=0;x<sequencia;x++){
		printf("Código do produto: %d", produtos[x].codigo);
		printf("\nProduto: %s", produtos[x].nome);
		printf("\nPreço do produto: %.2lf", produtos[x].preco);
		printf("\nQuantidade em estoque: %d\n", produtos[x].estoque);
		printf("_____________________________\n\n");
	}
	
	system("pause");
}

void venda () {
	int x=1, produto;
	
	while(x==1){
	system("cls");

		if(x==1){
			printf("\nDigite o código do produto: ");
			scanf("%d",&produto);
			if(busca(produto)==1){
				printf("\nDigite a quantidade do produto: ");
				int qtde;
				scanf("%d", &qtde);
				if(qtde>0){
					if(verificaEstoque(produto,qtde)==1){
						produtos[produto-1].estoque-=qtde;
						double preco;
						preco=qtde * produtos[produto-1].preco;
						printf("\nValor a pagar: %.2lf\n\n", preco);
						printf("\nEstoque restante: %d\n\n", produtos[produto-1].estoque);
						system("pause");
					}else{
						printf("\nQuantidade de estoque insuficiente.");
					}	
				}else{
					printf("\nQuantidade de estoque inválida.\n");
				}
			}else{
				printf("\nProduto não existe.\n");
				system("pause");
			}
		}
		printf("\nDeseja fazer outra venda?\n 1 - sim    //   Outro valor - não \n\n");
		scanf("%d",&x);	
	}
}
	
void menu () {
	printf("\n-----Sistema de Gerenciamento-----\n");
	printf("\nSelecione a ação a ser executada:\n");
	printf("\n1-Cadastrar produto(s).   \n2-Listar os produtos.   \n3-Realizar venda(s).   \n4-Buscar produto.   \n5-Quantidade no estoque(Código).   \n0-Sair.\n\n");
}

int main () {
	
	setlocale(LC_ALL, "Portuguese");
	int opcao, produto;
	
	do{
		system("cls");
		menu();
		scanf("%d",&opcao);
		switch(opcao){
			
			case 1:
				cadastro();
			break;
			
			case 2:
				listar();
			break;
			
			case 3:
				venda();
			break;
			
			case 4:
				printf("\nDigite o código do produto: ");
				scanf("%d", &produto);
				if(busca(produto)==1){
					printf("Produto existente.\n");
				} else {
					printf("Produto inexistente.\n");
				}
				system("pause");
			break;
			
			case 5:
				system("cls");
				printf("\nDigite o código do produto: ");
				scanf("%d", &produto);
				printf("Digite a quantidade de estoque desejada: ");
				int qtde;
				scanf("%d", &qtde);
				system("cls");
				if(verificaEstoque(produto,qtde)==1){
					printf("\ntem em estoque: %d\n", produtos[produto-1].estoque);
				}else{
					printf("\nNão tem estoque ou não existe produto, quantidade: %d\n", produtos[produto-1].estoque);
				}
				system("pause");
					
			break;
			
			case 0:
				printf("\nSaindo da aplicação.\n");
			break;
			default:
				printf("Opção Inválida!\n");
		}
	} while(opcao!= 0);
	
	printf("\nAplicação encerrada.\n");
	return 0;
}
