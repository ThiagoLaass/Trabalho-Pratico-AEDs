# Sistema de Controle de Vendas de Meias
Este repositório contém um programa simples para auxiliar um pequeno produtor de vestuário a gerenciar suas vendas de meias. O programa foi desenvolvido para atender a algumas necessidades específicas do produtor, tais como:

* Controle de Estoque: Apenas permite a venda de produtos disponíveis em estoque.
* Registro de Vendas Diárias: Registra as vendas realizadas durante o dia.
* Geração de Relatórios: Produz relatórios de meias em estoque e de vendas diárias, incluindo o lucro obtido.
## Funcionalidades
### Controle de Estoque
 O programa utiliza uma matriz para representar os produtos disponíveis para venda. Cada linha na matriz corresponde a um produto de meia e suas características:

* Tipo: Se é infantil ou adulto.
* Padrão: Se é lisa ou estampada.
* Quantidade em Estoque: A quantidade atual disponível para venda.
* Custo de Produção: O custo de produção da unidade.
* Preço de Venda: O preço de venda da unidade.
* Registro de Vendas Diárias
* O programa registra as vendas realizadas durante o dia, atualizando automaticamente a quantidade em estoque de cada produto após cada venda.

## Relatórios
* Relatório de Meias em Estoque: Gera um relatório detalhado das meias disponíveis para venda, incluindo tipo, padrão e quantidade em estoque.
* Relatório de Vendas do Dia e Lucro Obtido: Produz um resumo das vendas realizadas no dia, incluindo quantidade vendida, lucro obtido e outros dados relevantes.

## Uso do Programa
O programa foi desenvolvido em C e utiliza uma estrutura de matriz para armazenar e atualizar os dados dos produtos. Ao executa-lo, será perguntando o perfil atual, o usuario deve então escolher entre "funcionario" ou "cliente".
Funcionarios possuem a capacidade de editar dados dos produtos, como o estoque, preço e custo de produção. Se iniciado como cliente, o mesmo terá acesso apenas a funcionalidades como verificar preço, estoque e fazer a compra de algum(s) produto(s).

## Autores
Thiago Borges Laass, Matheus E. M. de Miranda H.
