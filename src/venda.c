#include "venda.h"

void BaseVenda()
{
  ven = fopen(ARQ_VENDAS, "r+b");
  if (ven == NULL)
  {
    ven = fopen(ARQ_VENDAS, "w+b");
    if (ven == NULL)
    {
      printf(" Erro fatal: impossível criar arquivo de dados.\n");
      exit(1);
    }
  }
}

void InicializarVenda(Venda *venda)
{
  int i;
  strstr(venda->cod, "");
  strstr(venda->cliente->razaoSocial, "");
  for (i = 0; i < MAX; i++) {
    strstr(venda->selecao->produto.codProd, "");
    strstr(venda->selecao->produto.nomeProd, "");
    venda->selecao->produto.descricao = 0;
    venda->selecao->produto.catProd = 0;
    strstr(venda->selecao->produto.valorProd, "");
  }
  venda->pagamento = 0;
  venda->total = 0;
  venda->tamanho = 0;
}