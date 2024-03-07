#include <stdio.h>
#include <string.h>

#define TABELA                                                                 \
  "0123456789ABCDEFGHIJKLMNOPQRSTYVWXYZabcdefghijklmnopqrstuvwxyz .,;-"

void cifra_de_vigenere(char *texto, char *senha, char *cifra);
char cifrar(char *pos, int offset);

void cifra_de_vigenere(char *texto, char *senha, char *cifra) {
  for (char *t = texto; *t != '\n'; t++) {
    printf("letra: %c\n", *t);
    char *pos = strchr(TABELA, *t);
    if (pos == NULL)
      continue;
    printf("pos: %c\n", *pos);
    char c = cifrar(pos, 3);
    printf("cifra: %c\n", c);
  }
}

char cifrar(char *pos, int offset) {
  int index = (pos - TABELA);
  int new_index = (index + offset) % 67;
  return TABELA[new_index];
}
