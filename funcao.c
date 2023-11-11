#include "funcao.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Aluno: João Pedro Lopes Santana Villas Bôas - RA: 24.123.071-3
//Aluno: João Pedro Gardenghi Peterutto - RA: 24.123.045-7
//Aluno: Gabriel Koiama Rocha de Oliveira Lira - RA: 24.123.051-5

//Função para salvar os clientes criados no arquivo binario
void salvar_cliente(struct Cliente cliente) {
  FILE *arquivo;
  arquivo = fopen("clientes.dat", "ab");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo de clientes.\n");
    exit(1);
  }
  fwrite(&cliente, sizeof(struct Cliente), 1, arquivo);
  fclose(arquivo);
}

//Função para salvar os funcionários criados no arquivo binario
void salvar_funcionario(struct Funcionario funcionario) {
  FILE *arquivo;
  arquivo = fopen("funcionarios.dat", "ab");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo de funcionários.\n");
    exit(1);
  }
  fwrite(&funcionario, sizeof(struct Funcionario), 1, arquivo);
  fclose(arquivo);
}
//Função para ver se os clientes estão cadastrados no arquivo binario
int cliente_existe(int cpf, int senha) {
  FILE *arquivo;
  struct Cliente cliente;

  arquivo = fopen("clientes.dat", "rb");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo de clientes.\n");
    exit(1);
  }

  while (fread(&cliente, sizeof(struct Cliente), 1, arquivo)) {
    if (cliente.cpf == cpf && cliente.senha == senha) {
      fclose(arquivo);
      return 1;
    }
  }

  fclose(arquivo);
  return 0;
}

//Função para ver se os funcionários estão cadastrados no arquivo binario
int funcionario_existe(int cpf_funcionario, int senha) {
  FILE *arquivo;
  struct Funcionario funcionario;

  arquivo = fopen("funcionarios.dat", "rb");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo de funcionários.\n");
    exit(1);
  }

  while (fread(&funcionario, sizeof(struct Funcionario), 1, arquivo)) {
    if (funcionario.cpf_funcionario == cpf_funcionario && funcionario.senha == senha) {
      fclose(arquivo);
      return 1;
    }
  }

  fclose(arquivo);
  return 0;
}

//Função para criar um novo funcionário
void novo_funcionario(void) {
  int cpf_funcionario;
  char nome[100];
  int senha;

  printf("Digite seu CPF: ");
  scanf("%d", &cpf_funcionario);
  printf("Digite seu nome: ");
  scanf("%s", nome);
  printf("Digite sua senha: ");
  scanf("%d", &senha);

  if (funcionario_existe(cpf_funcionario, senha)) {
    printf("Funcionário já cadastrado.\n");
  } else {
    struct Funcionario novo_funcionario = {cpf_funcionario, "", senha};
    strcpy(novo_funcionario.nome, nome);
    salvar_funcionario(novo_funcionario);
    printf("Funcionário cadastrado com sucesso!\n");
    menu_login();
  }
}

//Função para criar um novo cliente
void novo_cliente(void) {
  int cpf;
  char nome_cliente[100];
  char conta[10];
  float saldo;
  int senha;

  printf("Digite seu CPF: ");
  scanf("%d", &cpf);
  printf("Digite seu nome: ");
  scanf("%s", nome_cliente);
  printf("Digite o tipo da conta (Comum ou Plus): ");
  scanf("%s", conta);
  printf("Digite o saldo inicial: ");
  scanf("%f", &saldo);
  printf("Digite sua senha: ");
  scanf("%d", &senha);

  if (cliente_existe(cpf, senha)) {
    printf("Cliente já cadastrado.\n");
  } else {
    struct Cliente novo_cliente = {cpf, "", "", 0, senha};
    strcpy(novo_cliente.nome_cliente, nome_cliente);
    strcpy(novo_cliente.conta, conta);
    novo_cliente.saldo = saldo;
    salvar_cliente(novo_cliente);
    printf("Cliente cadastrado com sucesso!\n");
    menu_login();
  }
}

