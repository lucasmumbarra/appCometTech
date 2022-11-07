#ifndef PRODUTO_H
#define PRODUTO_H

#include "libs.h"
#include "produtoMensagem.h"

#define MAX 250
#define MIN 30

#define ARQ_PRODUTO "produtos.txt"

FILE *fp;

typedef struct
{
  char cod[MIN];
  char codProd[MIN];
  char nomeProd[MAX];
  int descricao;
  int catProd;
  int itensInc;
  int funcProd;
  int integProd;
  char valorProd[MIN];
  int ativo;
  int tipo;
} Produto;

void BaseProduto();

void InicializarProduto(Produto *produto);

void LerProduto(Produto *produto);

void ExibirProduto(Produto *produto);

void CadastrarProduto();

void ListarProduto();

int PesquisarProduto();

void ExcluirProduto();

void AlterarProduto();

Produto BuscarProduto(char *valor);
#endif // PRODUTO_H