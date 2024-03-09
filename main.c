#include "cifras.h"
#include <stdio.h>
#include <unistd.h>

#define DEFAULTPASSWORD "Programacao2024"
#define MAXLENGTH 100

int main(int argc, char *argv[]) {
  char texto[MAXLENGTH];
  char cifra[MAXLENGTH];
  char *senha = NULL;

  int ch;
  while ((ch = getopt(argc, argv, "s:c:d:")) != -1) {
    switch (ch) {
    case 's':
      senha = optarg;
      break;
    case 'c': {
      switch (*optarg) {
      case '1':
        puts("Cifra de César");
        break;
      case '2':
        puts("Cifra de Vigenére");
        break;
      default:
        puts("Cifra Inválida");
      }
      break;
    }
    case 'd': {
      switch (*optarg) {
      case '1':
        puts("Decifrar Cifra de César");
        break;
      case '2':
        puts("Decifrar Cifra de Vigenére");
        break;
      default:
        puts("Cifra Inválida");
      }
      break;
    }
    default:
      puts("Use -h para saber opções");
    }
  }
  printf("A senha é: %s", senha);
  // cifra_de_vigenere(texto, DEFAULTPASSWORD, cifra);
  // printf(" O texto %s foi cifrado para: %s ", texto, cifra);
}
