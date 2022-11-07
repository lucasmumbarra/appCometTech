#ifndef VENDAS_H
#define VENDAS_H

#include "libs.h"
#include "cliente.h"
#include "selecao.h"
#include "cartao.h"

#define MAX 30

#define ARQ_VENDAS "vendas.txt"

FILE *ven;

typedef struct
{
  char cod[MAX];
  Cliente cliente[MAX];
  Selecao selecao[MAX];
  int pagamento;
  float total;
  int tamanho;
} Venda;

void BaseVenda();

void InicializarVenda(Venda *venda);

#endif // VENDAS_H