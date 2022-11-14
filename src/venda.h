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

void ExibirVenda(char nome[MAX], char cod[MAX]);

void CarregarVenda(char *cod, char *nome);

void CarregarSelecao(char *cod, Venda *venda);

void ExibirProdVenda(Venda *venda);

void ExibirListaVenda(Venda *venda);

void ListarVenda();

void AlterarVenda(char *cod);

#endif // VENDAS_H