#include "submenu.h"

void MenuCadastro() {
    int op;

    do {
        system("cls");
        printf(" //////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        printf("                           COMET TECH - CADASTRO  \n");
        printf("\n");
        printf(" //////////////////////////////////////////////////////////////////////\n");

        printf("\n\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n\n");
        printf(" 1 - CADASTRAR\n");
        printf(" 2 - PESQUISAR\n");
        printf(" 3 - LISTAR \n");
        printf(" 4 - ALTERAR \n");
        printf(" 5 - EXCLUIR \n");
        printf(" 0 - VOLTAR");

        printf("\n Escolha uma das opções acima: ");
        scanf("%d", &op);

        switch(op) {

        case 1:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                      COMET TECH - CADASTRAR\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            Cadastro();
            break;
        case 2:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                      COMET TECH - PESQUISAR\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            Pesquisar();
            break;
        case 3:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                         COMET TECH - LISTAR\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            Listar();
            break;
        case 4:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                         COMET TECH - ALTERAR\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            Alterar();
            break;
        case 5:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                         COMET TECH - EXCLUIR\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            Excluir();
            break;
        case 0:
            system("cls");
            MenuGerencia();
            break;
        }
    } while (op != 0);
}

void Cadastro() {
    int op;

    do {
        system("cls");
        printf(" //////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        printf("                           COMET TECH - CADASTRAR  \n");
        printf("\n");
        printf(" //////////////////////////////////////////////////////////////////////\n");

        printf("\n\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n\n");
        printf(" 1 - CLIENTE\n");
        printf(" 2 - FUNCIONÁRIO\n");
        printf(" 3 - PRODUTO\n");
        printf(" 0 - VOLTAR");

        printf("\n Escolha uma das opções acima: ");
        scanf("%d", &op);

        switch(op) {

        case 1:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                    COMET TECH - CADASTRAR CLIENTE\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            system("pause");
            break;
        case 2:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                   COMET TECH - CADASTRAR FUNCIONÁRIO\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            CadastrarFuncionarioLogin();
            break;
        case 3:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                     COMET TECH - CADASTRAR PRODUTO\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            system("pause");
            break;
        case 0:
            system("cls");
            MenuCadastro();
            break;
        }
    } while (op != 0);
}

void Listar() {
    int op;

    do {
        system("cls");
        printf(" //////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        printf("                           COMET TECH - LISTAR  \n");
        printf("\n");
        printf(" //////////////////////////////////////////////////////////////////////\n");

        printf("\n\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n\n");
        printf(" 1 - CLIENTE\n");
        printf(" 2 - FUNCIONÁRIO\n");
        printf(" 3 - PRODUTO\n");
        printf(" 0 - VOLTAR");

        printf("\n Escolha uma das opções acima: ");
        scanf("%d", &op);

        switch(op) {

        case 1:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                    COMET TECH - LISTAR CLIENTE\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            system("pause");
            break;
        case 2:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                   COMET TECH - LISTAR FUNCIONÁRIO\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            ListarFuncionarioLogin();
            break;
        case 3:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                     COMET TECH - LISTAR PRODUTO\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            system("pause");
            break;
        case 0:
            system("cls");
            MenuCadastro();
            break;
        }
    } while (op != 0);
}

void Pesquisar() {
    int op;

    do {
        system("cls");
        printf(" //////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        printf("                           COMET TECH - PESQUISAR  \n");
        printf("\n");
        printf(" //////////////////////////////////////////////////////////////////////\n");

        printf("\n\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n\n");
        printf(" 1 - CLIENTE\n");
        printf(" 2 - FUNCIONÁRIO\n");
        printf(" 3 - PRODUTO\n");
        printf(" 0 - VOLTAR");

        printf("\n Escolha uma das opções acima: ");
        scanf("%d", &op);

        switch(op) {

        case 1:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                    COMET TECH - PESQUISAR CLIENTE\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            system("pause");
            break;
        case 2:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                   COMET TECH - PESQUISAR FUNCIONÁRIO\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            PesquisarFuncionarioLogin();
            break;
        case 3:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                     COMET TECH - PESQUISAR PRODUTO\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            system("pause");
            break;
        case 0:
            system("cls");
            MenuCadastro();
            break;
        }
    } while (op != 0);
}

void Excluir() {
    int op;

    do {
        system("cls");
        printf(" //////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        printf("                           COMET TECH - EXCLUIR  \n");
        printf("\n");
        printf(" //////////////////////////////////////////////////////////////////////\n");

        printf("\n\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n\n");
        printf(" 1 - CLIENTE\n");
        printf(" 2 - FUNCIONÁRIO\n");
        printf(" 3 - PRODUTO\n");
        printf(" 0 - VOLTAR");

        printf("\n Escolha uma das opções acima: ");
        scanf("%d", &op);

        switch(op) {

        case 1:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                    COMET TECH - EXCLUIR CLIENTE\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            system("pause");
            break;
        case 2:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                   COMET TECH - EXCLUIR FUNCIONÁRIO\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            ExcluirFuncionarioLogin();
            break;
        case 3:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                     COMET TECH - EXCLUIR PRODUTO\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            system("pause");
            break;
        case 0:
            system("cls");
            MenuCadastro();
            break;
        }
    } while (op != 0);
}

void Alterar() {
    int op;

    do {
        system("cls");
        printf(" //////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        printf("                           COMET TECH - ALTERAR  \n");
        printf("\n");
        printf(" //////////////////////////////////////////////////////////////////////\n");

        printf("\n\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n\n");
        printf(" 1 - CLIENTE\n");
        printf(" 2 - FUNCIONÁRIO\n");
        printf(" 3 - PRODUTO\n");
        printf(" 0 - VOLTAR");

        printf("\n Escolha uma das opções acima: ");
        scanf("%d", &op);

        switch(op) {

        case 1:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                    COMET TECH - ALTERAR CLIENTE\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            system("pause");
            break;
        case 2:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                   COMET TECH - ALTERAR FUNCIONÁRIO\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            AlterarFuncionario();
            break;
        case 3:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                     COMET TECH - ALTERAR PRODUTO\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            system("pause");
            break;
        case 0:
            system("cls");
            MenuCadastro();
            break;
        }
    } while (op != 0);
}




