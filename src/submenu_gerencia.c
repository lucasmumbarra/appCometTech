#include "submenu_gerencia.h"

void MenuFuncionarioGerencia() {
    int op;

    do {
        system("cls");
        printf(" //////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        printf("                         COMET TECH - FUNCIONÁRIOS  \n");
        printf("\n");
        printf(" //////////////////////////////////////////////////////////////////////\n");

        printf("\n\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n\n");
        printf(" 1  - CADASTRAR LOGIN\n");
        printf(" 2  - CADASTRAR FUNCIONARIO\n");
        printf(" 3  - PESQUISAR LOGIN\n");
        printf(" 4  - PESQUISAR FUNCIONARIO\n");
        printf(" 5  - LISTAR LOGIN \n");
        printf(" 6  - LISTAR FUNCIONARIO \n");
        printf(" 7  - ALTERAR LOGIN \n");
        printf(" 8  - ALTERAR FUNCIONARIO \n");
        printf(" 9  - EXCLUIR LOGIN \n");
        printf(" 10 - EXCLUIR FUNCIONARIO \n");
        printf(" 0  - VOLTAR");

        printf("\n Escolha uma das opções acima: ");
        scanf("%d", &op);

        switch(op) {

        case 1:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                    COMET TECH - CADASTRAR LOGIN\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            system("pause");
            break;
        case 2:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                  COMET TECH - CADASTRAR FUNCIONARIO\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            system("pause");
            break;
        case 3:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                     COMET TECH - PESQUISAR LOGIN\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            system("pause");
            break;
        case 4:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                  COMET TECH - PESQUISAR FUNCIONARIO\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            system("pause");
            break;
        case 5:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                     COMET TECH - LISTAR LOGIN\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            system("pause");
            break;
        case 6:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                  COMET TECH - LISTAR FUNCIONARIO\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            system("pause");
            break;
        case 7:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                    COMET TECH - ALTERAR LOGIN\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            system("pause");
            break;
        case 8:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                 COMET TECH - ALTERAR FUNCIONARIO\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            system("pause");
            break;
        case 9:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                   COMET TECH - EXCLUIR LOGIN\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            system("pause");
            break;
        case 10:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                 COMET TECH - EXCLUIR FUNCIONARIO\n");
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