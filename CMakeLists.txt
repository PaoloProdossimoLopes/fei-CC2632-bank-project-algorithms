cmake_minimum_required(VERSION 3.26)
project(fei_CC2632_bank_project_algorithms)

set(CMAKE_CXX_STANDARD 17)

add_executable(fei_CC2632_bank_project_algorithms main.c
        cliente.h
        cadastrar-cliente.c
        cadastrar-cliente.h
        apagar-cliente.c
        apagar-cliente.h
        listar-clientes.c
        listar-clientes.h
        debitar-valor-da-conta.c
        debitar-valor-da-conta.h
        depositar-valor-na-conta-do-banco.c
        depositar-valor-na-conta-do-banco.h
        gerar-extrato.c
        gerar-extrato.h
        transferir_entre_contas_do_banco.c
        transferir_entre_contas_do_banco.h)
