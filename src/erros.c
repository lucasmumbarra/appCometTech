#include "erros.h"

void MensagemErroMenuFuncionarioGerencia() {
  printf("\nSelecione uma op��o v�lida!");
  printf("\n\nAperte ENTER para continuar.");
  getche();
  MenuFuncionarioGerencia();
}