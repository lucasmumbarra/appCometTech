#include "selecao.h"

void BaseSelecao(char cod[])
{
  sel = fopen(cod, "r+b");
  if (sel == NULL)
  {
    sel = fopen(cod, "w+b");
    if (sel == NULL)
    {
      printf(" Erro fatal: impossível criar arquivo de dados.\n");
      exit(1);
    }
  }
}

void InicializarSelecao(Selecao *selecao)
{
  strstr(selecao->valorProd, "");
  strstr(selecao->valorCliente, "");
  strstr(selecao->dataVenda, "");
  strstr(selecao->dataVencimento, "");
  selecao->quantidade = 0;
}

void LerSelecao(Selecao *selecao)
{
  printf("\n Digite o código do produto: ");
  fflush(stdin);
  fgets(selecao->valorProd, MAX, stdin);
  selecao->valorProd[strlen(selecao->valorProd) - 1] = '\0';

  selecao->produto = BuscarProduto(selecao->valorProd);

  printf("\n Digite o CNPJ do cliente: ");
  fflush(stdin);
  fgets(selecao->valorCliente, MAX, stdin);
  selecao->valorCliente[strlen(selecao->valorCliente) - 1] = '\0';

  selecao->cliente = BuscarCliente(selecao->valorCliente);

  printf("\n Digite a data de venda: ");
  fflush(stdin);
  fgets(selecao->dataVenda, MAX, stdin);
  selecao->dataVenda[strlen(selecao->dataVenda) - 1] = '\0';

  printf("\n Digite a data de vencimento: ");
  fflush(stdin);
  fgets(selecao->dataVencimento, MAX, stdin);
  selecao->dataVencimento[strlen(selecao->dataVencimento) - 1] = '\0';

  while (1)
  {
    printf("\n Digite a quantidade do produto: ");
    scanf("%i", &selecao->quantidade);
    if (selecao->quantidade > 0)
    {
      break;
    }
    else
    {
      printf("\n Quantidade inválida! \n");
      Sleep(1);
    }
  }
}

void ExibirSelecao(Selecao *selecao)
{
  printf("\n Código: %s", selecao->valorProd);
  printf("\n Nome: %s", selecao->produto.nomeProd);
  printf("\n Razão social: %s", selecao->cliente.razaoSocial);
  printf("\n Data da venda: %s", selecao->dataVenda);
  printf("\n Data de vencimento: %s", selecao->dataVencimento);

  if (selecao->produto.descricao == 1)
  {
    printf("\n-----------------");
    printf("\n Descrição: ");
    ProdutoLiteDescricao();
  }
  if (selecao->produto.descricao == 2)
  {
    printf("\n-----------------");
    printf("\n Descrição: ");
    ProdutoProDescricao();
  }

  if (selecao->produto.catProd == 1)
  {
    printf("\n-----------------");
    printf("\n Categoria - Restaurante: ");
    ProdutoLiteCategoriaRestaurante();
  }
  if (selecao->produto.catProd == 2)
  {
    printf("\n-----------------");
    printf("\n Categoria - Delivery: ");
    ProdutoLiteCategoriaDelivery();
  }
  if (selecao->produto.catProd == 3)
  {
    printf("\n-----------------");
    printf("\n Categoria - Hamburgueria: ");
    ProdutoLiteCategoriaHamburgueria();
  }
  if (selecao->produto.catProd == 4)
  {
    printf("\n-----------------");
    printf("\n Categoria - Pizzaria: ");
    ProdutoLiteCategoriaPizzaria();
  }

  printf("\n Valor: R$ %s por mês", selecao->produto.valorProd);
  printf("\n Quantidade: %i", selecao->quantidade);
}

void CadastrarSelecao()
{
  Selecao selecao;
  InicializarSelecao(&selecao);
  LerSelecao(&selecao);
  fseek(sel, 0, SEEK_END);
  fwrite(&selecao, sizeof(Selecao), 1, sel);
  fclose(sel);
}

void ListarSelecao()
{
  Selecao selecao;
  InicializarSelecao(&selecao);
  int linha = 0;
  rewind(sel);

  while (!feof(sel))
  {
    if (fread(&selecao, sizeof(Selecao), 1, sel) != 1)
    {
      break;
    }
    ExibirSelecao(&selecao);
    printf("\n +++++++++++++++++++++  \n");
    linha++;
  }

  if (linha == 0)
  {
    printf("\n Não contem registros. \n");
  }
  fclose(sel);
}