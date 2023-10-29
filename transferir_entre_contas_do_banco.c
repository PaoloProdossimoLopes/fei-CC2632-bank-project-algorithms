//
// Created by pprod on 29/10/2023.
//

#include <stdio.h>
#include <strings.h>
#include "transferir_entre_contas_do_banco.h"
#include "cliente.h"


void realizarTransferencia(char cpf_origem[], char senha_origem[], char cpf_destino[], float valor, int *resultado) {
    FILE *arquivoClientes;
    Cliente clienteOrigem, clienteDestino;

    // Abre o arquivo de clientes em modo leitura e escrita binária
    arquivoClientes = fopen("clientes.dat", "r+b");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivoClientes == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        *resultado = 0; // Indica falha
        return;
    }

    // Procura o cliente de origem pelo CPF e senha
    while (fread(&clienteOrigem, sizeof(Cliente), 1, arquivoClientes) == 1) {
        if (strcmp(clienteOrigem.cpf, cpf_origem) == 0 && strcmp(clienteOrigem.senha, senha_origem) == 0) {
            // Verifica se o cliente de origem tem saldo suficiente para a transferência
            if (clienteOrigem.saldo >= valor) {
                // Procura o cliente de destino pelo CPF
                while (fread(&clienteDestino, sizeof(Cliente), 1, arquivoClientes) == 1) {
                    if (strcmp(clienteDestino.cpf, cpf_destino) == 0) {
                        // Realiza a transferência
                        clienteOrigem.saldo -= valor;
                        clienteDestino.saldo += valor;

                        // Atualiza os dados dos clientes no arquivo
                        fseek(arquivoClientes, -sizeof(Cliente), SEEK_CUR);
                        fwrite(&clienteOrigem, sizeof(Cliente), 1, arquivoClientes);

                        fseek(arquivoClientes, -sizeof(Cliente), SEEK_CUR);
                        fwrite(&clienteDestino, sizeof(Cliente), 1, arquivoClientes);

                        *resultado = 1; // Indica sucesso
                        fclose(arquivoClientes);
                        return;
                    }
                }
                printf("CPF de destino não encontrado.\n");
                *resultado = 0; // Indica falha
                fclose(arquivoClientes);
                return;
            } else {
                printf("Saldo insuficiente para realizar a transferência.\n");
                *resultado = 0; // Indica falha
                fclose(arquivoClientes);
                return;
            }
        }
    }

    printf("CPF ou senha de origem incorretos.\n");
    *resultado = 0; // Indica falha
    fclose(arquivoClientes);
}

void transferir_entre_contas() {
    float valor;
    int resultado;
    char cpf_origem[12];
    char senha_origem[20];
    char cpf_destino[12];

    // requisitando dados do usuario executar a transferencia entre as contas
    printf("Digite o CPF de origem: ");
    scanf("%s", cpf_origem);

    printf("Digite a senha de origem: ");
    scanf("%s", senha_origem);

    printf("Digite o CPF de destino: ");
    scanf("%s", cpf_destino);

    printf("Digite o valor a ser transferido: ");
    scanf("%f", &valor);

    // chame a função para realizar a transferência
    realizarTransferencia(cpf_origem, senha_origem, cpf_destino, valor, &resultado);

    if (resultado) {
        printf("Transferência realizada com sucesso.\n");
    } else {
        printf("Erro ao realizar transferência. Verifique as informações fornecidas.\n");
    }
}