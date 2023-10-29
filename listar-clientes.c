//
// Created by pprod on 28/10/2023.
//

#include <stdio.h>
#include "listar-clientes.h"
#include "cliente.h"

void listar_nome_dos_clientes_cadastrados_no_banco() {
    FILE *arquivo;
    Cliente cliente;

    // abre o arquivo em modo leitura
    arquivo = fopen("clientes.dat", "rb");

    // verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    printf("\nNomes dos Clientes Cadastrados:\n");
    printf("---------------------------------\n");

    // le e imprime os nomes dos clientes
    while (fread(&cliente, sizeof(Cliente), 1, arquivo) == 1) {
        printf("%s\n", cliente.nome);
    }

    // fecha o arquivo
    fclose(arquivo);
}