//
// Created by pprod on 28/10/2023.
//

#include <stdio.h>
#include <strings.h>
#include "debitar-valor-da-conta.h"
#include "cliente.h"

void debitar_valor_da_conta(char cpf[], char senha[], float valor, int *resultado) {
    FILE *arquivo;
    Cliente cliente;

    // Abre o arquivo em modo leitura e escrita
    arquivo = fopen("clientes.dat", "r+b");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        *resultado = 0; // Indica falha
        return;
    }

    // Procura o cliente com o CPF e senha fornecidos
    while (fread(&cliente, sizeof(Cliente), 1, arquivo) == 1) {
        if (strcmp(cliente.cpf, cpf) == 0 && strcmp(cliente.senha, senha) == 0) {
            // Verifica se há saldo suficiente para o débito
            if (cliente.saldo >= valor) {
                // Aplica a taxa de acordo com o tipo de conta
                if (strcmp(cliente.tipo_conta, "comum") == 0) {
                    valor *= 1.05; // Cobra taxa de 5% para conta comum
                } else if (strcmp(cliente.tipo_conta, "plus") == 0) {
                    valor *= 1.03; // Cobra taxa de 3% para conta plus
                }

                cliente.saldo -= valor;

                // Verifica limite de saldo negativo
                float limite_negativo = (strcmp(cliente.tipo_conta, "comum") == 0) ? -1000.0 : -5000.0;
                if (cliente.saldo < limite_negativo) {
                    printf("Saldo negativo excedeu o limite permitido.\n");
                    fclose(arquivo);
                    *resultado = -1; // Indica saldo negativo excedido
                    return;
                }

                // Move o cursor para a posição correta no arquivo
                fseek(arquivo, -sizeof(Cliente), SEEK_CUR);
                // Escreve as informações atualizadas do cliente no arquivo
                fwrite(&cliente, sizeof(Cliente), 1, arquivo);
                // Fecha o arquivo
                fclose(arquivo);
                *resultado = 1; // Indica sucesso
                return;
            } else {
                printf("Saldo insuficiente.\n");
                fclose(arquivo);
                *resultado = -2; // Indica saldo insuficiente
                return;
            }
        }
    }

    // Cliente não encontrado
    printf("CPF ou senha incorretos.\n");
    fclose(arquivo);
    *resultado = 0; // Indica falha
}

void debitar_valor_da_conta_no_banco() {
    char senha[MAXIMO_CARACTERES_PARA_SENHA];
    char cpf[MAXIMO_CARACTERES_PARA_CPF];
    float valor;
    int resultado;

    // capturando a entrada nescessaria para executar o debito
    printf("Digite o CPF: ");
    scanf("%s", cpf);

    printf("Digite a senha: ");
    scanf("%s", senha);

    printf("Digite o valor a ser debitado: ");
    scanf("%f", &valor);

    // debitando valor na conta
    debitar_valor_da_conta(cpf, senha, valor, &resultado);

    if (resultado) {
        printf("Débito realizado com sucesso!\n");
    } else {
        printf("Erro ao realizar débito. Verifique as informações fornecidas.\n");
    }
}