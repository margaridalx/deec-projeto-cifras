#include "cifras.h"
#include <stdio.h>

#define DEFAULTPASSWORD "Programacao2024"
#define MAXLENGTH 100

int main(void) {
  char texto[MAXLENGTH];
  char cifra[MAXLENGTH];
  printf("Introduza senha: ");
  fgets(texto, MAXLENGTH, stdin);

  cifra_de_vigenere(texto, DEFAULTPASSWORD, cifra);
  printf(" O texto %s foi cifrado para: %s ", texto, cifra);
}
