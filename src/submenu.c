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
    } while (op != 0);
}
