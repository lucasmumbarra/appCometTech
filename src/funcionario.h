#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "libs.h"

#define MAX 250
#define MIN 30
#define MAX_ENDERECO 2500

#define ARQ_FUNCIONARIO "funcionarios.txt"

FILE *fp;

typedef struct {
  char cod[MIN];
  char nome[MAX];
  char email[MAX];
  char telefone[MIN];
  char endereco[MAX_ENDERECO];
  char dataNascimento[MIN];
  int sexo;
  char cpf[MIN];
  int ativo;
  int tipo;
} Funcionario;

void BaseFuncionario();

void InicializarFuncionario(Funcionario *funcionario);

void LerFuncionario(Funcionario *funcionario);

void ExibirFuncionario(Funcionario *funcionario);

void CadastrarFuncionario();

void ListarFuncionario();

int PesquisarFuncionario();

void ExcluirFuncionario();

void AlterarFuncionario();
#endif //FUNCIONARIO_H