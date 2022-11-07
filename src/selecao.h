#ifndef SELECAO_H
#define SELECAO_H

#include "libs.h"
#include "cliente.h"
#include "produto.h"

#define MAX 30

FILE *sel;

typedef struct {
  char valor[MAX];
  int quantidade;
  Produto produto;
} Selecao;

void BaseSelecao(char cod[]);

void InicializarSelecao(Selecao *selecao);

void LerSelecao(Selecao *selecao);

void ExibirSelecao(Selecao *selecao);

void CadastrarSelecao();

void ListarSelecao();

#endif // SELECAO_H