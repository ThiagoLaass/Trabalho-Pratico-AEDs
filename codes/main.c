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

void leiaProdutos(int produtos[4][4])
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

int acessoFuncionario(float produtos[4][4])
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
            printf("O preco atual das meias adultas estampadas e: %d\n reais", produtos[0][0]);

        else if (productSelection == 2)
            printf("O preco atual das meias adultas lisas: %d\n", produtos[1][0]);

        else if (productSelection == 3)
            printf("O preco das meias infantis estampadas: %d\n", produtos[2][0]);

        else if (productSelection == 4)
            printf("O preco atual das meias infantis lisas: %d\n", produtos[3][0]);

        else
            printf("Produto nao encontrado\n");

        break;

    case 2:

        if (productSelection == 1)
            printf("O estoque atual das meias adultas estampadas e: %d\n", produtos[0][1]);

        else if (productSelection == 2)
            printf("O estoque atual das meias adultas lisas: %d\n", produtos[1][1]);

        else if (productSelection == 3)
            printf("O estoque atual das meias infantis estampadas: %d\n", produtos[2][1]);

        else if (productSelection == 4)
            printf("O estoque atual das meias infantis lisas: %d\n", produtos[3][1]);

        else
            printf("Produto nao encontrado\n");

        break;

    case 3:
        if (productSelection == 1)
        {
            printf("Informe o novo estoque das meias adultas estampadas\n");
            scanf("%d", &produtos[0][1]);
            printf("Estoque cadastrado com sucesso\n");
        }
        else if (productSelection == 2)
        {
            printf("Informe o novo estoque das meias adultas lisas\n");
            scanf("%d", &produtos[1][1]);
            printf("Estoque cadastrado com sucesso\n");
        }
        else if (productSelection == 3)
        {
            printf("Informe o novo estoque das meias infantis estampadas\n");
            scanf("%d", &produtos[2][1]);
            printf("Estoque cadastrado com sucesso\n");
        }
        else if (productSelection == 4)
        {
            printf("Informe o novo estoque das meias infantis lisas\n");
            scanf("%d", &produtos[3][1]);
            printf("Estoque cadastrado com sucesso\n");
        }
        else
            printf("Produto nao encontrado\n");

        break;

    case 4:
        if (productSelection == 1)
        {
            printf("Informe o novo preco das meias adultas estampadas\n");
            scanf("%d", &produtos[0][0]);
            printf("Preco cadastrado com sucesso\n");
        }
        else if (productSelection == 2)
        {
            printf("Informe o novo preco das meias adultas lisas\n");
            scanf("%d", &produtos[1][0]);
            printf("Preco cadastrado com sucesso\n");
        }
        else if (productSelection == 3)
        {
            printf("Informe o novo preco das meias infantis estampadas\n");
            scanf("%d", &produtos[2][0]);
            printf("Preco cadastrado com sucesso\n");
        }
        else if (productSelection == 4)
        {
            printf("Informe o novo preco das meias infantis lisas\n");
            scanf("%d", &produtos[3][0]);
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
        return acessoFuncionario(produtos);
    else
        main();
}

// ***************************************************** TÉRMINO DA FUNÇÂO acessoFuncionario *****************************************************

/*
    Função para lidar o acesso dos clientes, tendo a opção de comprar e verificar preço do produto.
*/

// Função para exibir o catálogo de produtos, pegando os parâmetros passados na função 'acessoCliente'
void exibirCatalogo(char produtosRelatorio[][50], int produtos[4][4])
{
    printf("Catálogo de Produtos:\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if(j == 0 || j == 2)
            printf("%d. %s - R$ %.2f (Preço de Produção: R$ %.2f)\n", i + 1, produtosRelatorio[i], produtos[i][j]);
        }
    }
}

// Função para calcular o lucro obtido através das vendas, o preço total de produção é somado e o valor é subtraído no valor total das vendas
float calcularLucro(float totalVendas, float totalProducao)
{
    return totalVendas - totalProducao;
}

// Função para realizar uma compra. Pegando parâmetros passados na função 'acessoCliente'
float realizarCompra(char produtos[][50], float precos[], float precosProducao[], char operacoes[][50], float valores[], int *numOperacoes)
{
    int codigo, quantidade;
    float totalCompra = 0;

    printf("\nDigite o código do produto que deseja comprar (1 a 4) ou 0 para encerrar: ");
    scanf("%d", &codigo);

    while (codigo >= 1 && codigo <= 4)
    {
        printf("Digite a quantidade desejada: ");
        scanf("%d", &quantidade);

        if (quantidade > 0)
        {
            float subtotal = precos[codigo - 1] * quantidade;
            totalCompra += subtotal;
            printf("Produto %s adicionado ao carrinho. Subtotal: R$ %.2f\n", produtos[codigo - 1], subtotal);

            // Armazenar operação no vetor
            snprintf(operacoes[*numOperacoes], sizeof(operacoes[0]), "Compra de %d unidades de %s - R$ %.2f", quantidade, produtos[codigo - 1], subtotal);
            valores[*numOperacoes] = subtotal;
            (*numOperacoes)++;
        }
        else
        {
            printf("Quantidade inválida. Tente novamente.\n");
        }

        printf("\nDigite o código do próximo produto (1 a %d) ou 0 para encerrar: ", 4);
        scanf("%d", &codigo);
    }

    printf("Total da compra: R$ %.2f\n", totalCompra);
    printf("Compra finalizada. Obrigado!\n");

    return totalCompra;
}

// Função para exibir as operações realizadas
void exibirOperacoes(char operacoes[][50], float valores[], int numOperacoes)
{
    printf("\nOperações realizadas:\n");
    for (int i = 0; i < numOperacoes; i++)
    {
        printf("%s - R$ %.2f\n", operacoes[i], valores[i]);
    }
}

int acessoCliente(produtos)
{
    // Inicialização do catálogo de produtos, preços e preços de produção
    char produtosRelatorio[4][50] = {
        "Meia adulta lisa",
        "Meia adulta estampada",
        "Meia infantil lisa",
        "Meia infantil estampada"};

    // Inicialização do vetor de operações
    char operacoes[100][50];
    float valores[100];
    int numOperacoes = 0;

    int opcao;
    float totalVendas = 0;
    float totalProducao = 0;

    do
    {
        printf("\nEscolha uma opção:\n");
        printf("1. Exibir catálogo de produtos\n");
        printf("2. Realizar compra(Exibir catálogo)\n");
        printf("3. Exibir operações realizadas\n");
        printf("4. Exibir lucro\n");
        printf("5. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            exibirCatalogo(produtosRelatorio);
            break;
        case 2:
            totalVendas += realizarCompra(produtosRelatorio, operacoes, &numOperacoes);
            break;
        case 3:
            exibirOperacoes(operacoes, valores, numOperacoes);
            break;
        case 4:
            totalProducao = 0;
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    totalProducao += produtos[i][j];
                }
            }
            printf("Lucro total: R$ %.2f\n", totalVendas - totalProducao);
            break;
        case 5:
            printf("Saindo do programa.\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int pessoa;

    float produtos[4][4];

    leiaProdutos(produtos);

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
        acessoClientes(produtos);
    }
    else
        return 0;

    return 0;
}
