#include "submenu.h"

void MenuCliente()
{
  int op;

  do
  {
    system("cls");
    printf(" //////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("                         COMET TECH - CLIENTES  \n");
    printf("\n");
    printf(" //////////////////////////////////////////////////////////////////////\n");

    printf("\n\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n\n");
    printf(" 1 - CADASTRAR CLIENTE\n");
    printf(" 2 - PESQUISAR CLIENTE\n");
    printf(" 3 - LISTAR CLIENTE \n");
    printf(" 4 - ALTERAR CLIENTE \n");
    printf(" 5 - EXCLUIR CLIENTE \n");
    printf(" 0  - VOLTAR");

    printf("\n Escolha uma das opções acima: ");
    scanf("%d", &op);

    switch (op)
    {

    case 1:
      system("cls");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      printf("\n                  COMET TECH - CADASTRAR CLIENTE\n");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      system("pause");
      break;
    case 2:
      system("cls");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      printf("\n                  COMET TECH - PESQUISAR CLIENTE\n");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      system("pause");
      break;
    case 3:
      system("cls");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      printf("\n                  COMET TECH - LISTAR CLIENTE\n");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      system("pause");
      break;
    case 4:
      system("cls");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      printf("\n                 COMET TECH - ALTERAR CLIENTE\n");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      system("pause");
      break;
    case 5:
      system("cls");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      printf("\n                 COMET TECH - EXCLUIR CLIENTE\n");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      system("pause");
      break;
    case 0:
      system("cls");
      MenuGerencia();
      break;
    }
  } while (op != 0);
}

void MenuProduto()
{
  int op;

  do
  {
    system("cls");
    printf(" //////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("                         COMET TECH - PRODUTOS  \n");
    printf("\n");
    printf(" //////////////////////////////////////////////////////////////////////\n");

    printf("\n\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n\n");
    printf(" 1 - CADASTRAR PRODUTO\n");
    printf(" 2 - PESQUISAR PRODUTO\n");
    printf(" 3 - LISTAR PRODUTO \n");
    printf(" 4 - ALTERAR PRODUTO \n");
    printf(" 5 - EXCLUIR PRODUTO \n");
    printf(" 0 - VOLTAR");

    printf("\n Escolha uma das opções acima: ");
    scanf("%d", &op);

    switch (op)
    {

    case 1:
      system("cls");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      printf("\n                  COMET TECH - CADASTRAR PRODUTO\n");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      system("pause");
      break;
    case 2:
      system("cls");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      printf("\n                  COMET TECH - PESQUISAR PRODUTO\n");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      system("pause");
      break;
    case 3:
      system("cls");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      printf("\n                  COMET TECH - LISTAR PRODUTO\n");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      system("pause");
      break;
    case 4:
      system("cls");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      printf("\n                 COMET TECH - ALTERAR PRODUTO\n");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      system("pause");
      break;
    case 5:
      system("cls");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      printf("\n                 COMET TECH - EXCLUIR PRODUTO\n");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      system("pause");
      break;
    case 0:
      system("cls");
      MenuGerencia();
      break;
    }
  } while (op != 0);
}

void MenuVenda()
{
  int op;

  do
  {
    system("cls");
    printf(" //////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("                         COMET TECH - VENDAS  \n");
    printf("\n");
    printf(" //////////////////////////////////////////////////////////////////////\n");

    printf("\n\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n\n");
    printf(" 1 - CADASTRAR VENDA\n");
    printf(" 2 - PESQUISAR VENDA\n");
    printf(" 3 - LISTAR VENDA \n");
    printf(" 4 - ALTERAR VENDA \n");
    printf(" 5 - EXCLUIR VENDA \n");
    printf(" 0 - VOLTAR");

    printf("\n Escolha uma das opções acima: ");
    scanf("%d", &op);

    switch (op)
    {

    case 1:
      system("cls");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      printf("\n                  COMET TECH - CADASTRAR VENDA\n");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      system("pause");
      break;
    case 2:
      system("cls");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      printf("\n                  COMET TECH - PESQUISAR VENDA\n");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      system("pause");
      break;
    case 3:
      system("cls");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      printf("\n                  COMET TECH - LISTAR VENDA\n");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      system("pause");
      break;
    case 4:
      system("cls");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      printf("\n                 COMET TECH - ALTERAR VENDA\n");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      system("pause");
      break;
    case 5:
      system("cls");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      printf("\n                 COMET TECH - EXCLUIR VENDA\n");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      system("pause");
      break;
    case 0:
      system("cls");
      MenuGerencia();
      break;
    }
  } while (op != 0);
}
