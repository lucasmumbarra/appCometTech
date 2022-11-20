#include "cartao.h"

void ExibirCartao(char *cod)
{
  char numero[16], codigo[3];
  int numLen, codLen, val;

  while (1)
  {
    system("cls");
    printf("////////////////////////////////////////////////////\n");
    printf("\n               PAGAMENTO\n");
    printf("\n////////////////////////////////////////////////////\n");

    printf("\n\n Digite o número do cartão: ");
    fflush(stdin);
    gets(numero);
    numLen = strlen(numero);

    printf("\n\n Digite o código de seguraça do cartão: ");
    fflush(stdin);
    gets(codigo);
    codLen = strlen(codigo);

    if (numLen < 16)
    {
      printf(" \n Número do cartão Inválido! ");
      printf("\n\n Pressione Enter para continuar.");
      getche();
    }
    else if (codLen < 3)
    {
      printf(" \n Código de segurança Inválido! ");
      printf("\n\n Pressione Enter para continuar.");
      getche();
    }
    else
    {

      val = 1;

      printf("\n\n Verificando Pagamento...");
      Sleep(3000);
      AlterarVenda(cod, val);
      break;
    }
  }
}
