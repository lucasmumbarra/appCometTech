#include "login.h"

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
