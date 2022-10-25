#include "submenu.h"

void menuRegistration() {
    int op;

    do {
        system("cls");
        printf(" //////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        printf("                           COMET TECH - CADASTRO  \n");
        printf("\n");
        printf(" //////////////////////////////////////////////////////////////////////\n");

        printf("\n\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n\n");
        printf(" 1 - CADASTRAR CLIENTE\n");
        printf(" 2 - CADASTRAR FUNCIONÁRIOS\n");
        printf(" 3 - CADASTRAR PRODUTOS\n");
        printf(" 0 - VOLTAR");

        printf("\n Escolha uma das opções acima: ");
        scanf("%d", &op);

        switch(op) {

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
            printf("\n                COMET TECH - CADASTRAR FUNCIONÁRIOS\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            RegisterEmployee();
            break;
        case 3:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                  COMET TECH - CADASTRAR PRODUTOS\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            system("pause");
            break;
        case 0:
            system("cls");
            menuManagement();
            break;
        }
    } while (op != 0);
}




