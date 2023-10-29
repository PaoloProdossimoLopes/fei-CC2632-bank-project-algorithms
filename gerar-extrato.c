//
// Created by pprod on 29/10/2023.
//

#include <stdio.h>
#include <strings.h>
#include "gerar-extrato.h"
#include "cliente.h"

void visualizar_extrato(char cpf[]) {
    FILE *arquivo;
    char nome_arquivo[50];
    char linha[1000];  // assumindo que cada linha do extrato terá no máximo 1000 caracteres

    // Construa o nome do arquivo de extrato baseado no CPF do cliente
    sprintf(nome_arquivo, "%s_extrato.txt", cpf);

    // Abra o arquivo de extrato em modo leitura
    arquivo = fopen(nome_arquivo, "r");

    // Verifique se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de extrato.\n");
        return;
    }

    // Leia e imprima o conteúdo do extrato linha por linha
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }

    // Feche o arquivo de extrato
    fclose(arquivo);
}

void gerar_extrato_do_banco(char cpf[], char senha[], int *resultado) {
    FILE *arquivo_entrada, *arquivo_saida;
    Cliente cliente;
    char nome_arquivo[50];

    // abra o arquivo de clientes em modo leitura
    arquivo_entrada = fopen("clientes.dat", "rb");

    // vrifique se o arquivo foi aberto com sucesso
    if (arquivo_entrada == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        *resultado = 0; // Indica falha
        return;
    }

    // encontre o cliente com o CPF fornecido
    int encontrou_cliente = 0;
    while (fread(&cliente, sizeof(Cliente), 1, arquivo_entrada) == 1) {
        if (strcmp(cliente.cpf, cpf) == 0 && strcmp(cliente.senha, senha) == 0) {
            encontrou_cliente = 1;
            break;
        }
    }

    // feche o arquivo de clientes
    fclose(arquivo_entrada);

    // se o cliente não foi encontrado, indique erro e retorne
    if (!encontrou_cliente) {
        printf("CPF ou senha incorretos.\n");
        *resultado = 0; // Indica falha
        return;
    }

    // construa o nome do arquivo de saída baseado no CPF do cliente
    sprintf(nome_arquivo, "%s_extrato.txt", cpf);

    // abra o arquivo de saída em modo escrita
    arquivo_saida = fopen(nome_arquivo, "w");

    // verifique se o arquivo de saída foi aberto com sucesso
    if (arquivo_saida == NULL) {
        printf("Erro ao criar o arquivo de extrato.\n");
        *resultado = 0; // Indica falha
        return;
    }

    // escreva o cabeçalho no arquivo de saída
    fprintf(arquivo_saida, "Extrato de Operações\n");
    fprintf(arquivo_saida, "---------------------\n");

    // escreva as operações no arquivo de saída
    fprintf(arquivo_saida, "Data: %s", __DATE__); // Obtém a data atual
    fprintf(arquivo_saida, " | Operação: Depósito");
    fprintf(arquivo_saida, " | Valor: %.2f", cliente.saldo);
    fprintf(arquivo_saida, " | Saldo Atual: %.2f\n", cliente.saldo);

    // feche o arquivo de saída
    fclose(arquivo_saida);

    // visualize o extrato gerado
    visualizar_extrato(cpf);

    *resultado = 1; // Indica sucesso
}

void apresentar_extrato_do_banco() {
    char senha[20];
    char cpf[12];
    int resultado;

    // recebendo input do usuario para gerar o extrato do usuario especifico
    printf("Digite o CPF: ");
    scanf("%s", cpf);

    printf("Digite a senha: ");
    scanf("%s", senha);

    // chamando a função para gerar o extrato
    gerar_extrato_do_banco(cpf, senha, &resultado);

    if (resultado) {
        printf("Extrato gerado com sucesso. Consulte o arquivo %s_extrato.txt.\n", cpf);
    } else {
        printf("CPF ou senha incorretos. Não foi possível gerar o extrato.\n");
    }
}