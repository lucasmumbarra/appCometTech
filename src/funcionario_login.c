#include "login.h"

void BaseFuncionarioLogin()
{

    fp = fopen(ARQ_FUNCIONARIO_LOGIN, "r+b");
    if (fp == NULL)
    {
        fp = fopen(ARQ_FUNCIONARIO_LOGIN, "w+b");
        if (fp == NULL)
        {
            printf(" Erro fatal: impossível criar arquivo de dados\n");
            exit(1);
        }
    }
}

void InicializarFuncionarioLogin(FuncionarioLogin *fLogin)
{
    strcpy(fLogin->cod, "");
    strcpy(fLogin->nome, "");
    strcpy(fLogin->usuario, "");
    strcpy(fLogin->senha, "");
    fLogin->ativo = 1;
    fLogin->tipo = 1;
}

void LerFuncionarioLogin(FuncionarioLogin *fLogin)
{
    sprintf(fLogin->cod, "%i", CarregarCodigoFuncionarioLogin());
    printf(" Código: %s", fLogin->cod);

    printf("\n Nome: ");
    fflush(stdin);
    fgets(fLogin->nome, MAX, stdin);
    fLogin->nome[strlen(fLogin->nome) - 1] = '\0';

    printf("\n Usuário: ");
    fflush(stdin);
    fgets(fLogin->usuario, MAX, stdin);
    fLogin->usuario[strlen(fLogin->usuario) - 1] = '\0';

    printf("\n Senha: ");
    fflush(stdin);
    fgets(fLogin->senha, MIN, stdin);
    fLogin->senha[strlen(fLogin->senha) - 1] = '\0';

    printf("\n Selecione a função do funcionário:\n 1 - Administrador  2 - Vendedor");
    printf("\n Função: ");
    fflush(stdin);
    scanf("%i", &fLogin->tipo);
}

void ExibirFuncionarioLogin(FuncionarioLogin *fLogin)
{
    printf("\n Código: %s", fLogin->cod);
    printf("\n Nome: %s", fLogin->nome);
    printf("\n Usuário: %s", fLogin->usuario);
    printf("\n Senha: %s", fLogin->senha);
    if(fLogin->tipo == 1) {
        printf("\n Função: Administrador");
    }
    if(fLogin->tipo == 2) {
        printf("\n Função: Vendedor");
    }
}

void CadastrarFuncionarioLogin()
{
    FuncionarioLogin fLogin;
    int op;
    InicializarFuncionarioLogin(&fLogin);
    LerFuncionarioLogin(&fLogin);

    while (1)
    {
        system("cls");
        ExibirFuncionarioLogin(&fLogin);
        printf("\n\n 1 - SALVAR  2 - ALTERAR  3 - SAIR \n Selecione a opção: ");
        scanf("%i", &op);

        if (op == 1)
        {
            BaseFuncionarioLogin();
            fseek(fp, 0, SEEK_END);
            if (fwrite(&fLogin, sizeof(FuncionarioLogin), 1, fp) == 0)
            {
                printf("Erro ao gravar o registro! \n\n");
                printf("\n Pressione alguma tecla para continuar.");
                getch();
            }
            else
            {
                printf("Registro cadastrado com sucesso! \n\n");
                fclose(fp);
                Sleep(1);
                break;
            }
        }

        if (op == 2)
        {
            while (1)
            {
                system("cls");
                printf("ALTERAR \n\n");
                ExibirFuncionarioLogin(&fLogin);
                printf("\n 1 - NOME  2 - USUÁRIO  3 - SENHA  4 - FUNÇÃO  5 - VOLTAR\n");
                scanf("%i", &op);

                if (op == 1)
                {
                    printf("Nome: ");
                    fflush(stdin);
                    fgets(fLogin.nome, MAX, stdin);
                }

                if (op == 2)
                {
                    printf("Usuário: ");
                    fflush(stdin);
                    fgets(fLogin.usuario, MAX, stdin);
                }

                if (op == 3)
                {
                    printf("Senha: ");
                    fflush(stdin);
                    fgets(fLogin.senha, MAX, stdin);
                }

                if (op == 4)
                {
                    printf("\n Selecione a função do funcionário:\n 1 - Administrador  2 - Vendedor");
                    printf("\n Função: ");
                    fflush(stdin);
                    scanf("%i", &fLogin.tipo);
                }

                if (op == 5)
                {
                    fflush(stdin);
                    break;
                }
            }
        }

        if (op == 3)
        {
            printf("\nVoltando ao menu!");
            Sleep(1);
            break;
        }
        else
        {
            printf("\n Opção inválida! \n");
            Sleep(1);
        }
    }
}

void ListarFuncionarioLogin()
{
    BaseFuncionarioLogin();
    FuncionarioLogin fLogin;
    InicializarFuncionarioLogin(&fLogin);
    int linha = 0;
    rewind(fp);

    while (!feof(fp))
    {
        if (fread(&fLogin, sizeof(FuncionarioLogin), 1, fp) != 1)
        {
            break;
        }
        if (fLogin.ativo == 0)
        {
            continue;
        }
        if (fLogin.tipo == 0)
        {
            continue;
        }
        ExibirFuncionarioLogin(&fLogin);
        printf("\n ++++++++++++++++ \n");
        linha++;
    }

    if (linha == 0)
    {
        printf("\n Não contém registros. \n");
    }
    printf("\n Pressione ENTER para voltar ao MENU.");
    getche();
}

int PesquisarFuncionarioLogin()
{
    BaseFuncionarioLogin();
    FuncionarioLogin fLogin;
    InicializarFuncionarioLogin(&fLogin);

    char valor[MAX];
    strcpy(valor, "");

    int pos = 0, linha = 0, op;

    rewind(fp);

    while (!feof(fp))
    {
        printf("Digite o nome ou usuário a ser procurado: ");
        fflush(stdin);
        fgets(valor, MAX, stdin);
        valor[strlen(valor) - 1] = '\0';

        if (strlen(valor) < 1)
        {
            printf("Nome Inválido! \n\n");
        }
        else
        {
            while (fread(&fLogin, sizeof(FuncionarioLogin), 1, fp))
            {
                if (fLogin.ativo != 0 && strstr(fLogin.nome, valor) || fLogin.ativo != 0 && strstr(fLogin.usuario, valor))
                {
                    ExibirFuncionarioLogin(&fLogin);
                    pos = 1;
                    printf("\n\n Pressione ENTER para continuar.");
                    getche();
                    return linha;
                }
                linha++;
            }
            if (pos == 0)
            {
                printf("Registro não encontrado.");
            }
            printf("\n\n Pressione ENTER para continuar.");
            getche();

            break;
        }
    }
    fclose(fp);
}

void ExcluirFuncionarioLogin()
{
    BaseFuncionarioLogin();
    FuncionarioLogin fLogin;
    InicializarFuncionarioLogin(&fLogin);

    int pos = 0, op;

    pos = PesquisarFuncionarioLogin();

    fseek(fp, pos * sizeof(FuncionarioLogin), SEEK_SET);

    if (fread(&fLogin, sizeof(FuncionarioLogin), 1, fp) == 1)
    {
        while (1)
        {
            system("cls");
            ExibirFuncionarioLogin(&fLogin);
            printf("\n\n 1 - EXCLUIR  2 -SAIR \n Selecione uma opção: ");
            scanf("%i", &op);

            if (op == 1)
            {
                fLogin.ativo = 0;
                fseek(fp, pos * sizeof(FuncionarioLogin), SEEK_SET);

                if (fwrite(&fLogin, sizeof(FuncionarioLogin), 1, fp) != 1)
                {
                    printf("\n Falha ao excluir o registro!\n");
                    printf("\n\n Pressione ENTER para continuar.");
                    getche();
                    break;
                }
                else
                {
                    printf("\n Registro excluído com sucesso!\n");
                    printf("\n\n Pressione ENTER para continuar.");
                    getche();
                    break;
                }
            }
            if (op == 2)
            {
                break;
            }
        }
    }
    fclose(fp);
}

void AlterarFuncionarioLogin()
{
    BaseFuncionarioLogin();
    FuncionarioLogin fLogin;

    int pos, op;

    pos = PesquisarFuncionarioLogin();

    fseek(fp, pos * sizeof(FuncionarioLogin), SEEK_SET);

    if (fread(&fLogin, sizeof(FuncionarioLogin), 1, fp) == 1)
    {
        while (1)
        {
            system("cls");
            printf(" ++++++++++ ALTERAR FUNCIONÁRIO ++++++++++\n");
            ExibirFuncionarioLogin(&fLogin);
            printf("\n 1 - NOME  2 - USUÁRIO  3 - SENHA  4 - FUNÇÃO  5 - SALVAR  6 - SAIR \n Selecione uma opção: ");
            scanf("%i", &op);

            if (op == 1)
            {
                printf("Nome: ");
                fflush(stdin);
                fgets(fLogin.nome, MAX, stdin);
            }

            if (op == 2)
            {
                printf("Usuário: ");
                fflush(stdin);
                fgets(fLogin.usuario, MAX, stdin);
            }

            if (op == 3)
            {
                printf("Senha: ");
                fflush(stdin);
                fgets(fLogin.senha, MIN, stdin);
            }

            if (op == 4)
            {
                printf("\n Selecione a função do funcionário:\n 1 - Administrador  2 - Vendedor");
                printf("\n Função: ");
                fflush(stdin);
                scanf("%i", &fLogin.tipo);
            }

            if (op == 5)
            {
                fseek(fp, pos * sizeof(FuncionarioLogin), SEEK_SET);
                if (fwrite(&fLogin, sizeof(FuncionarioLogin), 1, fp) != 1)
                {
                    printf("\n Falha ao Alterar o registro!\n");
                    printf("\n\n Pressione ENTER para continuar.");
                    getche();
                    break;
                }
                else
                {
                    printf("\n Registro alterado com sucesso!\n");
                    printf("\n\n Pressione ENTER para continuar.");
                    getche();
                    break;
                }
            }

            if (op == 6)
            {
                printf("\n SAINDO \n");
                MenuFuncionarioGerencia();
            }
        }
    }
    fclose(fp);
}

int CarregarCodigoFuncionarioLogin()
{
    BaseFuncionarioLogin();
    FuncionarioLogin fLogin;

    int linha = 0;
    rewind(fp);

    while (!feof(fp))
    {
        if (fread(&fLogin, sizeof(FuncionarioLogin), 1, fp) != 1)
        {
            break;
        }
        linha++;
    }
    return linha + 1;
    fclose(fp);
}
