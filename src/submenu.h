#ifndef SUBMENU_H
#define SUBMENU_H

#include "libs.h"
#include "menu.h"
#include "funcionario_login.h"
#include "funcionario.h"
#include "cliente.h"
#include "produto.h"
#include "venda.h"
#include "erros.h"

void MenuCliente();

void MenuProduto();

void MenuVenda(Funcionario *funcionario);

#endif //SUBMENU_H