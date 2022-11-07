#include "selecao.h"

void BaseSelecao(char cod[])
{
  sel = fopen(cod, "r+b");
  if (sel == NULL)
  {
    sel = fopen(cod, "w+b");
    if (sel == NULL)
    {
      printf(" Erro fatal: imposs�vel criar arquivo de dados.\n");
      exit(1);
    }
  }
}

void InicializarSelecao(Selecao *selecao)
{
  strstr(selecao->valor, "");
  selecao->quantidade = 0;
}

void LerSelecao(Selecao *selecao)
{
  printf("\n Digite o c�digo do produto: ");
  fflush(stdin);
  fgets(selecao->valor, MAX, stdin);
  selecao->valor[strlen(selecao->valor) - 1] = '\0';

  selecao->produto = BuscarProduto(selecao->valor);

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
      printf("\n Quantidade inv�lida! \n");
      Sleep(1);
    }
  }
}

void ExibirSelecao(Selecao *selecao)
{
  printf("\n C�digo: %s", selecao->valor);
  printf("\n Nome: %s", selecao->produto.nomeProd);

  if (selecao->produto.descricao == 1)
  {
    printf("\n-----------------");
    printf("\n Descri��o: ");
    ProdutoLiteDescricao();
  }
  if (selecao->produto.descricao == 2)
  {
    printf("\n-----------------");
    printf("\n Descri��o: ");
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

  printf("\n Valor: R$ %s por m�s", selecao->produto.valorProd);
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
    printf("\n N�o contem registros. \n");
  }
  fclose(sel);
}