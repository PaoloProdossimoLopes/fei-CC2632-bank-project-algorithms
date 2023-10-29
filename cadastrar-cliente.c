//
// Created by pprod on 28/10/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "cadastrar-cliente.h"
#include "cliente.h"

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