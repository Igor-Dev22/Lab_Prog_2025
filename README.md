---

#  Sistema de Cadastro de Clientes e Produtos em C

Este é um sistema simples, desenvolvido em linguagem C, para **cadastro e gerenciamento de clientes e produtos**, com funcionalidades básicas como listar, excluir e atualizar informações de clientes, além de cadastrar vendas (em desenvolvimento).

##  Funcionalidades Implementadas

1. **Cadastrar Cliente**
2. **Cadastrar Produto**
3. **Efetuar Venda** (ainda não implementado)
4. **Listar Clientes**
5. **Excluir Cliente**
6. **Atualizar Cliente** (ainda não implementado)

---

##  Como Funciona

### Cadastrar cliente
* Opção `Cadastrar Cliente` no menu ele nos mostra dois campos , sendo `Nome` e `Idade`.
* Utilizando um `Scanf` para receber e armazenar essa dados do Cliente.

### Cadastrar Produto
* Opção `Cadastrar Produto` no menu ele nos mostra dois campos , sendo `Nome do Produto` e `Valor Unitário`.
* Utilizando um `Scanf` para receber e armazenar essa dados do Produto.

### Efetuar venda
#### Função ainda não realizada!

### Listar clientes
* Opção `Listar Clientes` usado para listar os clientes cadastrados , utilizando o `Contador` para ordenar de forma crescente.
```c
    int contador = 0;
      int i = 0 ;
      printf("\nListagem de clientes cadastrados:\n\n");

    while(i < total_clientes){
        printf("%d - %s\n",contador, clientes[i]);
        contador++;
        i++;
   }
```
### Excluir Cliente 
* Opção `Excluir Cliente` usado para remover algum cliente que já esteja cadastrado.
* solicitando o `nome` do cliente que quer ser removido da lista.
* Após removido é subtraido `1` do `Contador`, assumindo a possição na lista do cliente que foi removido.
---

##  Estrutura do Código

O código utiliza dois structs:

* `Cliente`: contém `nome` e `idade`
* `Produto`: contém `nome` e `preco`

Também há dois arrays globais com capacidade para armazenar até 10 clientes e 10 produtos:

```c
Cliente clientes[10];
Produto produtos[10];
```

E duas variáveis para controlar o número total cadastrado:

```c
int total_clientes = 0;
int total_produtos = 0;
```

---

##  Exemplo de Uso

```plaintext
Selecione uma opcao:
+-----------------------+
| 1 - Cadastrar cliente |
| 2 - Cadastrar produto |
| 3 - Efetuar uma venda |
| 4 - Listar clientes   |
| 5 - Excluir cliente   |
| 6 - Atualizar cliente |
+-----------------------+
: 1

Cadastrando cliente.....
Digite o nome do cliente: Maria
Digite a idade do cliente: 30
Cadastro concluido!
Nome: Maria
Idade: 30
```

---

##  Autor
---
