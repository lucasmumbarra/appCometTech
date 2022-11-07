#include "cartao.h"

void ExibirCartao(char *cod)
{
  char numero[16], codigo[3];

  while (1)
  {
    system("cls");
    printf("////////////////////////////////////////////////////\n");
    printf("\n                   PAGAMENTO");
    printf("\n////////////////////////////////////////////////////\n");

    printf("\n\n Digite o número do cartão: ");
    fflush(stdin);
    gets(numero);

    printf("\n\n Digite o código de segurança do cartão: ");
    fflush(stdin);
    gets(codigo);

    if(strlen(numero) < 16) {
      printf(" \n Número do cartão inválido!");
      printf("\n\n Pressione ENTER para continuar.");
      getche();
    } else if (strlen(codigo) < 3) {
      printf(" \n Código de segurança inválido!");
      printf("\n\n Pressione ENTER para continuar.");
      getche();
    } else {
      printf("\n\n Verificando Pagamento...");
      Sleep(3);
      // AlterarVenda(cod);
      break;
    }
  }
}