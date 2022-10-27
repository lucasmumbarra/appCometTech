#include "login.h"

void login() {

    char usuario[30], senha[30];

    while(1) {
        system("cls");
        printf(" //////////////////////////////////////////////////////////////////////\n");
        printf("                           SEJA BEM VINDO \n");
        printf("\n");
        printf(" //////////////////////////////////////////////////////////////////////\n");

        printf(" USUÁRIO: ");
        fflush(stdin);
        fgets(usuario, sizeof(usuario), stdin);
        usuario[strlen(usuario) - 1] = '\0';

        printf("\n SENHA: ");
        fflush(stdin);
        fgets(senha, sizeof(senha), stdin);
        senha[strlen(senha) - 1] = '\0';

        VerificarLogin(usuario,senha);
    }
}

void VerificarLogin(char *usuario, char *senha) {
    BaseFuncionario();
    Funcionario funcionario;
    InicializarFuncionario(&funcionario);
    int linha = 0, confirm = 0;

    rewind(fp);
    while(1) {
        if(fread(&funcionario, sizeof(Funcionario), 1, fp) != 1) {
            break;
        }
        if(funcionario.ativo == 0) {
            continue;
        }
        if(strcmp(funcionario.usuario,usuario) == 0 && funcionario.ativo == 1) {
            if(strcmp(funcionario.senha,senha) == 0) {
                if(funcionario.tipo == 2) {
                    system("cls");
                    printf("Menu em desenvolvimento");
                    system("pause");
                } else {
                    system("cls");
                    MenuGerencia(&funcionario);
                }
            } else {
                printf("\ SENHA INVÁLIDA! Pressione enter para continuar.");
                getch();
            }
            confirm = 1;
        }
        linha++;
    }
    if(confirm == 0) {
        printf("\n Usuário Inválido! Pressione enter para continuar.");
        getch();
    }
    if(linha == 0) {
        printf("Não há registros\n\n");
    }
    fclose(fp);
}
