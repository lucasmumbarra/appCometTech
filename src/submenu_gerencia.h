#ifndef SUBMENU_GERENCIA_H
#define SUBMENU_GERENCIA_H

#include "libs.h"
#include "menu.h"
#include "funcionario_login.h"
#include "funcionario.h"
#include "cliente.h"
#include "produto.h"
#include "venda.h"
#include "erros.h"

void MenuFuncionarioGerencia();

void MenuClienteGerencia();

void MenuProdutoGerencia();

void MenuVendaGerencia(Funcionario *funcionario);
#endif // SUBMENU_GERENCIA_H
