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

    printf("\n\n Digite o n�mero do cart�o: ");
    fflush(stdin);
    gets(numero);

    printf("\n\n Digite o c�digo de seguran�a do cart�o: ");
    fflush(stdin);
    gets(codigo);

    if(strlen(numero) < 16) {
      printf(" \n N�mero do cart�o inv�lido!");
      printf("\n\n Pressione ENTER para continuar.");
      getche();
    } else if (strlen(codigo) < 3) {
      printf(" \n C�digo de seguran�a inv�lido!");
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