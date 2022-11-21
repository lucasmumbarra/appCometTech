#include "menu.h"

void MenuGerencia(Funcionario *funcionario)
{

    int op;

    do
    {
        system("cls");
        printf(" //////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        printf("                           COMET TECH - GERÊNCIA  \n");
        printf("\n");
        printf(" //////////////////////////////////////////////////////////////////////\n");

        printf("\n\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n\n");
        printf(" 1 - CLIENTE \n");
        printf(" 2 - FUNCIONÁRIO \n");
        printf(" 3 - PRODUTO \n");
        printf(" 4 - VENDAS \n");
        printf(" 0 - SAIR \n");

        printf("\n Escolha uma das opções acima: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                        COMET TECH - CLIENTE   \n");
            printf("\n ////////////////////////////////////////////////////////////////////\n");
            MenuClienteGerencia();
            break;
        case 2:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                        COMET TECH - FUNCIONÁRIO   \n");
            printf("\n ////////////////////////////////////////////////////////////////////\n");
            MenuFuncionarioGerencia();
            break;
        case 3:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                        COMET TECH - PRODUTO   \n");
            printf("\n ////////////////////////////////////////////////////////////////////\n");
            MenuProdutoGerencia();
            break;
        case 4:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                          COMET TECH - VENDAS   \n");
            printf("\n ////////////////////////////////////////////////////////////////////\n");
            MenuVendaGerencia(&funcionario);
            break;
        }
    } while (op != 0);
}

void MenuVendedor(Funcionario *funcionario)
{

    int op;

    do
    {
        system("cls");
        printf(" //////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        printf("                           COMET TECH  \n");
        printf("\n");
        printf(" //////////////////////////////////////////////////////////////////////\n");

        printf("\n\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n\n");
        printf(" 1 - CLIENTE \n");
        printf(" 2 - PRODUTO \n");
        printf(" 3 - VENDAS \n");
        printf(" 0 - SAIR \n");

        printf("\n Escolha uma das opções acima: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                        COMET TECH - CLIENTE   \n");
            printf("\n ////////////////////////////////////////////////////////////////////\n");
            MenuCliente();
            break;
        case 2:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                        COMET TECH - PRODUTO   \n");
            printf("\n ////////////////////////////////////////////////////////////////////\n");
            MenuProduto();
            break;
        case 3:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                          COMET TECH - VENDAS   \n");
            printf("\n ////////////////////////////////////////////////////////////////////\n");
            MenuVenda(&funcionario);
            break;
        }
    } while (op != 0);
}