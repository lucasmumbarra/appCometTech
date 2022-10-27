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
        printf(" 4 - EXCLUIR \n");
        printf(" 0 - VOLTAR");

        printf("\n Escolha uma das op��es acima: ");
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
        printf(" 2 - FUNCION�RIO\n");
        printf(" 3 - PRODUTO\n");
        printf(" 0 - VOLTAR");

        printf("\n Escolha uma das op��es acima: ");
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
            printf("\n                   COMET TECH - CADASTRAR FUNCION�RIO\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            CadastrarFuncionario();
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
        printf(" 2 - FUNCION�RIO\n");
        printf(" 3 - PRODUTO\n");
        printf(" 0 - VOLTAR");

        printf("\n Escolha uma das op��es acima: ");
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
            printf("\n                   COMET TECH - LISTAR FUNCION�RIO\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            ListarFuncionario();
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
        printf(" 2 - FUNCION�RIO\n");
        printf(" 3 - PRODUTO\n");
        printf(" 0 - VOLTAR");

        printf("\n Escolha uma das op��es acima: ");
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
            printf("\n                   COMET TECH - PESQUISAR FUNCION�RIO\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            PesquisarFuncionario();
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
        printf(" 2 - FUNCION�RIO\n");
        printf(" 3 - PRODUTO\n");
        printf(" 0 - VOLTAR");

        printf("\n Escolha uma das op��es acima: ");
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
            printf("\n                   COMET TECH - EXCLUIR FUNCION�RIO\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            ExcluirFuncionario();
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




