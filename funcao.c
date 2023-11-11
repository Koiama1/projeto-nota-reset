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
