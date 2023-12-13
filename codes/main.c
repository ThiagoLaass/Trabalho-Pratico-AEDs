#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
Filename: main.c

Authors: Thiago Borges Laaass, Matheus Eduardo Marinho de Miranda Hermenegildo

Description: Desenvolver um programa em C para controlar vendas, cadastros e informações de produtos de uma loja ficticia de roupa.

Notes: Este arquivo contem o programa principal do trabalho pratico de AEDs.

Start date: 02 dez 2023

// Repositorio: https://github.com/ThiagoLaass/Trabalho-Pratico-AEDs.git

*/

/*
  Função para atribuir valores iniciais para a matriz de produtos.

  Exemeplo da matriz utilizada:
                                  Preço  Estoque  PreçoP  Lucro
  Linha de Meia adulta estampada    1       1       1       1
  Linha de Meia adulta lisa         1       1       1       1
  Linha de Meia infantil estampada  1       1       1       1
  Linha de Meia infantil lisa       1       1       1       1

  PrecoP = Preco de produção
    Lucro = Preco - PrecoP

*/

void leiaProdutos(float produtos[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (j == 3)
            {
                produtos[i][j] = 0; // A matriz é incializada com todos o lucros em valores 0
            }
            else
                produtos[i][j] = i * 2 + 2;
        }
    }
}

/*
    Função para lidar com o acesso dos funcionarios, tendo a opção de cadastrar,
    comprar e verificar estoque do produto. Após o cadastro de produtos, é perguntando ao usuario se o mesmo deseja fazer mais alguma operação.
*/

void acessoFuncionario(float produtos[4][4])
{
    int op;
    int productSelection;

    printf("Informe o produto desejado\n");
    printf("1 - Linha de Meia adulta estampada\n");
    printf("2 - Linha de Meia adulta lisa\n");
    printf("3 - Linha de Meia infantil estampada\n");
    printf("4 - Linha de Meia infantil lisa\n");
    printf("Para sair, digite qualquer outro numero\n");
    scanf("%d", &productSelection);

    if (productSelection < 1 || productSelection > 4)
    {
        return main();
    }

    printf("Informe a operacao desejada\n");
    printf("1 - Verificar preco do produto\n");
    printf("2 - Verificar estoque do produto\n");
    printf("3 - Alterar estoque do produto\n");
    printf("4 - Alterar preco do produto\n");
    scanf("%d", &op);

    switch (op) // Função de switch para controlar as operações desejadas
    {
    case 1:

        if (productSelection == 1)
            printf("O preco atual das meias adultas estampadas e: %.2f\n reais", produtos[0][0]);

        else if (productSelection == 2)
            printf("O preco atual das meias adultas lisas: %.2f\n", produtos[1][0]);

        else if (productSelection == 3)
            printf("O preco das meias infantis estampadas: %.2f\n", produtos[2][0]);

        else if (productSelection == 4)
            printf("O preco atual das meias infantis lisas: %.2f\n", produtos[3][0]);

        else
            printf("Produto nao encontrado\n");

        break;

    case 2:

        if (productSelection == 1)
            printf("O estoque atual das meias adultas estampadas e: %.0f\n", produtos[0][1]);

        else if (productSelection == 2)
            printf("O estoque atual das meias adultas lisas: %.0f\n", produtos[1][1]);

        else if (productSelection == 3)
            printf("O estoque atual das meias infantis estampadas: %.0f\n", produtos[2][1]);

        else if (productSelection == 4)
            printf("O estoque atual das meias infantis lisas: %.0f\n", produtos[3][1]);

        else
            printf("Produto nao encontrado\n");

        break;

    case 3:
        if (productSelection == 1)
        {
            printf("Informe o novo estoque das meias adultas estampadas\n");
            scanf("%f", &produtos[0][1]);
            printf("Estoque cadastrado com sucesso\n");
        }
        else if (productSelection == 2)
        {
            printf("Informe o novo estoque das meias adultas lisas\n");
            scanf("%f", &produtos[1][1]);
            printf("Estoque cadastrado com sucesso\n");
        }
        else if (productSelection == 3)
        {
            printf("Informe o novo estoque das meias infantis estampadas\n");
            scanf("%f", &produtos[2][1]);
            printf("Estoque cadastrado com sucesso\n");
        }
        else if (productSelection == 4)
        {
            printf("Informe o novo estoque das meias infantis lisas\n");
            scanf("%f", &produtos[3][1]);
            printf("Estoque cadastrado com sucesso\n");
        }
        else
            printf("Produto nao encontrado\n");

        break;

    case 4:
        if (productSelection == 1)
        {
            printf("Informe o novo preco das meias adultas estampadas\n");
            scanf("%f", &produtos[0][0]);
            printf("Preco cadastrado com sucesso\n");
        }
        else if (productSelection == 2)
        {
            printf("Informe o novo preco das meias adultas lisas\n");
            scanf("%f", &produtos[1][0]);
            printf("Preco cadastrado com sucesso\n");
        }
        else if (productSelection == 3)
        {
            printf("Informe o novo preco das meias infantis estampadas\n");
            scanf("%f", &produtos[2][0]);
            printf("Preco cadastrado com sucesso\n");
        }
        else if (productSelection == 4)
        {
            printf("Informe o novo preco das meias infantis lisas\n");
            scanf("%f", &produtos[3][0]);
            printf("Preco cadastrado com sucesso\n");
        }
        else
            printf("Produto nao encontrado\n");
        break;

    default:
        printf("Operacao invalida\n");
        return acessoFuncionario(produtos);
    }

    int choiceNewOp;
    printf("Deseja realizar outra operacao? (1 - sim, 2 - nao)\n");
    scanf("%d", &choiceNewOp);

    if (choiceNewOp == 1)
    {
        return acessoFuncionario(produtos);
    }
    else
        main();
}

// ***************************************************** TÉRMINO DA FUNÇÂO acessoFuncionario *****************************************************

// Função para exibir o catálogo de produtos, pegando os parâmetros passados na função 'acessoCliente'
void exibirCatalogo(char produtosRelatorio[][50], float produtos[4][4])
{
    setlocale(LC_CTYPE, "pt_BR.UTF-8");

    printf("Catálogo de Produtos:\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (j == 0 || j == 2)
                printf("Produto: %s: R$ %.2f; Estoque disponivel: %.0f\n", produtosRelatorio[i], produtos[i][j], produtos[i][j]); // Exibe o produto, preço e estoque disponível
        }
    }
}

// Função para calcular o lucro obtido através das vendas, o preço total de produção é somado e o valor é subtraído no valor total das vendas
float calcularLucro(float totalVendas, float totalProducao)
{
    return totalVendas - totalProducao;
}

// Função para realizar a compra, pegando os parâmetros passados na função 'acessoCliente'

float realizarCompra(float produtos[4][4])
{
    setlocale(LC_CTYPE, "pt_BR.UTF-8");

    int quantidade;
    int productSelection;
    int opSelection;
    float totalCompra = 0;

    printf("Informe o produto desejado\n");
    printf("1 - Linha de Meia adulta estampada\n");
    printf("2 - Linha de Meia adulta lisa\n");
    printf("3 - Linha de Meia infantil estampada\n");
    printf("4 - Linha de Meia infantil lisa\n");
    printf("Para sair, digite qualquer outro numero\n");
    scanf("%d", &productSelection);

    if (productSelection < 1 || productSelection > 4)
    {
        return main();
    }

    printf("Informe a quantidade desejada\n");
    scanf("%d", &quantidade);

    if (quantidade > produtos[productSelection - 1][1]) // Caso a quantidade seja maior que o estoque disponível, a compra não é realizada
    {
        printf("Quantidade indisponivel\n");
        return realizarCompra(produtos);
    }
    else if (quantidade == produtos[productSelection - 1][1] || quantidade < produtos[productSelection - 1][1]) // Caso a quantidade seja igual ou menor que o estoque disponível, o produto é comprado
    {
        printf("Produto comprado\n");
        produtos[productSelection - 1][1] -= quantidade;
    }

    totalCompra += produtos[productSelection - 1][0] * quantidade;

    printf("Compra realizada com sucesso\n");
    printf("Total da compra: R$ %.2f\n", totalCompra);
    printf("Realizar mais alguma compra? 1 - Sim, 2 - Nao\n");
    scanf("%d", &opSelection);

    if (opSelection == 1)
        return realizarCompra(produtos);
    else
        return totalCompra;
}

// Função para exibir as operações realizadas
void exibirOperacoes(char operacoes[100][50], float valores[100], int numOperacoes)
{
    printf("Operacoes realizadas:\n");
    for (int i = 0; i < numOperacoes; i++)
    {
        printf("%s\n", operacoes[i]);
    }
}

/*
    Função para lidar o acesso dos clientes, tendo a opção de comprar e verificar preço do produto.
*/

float acessoClientes(float produtos[4][4])
{
    setlocale(LC_CTYPE, "pt_BR.UTF-8");

    // Inicialização do catálogo de produtos, preços e preços de produção
    char produtosRelatorio[4][50] = {
        "Meia adulta lisa",
        "Meia adulta estampada",
        "Meia infantil lisa",
        "Meia infantil estampada"};

    // Inicialização do vetor de operações
    char operacoes[4][50] = {
        "Compra", 
        "Exibir catalogo", 
        "Exibir operacoes", 
        "Exibir lucro"};

    float valores[100];
    int numOperacoes = 0;

    int opcao;
    float totalVendas = 0;

    do
    {
        printf("\nEscolha uma opcao:\n");
        printf("1. Exibir catalogo de produtos\n");
        printf("2. Realizar compra(Exibir catalogo)\n");
        printf("3. Exibir operacoes realizadas\n");
        printf("5. Sair\n");
        scanf("%d", &opcao);

        if (opcao == 5)
            return main();

        switch (opcao)
        {
        case 1: 
            numOperacoes++;
            exibirCatalogo(produtosRelatorio, produtos);
            break;
        case 2:
            totalVendas += realizarCompra(produtos);
            break;
        case 3:
            numOperacoes++;
            exibirOperacoes(operacoes, valores, numOperacoes);
            break;
        case 4:
            printf("Saindo do programa.\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}

// Função principal

int main()
{
    int pessoa;

    float produtos[4][4];

    leiaProdutos(produtos); // Função para atribuir valores iniciais para a matriz de produtos

    printf("Informe seu id de usuario (1 - Funcionario, 2 - Cliente, 3 - Encerrar)\n");
    scanf("%d", &pessoa);

    if (pessoa == 1)
    {
        printf("\n***************************** BEM-VINDO FUNCIONARIO *****************************\n");
        acessoFuncionario(produtos);
    }
    else if (pessoa == 2)
    {
        printf("\n***************************** BEM-VINDO CLIENTE *****************************\n");
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                printf("%f\t", produtos[i][j]);
            }
            printf("\n");
        }
        acessoClientes(produtos);
    }
    else
        return 0;

    return 0;
}
