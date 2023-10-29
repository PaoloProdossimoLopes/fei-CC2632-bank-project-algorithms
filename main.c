#include <stdio.h>
#include <stdlib.h>

#include "cadastrar-cliente.h"
#include "apagar-cliente.h"
#include "listar-clientes.h"
#include "debitar-valor-da-conta.h"
#include "depositar-valor-na-conta-do-banco.h"
#include "gerar-extrato.h"
#include "transferir_entre_contas_do_banco.h"

#define TRUE 1

#define OPCAO_NOVO_CLIENTE 1
#define OPCAO_APAGAR_CLIENTE 2
#define OPCAO_LISTAR_CLIENTE 3
#define OPCAO_DEBITO 4
#define OPCAO_DEPOSITO 5
#define OPCAO_EXTRATO 6
#define OPCAO_TRANSFERENCIA 7
#define OPCAO_SAIR 0

/**
 * Função disponíbilizada para imprimir as operações que o banco pode fazer.
 */
void imprime_menu() {
    printf("\nMenu de Opcoes:\n");
    printf("%d. Novo Cliente\n", OPCAO_NOVO_CLIENTE);
    printf("%d. Apaga Cliente\n", OPCAO_APAGAR_CLIENTE);
    printf("%d. Listar Clientes\n", OPCAO_LISTAR_CLIENTE);
    printf("%d. Debito\n", OPCAO_DEBITO);
    printf("%d. Deposito\n", OPCAO_DEPOSITO);
    printf("%d. Extrato\n", OPCAO_EXTRATO);
    printf("%d. Transferencia Entre Contas\n", OPCAO_TRANSFERENCIA);
    printf("%d. Sair\n", OPCAO_SAIR);
    printf("Escolha: ");
}

/**
 * Metodo disponíbilizado para informar ao usuario que o programa foi finalizado.
 */
void apresentar_mensagem_de_sair() {
    printf("Saindo do programa.\n");
}

/**
 * Metodo disponíbilizado para informar ao usuario que a opcão escolida do menu é invalida.
 */
void apresentar_mensagem_de_opcao_invalida() {
    printf("Opcao invalida. Tente novamente.\n");
}

int main() {
    int escolha;

    while (TRUE) {
        imprime_menu();
        scanf("%d", &escolha);

        switch (escolha) {
            case OPCAO_NOVO_CLIENTE:
                cadatrar_cliente_no_banco();
                break;
            case OPCAO_APAGAR_CLIENTE:
                apagar_cliente_do_banco();
                break;
            case OPCAO_LISTAR_CLIENTE:
                listar_nome_dos_clientes_cadastrados_no_banco();
                break;
            case OPCAO_DEBITO:
                debitar_valor_da_conta_no_banco();
                break;
            case OPCAO_DEPOSITO:
                depositar_valor_na_conta_do_banco();
                break;
            case OPCAO_EXTRATO:
                apresentar_extrato_do_banco();
                break;
            case OPCAO_TRANSFERENCIA:
                transferir_entre_contas();
                break;
            case OPCAO_SAIR:
                apresentar_mensagem_de_sair();
                exit(0);
            default:
                apresentar_mensagem_de_opcao_invalida();
        }
    }
}