#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "libs.h"

#define MAX 250
#define MIN 30

#define ARQ_FUNCIONARIO "database/funcionarios.txt"

FILE *fp;

typedef struct {
    char cod[MIN];
    char nome[MAX];
    char cpf[MIN];
    char email[MAX];
    char senha[MIN];
    int ativo;
    int tipo
} Funcionario;

void EmployeeBase();

void InitializeEmployee(Funcionario *funcionario);

void ReadEmployee(Funcionario *funcionario);

void DisplayEmployee(Funcionario *funcionario);

void RegisterEmployee();
#endif // FUNCIONARIO_H
