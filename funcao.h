#ifndef funcao_h
#define funcao_h
#include <stdio.h>
#include <stdlib.h>

//Aluno: João Pedro Lopes Santana Villas Bôas - RA: 24.123.071-3
//Aluno: João Pedro Gardenghi Peterutto - RA: 24.123.045-7
//Aluno: Gabriel Koiama Rocha de Oliveira Lira - RA: 24.123.051-5

//Estrutura para poder criar e salvar um cadastro de cliente no arquivo binário
struct Cliente{
    int cpf;
    char nome_cliente[100];
    char conta[10];
    float saldo;
    int senha;
    char historico[500];
};

//Estrutura para poder criar e salvar um cadastro de funcionário6 no arquivo binário
struct Funcionario {
    int cpf_funcionario;
    char nome[100];
    int senha;
};

//Função para salvar os clientes criados no arquivo binario
void salvar_cliente(struct Cliente cliente);

//Função para salvar os funcionários criados no arquivo binario
void salvar_funcionario(struct Funcionario funcionario);

//Função para ver se os clientes estão cadastrados no arquivo binario
int cliente_existe(int cpf, int senha);

//Função para ver se os funcionários estão cadastrados no arquivo binario
int funcionario_existe(int cpf_funcionario, int senha);

//Função para criar um novo funcionário
void novo_funcionario(void);

//Função para criar um novo cliente
void novo_cliente(void);

//Função de login para escolher qual conta acessar, a de funcionário ou a de cliente
void login(void);

//Função inicial do programa em que apresenta as principais opções para utilizar o programa
void menu_login(void);
