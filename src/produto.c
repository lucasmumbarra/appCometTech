#include "produto.h"

void BaseProduto()
{

  fp = fopen(ARQ_PRODUTO, "r+b");
  if (fp == NULL)
  {
    fp = fopen(ARQ_PRODUTO, "w+b");
    if (fp == NULL)
    {
      printf(" Erro fatal: imposs�vel criar arquivo de dados\n");
      exit(1);
    }
  }
}

void InicializarProduto(Produto *produto)
{
  strcpy(produto->cod, "");
  strcpy(produto->codProd, "");
  strcpy(produto->nomeProd, "");
  produto->descricao = 0;
  produto->catProd = 0;
  produto->itensInc = 0;
  produto->funcProd = 0;
  produto->integProd = 0;
  strcpy(produto->valorProd, "");
  produto->ativo = 1;
  produto->tipo = 0;
}

void LerProduto(Produto *produto)
{
  sprintf(produto->cod, "%i", CarregarCodigoProduto());
  printf(" C�digo: %s", produto->cod);

  printf("\n C�digo produto: ");
  fflush(stdin);
  fgets(produto->codProd, MIN, stdin);
  produto->codProd[strlen(produto->codProd) - 1] = '\0';
  
  printf("\n Nome produto: ");
  fflush(stdin);
  fgets(produto->nomeProd, MAX, stdin);
  produto->nomeProd[strlen(produto->nomeProd) - 1] = '\0';

  printf("\n Selecione a descri��o do produto:\n 1 - Lite  2 - Pro");
  printf("\n Descri��o: ");
  fflush(stdin);
  scanf("%i", &produto->descricao);

  printf("\n Selecione a categoria do produto:\n 1 - Restaurante  2 - Delivery  3 - Hamburgueria  4 - Pizzaria");
  printf("\n Categoria: ");
  fflush(stdin);
  scanf("%i", &produto->catProd);

  printf("\n Selecione os itens inclusos:\n 1 - Lite  2 - Pro");
  printf("\n Itens inclusos: ");
  fflush(stdin);
  scanf("%i", &produto->itensInc);

  printf("\n Selecione as funcionalidades do produto:\n 1 - Lite  2 - Pro");
  printf("\n Funcionalidades do produto: ");
  fflush(stdin);
  scanf("%i", &produto->funcProd);

  printf("\n Selecione as integra��es do produto:\n 1 - Lite  2 - Pro");
  printf("\n Integra��es do produto: ");
  fflush(stdin);
  scanf("%i", &produto->integProd);

  printf("\n Valor do produto: ");
  fflush(stdin);
  fgets(produto->valorProd, MIN, stdin);
  produto->valorProd[strlen(produto->valorProd) - 1] = '\0';

  printf("\n Selecione o tipo do produto:\n 1 - Lite  2 - Pro");
  printf("\n Tipo do produto: ");
  fflush(stdin);
  scanf("%i", &produto->tipo);
}

void ExibirProduto(Produto *produto)
{
  printf("\n C�digo: %s", produto->cod);
  printf("\n C�digo produto: %s", produto->codProd);
  printf("\n Nome: %s", produto->nomeProd);


  if (produto->descricao == 1)
  {
    printf("\n-----------------");
    printf("\n Descri��o: ");
    ProdutoLiteDescricao();
  }
  if (produto->descricao == 2)
  {
    printf("\n Pro");
  }


  if (produto->catProd == 1)
  {
    printf("\n-----------------");
    printf("\n Categoria - Restaurante: ");
    ProdutoLiteCategoriaRestaurante();
  }
  if (produto->catProd == 2)
  {
    printf("\n-----------------");
    printf("\n Categoria - Delivery: ");
    ProdutoLiteCategoriaDelivery();
  }
  if (produto->catProd == 3)
  {
    printf("\n-----------------");
    printf("\n Categoria - Hamburgueria: ");
    ProdutoLiteCategoriaHamburgueria();
  }
  if (produto->catProd == 4)
  {
    printf("\n-----------------");
    printf("\n Categoria - Pizzaria: ");
    ProdutoLiteCategoriaPizzaria();
  }


  if (produto->itensInc == 1)
  {
    printf("\n Lite");
  }
  if (produto->itensInc == 2)
  {
    printf("\n Pro");
  }


  if (produto->funcProd == 1)
  {
    printf("\n Lite");
  }
  if (produto->funcProd == 2)
  {
    printf("\n Pro");
  }


  if (produto->integProd == 1)
  {
    printf("\n Lite");
  }
  if (produto->integProd == 2)
  {
    printf("\n Pro");
  }

  printf("\n Valor: %s", produto->valorProd);
}

void CadastrarProduto()
{
  Produto produto;
  int op;
  InicializarProduto(&produto);
  LerProduto(&produto);

  while (1)
  {
    system("cls");
    ExibirProduto(&produto);
    printf("\n\n 1 - SALVAR  2 - ALTERAR  3 - SAIR \n Selecione a op��o: ");
    scanf("%i", &op);

    if (op == 1)
    {
      BaseProduto();
      fseek(fp, 0, SEEK_END);
      if (fwrite(&produto, sizeof(Produto), 1, fp) == 0)
      {
        printf("Erro ao gravar o registro! \n\n");
        printf("\n Pressione alguma tecla para continuar.");
        getch();
      }
      else
      {
        printf("Registro cadastrado com sucesso! \n\n");
        fclose(fp);
        Sleep(1);
        break;
      }
    }

    if (op == 2)
    {
      while (1)
      {
        system("cls");
        printf("ALTERAR \n\n");
        ExibirProduto(&produto);
        printf("\n 1 - C�DIGO PRODUTO  2 - NOME PRODUTO  3 - DESCRI��O  4 - CATEGORIA  5 - ITENS INCLUSOS\n");
        printf("\n 6 - FUNCIONALIDADES DO PRODUTO  7 - INTEGRA��ES DO PRODUTO  8 - VALOR  9 - VOLTAR\n Selecione uma op��o: ");
        scanf("%i", &op);

        if (op == 1)
        {
          printf(" C�digo produto: ");
          fflush(stdin);
          fgets(produto.codProd, MIN, stdin);
        }

        if (op == 2)
        {
          printf(" Nome produto: ");
          fflush(stdin);
          fgets(produto.nomeProd, MAX, stdin);
        }

        if (op == 3)
        {
          printf("\n Selecione a descri��o do produto:\n 1 - Lite  2 - Pro");
          printf("\n Descri��o: ");
          fflush(stdin);
          scanf("%i", &produto.descricao);
        }

        if (op == 4)
        {
          printf("\n Selecione a categoria do produto:\n 1 - Restaurante  2 - Delivery  3 - Hamburgueria  4 - Pizzaria");
          printf("\n Categoria: ");
          fflush(stdin);
          scanf("%i", &produto.catProd);
        }

        if (op == 5)
        {
          printf("\n Selecione os itens inclusos:\n 1 - Lite  2 - Pro");
          printf("\n Itens inclusos: ");
          fflush(stdin);
          scanf("%i", &produto.itensInc);
        }

        if (op == 6)
        {
          printf("\n Selecione as funcionalidades do produto:\n 1 - Lite  2 - Pro");
          printf("\n Funcionalidades do produto: ");
          fflush(stdin);
          scanf("%i", &produto.funcProd);
        }

        if (op == 7)
        {
          printf("\n Selecione as integra��es do produto:\n 1 - Lite  2 - Pro");
          printf("\n Integra��es do produto: ");
          fflush(stdin);
          scanf("%i", &produto.integProd);
        }

        if (op == 8)
        {
          printf("Valor do produto: ");
          fflush(stdin);
          fgets(produto.valorProd, MIN, stdin);
        }

        if (op == 9)
        {
          fflush(stdin);
          break;
        }
      }
    }

    if (op == 3)
    {
      printf("\nVoltando ao menu!");
      Sleep(1);
      break;
    }
    else
    {
      printf("\n Op��o inv�lida! \n");
      Sleep(1);
    }
  }
}

void ListarProduto()
{
  BaseProduto();
  Produto produto;
  InicializarProduto(&produto);
  int linha = 0;
  rewind(fp);

  while (!feof(fp))
  {
    if (fread(&produto, sizeof(Produto), 1, fp) != 1)
    {
      break;
    }
    if (produto.ativo == 0)
    {
      continue;
    }
    if (produto.tipo == 0)
    {
      continue;
    }
    ExibirProduto(&produto);
    printf("\n ++++++++++++++++ \n");
    linha++;
  }

  if (linha == 0)
  {
    printf("\n N�o cont�m registros. \n");
  }
  printf("\n Pressione ENTER para voltar ao MENU.");
  getche();
}

int PesquisarProduto()
{
  BaseProduto();
  Produto produto;
  InicializarProduto(&produto);

  char valor[MAX];
  strcpy(valor, "");

  int pos = 0, linha = 0, op;

  rewind(fp);

  while (!feof(fp))
  {
    printf("Digite a nome do produto ou o c�digo do produto a ser procurado: ");
    fflush(stdin);
    fgets(valor, MAX, stdin);
    valor[strlen(valor) - 1] = '\0';

    if (strlen(valor) < 1)
    {
      printf("Nome Inv�lido! \n\n");
    }
    else
    {
      while (fread(&produto, sizeof(Produto), 1, fp))
      {
        if (produto.ativo != 0 && strstr(produto.nomeProd, valor) || produto.ativo != 0 && strstr(produto.codProd, valor))
        {
          ExibirProduto(&produto);
          pos = 1;
          printf("\n\n Pressione ENTER para continuar.");
          getche();
          return linha;
        }
        linha++;
      }
      if (pos == 0)
      {
        printf("Registro n�o encontrado.");
      }
      printf("\n\n Pressione ENTER para continuar.");
      getche();

      break;
    }
  }
  fclose(fp);
}

void ExcluirProduto()
{
  BaseProduto();
  Produto produto;
  InicializarProduto(&produto);

  int pos = 0, op;

  pos = PesquisarProduto();

  fseek(fp, pos * sizeof(Produto), SEEK_SET);

  if (fread(&produto, sizeof(Produto), 1, fp) == 1)
  {
    while (1)
    {
      system("cls");
      ExibirProduto(&produto);
      printf("\n\n 1 - EXCLUIR  2 -SAIR \n Selecione uma op��o: ");
      scanf("%i", &op);

      if (op == 1)
      {
        produto.ativo = 0;
        fseek(fp, pos * sizeof(Produto), SEEK_SET);

        if (fwrite(&produto, sizeof(Produto), 1, fp) != 1)
        {
          printf("\n Falha ao excluir o registro!\n");
          printf("\n\n Pressione ENTER para continuar.");
          getche();
          break;
        }
        else
        {
          printf("\n Registro exclu�do com sucesso!\n");
          printf("\n\n Pressione ENTER para continuar.");
          getche();
          break;
        }
      }
      if (op == 2)
      {
        break;
      }
    }
  }
  fclose(fp);
}

void AlterarProduto()
{
  BaseProduto();
  Produto produto;

  int pos, op;

  pos = PesquisarProduto();

  fseek(fp, pos * sizeof(Produto), SEEK_SET);

  if (fread(&produto, sizeof(Produto), 1, fp) == 1)
  {
    while (1)
    {
      system("cls");
      printf(" ++++++++++ ALTERAR FUNCION�RIO ++++++++++\n");
      ExibirProduto(&produto);
      printf("\n 1 - C�DIGO PRODUTO  2 - NOME PRODUTO  3 - DESCRI��O  4 - CATEGORIA  5 - ITENS INCLUSOS\n");
      printf("\n 6 - FUNCIONALIDADES DO PRODUTO  7 - INTEGRA��ES DO PRODUTO  8 - VALOR  9 - SALVAR  10 - SAIR\n Selecione uma op��o: ");
      scanf("%i", &op);

      if (op == 1)
      {
        printf(" C�digo produto: ");
        fflush(stdin);
        fgets(produto.codProd, MIN, stdin);
      }

      if (op == 2)
      {
        printf(" Nome produto: ");
        fflush(stdin);
        fgets(produto.nomeProd, MAX, stdin);
      }

      if (op == 3)
      {
        printf("\n Selecione a descri��o do produto:\n 1 - Lite  2 - Pro");
        printf("\n Descri��o: ");
        fflush(stdin);
        scanf("%i", &produto.descricao);
      }

      if (op == 4)
      {
        printf("\n Selecione a categoria do produto:\n 1 - Restaurante  2 - Delivery  3 - Hamburgueria  4 - Pizzaria");
        printf("\n Categoria: ");
        fflush(stdin);
        scanf("%i", &produto.catProd);
      }

      if (op == 5)
      {
        printf("\n Selecione os itens inclusos:\n 1 - Lite  2 - Pro");
        printf("\n Itens inclusos: ");
        fflush(stdin);
        scanf("%i", &produto.itensInc);
      }

      if (op == 6)
      {
        printf("\n Selecione as funcionalidades do produto:\n 1 - Lite  2 - Pro");
        printf("\n Funcionalidades do produto: ");
        fflush(stdin);
        scanf("%i", &produto.funcProd);
      }

      if (op == 7)
      {
        printf("\n Selecione as integra��es do produto:\n 1 - Lite  2 - Pro");
        printf("\n Integra��es do produto: ");
        fflush(stdin);
        scanf("%i", &produto.integProd);
      }

      if (op == 8)
      {
        printf("Valor do produto: ");
        fflush(stdin);
        fgets(produto.valorProd, MIN, stdin);
      }

      if (op == 9)
      {
        fseek(fp, pos * sizeof(Produto), SEEK_SET);
        if (fwrite(&produto, sizeof(Produto), 1, fp) != 1)
        {
          printf("\n Falha ao Alterar o registro!\n");
          printf("\n\n Pressione ENTER para continuar.");
          getche();
          break;
        }
        else
        {
          printf("\n Registro alterado com sucesso!\n");
          printf("\n\n Pressione ENTER para continuar.");
          getche();
          break;
        }
      }

      if (op == 10)
      {
        printf("\n SAINDO \n");
        MenuProdutoGerencia();
      }
    }
  }
  fclose(fp);
}

int CarregarCodigoProduto()
{
  BaseProduto();
  Produto produto;

  int linha = 0;
  rewind(fp);

  while (!feof(fp))
  {
    if (fread(&produto, sizeof(Produto), 1, fp) != 1)
    {
      break;
    }
    linha++;
  }
  return linha + 1;
  fclose(fp);
}
