#ifndef FUNCIONARIO_LOGIN_H
#define FUNCIONARIO_LOGIN_H

#include "libs.h"
#include "submenu_gerencia.h"

#define MAX 250
#define MIN 30

#define ARQ_FUNCIONARIO_LOGIN "funcionarios_login.txt"

FILE *fp;

typedef struct {
    char cod[MIN];
    char nome[MAX];
    char usuario[MAX];
    char senha[MIN];
    int ativo;
    int tipo;
} FuncionarioLogin;

void BaseFuncionarioLogin();

void InicializarFuncionarioLogin(FuncionarioLogin *fLogin);

void LerFuncionarioLogin(FuncionarioLogin *fLogin);

void ExibirFuncionarioLogin(FuncionarioLogin *fLogin);

void CadastrarFuncionarioLogin();

void ListarFuncionarioLogin();

int PesquisarFuncionarioLogin();

void ExcluirFuncionarioLogin();

void AlterarFuncionarioLogin();
#endif // FUNCIONARIO_LOGIN_H
