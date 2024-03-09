#include "cifras.h"
#include <stdio.h>
#include <string.h>

void cifra_de_vigenere(char *texto, char *senha, char *cifra) {
  int tam_senha = strlen(senha);
  int salto = 0;
  for (char *t = texto; *t != '\n'; t++, cifra++, senha++, salto++) {
    char *pos = strchr(TABELA, *t);
    if (pos == NULL)
      continue;
    if (salto == tam_senha) {
      senha -= salto;
      salto = 0;
    }
    char *pos_senha = strchr(TABELA, *senha);
    // TODO: retornar um erro aqui
    if (pos_senha == NULL)
      continue;

    *cifra = cifrar(pos, pos_senha - TABELA);
  }
}

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
