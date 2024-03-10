#define TABELA                                                                 \
  "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz .,;-"

char cifrar(char *pos, int offset);
char decifrar(char *pos, int offset);
void metodo_de_vigenere(char *texto, char *senha, char *cifra, int action);
void metodo_de_cesar(char *texto, char *senha, char *cifra, int action);
