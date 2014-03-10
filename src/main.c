#include "main.h"

void yyerror (char const *mensagem)
{
  fprintf (stderr, "%s\n", mensagem); //altere para que apareça a linha
}

int main (int argc, char **argv)
{
  int resultado = yyparse();
  return resultado;
}
