// * Procedimento que realiza a verificação dos dados *
// * de login										  *
// *                                                  *
// *          	                                      *
// *                                                  *
// * **************************************************/
#include "login.h"

void login()
{

    char usuario[30], senha[30];
    int tam;

    while (1)
    {
        system("cls");
        printf(" //////////////////////////////////////////////////////////////////////\n");
        printf("                           SEJA BEM-VINDO \n");
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

        VerificarLogin(usuario, senha);
    }
}

void VerificarLogin(char *usuario, char *senha)
{
    BaseFuncionarioLogin();
    FuncionarioLogin fLogin;
    InicializarFuncionarioLogin(&fLogin);
    int linha = 0, confirm = 0;

    rewind(fp);
    while (1)
    {
        if (fread(&fLogin, sizeof(FuncionarioLogin), 1, fp) != 1)
        {
            break;
        }
        if (fLogin.ativo == 0)
        {
            continue;
        }
        if (strcmp(fLogin.usuario, usuario) == 0 && fLogin.ativo == 1)
        {
            if (strcmp(fLogin.senha, senha) == 0)
            {
                if (fLogin.tipo == 2)
                {
                    system("cls");
                    MenuVendedor(&fLogin);
                }
                else
                {
                    system("cls");
                    MenuGerencia(&fLogin);
                }
            }
            else
            {
                printf("\ SENHA INVÁLIDA! Pressione enter para continuar.");
                getch();
            }
            confirm = 1;
        }
        linha++;
    }
    if (confirm == 0)
    {
        printf("\n Usuário Inválido! Pressione enter para continuar.");
        getch();
    }
    if (linha == 0)
    {
        printf("Não há registros\n\n");
    }
    fclose(fp);
}
