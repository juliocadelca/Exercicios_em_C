#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para validar os dados
char* validar_dados(char* nome, int idade, char* email) {
  char* mensagem;
  if (idade < 0 || idade > 120) {
    mensagem = "Dados Invalidos: Idade fora do intervalo permitido!";
  } else if (strchr(email, '@') == NULL || strchr(email, '.') == NULL) {
    mensagem = "Dados Invalidos: E-mail no formato incorreto!";
  } else {
    mensagem = "Dados Validados com Sucesso!";
  }
  return mensagem;
}

int main() {
  // Variáveis para armazenar os dados
  char nome[100];
  int idade;
  char email[100];

  // Solicitar entrada do usuário
  fgets(nome, sizeof(nome), stdin);
  scanf("%d", & idade);
  scanf("%s", email);

  // Chamar a função validar_dados com os valores inseridos pelo usuário
  char* resultado = validar_dados(nome, idade, email);

  // Exibir o resultado
  printf("%s", resultado);

  return 0;
}