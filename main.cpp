#include <stdio.h>
#include <stdlib.h>
#include <cstring>

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

#define MAXIMO_CARACTERES_PARA_NOME 100
#define MAXIMO_CARACTERES_PARA_CPF 12
#define MAXIMO_CARACTERES_PARA_TIPO_CONTA 10
#define MAXIMO_CARACTERES_PARA_SENHA 20

/**
 * Estrutura responsavel por representar o cliente do banco\n\n
 *
 * @param nome Lista de caracteres que representa o nome do usuario (limitado em até 100 caracteres).
 * @param cpf Lista de caracteres que representa o cpf do usuario (limitado em até 12 caracteres).
 * @param tipo_conta Lista de caracteres que representa o tipo da conta do usuario (limitado em até 10 caracteres).
 * @param saldo Numero que representa o saldo em conta do usuario.
 * @param senha Lista de caracteres que representa a senha do usuario (limitado em até 20 caracteres).
 */
typedef struct {
    char nome[MAXIMO_CARACTERES_PARA_NOME];
    char cpf[MAXIMO_CARACTERES_PARA_CPF];
    char tipo_conta[MAXIMO_CARACTERES_PARA_TIPO_CONTA];
    float saldo;
    char senha[MAXIMO_CARACTERES_PARA_SENHA];
} Cliente;

/**
 * Metodo disponibilziado para cadastrar o cliente no banco.\n\n
 *
 * Esse metodo salva as informações do cliente em um arquivo binario.\n\n
 *
 * Caso ocorrar um problema na abertura do arquivo a aplicação sera finalziada com o codigo `1`.
 */
void cadatrar_cliente_no_banco() {
    Cliente cliente;
    FILE *arquivo;

    // Captura inforções do cliente
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]s", cliente.nome);
    printf("Digite o CPF do cliente: ");
    scanf(" %s", cliente.cpf);
    printf("Digite o tipo de conta (comum ou plus): ");
    scanf(" %s", cliente.tipo_conta);
    printf("Digite o valor inicial da conta: ");
    scanf("%f", &cliente.saldo);
    printf("Digite a senha do cliente: ");
    scanf(" %s", cliente.senha);

    // Abre o arquivo binário em modo de escrita (append)
    arquivo = fopen("clientes.dat", "ab");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Escreve os dados do cliente no arquivo
    fwrite(&cliente, sizeof(Cliente), 1, arquivo);

    // Fecha o arquivo
    fclose(arquivo);

    printf("Cliente cadastrado com sucesso!\n");
}

/**
 * O Metodo de apagar cliente remove as inforçoes do usuario do banco apartir do CPF\n\n
 *
 * Caso ocorrar um problema na abertura do arquivo a aplicação sera finalziada com o codigo `1`.\n\n
 *
 * Caso ocorrar um problema na abertura do arquivo temporario a aplicação sera finalziada com o codigo `1`.
 */
void apagar_cliente_do_banco() {
    char cpf_busca[MAXIMO_CARACTERES_PARA_CPF];
    FILE *arquivo_temp, *arquivo;
    Cliente cliente;

    printf("Digite o CPF do cliente que deseja apagar: ");
    scanf(" %s", cpf_busca);

    // Abre o arquivo original em modo leitura
    arquivo = fopen("clientes.dat", "rb");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Abre um arquivo temporário em modo de escrita
    arquivo_temp = fopen("temp.dat", "wb");

    // Verifica se o arquivo temporário foi aberto com sucesso
    if (arquivo_temp == NULL) {
        printf("Erro ao abrir o arquivo temporario.\n");
        fclose(arquivo);
        exit(1);
    }

    int encontrado = 0;

    // Lê os registros do arquivo original e grava no arquivo temporário, exceto o registro com CPF igual ao informado
    while (fread(&cliente, sizeof(Cliente), 1, arquivo) == 1) {
        if (strcmp(cliente.cpf, cpf_busca) == 0) {
            encontrado = 1;
        } else {
            fwrite(&cliente, sizeof(Cliente), 1, arquivo_temp);
        }
    }

    // Fecha os arquivos
    fclose(arquivo);
    fclose(arquivo_temp);

    // Remove o arquivo original
    remove("clientes.dat");

    // Renomeia o arquivo temporário para o arquivo original
    rename("temp.dat", "clientes.dat");

    if (encontrado) {
        printf("Cliente apagado com sucesso!\n");
    } else {
        printf("Cliente nao encontrado.\n");
    }
}

/**
 * Metodo usado para listar o nome dos clientes já cadastrados no banco.\n\n
 *
 * Caso ocorrar um problema na abertura do arquivo a aplicação sera finalziada com o codigo `1`.
 */
void listar_nome_dos_clientes_cadastrados_no_banco() {
    FILE *arquivo;
    Cliente cliente;

    // Abre o arquivo em modo leitura
    arquivo = fopen("clientes.dat", "rb");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    printf("\nNomes dos Clientes Cadastrados:\n");
    printf("---------------------------------\n");

    // Lê e imprime os nomes dos clientes
    while (fread(&cliente, sizeof(Cliente), 1, arquivo) == 1) {
        printf("%s\n", cliente.nome);
    }

    // Fecha o arquivo
    fclose(arquivo);
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
                break;
            case OPCAO_DEPOSITO:
                break;
            case OPCAO_EXTRATO:
                break;
            case OPCAO_TRANSFERENCIA:
                break;
            case OPCAO_SAIR:
                apresentar_mensagem_de_sair();
                exit(0);
            default:
                apresentar_mensagem_de_opcao_invalida();
        }
    }
}
