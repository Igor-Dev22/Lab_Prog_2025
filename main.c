#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   char nome[50];
   int idade;
} Cliente;

typedef struct {
   char nome[50];
   float preco;
} Produto;


int cadastrar_cliente();
int cadastrar_produto();
int cadastrar_venda();
void listar_clientes();
void excluir_cliente();
void atualizar_clientes();


Cliente clientes[10];
Produto produtos[10];

int total_clientes = 0;
int total_produtos = 0;

void main()
{
    int menu;

    do{
        printf("\n\nSelecione uma opcao: \n");

        printf("+-----------------------+");
        printf("\n| 1 - Cadastrar cliente |");
        printf("\n| 2 - Cadastrar produto |");
        printf("\n| 3 - Efetuar uma venda |");
        printf("\n| 4 - Listar clientes   |");
        printf("\n| 5 - Exlcuir cliente   |");
        printf("\n| 6 - Atualizar cliente |\n");
        printf("+-----------------------+");
        printf("\n:");
        scanf("%d",&menu);

        switch(menu){
            case 1:
                cadastrar_cliente();
                break;
            case 2:
                cadastrar_produto();
                break;
            case 3:
                cadastrar_venda();
                break;
                case 4:
                listar_clientes();
                break;
                case 5:
                    excluir_cliente();
                    break;
                case 6:
                    atualizar_clientes();
            default:
                printf("\nOpcao de menu invalida!");

        }

    }while(menu != 0);

}

int cadastrar_cliente(){

    printf("\nCadastrando cliente.....");
    printf("\n\n<------------------------------>");
    printf("\n\nDigite o nome do cliente: ");
    scanf("%s", &clientes[total_clientes].nome);
    printf("Digite a idade do cliente: ");
    scanf("%d", &clientes[total_clientes].idade);
    printf("\n-Cadastro concluido-\nNome: %s \nIdade: %d", clientes[total_clientes].nome , clientes[total_clientes].idade);
    printf("\n<------------------------------>");
    total_clientes++;
}

int cadastrar_produto(){

    printf("\nCadastrando produto.....");
    printf("\n\nDigite o nome do produto: ");
    scanf("%s", &produtos[total_produtos].nome);
    printf("Digite o valor unitario do produto: ");
    scanf("%f", &produtos[total_produtos].preco);
    printf("\nCadastro concluido!\nNome: %s \nValor Unitario: %.2f", produtos[total_produtos].nome, produtos[total_produtos].preco);
    total_produtos++;

}


int cadastrar_venda(){
    printf("\nCadastrando venda.......");
}

void listar_clientes(){ //Fazer a listagem , de toda lista de clientes cadastrados!

   int contador = 0;
   int i = 0 ;
   printf("\nListagem de clientes cadastrados:\n\n");

    while(i < total_clientes){
    printf("%d - %s\n",contador, clientes[i]);
    contador++;
    i++;
   }
}

void excluir_cliente(){
   char nome[50];
   int i, j;

   printf("\nDigite o nome do cliente que deseja EXCLUIR: ");
   scanf("%s",&nome);

   for(i = 0 ; i < total_clientes; i++){

        if(strcmp(clientes[i].nome, nome) == 0){

            for(j = i; j < total_clientes; j++){
                clientes[j] = clientes[j + 1];
            }
            total_clientes --;
            printf("\n\n--Cliente %s exlcuido com sucesso!--", nome);
            return 0;

        }
                printf("\n---Cliente nao cadastrado!---");
   }

}

void atualizar_clientes(){

    printf("");

}
