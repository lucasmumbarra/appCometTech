#include "menu.h"

void menuManagement() {

    int op;

    do {
        system("cls");
        printf(" //////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        printf("                           COMET TECH - GER�NCIA  \n");
        printf("\n");
        printf(" //////////////////////////////////////////////////////////////////////\n");

        printf("\n\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n\n");
        printf(" 1 - CADASTRO \n");
        printf(" 2 - DEPARTAMENTO PESSOAL \n");
        printf(" 3 - RELAT�RIOS \n");
        printf(" 4 - VENDAS \n");

        printf("\n Escolha uma das op��es acima: ");
        scanf("%d", &op);

        switch(op) {
        case 1:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                          COMET TECH - CADASTRO   \n");
            printf("\n ////////////////////////////////////////////////////////////////////\n");
            menuRegistration();
            break;
        case 2:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                    COMET TECH - DEPARTAMENTO PESSOAL   \n");
            printf("\n ////////////////////////////////////////////////////////////////////\n");
            system("pause");
            break;
        case 3:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                         COMET TECH - RELAT�RIOS   \n");
            printf("\n ////////////////////////////////////////////////////////////////////\n");
            system("pause");
            break;
        case 4:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                          COMET TECH - VENDAS   \n");
            printf("\n ////////////////////////////////////////////////////////////////////\n");
            system("pause");
            break;
        }
    } while(op != 0);
}
