#include "cifras.h"
#include <stdio.h>
#include <string.h>

char cifrar(char *pos, int offset) {
  int index = (pos - TABELA);
  int new_index = (index + offset) % 67;
  return TABELA[new_index];
}

char decifrar(char *pos, int offset) {
  int index = (pos - TABELA);
  int new_index = (index + 67 - offset) % 67;
  return TABELA[new_index];
}

void metodo_de_vigenere(char *texto, char *senha, char *cifra, int action) {
  int tam_senha = strlen(senha);
  int salto = 0;
  for (char *t = texto; *t != '\n'; t++) {
    char *pos = strchr(TABELA, *t);
    if (pos == NULL) {
      *cifra = *t;
      cifra++;
      continue;
    }
    if (salto == tam_senha) {
      senha -= salto;
      salto = 0;
    }
    char *pos_senha = strchr(TABELA, *senha);
    int offset = pos_senha - TABELA;

    if (action == 1) {
      *cifra = cifrar(pos, offset);
    } else {
      *cifra = decifrar(pos, offset);
    }
    cifra++, senha++, salto++;
  }
}
void metodo_de_cesar(char *texto, char *senha, char *cifra, int action) {
  char *pos_senha = strchr(TABELA, senha[0]);
  for (char *t = texto; *t != '\n'; t++) {
    char *pos = strchr(TABELA, *t);
    if (pos == NULL) {
      *cifra = *t;
      cifra++;
      continue;
    }

    if (action == 1) {
      *cifra = cifrar(pos, pos_senha - TABELA);
    } else {
      *cifra = decifrar(pos, pos_senha - TABELA);
    }
  }
}
