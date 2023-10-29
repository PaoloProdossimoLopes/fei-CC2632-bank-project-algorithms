//
// Created by pprod on 28/10/2023.
//

#include <stdio.h>
#include <strings.h>
#include "depositar-valor-na-conta-do-banco.h"
#include "cliente.h"


void depositar_valor_na_conta(char cpf[], float valor, int *resultado) {
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

    // Procura o cliente com o CPF fornecido
    while (fread(&cliente, sizeof(Cliente), 1, arquivo) == 1) {
        if (strcmp(cliente.cpf, cpf) == 0) {
            // Atualiza o saldo do cliente com o valor depositado
            cliente.saldo += valor;

            // Move o cursor para a posição correta no arquivo
            fseek(arquivo, -sizeof(Cliente), SEEK_CUR);
            // Escreve as informações atualizadas do cliente no arquivo
            fwrite(&cliente, sizeof(Cliente), 1, arquivo);
            // Fecha o arquivo
            fclose(arquivo);
            *resultado = 1; // Indica sucesso
            return;
        }
    }

    // Cliente não encontrado
    printf("CPF incorreto.\n");
    fclose(arquivo);
    *resultado = 0; // Indica falha
}

void depositar_valor_na_conta_do_banco() {
    char cpf[MAXIMO_CARACTERES_PARA_CPF];
    float valor;
    int resultado;

    // capturando os dados de usuario
    printf("Digite o CPF: ");
    scanf("%s", cpf);

    printf("Digite o valor a ser depositado: ");
    scanf("%f", &valor);

    // depositar o valor na conta
    depositar_valor_na_conta(cpf, valor, &resultado);

    if (resultado) {
        printf("Depósito realizado com sucesso!\n");
    } else {
        printf("Erro ao realizar depósito. Verifique as informações fornecidas.\n");
    }
}