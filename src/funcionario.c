#include "funcionario.h"

void BaseFuncionario() {

    fp = fopen(ARQ_FUNCIONARIO, "r+b");
    if(fp == NULL) {
        fp = fopen(ARQ_FUNCIONARIO, "w+b");
        if(fp == NULL) {
            printf(" Erro fatal: impossível criar arquivo de dados\n");
            exit(1);
        }
    }
}

void InicializarFuncionario(Funcionario *funcionario) {
    strcpy(funcionario->cod, "");
    strcpy(funcionario->nome, "");
    strcpy(funcionario->cpf, "");
    strcpy(funcionario->usuario, "");
    strcpy(funcionario->senha, "");
    funcionario->ativo = 1;
    funcionario->tipo = 1;
}

void LerFuncionario(Funcionario *funcionario) {
    sprintf(funcionario->cod, "%i", CarregarCodigoFuncionario());
    printf(" Código: %s", funcionario->cod);

    printf("\n Nome: ");
    fflush(stdin);
    fgets(funcionario->nome, MAX, stdin);
    funcionario->nome[strlen(funcionario->nome) - 1] = '\0';

    printf("\n CPF: ");
    fflush(stdin);
    fgets(funcionario->cpf, MIN, stdin);
    funcionario->cpf[strlen(funcionario->cpf) - 1] = '\0';

    printf("\n Usuário: ");
    fflush(stdin);
    fgets(funcionario->usuario, MAX, stdin);
    funcionario->usuario[strlen(funcionario->usuario) - 1] = '\0';

    printf("\n Senha: ");
    fflush(stdin);
    fgets(funcionario->senha, MIN, stdin);
    funcionario->senha[strlen(funcionario->senha) - 1] = '\0';
}

void ExibirFuncionario(Funcionario *funcionario) {
    printf("\n Código: %s", funcionario->cod);
    printf("\n Nome: %s", funcionario->nome);
    printf("\n CPF: %s", funcionario->cpf);
    printf("\n Usuário: %s", funcionario->usuario);
    printf("\n Senha: %s", funcionario->senha);
}

void CadastrarFuncionario() {
    Funcionario funcionario;
    int op;
    InicializarFuncionario(&funcionario);
    LerFuncionario(&funcionario);

    while(1) {
        system("cls");
        ExibirFuncionario(&funcionario);
        printf("\n\n 1 - SALVAR  2 - ALTERAR  3 - SAIR \n Selecione a opção: ");
        scanf("%i", &op);

        if(op == 1) {
            BaseFuncionario();
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
                ExibirFuncionario(&funcionario);
                printf("\n 1 - NOME  2 - CPF  3 - USUÁRIO  4 - SENHA  5 - VOLTAR\n");
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
                    printf("Usuário: ");
                    fflush(stdin);
                    fgets(funcionario.usuario, MAX, stdin);
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

void ListarFuncionario() {
    BaseFuncionario();
    Funcionario funcionario;
    InicializarFuncionario(&funcionario);
    int linha = 0;
    rewind(fp);

    while(!feof(fp)) {
        if(fread(&funcionario, sizeof(Funcionario), 1, fp) != 1) {
            break;
        }
        if(funcionario.ativo == 0) {
            continue;
        }
        if(funcionario.tipo == 0) {
            continue;
        }
        ExibirFuncionario(&funcionario);
        printf("\n ++++++++++++++++ \n");
        linha++;
    }

    if(linha == 0) {
        printf("\n Não contém registros. \n");
    }
    printf("\n Pressione ENTER para voltar ao MENU.");
    getche();
}

int PesquisarFuncionario() {
    BaseFuncionario();
    Funcionario funcionario;
    InicializarFuncionario(&funcionario);

    char valor[MAX];
    strcpy(valor,"");

    int pos = 0, linha = 0, op;

    rewind(fp);

    while(!feof(fp)) {
        printf("Digite o nome ou cpf a ser procurado: ");
        fflush(stdin);
        fgets(valor, MAX, stdin);
        valor[strlen(valor) - 1] = '\0';

        if(strlen(valor) < 1) {
            printf("Nome Inválido! \n\n");
        } else {
            while(fread(&funcionario, sizeof(Funcionario), 1, fp)) {
                if(funcionario.ativo != 0 && strstr(funcionario.nome,valor) || funcionario.ativo != 0 && strstr(funcionario.cpf,valor)) {
                    ExibirFuncionario(&funcionario);
                    pos = 1;
                    printf("\n\n Pressione ENTER para continuar.");
                    getche();
                    return linha;
                }
                linha++;
            }
            if(pos == 0) {
                printf("Registro não encontrado.");
            }
            printf("\n\n Pressione ENTER para continuar.");
            getche();

            break;
        }
    }
    fclose(fp);
}

void ExcluirFuncionario() {
    BaseFuncionario();
    Funcionario funcionario;
    InicializarFuncionario(&funcionario);

    int pos = 0, op;

    pos = PesquisarFuncionario();

    fseek(fp, pos*sizeof(Funcionario), SEEK_SET);

    if(fread(&funcionario, sizeof(Funcionario), 1, fp)== 1){
        while(1) {
            system("cls");
            ExibirFuncionario(&funcionario);
            printf("\n\n 1 - EXCLUIR  2 -SAIR \n Selecione uma opção: ");
            scanf("%i", &op);

            if(op == 1) {
                funcionario.ativo = 0;
                fseek(fp, pos*sizeof(Funcionario), SEEK_SET);

                if(fwrite(&funcionario, sizeof(Funcionario), 1, fp) != 1) {
                    printf("\n Falha ao excluir o registro!\n");
                    printf("\n\n Pressione ENTER para continuar.");
                    getche();
                    break;
                } else {
                    printf("\n Registro excluído com sucesso!\n");
                    printf("\n\n Pressione ENTER para continuar.");
                    getche();
                    break;
                }
            }
            if(op == 2) {
                break;
            }
        }
    }
    fclose(fp);
}

int CarregarCodigoFuncionario() {
    BaseFuncionario();
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
