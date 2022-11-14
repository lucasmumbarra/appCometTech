#include "venda.h"

void BaseVenda()
{
  ven = fopen(ARQ_VENDAS, "r+b");
  if (ven == NULL)
  {
    ven = fopen(ARQ_VENDAS, "w+b");
    if (ven == NULL)
    {
      printf(" Erro fatal: impossível criar arquivo de dados.\n");
      exit(1);
    }
  }
}

void InicializarVenda(Venda *venda)
{
  int i;
  strstr(venda->cod, "");
  strstr(venda->cliente->razaoSocial, "");
  for (i = 0; i < MAX; i++)
  {
    strstr(venda->selecao->produto.codProd, "");
    strstr(venda->selecao->produto.nomeProd, "");
    venda->selecao->produto.descricao = 0;
    venda->selecao->produto.catProd = 0;
    strstr(venda->selecao->produto.valorProd, "");
  }
  venda->pagamento = 0;
  venda->total = 0;
  venda->tamanho = 0;
}

void ExibirVenda(char nome[MAX], char cod[MAX])
{
  system("cls");
  printf(" /////////////////////////////////////////////////////////////////////\n");
  printf("\n");
  printf("                          FINALIZAR VENDA  \n");
  printf("\n");
  printf(" /////////////////////////////////////////////////////////////////////\n");
  printf("\n\n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
}

void CarregarVenda(char *cod, char *nome)
{
  int op;

  Venda venda;

  sprintf(venda.cod, "%i", CarregarCodigo());
  CarregarSelecao(cod, &venda);
  ExibirProdVenda(&venda);
  printf("\n\n Valor Total: %.2f", venda.total);
  printf("\n\n Deseja finalizar a compra: 1 - Sim  2 - Cancelar: ");
  scanf("%i", &op);

  if (op == 1)
  {
    BaseVenda();
    fseek(ven, 0, SEEK_END);

    if (fwrite(&venda, sizeof(Venda), 1, ven) == 0)
    {
      printf("Erro ao gravar o registro! \n\n");
      remove(cod);
      printf("\n Pressione alguma tecla para continuar.");
      getch();
    }
    else
    {
      fclose(ven);
      remove(cod);
      Sleep(1);
      ExibirCartao(venda.cod);
    }
  }
  else
  {
    remove(cod);
  }
}

void CarregarSelecao(char *cod, Venda *venda)
{
  BaseSelecao(cod);

  Selecao selecao;

  InicializarSelecao(&selecao);
  InicializarVenda(venda);

  int linha = 0, i = 0;

  rewind(sel);

  while (!feof(sel))
  {
    if (fread(&selecao, sizeof(Selecao), 1, sel) != 1)
    {
      break;
    }
    strcpy(venda->selecao[i].produto.codProd, selecao.produto.codProd);
    strcpy(venda->selecao[i].produto.nomeProd, selecao.produto.nomeProd);
    venda->selecao[i].produto.descricao = selecao.produto.descricao;
    venda->selecao[i].produto.catProd = selecao.produto.catProd;
    strcpy(venda->selecao[i].produto.valorProd, selecao.produto.valorProd);
    venda->selecao[i].quantidade = selecao.quantidade;
    venda->total = venda->total + (venda->selecao[i].quantidade * atoi(venda->selecao[i].produto.valorProd));
    venda->tamanho++;
    i++;
    linha++;
  }

  if (linha == 0)
  {
    printf("\n Não contém registros \n");
  }
  fclose(sel);
}

void ExibirProdVenda(Venda *venda)
{
  int i;

  for (i = 0; i < venda->tamanho; i++)
  {
    printf("\n\n Código: %s", venda->selecao[i].produto.codProd);
    printf("\n Nome: %s", venda->selecao[i].produto.nomeProd);

    if (venda->selecao[i].produto.descricao == 1)
    {
      printf("\n-----------------");
      printf("\n Descrição: ");
      ProdutoLiteDescricao();
    }
    if (venda->selecao[i].produto.descricao == 2)
    {
      printf("\n-----------------");
      printf("\n Descrição: ");
      ProdutoProDescricao();
    }

    if (venda->selecao[i].produto.catProd == 1)
    {
      printf("\n-----------------");
      printf("\n Categoria - Restaurante: ");
      ProdutoLiteCategoriaRestaurante();
    }
    if (venda->selecao[i].produto.catProd == 2)
    {
      printf("\n-----------------");
      printf("\n Categoria - Delivery: ");
      ProdutoLiteCategoriaDelivery();
    }
    if (venda->selecao[i].produto.catProd == 3)
    {
      printf("\n-----------------");
      printf("\n Categoria - Hamburgueria: ");
      ProdutoLiteCategoriaHamburgueria();
    }
    if (venda->selecao[i].produto.catProd == 4)
    {
      printf("\n-----------------");
      printf("\n Categoria - Pizzaria: ");
      ProdutoLiteCategoriaPizzaria();
    }

    printf("\n Valor: %s por mês", venda->selecao[i].produto.valorProd);
    printf("\n Quantidade: %i", venda->selecao[i].quantidade);
  }
}

void ExibirListaVenda(Venda *venda)
{
  int i;

  printf("\n Código venda: %s", venda->cod);
  printf("\n\n Cliente: %s", venda->cliente->razaoSocial);

  for (i = 0; i < venda->tamanho; i++)
  {
    printf("\n\n Código: %s", venda->selecao[i].produto.codProd);
    printf("\n Nome: %s", venda->selecao[i].produto.nomeProd);

    if (venda->selecao[i].produto.descricao == 1)
    {
      printf("\n-----------------");
      printf("\n Descrição: ");
      ProdutoLiteDescricao();
    }
    if (venda->selecao[i].produto.descricao == 2)
    {
      printf("\n-----------------");
      printf("\n Descrição: ");
      ProdutoProDescricao();
    }

    if (venda->selecao[i].produto.catProd == 1)
    {
      printf("\n-----------------");
      printf("\n Categoria - Restaurante: ");
      ProdutoLiteCategoriaRestaurante();
    }
    if (venda->selecao[i].produto.catProd == 2)
    {
      printf("\n-----------------");
      printf("\n Categoria - Delivery: ");
      ProdutoLiteCategoriaDelivery();
    }
    if (venda->selecao[i].produto.catProd == 3)
    {
      printf("\n-----------------");
      printf("\n Categoria - Hamburgueria: ");
      ProdutoLiteCategoriaHamburgueria();
    }
    if (venda->selecao[i].produto.catProd == 4)
    {
      printf("\n-----------------");
      printf("\n Categoria - Pizzaria: ");
      ProdutoLiteCategoriaPizzaria();
    }

    printf("\n Valor: %s", venda->selecao[i].produto.valorProd);
    printf("\n Quantidade: %i", venda->selecao[i].quantidade);
  }
  printf("\n\n Valor total: %.2f", venda->total);

  if (venda->pagamento == 0)
  {
    printf("\n\n Pagamento pendente \n");
  }
  else
  {
    printf("\n\n Pagamento efetuado \n");
  }
}

void ListarVenda()
{
  BaseVenda();
  Venda venda;
  InicializarVenda(&venda);

  int linha = 0;

  rewind(fp);

  while (!feof(ven))
  {
    if (fread(&venda, sizeof(Venda), 1, ven) != 1)
    {
      break;
    }
    ExibirListaVenda(&venda);
    printf("\n +++++++++++++++++++++++++++++ \n");
    linha++;
  }

  if (linha == 0)
  {
    printf("\n Não contém registros \n");
  }
  fclose(ven);
  printf("\n\n Pressione ENTER para voltar\n");
  getche();
}

void AlterarVenda(char *cod)
{
  BaseVenda();
  Venda venda;
  InicializarVenda(&venda);

  int pos = 0, op;

  pos = PesquisarVenda(cod);

  fseek(ven, pos * sizeof(Venda), SEEK_SET);

  if (fread(&venda, sizeof(Venda), 1, ven) == 1) {
    while(1) {
      venda.pagamento = 1;

      fseek(ven, pos * sizeof(Venda), SEEK_SET);

      if (fwrite(&venda, sizeof(Venda), 1, ven) != 1) {
        printf("\n Falha ao concluir pagamento!\n");
        printf("\n\n Pressione ENTER para continuar.");
        getche();
        break;
      } else {
        printf("\n\n Pagamento realizado com sucesso!\n");
        Sleep(2);
        break;
      }
    }
  }
  fclose(ven);
}

int PesquisarVenda(char *cod)
{
  BaseVenda();
  Venda venda;
  InicializarVenda(&venda);

  int pos = 0, linha = 0, op;

  rewind(ven);

  while (!feof(ven))
  {
    while (fread(&venda, sizeof(Venda), 1, ven))
    {
      if (strstr(venda.cod, cod))
      {
        pos = 1;
        return linha;
      }
      linha++;
    }
    if (pos == 0)
    {
      printf("Registro não encontrado");
    }
    break;
  }
  fclose(ven);
}

int CarregarCodigo()
{
  BaseVenda();

  Venda venda;

  InicializarVenda(&venda);

  int linha = 0;
  char codigo;
  rewind(fp);

  while (!feof(ven))
  {
    if (fread(&venda, sizeof(Venda), 1, ven) != 1)
    {
      break;
    }
    linha++;
  }
  return linha + 1;
  fclose(ven);
}