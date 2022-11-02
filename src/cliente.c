#include "cliente.h"

void BaseCliente()
{

  fp = fopen(ARQ_CLIENTE, "r+b");
  if (fp == NULL)
  {
    fp = fopen(ARQ_CLIENTE, "w+b");
    if (fp == NULL)
    {
      printf(" Erro fatal: imposs�vel criar arquivo de dados\n");
      exit(1);
    }
  }
}

void InicializarCliente(Cliente *cliente)
{
  strcpy(cliente->cod, "");
  strcpy(cliente->razaoSocial, "");
  strcpy(cliente->cnpj, "");
  cliente->categoria = 0;
  strcpy(cliente->telefone, "");
  strcpy(cliente->emailCorp, "");
  strcpy(cliente->endereco, "");
  strcpy(cliente->nomeResponsavel, "");
  strcpy(cliente->emailResponsavel, "");
  strcpy(cliente->telefoneResponsavel, "");
  cliente->ativo = 1;
}

void LerCliente(Cliente *cliente)
{
  sprintf(cliente->cod, "%i", CarregarCodigoCliente());
  printf(" C�digo: CLI%s", cliente->cod);

  printf("\n Raz�o social: ");
  fflush(stdin);
  fgets(cliente->razaoSocial, MAX, stdin);
  cliente->razaoSocial[strlen(cliente->razaoSocial) - 1] = '\0';

  printf("\n CNPJ: ");
  fflush(stdin);
  fgets(cliente->cnpj, MIN, stdin);
  cliente->cnpj[strlen(cliente->cnpj) - 1] = '\0';

  printf("\n Selecione a categoria do cliente:\n 1 - Lanchonete  2 - Restaurante  3 - Bar");
  printf("\n Categoria: ");
  fflush(stdin);
  scanf("%i", &cliente->categoria);

  printf("\n Telefone: ");
  fflush(stdin);
  fgets(cliente->telefone, MIN, stdin);
  cliente->telefone[strlen(cliente->telefone) - 1] = '\0';

  printf("\n E-mail corporativo: ");
  fflush(stdin);
  fgets(cliente->emailCorp, MAX, stdin);
  cliente->emailCorp[strlen(cliente->emailCorp) - 1] = '\0';

  printf("\n Endereco: ");
  fflush(stdin);
  fgets(cliente->endereco, MAX_ENDERECO, stdin);
  cliente->endereco[strlen(cliente->endereco) - 1] = '\0';

  printf("\n Nome respons�vel: ");
  fflush(stdin);
  fgets(cliente->nomeResponsavel, MAX, stdin);
  cliente->nomeResponsavel[strlen(cliente->nomeResponsavel) - 1] = '\0';

  printf("\n E-mail respons�vel: ");
  fflush(stdin);
  fgets(cliente->emailResponsavel, MAX, stdin);
  cliente->emailResponsavel[strlen(cliente->emailResponsavel) - 1] = '\0';

  printf("\n Telefone respons�vel: ");
  fflush(stdin);
  fgets(cliente->telefoneResponsavel, MIN, stdin);
  cliente->telefoneResponsavel[strlen(cliente->telefoneResponsavel) - 1] = '\0';
}

void ExibirCliente(Cliente *cliente)
{
  printf("\n C�digo: %s", cliente->cod);
  printf("\n Raz�o social: %s", cliente->razaoSocial);
  printf("\n CNPJ: %s", cliente->cnpj);
  if (cliente->categoria == 1)
  {
    printf("\n Categoria: Lanchonete");
  }
  if (cliente->categoria == 2)
  {
    printf("\n Categoria: Restaurante");
  }
  if (cliente->categoria == 3)
  {
    printf("\n Categoria: Bar");
  }
  printf("\n Telefone: %s", cliente->telefone);
  printf("\n E-mail corporativo: %s", cliente->emailCorp);
  printf("\n Endere�o: %s", cliente->endereco);
  printf("\n Nome respons�vel: %s", cliente->nomeResponsavel);
  printf("\n E-mail respons�vel: %s", cliente->emailResponsavel);
  printf("\n Telefone respons�vel: %s", cliente->telefoneResponsavel);
}

void CadastrarCliente()
{
  Cliente cliente;
  int op;
  InicializarCliente(&cliente);
  LerCliente(&cliente);

  while (1)
  {
    system("cls");
    ExibirCliente(&cliente);
    printf("\n\n 1 - SALVAR  2 - ALTERAR  3 - SAIR \n Selecione a op��o: ");
    scanf("%i", &op);

    if (op == 1)
    {
      BaseCliente();
      fseek(fp, 0, SEEK_END);
      if (fwrite(&cliente, sizeof(Cliente), 1, fp) == 0)
      {
        printf("Erro ao gravar o registro! \n\n");
        printf("\n Pressione alguma tecla para continuar.");
        getch();
      }
      else
      {
        printf("Registro cadastrado com sucesso! \n\n");
        fclose(fp);
        Sleep(1);
        break;
      }
    }

    if (op == 2)
    {
      while (1)
      {
        system("cls");
        printf("ALTERAR \n\n");
        ExibirCliente(&cliente);
        printf("\n 1 - RAZ�O SOCIAL  2 - CNPJ  3 - CATEGORIA  4 - TELEFONE  5 - E-MAIL CORPORATIVO\n");
        printf("\n 6 - ENDERE�O  7 - NOME RESPONS�VEL  8 - E-MAIL RESPONS�VEL  9 - TELEFONE RESPONS�VEL  10 - VOLTAR\n Selecione uma op��o: ");
        scanf("%i", &op);

        if (op == 1)
        {
          printf("Raz�o social: ");
          fflush(stdin);
          fgets(cliente.razaoSocial, MAX, stdin);
        }

        if (op == 2)
        {
          printf("CNPJ: ");
          fflush(stdin);
          fgets(cliente.cnpj, MIN, stdin);
        }

        if (op == 3)
        {
          printf("\n Selecione a categoria do cliente:\n 1 - Lanchonete  2 - Restaurante  3 - Bar");
          printf("\n Categoria: ");
          fflush(stdin);
          scanf("%i", &cliente.categoria);
        }

        if (op == 4)
        {
          printf("Telefone: ");
          fflush(stdin);
          fgets(cliente.telefone, MIN, stdin);
        }

        if (op == 5)
        {
          printf("E-mail corporativo: ");
          fflush(stdin);
          fgets(cliente.emailCorp, MAX, stdin);
        }

        if (op == 6)
        {
          printf("Endere�o: ");
          fflush(stdin);
          fgets(cliente.endereco, MAX_ENDERECO, stdin);
        }

        if (op == 7)
        {
          printf("Nome respons�vel: ");
          fflush(stdin);
          fgets(cliente.nomeResponsavel, MAX, stdin);
        }

        if (op == 8)
        {
          printf("E-mail respons�vel: ");
          fflush(stdin);
          fgets(cliente.emailResponsavel, MAX, stdin);
        }

        if (op == 9)
        {
          printf("E-mail respons�vel: ");
          fflush(stdin);
          fgets(cliente.emailResponsavel, MAX, stdin);
        }

        if (op == 10)
        {
          fflush(stdin);
          break;
        }
      }
    }

    if (op == 3)
    {
      printf("\nVoltando ao menu!");
      Sleep(1);
      break;
    }
    else
    {
      printf("\n Op��o inv�lida! \n");
      Sleep(1);
    }
  }
}

void ListarCliente()
{
  BaseCliente();
  Cliente cliente;
  InicializarCliente(&cliente);
  int linha = 0;
  rewind(fp);

  while (!feof(fp))
  {
    if (fread(&cliente, sizeof(Cliente), 1, fp) != 1)
    {
      break;
    }
    if (cliente.ativo == 0)
    {
      continue;
    }
    if (cliente.categoria == 0)
    {
      continue;
    }
    ExibirCliente(&cliente);
    printf("\n ++++++++++++++++ \n");
    linha++;
  }

  if (linha == 0)
  {
    printf("\n N�o cont�m registros. \n");
  }
  printf("\n Pressione ENTER para voltar ao MENU.");
  getche();
}

int PesquisarCliente()
{
  BaseCliente();
  Cliente cliente;
  InicializarCliente(&cliente);

  char valor[MAX];
  strcpy(valor, "");

  int pos = 0, linha = 0, op;

  rewind(fp);

  while (!feof(fp))
  {
    printf("Digite a raz�o social, cnpj ou c�digo a ser procurado: ");
    fflush(stdin);
    fgets(valor, MAX, stdin);
    valor[strlen(valor) - 1] = '\0';

    if (strlen(valor) < 1)
    {
      printf("Nome Inv�lido! \n\n");
    }
    else
    {
      while (fread(&cliente, sizeof(Cliente), 1, fp))
      {
        if (cliente.ativo != 0 && strstr(cliente.razaoSocial, valor) || cliente.ativo != 0 && strstr(cliente.cnpj, valor || cliente.ativo != 0 && strstr(cliente.cod, valor)))
        {
          ExibirCliente(&cliente);
          pos = 1;
          printf("\n\n Pressione ENTER para continuar.");
          getche();
          return linha;
        }
        linha++;
      }
      if (pos == 0)
      {
        printf("Registro n�o encontrado.");
      }
      printf("\n\n Pressione ENTER para continuar.");
      getche();

      break;
    }
  }
  fclose(fp);
}

void ExcluirCliente()
{
  BaseCliente();
  Cliente cliente;
  InicializarCliente(&cliente);

  int pos = 0, op;

  pos = PesquisarCliente();

  fseek(fp, pos * sizeof(Cliente), SEEK_SET);

  if (fread(&cliente, sizeof(Cliente), 1, fp) == 1)
  {
    while (1)
    {
      system("cls");
      ExibirCliente(&cliente);
      printf("\n\n 1 - EXCLUIR  2 -SAIR \n Selecione uma op��o: ");
      scanf("%i", &op);

      if (op == 1)
      {
        cliente.ativo = 0;
        fseek(fp, pos * sizeof(Cliente), SEEK_SET);

        if (fwrite(&cliente, sizeof(Cliente), 1, fp) != 1)
        {
          printf("\n Falha ao excluir o registro!\n");
          printf("\n\n Pressione ENTER para continuar.");
          getche();
          break;
        }
        else
        {
          printf("\n Registro exclu�do com sucesso!\n");
          printf("\n\n Pressione ENTER para continuar.");
          getche();
          break;
        }
      }
      if (op == 2)
      {
        break;
      }
    }
  }
  fclose(fp);
}

void AlterarCliente()
{
  BaseCliente();
  Cliente cliente;

  int pos, op;

  pos = PesquisarCliente();

  fseek(fp, pos * sizeof(Cliente), SEEK_SET);

  if (fread(&cliente, sizeof(Cliente), 1, fp) == 1)
  {
    while (1)
    {
      system("cls");
      printf(" ++++++++++ ALTERAR FUNCION�RIO ++++++++++\n");
      ExibirCliente(&cliente);
      printf("\n 1 - RAZ�O SOCIAL  2 - CNPJ  3 - CATEGORIA  4 - TELEFONE  5 - E-MAIL CORPORATIVO  6 - ENDERE�O\n");
      printf("\n 7 - NOME RESPONS�VEL  8 - E-MAIL RESPONS�VEL  9 - TELEFONE RESPONS�VEL  10 - SALVAR  11 - SAIR\n Selecione uma op��o: ");
      scanf("%i", &op);

      if (op == 1)
        {
          printf("Raz�o social: ");
          fflush(stdin);
          fgets(cliente.razaoSocial, MAX, stdin);
        }

        if (op == 2)
        {
          printf("CNPJ: ");
          fflush(stdin);
          fgets(cliente.cnpj, MIN, stdin);
        }

        if (op == 3)
        {
          printf("\n Selecione a categoria do cliente:\n 1 - Lanchonete  2 - Restaurante  3 - Bar");
          printf("\n Categoria: ");
          fflush(stdin);
          scanf("%i", &cliente.categoria);
        }

        if (op == 4)
        {
          printf("Telefone: ");
          fflush(stdin);
          fgets(cliente.telefone, MIN, stdin);
        }

        if (op == 5)
        {
          printf("E-mail corporativo: ");
          fflush(stdin);
          fgets(cliente.emailCorp, MAX, stdin);
        }

        if (op == 6)
        {
          printf("Endere�o: ");
          fflush(stdin);
          fgets(cliente.endereco, MAX_ENDERECO, stdin);
        }

        if (op == 7)
        {
          printf("Nome respons�vel: ");
          fflush(stdin);
          fgets(cliente.nomeResponsavel, MAX, stdin);
        }

        if (op == 8)
        {
          printf("E-mail respons�vel: ");
          fflush(stdin);
          fgets(cliente.emailResponsavel, MAX, stdin);
        }

        if (op == 9)
        {
          printf("E-mail respons�vel: ");
          fflush(stdin);
          fgets(cliente.emailResponsavel, MAX, stdin);
        }

      if (op == 10)
      {
        fseek(fp, pos * sizeof(Cliente), SEEK_SET);
        if (fwrite(&cliente, sizeof(Cliente), 1, fp) != 1)
        {
          printf("\n Falha ao Alterar o registro!\n");
          printf("\n\n Pressione ENTER para continuar.");
          getche();
          break;
        }
        else
        {
          printf("\n Registro alterado com sucesso!\n");
          printf("\n\n Pressione ENTER para continuar.");
          getche();
          break;
        }
      }

      if (op == 11)
      {
        printf("\n SAINDO \n");
        MenuClienteGerencia();
      }
    }
  }
  fclose(fp);
}

int CarregarCodigoCliente()
{
  BaseCliente();
  Cliente cliente;

  int linha = 0;
  rewind(fp);

  while (!feof(fp))
  {
    if (fread(&cliente, sizeof(Cliente), 1, fp) != 1)
    {
      break;
    }
    linha++;
  }
  return linha + 1;
  fclose(fp);
}
