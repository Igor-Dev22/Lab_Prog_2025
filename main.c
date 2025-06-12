#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cadastro_cliente();
int cadastro_produto();
int venda();
void listar_clientes();
void listar_produtos();
void excluir_cliente();
void excluir_produto();
void editar_cliente();
void editar_produto();


typedef struct {
   char nome[50];
   char cpf[12];
   int idade;
} Cliente;

typedef struct {
   char nome[50];
   float preco;
   int codigo;
} Produto;

Cliente clientes[10];
Produto produtos[10];

int total_clientes = 0;
int total_produtos = 0;

int main()
{
int opcao;

    do {
        printf("    Menu Principal:\n\n");
        printf("+----------------------+");
        printf("\n|0 = sair              |\n");
        printf("|1 = cadastrar clientes|\n");
        printf("|2 = cadastrar produtos|\n");
        printf("|3 = efetuar uma venda |\n");
        printf("|4 = listar os clientes|\n");
        printf("|5 = listar os produtos|\n");
        printf("|6 = excluir um cliente|\n");
        printf("|7 = excluir um produto|\n");
        printf("|8 = editar um cliente |\n");
        printf("|9 = editar um produto |\n");
        printf("+----------------------+");
        printf("\nEscolha uma opcao:");
        scanf("%d", &opcao);

        switch(opcao) {

        case 1:
        cadastro_cliente();
        break;
        case 2:
        cadastro_produto();
        break;
        case 3:
        venda();
        break;
        case 4:
        listar_clientes();
        break;
        case 5:
        listar_produtos();
        break;
        case 6:
        excluir_cliente();
        break;
        case 7:
        excluir_produto();
        break;
        case 8:
        editar_cliente();
        break;
        case 9:
        editar_produto();
        break;
        case 0:
        printf("Encerrando o programa...\n");
        break;
        default:
        printf("Opcao Invalida, escolha outra\n");
        break;
        }

    } while(opcao != 0);
}

    int cadastro_cliente() {

    printf("\n|CADASTRO DE CLIENTE|\n\n");
    printf("Nome do cliente:\n-");
    scanf("%s", clientes[total_clientes].nome);
    printf("Idade do cliente:\n-");
    scanf("%d", &clientes[total_clientes].idade);
    printf("CPF do cliente (SOMENTE NUMEROS):\n-");
    scanf("%s", clientes[total_clientes].cpf);
    printf("\nCliente cadastrado com sucesso!\nNome: %s\nIdade: %d\nCPF: %s\n\n", clientes[total_clientes].nome, clientes[total_clientes].idade, clientes[total_clientes].cpf);
    total_clientes++;
    }

    int cadastro_produto() {

    printf("|CADASTRO DE PRODUTO|\n\n");
    printf("Nome do produto:\n-");
     scanf("%s", produtos[total_produtos].nome);
    printf("Codigo do produto:\n-");
    scanf("%d", &produtos[total_produtos].codigo);
    printf("Valor unitario do produto:\n-");
    scanf("%f", &produtos[total_produtos].preco);
    printf("Produto cadastrado com sucesso!\nNome: %s\nCodigo: %d\nR$: %.2lf\n\n", produtos[total_produtos].nome, produtos[total_produtos].codigo, produtos[total_produtos].preco);
    total_produtos++;
    }

    int venda() {
    char cliente[50];
    int quantidade, codigo, pagamento;
    double valor;
    printf("Bem vindo ao menu de venda\n");
    printf("Informe o codigo do produto:\n");
    scanf("%d", &codigo);
    printf("Informe a quantidade:\n");
    scanf("%d", &quantidade);
    printf("Informe o valor de venda do produto:\n");
    scanf("%lf", &valor);
    printf("Informe o cliente:\n");
    scanf("%s", cliente);
    printf("Qual o metodo de pagamento?\n1 - dinheiro\n2 - pix\n3 - cartao\n4 - crediario\n");
    scanf("%d", &pagamento);
    valor = valor * quantidade;
    switch(pagamento) {

case 1:
    printf("Venda efetuada com sucesso!\nProduto: %d\nQuantidade: %d\nValor: %.2lf\nCliente: %s\nMetodo de pagamento: Dinheiro\n", codigo, quantidade, valor, cliente);
    break;
case 2:
    printf("Venda efetuada com sucesso!\nProduto: %d\nQuantidade: %d\nValor: %.2lf\nCliente: %s\nMetodo de pagamento: PIX\n", codigo, quantidade, valor, cliente);
    break;
case 3:
    printf("Venda efetuada com sucesso!\nProduto: %d\nQuantidade: %d\nValor: %.2lf\nCliente: %s\nMetodo de pagamento: Cartao\n", codigo, quantidade, valor, cliente);
    break;
case 4:
    printf("Venda efetuada com sucesso!\nProduto: %d\nQuantidade: %d\nValor: %.2lf\nCliente: %s\nMetodo de pagamento: Crediario\n", codigo, quantidade, valor, cliente);
    break;
default:
    printf("Metodo de pagamento invalido!\n");

    }
    }

    void listar_clientes() {

   int contador = 0;
   int i = 0 ;
   printf("\nListagem de clientes cadastrados:\n\n");

    while(i < total_clientes){
    printf("%d - %s\n", contador, clientes[i].nome);
    contador++;
    i++;
   }
    }

    void listar_produtos() {

    int contador = 0;
    int i = 0 ;
    printf("\nListagem de produtos cadastrados:\n\n");

    while(i < total_produtos){
    printf("%d - %s\n", contador, produtos[i].nome);
    contador++;
    i++;
    }
    }


    void excluir_cliente(){
   char nome[50];
   int i, j;

   printf("Digite o nome do cliente que deseja EXCLUIR:\n");
   scanf("%s",&nome);

   for(i = 0 ; i < total_clientes; i++){

        if(strcmp(clientes[i].nome, nome) == 0){

            for(j = i; j < total_clientes; j++){
                clientes[j] = clientes[j + 1];
            }
            total_clientes --;
            printf("\n\n--Cliente %s excluido com sucesso!\n", nome);
            return 0;

        }
   }
    printf("Cliente nao cadastrado!\nReiniciando processo...\n");
    excluir_cliente();


}

void excluir_produto(){
   char nome[50];
   int i, j;

   printf("Digite o nome do produto que deseja EXCLUIR:\n");
   scanf("%s",&nome);

   for(i = 0 ; i < total_produtos; i++){

        if(strcmp(produtos[i].nome, nome) == 0){

            for(j = i; j < total_produtos; j++){
                produtos[j] = produtos[j + 1];
            }
            total_produtos --;
            printf("\n\n--Produto %s excluido com sucesso!\n", nome);
            return 0;

        }
   }
    printf("Produto nao cadastrado!\nReiniciando processo...\n");
    excluir_produto();


}

void editar_cliente(){

    char nome[50];
    int i , opcao, encontrado = 0;

    printf("Bem vindo a edicao de cliente\n");
    listar_clientes();
    printf("Digite o nome do cliente que deseja editar:\n");
    scanf("%s", nome);

    for(i = 0; i < total_clientes; i++){
        if(strcmp(clientes[i].nome, nome) == 0){

            printf("Qual informacao deseja editar?\n1-nome\n2-idade\n3-cpf\n");
            scanf("%d", &opcao);

            switch(opcao) {
        case 1:
            printf("Digite o novo nome:\n");
            scanf("%s", clientes[i].nome);
            break;

        case 2:
            printf("Digite a nova idade:\n");
            scanf("%d", clientes[i].idade);
            break;

        case 3:
            printf("Digite o novo cpf:\n");
            scanf("%d", clientes[i].cpf);
            break;
        default:
            printf("Opcao invalida, reiniciando o processo...\n");
            editar_cliente();
            }

            printf("\n Cliente editado com sucesso!\n");


            encontrado = 1;
            break;
        }
    }

    if(!encontrado){
        printf("Cliente nao encontrado, reiniciando o processo...\n");
        editar_cliente();
    }

}
void editar_produto(){

    char nome[50];
    int i , opcao, encontrado = 0;

    printf("Bem vindo a edicao de produto\n");
    listar_produtos();
    printf("Digite o nome do produto que deseja editar:\n");
    scanf("%s", nome);

    for(i = 0; i < total_produtos; i++){
        if(strcmp(produtos[i].nome, nome) == 0){

            printf("Qual informacao deseja editar?\n1-nome\n2-preco\n3-codigo\n");
            scanf("%d", &opcao);

            switch(opcao) {
        case 1:
            printf("Digite o novo nome:\n");
            scanf("%s", produtos[i].nome);
            break;

        case 2:
            printf("Digite o novo preco:\n");
            scanf("%d", produtos[i].preco);
            break;

        case 3:
            printf("Digite o novo codigo:\n");
            scanf("%d", produtos[i].codigo);
            break;
        default:
            printf("Opcao invalida, reiniciando o processo...\n");
            editar_produto();
            }

            printf("\n Produto editado com sucesso!\n");


            encontrado = 1;
            break;
        }
    }

    if(!encontrado){
        printf("Produto nao encontrado, reiniciando o processo...\n");
        editar_produto();
    }

}


