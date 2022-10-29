#include "funcionario.h"

void BaseFuncionario()
{

  fp = fopen(ARQ_FUNCIONARIO, "r+b");
  if (fp == NULL)
  {
    fp = fopen(ARQ_FUNCIONARIO, "w+b");
    if (fp == NULL)
    {
      printf(" Erro fatal: impossível criar arquivo de dados\n");
      exit(1);
    }
  }
}

void InicializarFuncionario(Funcionario *funcionario)
{
  strcpy(funcionario->cod, "");
  strcpy(funcionario->nome, "");
  strcpy(funcionario->email, "");
  strcpy(funcionario->telefone, "");
  strcpy(funcionario->endereco, "");
  strcpy(funcionario->dataNascimento, "");
  funcionario->sexo = 0;
  strcpy(funcionario->cpf, "");
  funcionario->ativo = 1;
  funcionario->tipo = 1;
}

void LerFuncionario(Funcionario *funcionario)
{
  sprintf(funcionario->cod, "%i", CarregarCodigoFuncionario());
  printf(" Código: %s", funcionario->cod);

  printf("\n Nome: ");
  fflush(stdin);
  fgets(funcionario->nome, MAX, stdin);
  funcionario->nome[strlen(funcionario->nome) - 1] = '\0';

  printf("\n Email: ");
  fflush(stdin);
  fgets(funcionario->email, MAX, stdin);
  funcionario->email[strlen(funcionario->email) - 1] = '\0';

  printf("\n Telefone: ");
  fflush(stdin);
  fgets(funcionario->telefone, MIN, stdin);
  funcionario->telefone[strlen(funcionario->telefone) - 1] = '\0';

  printf("\n Endereco: ");
  fflush(stdin);
  fgets(funcionario->endereco, MAX_ENDERECO, stdin);
  funcionario->endereco[strlen(funcionario->endereco) - 1] = '\0';

  printf("\n Data de nascimento: ");
  fflush(stdin);
  fgets(funcionario->dataNascimento, MIN, stdin);
  funcionario->dataNascimento[strlen(funcionario->dataNascimento) - 1] = '\0';

  printf("\n Selecione o sexo do funcionário:\n 1 - Masculino  2 - Feminino");
  printf("\n Sexo: ");
  fflush(stdin);
  scanf("%i", &funcionario->sexo);

  printf("\n CPF: ");
  fflush(stdin);
  fgets(funcionario->cpf, MIN, stdin);
  funcionario->cpf[strlen(funcionario->cpf) - 1] = '\0';

  printf("\n Selecione a função do funcionário:\n 1 - Administrador  2 - Vendedor");
  printf("\n Função: ");
  fflush(stdin);
  scanf("%i", &funcionario->tipo);
}

void ExibirFuncionario(Funcionario *funcionario)
{
  printf("\n Código: %s", funcionario->cod);
  printf("\n Nome: %s", funcionario->nome);
  printf("\n E-mail: %s", funcionario->email);
  printf("\n Telefone: %s", funcionario->telefone);
  printf("\n Endereço: %s", funcionario->endereco);
  printf("\n Data de nascimento: %s", funcionario->dataNascimento);
  if (funcionario->sexo == 1)
  {
    printf("\n Sexo: Masculino");
  }
  if (funcionario->sexo == 2)
  {
    printf("\n Sexo: Feminino");
  }
  printf("\n CPF: %s", funcionario->cpf);
  if (funcionario->tipo == 1)
  {
    printf("\n Função: Administrador");
  }
  if (funcionario->tipo == 2)
  {
    printf("\n Função: Vendedor");
  }
}

void CadastrarFuncionario()
{
  Funcionario funcionario;
  int op;
  InicializarFuncionario(&funcionario);
  LerFuncionario(&funcionario);

  while (1)
  {
    system("cls");
    ExibirFuncionario(&funcionario);
    printf("\n\n 1 - SALVAR  2 - ALTERAR  3 - SAIR \n Selecione a opção: ");
    scanf("%i", &op);

    if (op == 1)
    {
      BaseFuncionario();
      fseek(fp, 0, SEEK_END);
      if (fwrite(&funcionario, sizeof(Funcionario), 1, fp) == 0)
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
        ExibirFuncionario(&funcionario);
        printf("\n 1 - NOME  2 - E-MAIL  3 - TELEFONE  4 - ENDERECO  5 - DATA DE NASCIMENTO\n");
        printf("\n 6 - SEXO  7 - CPF  8 - FUNÇÃO  9 - VOLTAR\n Selecione uma opção: ");
        scanf("%i", &op);

        if (op == 1)
        {
          printf("Nome: ");
          fflush(stdin);
          fgets(funcionario.nome, MAX, stdin);
        }

        if (op == 2)
        {
          printf("E-mail: ");
          fflush(stdin);
          fgets(funcionario.email, MAX, stdin);
        }

        if (op == 3)
        {
          printf("Telefone: ");
          fflush(stdin);
          fgets(funcionario.telefone, MIN, stdin);
        }

        if (op == 4)
        {
          printf("Endereço: ");
          fflush(stdin);
          fgets(funcionario.endereco, MAX_ENDERECO, stdin);
        }

        if (op == 5)
        {
          printf("Data de nascimento: ");
          fflush(stdin);
          fgets(funcionario.dataNascimento, MIN, stdin);
        }

        if (op == 6)
        {
          printf("\n Selecione o sexo do funcionário:\n 1 - Masculino  2 - Feminino");
          printf("\n Sexo: ");
          fflush(stdin);
          scanf("%i", &funcionario.sexo);
        }

        if (op == 7)
        {
          printf("CPF: ");
          fflush(stdin);
          fgets(funcionario.cpf, MIN, stdin);
        }

        if (op == 8)
        {
          printf("\n Selecione a função do funcionário:\n 1 - Administrador  2 - Vendedor");
          printf("\n Função: ");
          fflush(stdin);
          scanf("%i", &funcionario.tipo);
        }

        if (op == 9)
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
      printf("\n Opção inválida! \n");
      Sleep(1);
    }
  }
}

void ListarFuncionario()
{
  BaseFuncionario();
  Funcionario funcionario;
  InicializarFuncionario(&funcionario);
  int linha = 0;
  rewind(fp);

  while (!feof(fp))
  {
    if (fread(&funcionario, sizeof(Funcionario), 1, fp) != 1)
    {
      break;
    }
    if (funcionario.ativo == 0)
    {
      continue;
    }
    if (funcionario.tipo == 0)
    {
      continue;
    }
    ExibirFuncionario(&funcionario);
    printf("\n ++++++++++++++++ \n");
    linha++;
  }

  if (linha == 0)
  {
    printf("\n Não contém registros. \n");
  }
  printf("\n Pressione ENTER para voltar ao MENU.");
  getche();
}

int PesquisarFuncionario()
{
  BaseFuncionario();
  Funcionario funcionario;
  InicializarFuncionario(&funcionario);

  char valor[MAX];
  strcpy(valor, "");

  int pos = 0, linha = 0, op;

  rewind(fp);

  while (!feof(fp))
  {
    printf("Digite o nome ou cpf a ser procurado: ");
    fflush(stdin);
    fgets(valor, MAX, stdin);
    valor[strlen(valor) - 1] = '\0';

    if (strlen(valor) < 1)
    {
      printf("Nome Inválido! \n\n");
    }
    else
    {
      while (fread(&funcionario, sizeof(Funcionario), 1, fp))
      {
        if (funcionario.ativo != 0 && strstr(funcionario.nome, valor) || funcionario.ativo != 0 && strstr(funcionario.cpf, valor))
        {
          ExibirFuncionario(&funcionario);
          pos = 1;
          printf("\n\n Pressione ENTER para continuar.");
          getche();
          return linha;
        }
        linha++;
      }
      if (pos == 0)
      {
        printf("Registro não encontrado.");
      }
      printf("\n\n Pressione ENTER para continuar.");
      getche();

      break;
    }
  }
  fclose(fp);
}

void ExcluirFuncionario()
{
  BaseFuncionario();
  Funcionario funcionario;
  InicializarFuncionario(&funcionario);

  int pos = 0, op;

  pos = PesquisarFuncionario();

  fseek(fp, pos * sizeof(Funcionario), SEEK_SET);

  if (fread(&funcionario, sizeof(Funcionario), 1, fp) == 1)
  {
    while (1)
    {
      system("cls");
      ExibirFuncionario(&funcionario);
      printf("\n\n 1 - EXCLUIR  2 -SAIR \n Selecione uma opção: ");
      scanf("%i", &op);

      if (op == 1)
      {
        funcionario.ativo = 0;
        fseek(fp, pos * sizeof(Funcionario), SEEK_SET);

        if (fwrite(&funcionario, sizeof(Funcionario), 1, fp) != 1)
        {
          printf("\n Falha ao excluir o registro!\n");
          printf("\n\n Pressione ENTER para continuar.");
          getche();
          break;
        }
        else
        {
          printf("\n Registro excluído com sucesso!\n");
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

void AlterarFuncionario()
{
  BaseFuncionario();
  Funcionario funcionario;

  int pos, op;

  pos = PesquisarFuncionario();

  fseek(fp, pos * sizeof(Funcionario), SEEK_SET);

  if (fread(&funcionario, sizeof(Funcionario), 1, fp) == 1)
  {
    while (1)
    {
      system("cls");
      printf(" ++++++++++ ALTERAR FUNCIONÁRIO ++++++++++\n");
      ExibirFuncionario(&funcionario);
      printf("\n 1 - NOME  2 - E-MAIL  3 - TELEFONE  4 - ENDERECO  5 - DATA DE NASCIMENTO\n");
      printf("\n 6 - SEXO  7 - CPF  8 - FUNÇÃO  9 - SALVAR  10 - SAIR\n Selecione uma opção: ");
      scanf("%i", &op);

      if (op == 1)
      {
        printf("Nome: ");
        fflush(stdin);
        fgets(funcionario.nome, MAX, stdin);
      }

      if (op == 2)
      {
        printf("E-mail: ");
        fflush(stdin);
        fgets(funcionario.email, MAX, stdin);
      }

      if (op == 3)
      {
        printf("Telefone: ");
        fflush(stdin);
        fgets(funcionario.telefone, MIN, stdin);
      }

      if (op == 4)
      {
        printf("Endereço: ");
        fflush(stdin);
        fgets(funcionario.endereco, MAX_ENDERECO, stdin);
      }

      if (op == 5)
      {
        printf("Data de nascimento: ");
        fflush(stdin);
        fgets(funcionario.dataNascimento, MIN, stdin);
      }

      if (op == 6)
      {
        printf("\n Selecione o sexo do funcionário:\n 1 - Masculino  2 - Feminino");
        printf("\n Sexo: ");
        fflush(stdin);
        scanf("%i", &funcionario.sexo);
      }

      if (op == 7)
      {
        printf("CPF: ");
        fflush(stdin);
        fgets(funcionario.cpf, MIN, stdin);
      }

      if (op == 8)
      {
        printf("\n Selecione a função do funcionário:\n 1 - Administrador  2 - Vendedor");
        printf("\n Função: ");
        fflush(stdin);
        scanf("%i", &funcionario.tipo);
      }

      if (op == 9)
      {
        fseek(fp, pos * sizeof(Funcionario), SEEK_SET);
        if (fwrite(&funcionario, sizeof(Funcionario), 1, fp) != 1)
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

      if (op == 10)
      {
        printf("\n SAINDO \n");
        MenuFuncionarioGerencia();
      }
    }
  }
  fclose(fp);
}

int CarregarCodigoFuncionario()
{
  BaseFuncionario();
  Funcionario funcionario;

  int linha = 0;
  rewind(fp);

  while (!feof(fp))
  {
    if (fread(&funcionario, sizeof(Funcionario), 1, fp) != 1)
    {
      break;
    }
    linha++;
  }
  return linha + 1;
  fclose(fp);
}
