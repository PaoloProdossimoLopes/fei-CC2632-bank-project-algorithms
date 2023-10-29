//
// Created by pprod on 28/10/2023.
//

#ifndef FEI_CC2632_BANK_PROJECT_ALGORITHMS_CLIENTE_H
#define FEI_CC2632_BANK_PROJECT_ALGORITHMS_CLIENTE_H

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

#endif //FEI_CC2632_BANK_PROJECT_ALGORITHMS_CLIENTE_H
