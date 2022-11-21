#include "submenu.h"

void MenuCliente()
{
  int op;

  Funcionario funcionario;

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
      CadastrarCliente();
      break;
    case 2:
      system("cls");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      printf("\n                  COMET TECH - PESQUISAR CLIENTE\n");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      PesquisarCliente();
      break;
    case 3:
      system("cls");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      printf("\n                  COMET TECH - LISTAR CLIENTE\n");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      ListarCliente();
      break;
    case 0:
      system("cls");
      MenuVendedor(&funcionario);
      break;
    }
  } while (op != 0);
}

void MenuProduto()
{
  int op;

  Funcionario funcionario;

  do
  {
    system("cls");
    printf(" //////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("                         COMET TECH - PRODUTOS  \n");
    printf("\n");
    printf(" //////////////////////////////////////////////////////////////////////\n");

    printf("\n\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n\n");
    printf(" 1 - PESQUISAR PRODUTO\n");
    printf(" 2 - LISTAR PRODUTO \n");
    printf(" 0 - VOLTAR");

    printf("\n Escolha uma das opções acima: ");
    scanf("%d", &op);

    switch (op)
    {

    case 1:
      system("cls");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      printf("\n                  COMET TECH - PESQUISAR PRODUTO\n");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      PesquisarProduto();
      break;
    case 2:
      system("cls");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      printf("\n                  COMET TECH - LISTAR PRODUTO\n");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      ListarProduto();
      break;
    case 0:
      system("cls");
      MenuVendedor(&funcionario);
      break;
    }
  } while (op != 0);
}

void MenuVenda(Funcionario *funcionario)
{
  int op, val;

  char cod[30];

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
    printf(" 0 - VOLTAR\n");

    printf("\n Escolha uma das opções acima: ");
    scanf("%d", &op);

    switch (op)
    {

    case 1:
      system("cls");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      printf("\n                  COMET TECH - CADASTRAR VENDA\n");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      BaseSelecao(funcionario->cod);
      CadastrarSelecao();
      printf("\n Deseja continuar a compra: 1 - Sim   2 - Não: \n Selecione a opção: ");
      scanf("%i", &op);
      if (op == 1)
      {
        ExibirVenda(funcionario->cod);
        break;
      }
      else if (op == 2)
      {
        printf("Pressione ENTER para voltar ao menu.");
        break;
      }
      else
      {
        printf("\n\n Opção inválida! \n");
        Sleep(1);
      }
      break;
    case 2:
      system("cls");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      printf("\n                  COMET TECH - PESQUISAR VENDA\n");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      PesquisarVendaLt();
      break;
    case 3:
      system("cls");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      printf("\n                  COMET TECH - LISTAR VENDA\n");
      printf(" //////////////////////////////////////////////////////////////////////\n");
      ListarVenda();
      break;
    case 0:
      system("cls");
      break;
    }
  } while (op != 0);
}
