#include "submenu_gerencia.h"

void MenuFuncionarioGerencia()
{
    int op;

    do
    {
        system("cls");
        printf(" //////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        printf("                         COMET TECH - FUNCIONÁRIOS  \n");
        printf("\n");
        printf(" //////////////////////////////////////////////////////////////////////\n");

        printf("\n\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n\n");
        printf(" 1  - CADASTRAR LOGIN\n");
        printf(" 2  - CADASTRAR FUNCIONARIO\n");
        printf(" 3  - PESQUISAR LOGIN\n");
        printf(" 4  - PESQUISAR FUNCIONARIO\n");
        printf(" 5  - LISTAR LOGIN \n");
        printf(" 6  - LISTAR FUNCIONARIO \n");
        printf(" 7  - ALTERAR LOGIN \n");
        printf(" 8  - ALTERAR FUNCIONARIO \n");
        printf(" 9  - EXCLUIR LOGIN \n");
        printf(" 10 - EXCLUIR FUNCIONARIO \n");
        printf(" 0  - VOLTAR\n");

        printf("\n Escolha uma das opções acima: ");
        scanf("%d", &op);

        switch (op)
        {

        case 1:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                    COMET TECH - CADASTRAR LOGIN\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            CadastrarFuncionarioLogin();
            break;
        case 2:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                  COMET TECH - CADASTRAR FUNCIONARIO\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            CadastrarFuncionario();
            break;
        case 3:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                     COMET TECH - PESQUISAR LOGIN\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            PesquisarFuncionarioLogin();
            break;
        case 4:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                  COMET TECH - PESQUISAR FUNCIONARIO\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            PesquisarFuncionario();
            break;
        case 5:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                     COMET TECH - LISTAR LOGIN\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            ListarFuncionarioLogin();
            break;
        case 6:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                  COMET TECH - LISTAR FUNCIONARIO\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            ListarFuncionario();
            break;
        case 7:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                    COMET TECH - ALTERAR LOGIN\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            AlterarFuncionarioLogin();
            break;
        case 8:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                 COMET TECH - ALTERAR FUNCIONARIO\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            AlterarFuncionario();
            break;
        case 9:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                   COMET TECH - EXCLUIR LOGIN\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            ExcluirFuncionarioLogin();
            break;
        case 10:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                 COMET TECH - EXCLUIR FUNCIONARIO\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            ExcluirFuncionario();
            break;
        case 0:
            system("cls");
            break;
        default:
            system("cls");
            MensagemErroMenuFuncionarioGerencia();
            break;
        }
    } while (op != 0);
}

void MenuClienteGerencia()
{
    int op;

    do
    {
        system("cls");
        printf(" //////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        printf("                         COMET TECH - CLIENTES  \n");
        printf("\n");
        printf(" //////////////////////////////////////////////////////////////////////\n");

        printf("\n\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n\n");
        printf(" 1 - CADASTRAR CLIENTE\n");
        printf(" 2 - PESQUISAR CLIENTE\n");
        printf(" 3 - LISTAR CLIENTE \n");
        printf(" 4 - ALTERAR CLIENTE \n");
        printf(" 5 - EXCLUIR CLIENTE \n");
        printf(" 0  - VOLTAR\n");

        printf("\n Escolha uma das opções acima: ");
        scanf("%d", &op);

        switch (op)
        {

        case 1:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                  COMET TECH - CADASTRAR CLIENTE\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            CadastrarCliente();
            break;
        case 2:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                  COMET TECH - PESQUISAR CLIENTE\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            PesquisarCliente();
            break;
        case 3:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                  COMET TECH - LISTAR CLIENTE\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            ListarCliente();
            break;
        case 4:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                 COMET TECH - ALTERAR CLIENTE\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            AlterarCliente();
            break;
        case 5:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                 COMET TECH - EXCLUIR CLIENTE\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            ExcluirCliente();
            break;
        case 0:
            system("cls");
            break;
        }
    } while (op != 0);
}

void MenuProdutoGerencia()
{
    int op;

    do
    {
        system("cls");
        printf(" //////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        printf("                         COMET TECH - PRODUTOS  \n");
        printf("\n");
        printf(" //////////////////////////////////////////////////////////////////////\n");

        printf("\n\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n\n");
        printf(" 1 - CADASTRAR PRODUTO\n");
        printf(" 2 - PESQUISAR PRODUTO\n");
        printf(" 3 - LISTAR PRODUTO \n");
        printf(" 4 - ALTERAR PRODUTO \n");
        printf(" 5 - EXCLUIR PRODUTO \n");
        printf(" 0 - VOLTAR\n");

        printf("\n Escolha uma das opções acima: ");
        scanf("%d", &op);

        switch (op)
        {

        case 1:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                  COMET TECH - CADASTRAR PRODUTO\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            CadastrarProduto();
            break;
        case 2:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                  COMET TECH - PESQUISAR PRODUTO\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            PesquisarProduto();
            break;
        case 3:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                  COMET TECH - LISTAR PRODUTO\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            ListarProduto();
            break;
        case 4:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                 COMET TECH - ALTERAR PRODUTO\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            AlterarProduto();
            break;
        case 5:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                 COMET TECH - EXCLUIR PRODUTO\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            ExcluirProduto();
            break;
        case 0:
            system("cls");
            break;
        }
    } while (op != 0);
}

void MenuVendaGerencia(Funcionario *funcionario)
{
    int op, val;

    char cod[30];

    do
    {
        system("cls");
        printf(" //////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        printf("                         COMET TECH - VENDAS  \n");
        printf("\n");
        printf(" //////////////////////////////////////////////////////////////////////\n");

        printf("\n\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ \n\n");
        printf(" 1 - CADASTRAR VENDA\n");
        printf(" 2 - PESQUISAR VENDA\n");
        printf(" 3 - LISTAR VENDA \n");
        printf(" 4 - EXCLUIR VENDA \n");
        printf(" 0 - VOLTAR\n");

        printf("\n Escolha uma das opções acima: ");
        scanf("%d", &op);

        switch (op)
        {

        case 1:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                  COMET TECH - CADASTRAR VENDA\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            BaseSelecao(funcionario->cod);
            CadastrarSelecao();
            printf("\n Deseja continuar a compra: 1 - Sim   2 - Não: \n Selecione a opção: ");
            scanf("%i", &op);
            if (op == 1)
            {
                ExibirVenda(funcionario->cod);
                break;
            }
            else if (op == 2)
            {
                printf("Pressione ENTER para voltar ao menu.");
                break;
            }
            else
            {
                printf("\n\n Opção inválida! \n");
                Sleep(1);
            }
            break;
        case 2:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                  COMET TECH - PESQUISAR VENDA\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            PesquisarVendaLt();
            break;
        case 3:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                  COMET TECH - LISTAR VENDA\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            ListarVenda();
            break;
        case 4:
            system("cls");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n                 COMET TECH - EXCLUIR VENDA\n");
            printf(" //////////////////////////////////////////////////////////////////////\n");
            printf("\n Dígite o código da venda a ser excluída: ");
            scanf("%s", &cod);
            printf("\n Deseja realmente excluir a venda?\n 1 - SIM  2 - NÃO \n Selecione uma opção: ");
            scanf("%i", &op);

            if (op == 1)
            {
                val = 2;
                AlterarVenda(cod, val);
                break;
            }

            if (op == 2)
            {
                printf("Pressíone ENTER para continuar");
                getche();
                break;
            }
        case 0:
            system("cls");
            break;
        }
    } while (op != 0);
}