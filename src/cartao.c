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

    printf("\n\n Digite o n�mero do cart�o: ");
    fflush(stdin);
    gets(numero);
    numLen = strlen(numero);

    printf("\n\n Digite o c�digo de segura�a do cart�o: ");
    fflush(stdin);
    gets(codigo);
    codLen = strlen(codigo);

    if (numLen < 16)
    {
      printf(" \n N�mero do cart�o Inv�lido! ");
      printf("\n\n Pressione Enter para continuar.");
      getche();
    }
    else if (codLen < 3)
    {
      printf(" \n C�digo de seguran�a Inv�lido! ");
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
