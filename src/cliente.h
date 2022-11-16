#ifndef CLIENTE_H
#define CLIENTE_H

#include "libs.h"

#define MAX 250
#define MIN 30
#define MAX_ENDERECO 2500

#define ARQ_CLIENTE "clientes.txt"

FILE *fp;

typedef struct
{
  char cod[MIN];
  char razaoSocial[MAX];
  char cnpj[MIN];
  int categoria;
  char telefone[MIN];
  char emailCorp[MAX];
  char endereco[MAX_ENDERECO];
  char nomeResponsavel[MAX];
  char emailResponsavel[MAX];
  char telefoneResponsavel[MIN];
  int ativo;
} Cliente;

void BaseCliente();

void InicializarCliente(Cliente *cliente);

void LerCliente(Cliente *cliente);

void ExibirCliente(Cliente *cliente);

void CadastrarCliente();

void ListarCliente();

int PesquisarCliente();

void ExcluirCliente();

void AlterarCliente();

Cliente BuscarCliente(char *valor);

#endif // CLIENTE_H