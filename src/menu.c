#include "menu.h"

void MenuGerencia()
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
        printf(" 0 - ENCERRAR \n");

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
            MenuVendaGerencia();
            break;
        case 0:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                               ENCERRAR   \n");
            printf("\n ////////////////////////////////////////////////////////////////////\n");
            EncerrarPrograma();
            break;
        }
    } while (op != 0);
}

void EncerrarPrograma()
{
    int op;

    printf("\nVocê Deseja realmente sair?\n");
    printf("\n 1 - SIM, SAIR!  2 - NÃO\n Selecione uma opção: ");
    scanf("%i", &op);

    if (op == 1)
    {
        system("taskkill /IM app.exe");
    }
    if (op == 2)
    {
        MenuGerencia();
    }
}
