#include <stdio.h>
#include <stdlib.h>
#include "main.h"

extern struct comp_tree_t* local_scope;
extern char *yytext;
extern int yylineno;
extern int getLineNumber();
extern comp_dict_t *dictionary;
#define print_nome(TOKEN) printf("\n%d " #TOKEN " [%s]", getLineNumber(), yytext);
#define print_nome2(TOKEN) printf("\n%d %c", getLineNumber(), TOKEN);

#include "main.h"

void yyerror (char const *mensagem)
{
	fprintf (stderr, "%s on line %d\n", mensagem,yylineno);
	//IMPROVE 
}

/*int main (int argc, char **argv)
{

  int token = TOKEN_ERRO;
  while (token = yylex()){	
    printf ("token <%d> at %d\n", token, getLineNumber());
  }
  return 0;
}*/

/* test main function provided*/

int main (int argc, char **argv)
{
  local_scope =  treeCreateNode(0, NULL);

  gv_init("teste.dot");
	int resultado = yyparse();
	printf("\nResult: %d\n", resultado);
	gv_close();
	
	if(resultado)
		exit(IKS_SYNTAX_ERRO);
	else
		exit(IKS_SYNTAX_SUCESSO);		
	
	return resultado;
}

