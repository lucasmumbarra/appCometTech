#include "venda.h"

void BaseVenda()
{
  ven = fopen(ARQ_VENDAS, "r+b");
  if (ven == NULL)
  {
    ven = fopen(ARQ_VENDAS, "w+b");
    if (ven == NULL)
    {
      printf(" Erro fatal: imposs�vel criar arquivo de dados.\n");
      exit(1);
    }
  }
}

void InicializarVenda(Venda *venda)
{
  int i;
  strstr(venda->cod, "");
  for (i = 0; i < MAX; i++)
  {
    strstr(venda->selecao->produto.codProd, "");
    strstr(venda->selecao->produto.nomeProd, "");
    strstr(venda->selecao->cliente.razaoSocial, "");
    venda->selecao->produto.descricao = 0;
    venda->selecao->produto.catProd = 0;
    strstr(venda->selecao->produto.valorProd, "");
  }
  venda->pagamento = 0;
  venda->total = 0;
  venda->tamanho = 0;
}

void ExibirVenda(char cod[MAX])
{
  system("cls");
  printf(" /////////////////////////////////////////////////////////////////////\n");
  printf("\n");
  printf("                          FINALIZAR VENDA  \n");
  printf("\n");
  printf(" /////////////////////////////////////////////////////////////////////\n");
  printf("\n\n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n");
  CarregarVenda(cod);
}

void CarregarVenda(char *cod)
{
  int op, ano = 12;
  float total;

  Venda venda;

  sprintf(venda.cod, "%i", CarregarCodigo());
  CarregarSelecao(cod, &venda);
  ExibirProdVenda(&venda);

  total = venda.total * ano;

  printf("\n\n Valor Total: R$ %.2f por ano", total);
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
      Sleep(1000);
      ExibirCartao(venda.cod);
    }
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
    strcpy(venda->selecao[i].cliente.razaoSocial, selecao.cliente.razaoSocial);
    strcpy(venda->selecao[i].dataVenda, selecao.dataVenda);
    strcpy(venda->selecao[i].dataVencimento, selecao.dataVencimento);
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
    printf("\n N�o cont�m registros \n");
  }
  fclose(sel);
}

void ExibirProdVenda(Venda *venda)
{
  int i;

  for (i = 0; i < venda->tamanho; i++)
  {
    printf("\n\n C�digo: %s", venda->selecao[i].produto.codProd);
    printf("\n Nome: %s", venda->selecao[i].produto.nomeProd);
    printf("\n Raz�o social: %s", venda->selecao[i].cliente.razaoSocial);
    printf("\n Data de venda: %s", venda->selecao[i].dataVenda);
    printf("\n Data de vencimento: %s", venda->selecao[i].dataVencimento);

    if (venda->selecao[i].produto.descricao == 1)
    {
      printf("\n-----------------");
      printf("\n Descri��o: ");
      ProdutoLiteDescricao();
    }
    if (venda->selecao[i].produto.descricao == 2)
    {
      printf("\n-----------------");
      printf("\n Descri��o: ");
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

    printf("\n Valor: %s por m�s", venda->selecao[i].produto.valorProd);
    printf("\n Quantidade: %i", venda->selecao[i].quantidade);
  }
}

void ExibirListaVenda(Venda *venda)
{
  int i, ano = 12;
  float total;

  printf("\n C�digo venda: %s", venda->cod);

  for (i = 0; i < venda->tamanho; i++)
  {
    printf("\n\n C�digo: %s", venda->selecao[i].produto.codProd);
    printf("\n Nome: %s", venda->selecao[i].produto.nomeProd);
    printf("\n Raz�o social: %s", venda->selecao[i].cliente.razaoSocial);
    printf("\n Data de venda: %s", venda->selecao[i].dataVenda);
    printf("\n Data de vencimento: %s", venda->selecao[i].dataVencimento);

    if (venda->selecao[i].produto.descricao == 1)
    {
      printf("\n-----------------");
      printf("\n Descri��o: ");
      ProdutoLiteDescricao();
    }
    if (venda->selecao[i].produto.descricao == 2)
    {
      printf("\n-----------------");
      printf("\n Descri��o: ");
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

    printf("\n Valor: R$ %s por m�s", venda->selecao[i].produto.valorProd);
    printf("\n Quantidade: %i", venda->selecao[i].quantidade);
  }

  total = venda->total * ano;

  printf("\n\n Valor total: R$ %.2f por ano", total);

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
    printf("\n N�o cont�m registros \n");
  }
  fclose(ven);
  printf("\n\n Pressione ENTER para voltar\n");
  getche();
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
      printf("Registro n�o encontrado");
    }
    break;
  }
  fclose(ven);
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
        Sleep(2000);
        break;
      }
    }
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