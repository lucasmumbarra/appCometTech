#include "funcionario.h"

void EmployeeBase() {

    fp = fopen(ARQ_FUNCIONARIO, "r+b");
    if(fp == NULL) {
        fp = fopen(ARQ_FUNCIONARIO, "w+b");
        if(fp == NULL) {
            printf(" Erro fatal: impossível criar arquivo de dados\n");
            exit(1);
        }
    }
}

void InitializeEmployee(Funcionario *funcionario) {
    strcpy(funcionario->cod, "");
    strcpy(funcionario->nome, "");
    strcpy(funcionario->cpf, "");
    strcpy(funcionario->email, "");
    strcpy(funcionario->senha, "");
    funcionario->ativo = 1;
    funcionario->tipo = 1;
}

void ReadEmployee(Funcionario *funcionario) {
    sprintf(funcionario->cod, "%i", LoadCodeEmployee());
    printf("Código: %s", funcionario->cod);

    printf("\n\nNome: ");
    fflush(stdin);
    fgets(funcionario->nome, MAX, stdin);
    funcionario->nome[strlen(funcionario->nome) - 1] = '\0';

    printf("\n\CPF: ");
    fflush(stdin);
    fgets(funcionario->cpf, MIN, stdin);
    funcionario->cpf[strlen(funcionario->cpf) - 1] = '\0';

    printf("\n\E-mail: ");
    fflush(stdin);
    fgets(funcionario->email, MAX, stdin);
    funcionario->email[strlen(funcionario->email) - 1] = '\0';

    printf("\n\Senha: ");
    fflush(stdin);
    fgets(funcionario->senha, MIN, stdin);
    funcionario->senha[strlen(funcionario->senha) - 1] = '\0';
}

void DisplayEmployee(Funcionario *funcionario) {
    printf("\n Código: %s", funcionario->cod);
    printf("\n Nome: %s", funcionario->nome);
    printf("\n CPF: %s", funcionario->cpf);
    printf("\n E-mail: %s", funcionario->email);
    printf("\n Senha: %s", funcionario->senha);
}

void RegisterEmployee() {
    Funcionario funcionario;
    int op;
    InitializeEmployee(&funcionario);
    ReadEmployee(&funcionario);

    while(1) {
        system("cls");
        DisplayEmployee(&funcionario);
        printf("\n\n 1 - SALVAR  2 - ALTERAR  3 - SAIR");
        scanf("%i", &op);

        if(op == 1) {
            EmployeeBase();
            fseek(fp, 0, SEEK_END);
            if(fwrite(&funcionario, sizeof(Funcionario), 1, fp) == 0) {
                printf("Erro ao gravar o registro! \n\n");
                printf("\n Pressione alguma tecla para continuar.");
                getch();
            } else {
                printf("Registro cadastrado com sucesso! \n\n");
                fclose(fp);
                Sleep(1);
                break;
            }
        }

        if(op == 2) {
            while(1) {
                system("cls");
                printf("ALTERAR \n\n");
                DisplayEmployee(&funcionario);
                printf("\n 1 - NOME  2 - CPF  3 - EMAIL  4 - SENHA  5 - VOLTAR\n");
                scanf("%i", &op);

                if(op == 1) {
                    printf("Nome: ");
                    fflush(stdin);
                    fgets(funcionario.nome, MAX, stdin);
                }

                if(op == 2) {
                    printf("CPF: ");
                    fflush(stdin);
                    fgets(funcionario.cpf, MIN, stdin);
                }

                if(op == 3) {
                    printf("Email: ");
                    fflush(stdin);
                    fgets(funcionario.email, MAX, stdin);
                }

                if(op == 4) {
                    printf("Senha: ");
                    fflush(stdin);
                    fgets(funcionario.senha, MAX, stdin);
                }

                if(op == 5) {
                    fflush(stdin);
                    break;
                }
            }
        }

        if(op == 3) {
            printf("\nVoltando ao menu!");
            Sleep(1);
            break;
        } else {
            printf("\n Opção inválida! \n");
            Sleep(1);
        }
    }
}

int LoadCodeEmployee() {
    EmployeeBase();
    Funcionario funcionario;

    int linha = 0;
    rewind(fp);

    while(!feof(fp)) {
        if(fread(&funcionario, sizeof(Funcionario), 1, fp)!=1) {
            break;
        }
        linha++;
    }
    return linha + 1;
    fclose(fp);
}
