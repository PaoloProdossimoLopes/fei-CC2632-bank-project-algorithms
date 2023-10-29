//
// Created by pprod on 28/10/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "apagar-cliente.h"
#include "cliente.h"

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
