#include "utils.h"
#include "cifras.h"
#include <string.h>

void filter_input(char *input, char *filtered_input) {
  for (char *c = input; *c != '\n'; c++) {
    char *pos = strchr(TABELA, *c);
    if (pos == NULL)
      continue;

    *filtered_input = *c;
    filtered_input++;
  }
}
