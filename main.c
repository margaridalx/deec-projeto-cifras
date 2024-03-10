#include "cifras.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define DEFAULTPASSWORD "Programacao2024"
#define MAXLENGTH 100

int main(int argc, char *argv[]) {
  char texto[MAXLENGTH];
  char cifra[MAXLENGTH];
  char *senha = NULL;
  char *metodo = NULL;
  int action;
  int filter_format = 0;

  int ch;
  while ((ch = getopt(argc, argv, "s:c:d:hf")) != -1) {
    switch (ch) {
    case 's':
      senha = optarg;
      break;
    case 'c': {
      metodo = optarg;
      action = 1;
      break;
    }
    case 'd':
      metodo = optarg;
      action = 0;
      break;
    case 'h':
    case 'f':
      filter_format = 1;
      break;
    default:
      puts("use -h para saber opções");
    }
  }
  // Validação dos argumentos

  if (senha == NULL)
    senha = DEFAULTPASSWORD;

  printf("Digite o texto: ");
  fgets(texto, MAXLENGTH, stdin);

  char filtered_input[MAXLENGTH];
  if (filter_format == 1) {
    filter_input(texto, filtered_input);
  }
  printf("filtro: %s\n", filtered_input);

  switch (*metodo) {
  case '1':
    metodo_de_cesar(filtered_input, senha, cifra, action);
    break;
  case '2':
    metodo_de_vigenere(filtered_input, senha, cifra, action);
    break;
  default:
    puts("Not implemented");
  }
  // formatar output
  //
  //

  printf("A senha utilizada foi: %s", senha);
  printf(" O texto %s foi cifrado para: %s ", texto, cifra);
}
