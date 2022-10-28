#include "menu.h"

void MenuGerencia()
{

    int op, validacaoGerencia = 1;

    do
    {
        system("cls");
        printf(" //////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        printf("                           COMET TECH - GER�NCIA  \n");
        printf("\n");
        printf(" //////////////////////////////////////////////////////////////////////\n");

        printf("\n\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n\n");
        printf(" 1 - CLIENTE \n");
        printf(" 2 - FUNCION�RIO \n");
        printf(" 3 - PRODUTO \n");
        printf(" 4 - VENDAS \n");
        printf(" 0 - ENCERRAR \n");

        printf("\n Escolha uma das op��es acima: ");
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
            printf("\n                        COMET TECH - FUNCION�RIO   \n");
            printf("\n ////////////////////////////////////////////////////////////////////\n");
            MenuFuncionarioGerencia();
            break;
        case 3:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                        COMET TECH - PRODUTO   \n");
            printf("\n ////////////////////////////////////////////////////////////////////\n");
            MenuProduto();
            break;
        case 4:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                          COMET TECH - VENDAS   \n");
            printf("\n ////////////////////////////////////////////////////////////////////\n");
            system("pause");
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

    printf("\nVoc� Deseja realmente encerrar o programa?\n");
    printf("\n 1 - SIM, ENCERRAR!  2 - N�O\n Selecione uma op��o: ");
    scanf("%i", &op);

    if (op == 1)
    {
        // exit(EXIT_SUCCESS);
        system("taskkill /IM cb_console_runner.exe");
    }
    if (op == 2)
    {
        MenuGerencia();
    }
}
