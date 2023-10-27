#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define OPCAO_NOVO_CLIENTE 1
#define OPCAO_APAGAR_CLIENTE 2
#define OPCAO_LISTAR_CLIENTE 3
#define OPCAO_DEBITO 4
#define OPCAO_DEPOSITO 5
#define OPCAO_EXTRATO 6
#define OPCAO_TRANSFERENCIA 7
#define OPCAO_SAIR 0

void inprime_menu() {
    printf("\nMenu de Opcoes:\n");
    printf("%d. Novo Cliente\n", OPCAO_NOVO_CLIENTE);
    printf("%d. Apaga Cliente\n", OPCAO_APAGAR_CLIENTE);
    printf("%d. Listar Clientes\n", OPCAO_LISTAR_CLIENTE);
    printf("%d. Debito\n", OPCAO_DEBITO);
    printf("%d. Deposito\n", OPCAO_DEPOSITO);
    printf("%d. Extrato\n", OPCAO_EXTRATO);
    printf("%d. Transferencia Entre Contas\n", OPCAO_TRANSFERENCIA);
    printf("%d. Sair\n", OPCAO_SAIR);
}

int main() {
    int escolha;

    while (TRUE) {
        inprime_menu();
        printf("Escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case OPCAO_NOVO_CLIENTE:
                break;
            case OPCAO_APAGAR_CLIENTE:
                break;
            case OPCAO_LISTAR_CLIENTE:
                break;
            case OPCAO_DEBITO:
                break;
            case OPCAO_DEPOSITO:
                break;
            case OPCAO_EXTRATO:
                break;
            case OPCAO_TRANSFERENCIA:
                break;
            case OPCAO_SAIR:
                printf("Saindo do programa.\n");
                exit(0);
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }
}
