#include "erros.h"

void MensagemErroMenuFuncionarioGerencia() {
  printf("\nSelecione uma opção válida!");
  printf("\n\nAperte ENTER para continuar.");
  getche();
  MenuFuncionarioGerencia();
}