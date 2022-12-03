// Inclus�o do cabe�ario de funcionaio login
#include "funcionario_login.h"
// Implementa��o da fun��o base funcionario login
void BaseFuncionarioLogin()
{

    fp = fopen(ARQ_FUNCIONARIO_LOGIN, "r+b");
    if (fp == NULL)
    {
        fp = fopen(ARQ_FUNCIONARIO_LOGIN, "w+b");
        if (fp == NULL)
        {
            printf(" Erro fatal: imposs�vel criar arquivo de dados\n");
            exit(1);
        }
    }
}
//Implementa��o da fun��o inicializar funcionario login
void InicializarFuncionarioLogin(FuncionarioLogin *fLogin)
{
    strcpy(fLogin->cod, "");
    strcpy(fLogin->nome, "");
    strcpy(fLogin->usuario, "");
    strcpy(fLogin->senha, "");
    fLogin->ativo = 1;
    fLogin->tipo = 1;
}
// Implementa��o da fun��o que realiza a leitura dos dados do teclado
void LerFuncionarioLogin(FuncionarioLogin *fLogin)
{
    sprintf(fLogin->cod, "%i", CarregarCodigoFuncionarioLogin());
    printf(" C�digo: %s", fLogin->cod);

    printf("\n Nome: ");
    fflush(stdin);
    fgets(fLogin->nome, MAX, stdin);
    fLogin->nome[strlen(fLogin->nome) - 1] = '\0';

    printf("\n Usu�rio: ");
    fflush(stdin);
    fgets(fLogin->usuario, MAX, stdin);
    fLogin->usuario[strlen(fLogin->usuario) - 1] = '\0';

    printf("\n Senha: ");
    fflush(stdin);
    fgets(fLogin->senha, MIN, stdin);
    fLogin->senha[strlen(fLogin->senha) - 1] = '\0';

    printf("\n Selecione a fun��o do funcion�rio:\n 1 - Administrador  2 - Vendedor");
    printf("\n Fun��o: ");
    fflush(stdin);
    scanf("%i", &fLogin->tipo);
}
// Implementa��o da fun��o de exibi��o
void ExibirFuncionarioLogin(FuncionarioLogin *fLogin)
{
    printf("\n C�digo: %s", fLogin->cod);
    printf("\n Nome: %s", fLogin->nome);
    printf("\n Usu�rio: %s", fLogin->usuario);
    printf("\n Senha: %s", fLogin->senha);  
    if(fLogin->tipo == 1) {
        printf("\n Fun��o: Administrador");
    }
    if(fLogin->tipo == 2) {
        printf("\n Fun��o: Vendedor");
    }
}
// Implementa��o da fun��o cadastro
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
        printf("\n\n 1 - SALVAR  2 - ALTERAR  3 - SAIR \n Selecione a op��o: ");
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
                printf("\n 1 - NOME  2 - USU�RIO  3 - SENHA  4 - FUN��O  5 - VOLTAR\n");
                scanf("%i", &op);

                if (op == 1)
                {
                    printf("Nome: ");
                    fflush(stdin);
                    fgets(fLogin.nome, MAX, stdin);
                }

                if (op == 2)
                {
                    printf("Usu�rio: ");
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
                    printf("\n Selecione a fun��o do funcion�rio:\n 1 - Administrador  2 - Vendedor");
                    printf("\n Fun��o: ");
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
            printf("\n Op��o inv�lida! \n");
            Sleep(1);
        }
    }
}
// Implementa��o da fun��o listar
void ListarFuncionarioLogin()
{
    // Abrir o arquivo para leitura
    BaseFuncionarioLogin();
    FuncionarioLogin fLogin;
    // Inicializar estrutura
    InicializarFuncionarioLogin(&fLogin);
    int linha = 0;
    rewind(fp); // coloca o curso no inicio do arquivo
    // Percorrer o arquivo at� o final dele
    while (!feof(fp))
    {   //verifica se cont�m dados no in�cio do arquivo
        if (fread(&fLogin, sizeof(FuncionarioLogin), 1, fp) != 1)
        {
            break;
        }
        // Se funcion�rio Login for igual a ativo 0 pula para o final do la�o e faz uma nova leitura no pr�ximo registro
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
    // Verificador pra ver se tem registros no arquivo
    if (linha == 0)
    {
        printf("\n N�o cont�m registros. \n");
    }
    printf("\n Pressione ENTER para voltar ao MENU.");
    getche();
}
// Implementa��o da fun��o pesquisa
int PesquisarFuncionarioLogin()
{   // Abrir o arquivo pessoa
    BaseFuncionarioLogin();
    // Criar estrutura
    FuncionarioLogin fLogin;
    // Inicializar estrutura
    InicializarFuncionarioLogin(&fLogin);
    // Vari�veis de captura para a compara��o dos par�metros
    char valor[MAX];
    strcpy(valor, "");

    int pos = 0, linha = 0, op;
    // Colocar o cursor no inicio do arquivo
    rewind(fp);

    while (!feof(fp))
    {
        printf("Digite o nome ou usu�rio a ser procurado: ");
        fflush(stdin);
        fgets(valor, MAX, stdin);
        valor[strlen(valor) - 1] = '\0';
        // Verificar a quantidade de caracteres digitados
        if (strlen(valor) < 1)
        {
            printf("Nome Inv�lido! \n\n");
        }
        else
        {   // Realiza a leitura dos registros
            while (fread(&fLogin, sizeof(FuncionarioLogin), 1, fp))
            {   // Realiza os comparativos
                if (fLogin.ativo != 0 && strstr(fLogin.nome, valor) || fLogin.ativo != 0 && strstr(fLogin.usuario, valor))
                {
                    ExibirFuncionarioLogin(&fLogin);
                    pos = 1; // Informa se achou o registro
                    printf("\n\n Pressione ENTER para continuar.");
                    getche();
                    // Manda a posi��o do registro no arquivo para exclus�o e altera�a�
                    return linha;
                }
                linha++;
            }
            if (pos == 0)
            {
                printf("Registro n�o encontrado.");
            }
            printf("\n\n Pressione ENTER para continuar.");
            getche();

            break;
        }
    }
    fclose(fp);
}
// Implementa��o da fun��o de exclus�o
void ExcluirFuncionarioLogin()
{   // Abrir o arquivo
    BaseFuncionarioLogin();
    FuncionarioLogin fLogin;
    InicializarFuncionarioLogin(&fLogin);

    int pos = 0, op;

    pos = PesquisarFuncionarioLogin();
    // Possiciona o curso at� o registro partindo do inicio
    fseek(fp, pos * sizeof(FuncionarioLogin), SEEK_SET);
    // Realizo a leitura e vejo se naquela posi��o tem algum registro
    if (fread(&fLogin, sizeof(FuncionarioLogin), 1, fp) == 1)
    {
        while (1)
        {
            system("cls");
            ExibirFuncionarioLogin(&fLogin);
            printf("\n\n 1 - EXCLUIR  2 -SAIR \n Selecione uma op��o: ");
            scanf("%i", &op);

            if (op == 1)
            {   // Troca o ativo 1 por 0
                fLogin.ativo = 0; // Possiciona o curso novamente no registro para sobreescrevelo
                fseek(fp, pos * sizeof(FuncionarioLogin), SEEK_SET);
                // Realiza a grava��o
                if (fwrite(&fLogin, sizeof(FuncionarioLogin), 1, fp) != 1)
                {
                    printf("\n Falha ao excluir o registro!\n");
                    printf("\n\n Pressione ENTER para continuar.");
                    getche();
                    break;
                }
                else
                {
                    printf("\n Registro exclu�do com sucesso!\n");
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
// Implementa��o da fun��o alterar
void AlterarFuncionarioLogin()
{   // Abre o arquivo
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
            printf(" ++++++++++ ALTERAR FUNCION�RIO ++++++++++\n");
            ExibirFuncionarioLogin(&fLogin);
            printf("\n 1 - NOME  2 - USU�RIO  3 - SENHA  4 - FUN��O  5 - SALVAR  6 - SAIR \n Selecione uma op��o: ");
            scanf("%i", &op);

            if (op == 1)
            {
                printf("Nome: ");
                fflush(stdin);
                fgets(fLogin.nome, MAX, stdin);
            }

            if (op == 2)
            {
                printf("Usu�rio: ");
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
                printf("\n Selecione a fun��o do funcion�rio:\n 1 - Administrador  2 - Vendedor");
                printf("\n Fun��o: ");
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
{   // Abrir o arquivo para leitura
    BaseFuncionarioLogin();
    FuncionarioLogin fLogin;
    // Inicializar nossa estrutura
    int linha = 0;
    rewind(fp); // Coloca o curso no inicio do arquivo
    // percorre o arquivo at� o final dele
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
