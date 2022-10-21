#include "libs.h"

int main(int argc, char *argv[]) {

    setlocale(LC_ALL, "Portuguese");

    SetConsoleTitle("Sistema de Gerenciamento - Comet Tech");
    login();
    return 0;
}

void login() {

    char email[30], password[30];

    while(1) {
        system("cls");
        printf(" //////////////////////////////////////////////////////////////////////\n");
        printf("                           SEJA BEM VINDO \n");
        printf("\n");
        printf(" //////////////////////////////////////////////////////////////////////\n");

        printf(" EMAIL: ");
        fflush(stdin);
        fgets(email, sizeof(email), stdin);
        email[strlen(email) -1] = '\0';

        printf("\n SENHA: ");
        fflush(stdin);
        fgets(password, sizeof(password), stdin);

        menuManagement();
    }
}

void menuManagement() {

    int op;

    do {
        system("cls");
        printf(" //////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        printf("                           COMET TECH - GERÊNCIA  \n");
        printf("\n");
        printf(" //////////////////////////////////////////////////////////////////////\n");

        printf("\n\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n\n");
        printf(" 1 - CADASTRO \n");
        printf(" 2 - DEPARTAMENTO PESSOAL \n");
        printf(" 3 - RELATÓRIOS \n");
        printf(" 4 - VENDAS \n");

        printf("\n Escolha uma das opções acima: ");
        scanf("%d", &op);

        switch(op) {
        case 1:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                          COMET TECH - CADASTRO   \n");
            printf("\n ////////////////////////////////////////////////////////////////////\n");
            system("pause");
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
            printf("\n                         COMET TECH - RELATÓRIOS   \n");
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





