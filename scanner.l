/*DEFINITIONS*/
%x MLCOMMENT
%option   yylineno
%{
#include "comp_dict.h"
#include "parser.h" //arquivo automaticamente gerado pelo bison
comp_dict_t *dictionary;
%}

/* Regular Expressions*/
ID          [_a-zA-Z][_a-zA-Z0-9]*
INT         ([0-9]+)
FLOAT       ([0-9]+"."[0-9]+)
CHAR        ("\'")[^\']?("\'")
STRING      ("\"")[^\"]*("\"")
WHITESPACE  [ \t\v\f]*

/*RULES*/
%%
int		{ yylval.symbol = dictAddItem(&dictionary, "int", IKS_SIMBOLO_INDEFINIDO, TK_PR_INT, yylineno); 
			return TK_PR_INT;	}
float	{ yylval.symbol = dictAddItem(&dictionary, "float", IKS_SIMBOLO_INDEFINIDO, TK_PR_FLOAT, yylineno);
		  return TK_PR_FLOAT;	}
bool	{ yylval.symbol = dictAddItem(&dictionary, "bool", IKS_SIMBOLO_INDEFINIDO, TK_PR_BOOL, yylineno);
		  return TK_PR_BOOL;	}
char	{ yylval.symbol = dictAddItem(&dictionary, "char", IKS_SIMBOLO_INDEFINIDO, TK_PR_CHAR, yylineno);
		  return TK_PR_CHAR;	}
string	{ yylval.symbol = dictAddItem(&dictionary, "string", IKS_SIMBOLO_INDEFINIDO, TK_PR_STRING, yylineno);
		  return TK_PR_STRING;	}
if		{ yylval.symbol = dictAddItem(&dictionary, "if", IKS_SIMBOLO_INDEFINIDO, TK_PR_IF, yylineno);
		  return TK_PR_IF;		}
then	{ yylval.symbol = dictAddItem(&dictionary, "then", IKS_SIMBOLO_INDEFINIDO, TK_PR_THEN, yylineno);
		  return TK_PR_THEN;	}
else	{ yylval.symbol = dictAddItem(&dictionary, "else", IKS_SIMBOLO_INDEFINIDO, TK_PR_ELSE, yylineno); 
		  return TK_PR_ELSE;	}
while	{ yylval.symbol = dictAddItem(&dictionary, "while", IKS_SIMBOLO_INDEFINIDO, TK_PR_WHILE, yylineno); 
		  return TK_PR_WHILE;	}
do		{ yylval.symbol = dictAddItem(&dictionary, "do", IKS_SIMBOLO_INDEFINIDO, TK_PR_DO, yylineno);
		  return TK_PR_DO;		}
output	{ yylval.symbol = dictAddItem(&dictionary, "output", IKS_SIMBOLO_INDEFINIDO, TK_PR_OUTPUT, yylineno);
		  return TK_PR_OUTPUT;	}
input	{ yylval.symbol = dictAddItem(&dictionary, "input", IKS_SIMBOLO_INDEFINIDO, TK_PR_INPUT, yylineno); 
		  return TK_PR_INPUT;	}
return	{ yylval.symbol = dictAddItem(&dictionary, "return", IKS_SIMBOLO_INDEFINIDO, TK_PR_RETURN, yylineno); 
		  return TK_PR_RETURN;	}
false	{ yylval.symbol = dictAddItem(&dictionary, "false", IKS_SIMBOLO_LITERAL_BOOL, TK_LIT_FALSE, yylineno); 
		  return TK_LIT_FALSE;	}
true	{ yylval.symbol = dictAddItem(&dictionary, "true", IKS_SIMBOLO_LITERAL_BOOL, TK_LIT_TRUE, yylineno); 
		  return TK_LIT_TRUE;	}

","		{ return yytext[0]; }
";"		{ return yytext[0]; }
":"		{ return yytext[0]; }
"("		{ return yytext[0]; }
")"		{ return yytext[0]; }
"["		{ return yytext[0]; }
"]"		{ return yytext[0]; }
"{"		{ return yytext[0]; }
"}"		{ return yytext[0]; }
"+"		{ return yytext[0]; }
"-"		{ return yytext[0]; }
"*"		{ return yytext[0]; }
"/"		{ return yytext[0]; }
"<"		{ return yytext[0]; }
">"		{ return yytext[0]; }
"="		{ return yytext[0]; }
"!"		{ return yytext[0]; }
"&"		{ return yytext[0]; }
"$"		{ return yytext[0]; }

"<="	{ yylval.symbol = dictAddItem(&dictionary, "<=", IKS_SIMBOLO_INDEFINIDO, TK_OC_LE, yylineno); 
		  return TK_OC_LE;	}
">="	{ yylval.symbol = dictAddItem(&dictionary, ">=", IKS_SIMBOLO_INDEFINIDO, TK_OC_GE, yylineno);
		  return TK_OC_GE;	}
"=="	{ yylval.symbol = dictAddItem(&dictionary, "==", IKS_SIMBOLO_INDEFINIDO, TK_OC_EQ, yylineno); 
		  return TK_OC_EQ;	}
"!=" 	{ yylval.symbol = dictAddItem(&dictionary, "!=", IKS_SIMBOLO_INDEFINIDO, TK_OC_NE, yylineno); 
		  return TK_OC_NE;	}
"&&"	{ yylval.symbol = dictAddItem(&dictionary, "&&", IKS_SIMBOLO_INDEFINIDO, TK_OC_AND, yylineno); 
		  return TK_OC_AND; }
"||" 	{ yylval.symbol = dictAddItem(&dictionary, "||", IKS_SIMBOLO_INDEFINIDO, TK_OC_OR, yylineno); 
		  return TK_OC_OR;	}

{ID}		{ char *key = malloc(sizeof(char) *strlen(yytext) + 1);
			  strcpy(key,yytext);			  
			  yylval.symbol = dictAddItem(&dictionary, key, IKS_SIMBOLO_IDENTIFICADOR, TK_IDENTIFICADOR, yylineno);
			  return TK_IDENTIFICADOR;	}
{INT}		{ char *key = malloc(sizeof(char) * strlen(yytext) + 1);
			  strcpy(key,yytext);
			  yylval.symbol = dictAddItem(&dictionary, key, IKS_SIMBOLO_LITERAL_INT, TK_LIT_INT, yylineno);
			  return TK_LIT_INT;		}
{FLOAT}		{ char *key = malloc(sizeof(char) * strlen(yytext) + 1);
			  strcpy(key,yytext);
			  yylval.symbol = dictAddItem(&dictionary, key, IKS_SIMBOLO_LITERAL_FLOAT, TK_LIT_FLOAT, yylineno);
			  return TK_LIT_FLOAT;		}
{CHAR}		{ char *key = malloc(sizeof(char) * strlen(yytext) + 1);
			  strcpy(key,yytext);
			  char *untreated_token = key;
			  char *treated_token = untreated_token;
			  memmove(treated_token, untreated_token+1, strlen(untreated_token)-2);
			  treated_token[strlen(treated_token)-1] = 0;
			  //printf("\n be added: %s", key);
			  yylval.symbol = dictAddItem(&dictionary, key, IKS_SIMBOLO_LITERAL_CHAR, TK_LIT_CHAR, yylineno);
			  return TK_LIT_CHAR;		}
{STRING}	{ char *key = malloc(sizeof(char) * strlen(yytext) + 1);
			  strcpy(key,yytext);
			  char *untreated_token = key;
			  char *treated_token = untreated_token;
			  memmove(treated_token, untreated_token+1, strlen(untreated_token)-2);
			  treated_token[strlen(treated_token)-1] = 0;
			  //printf("\n be added: %s", key);
			  yylval.symbol = dictAddItem(&dictionary, key, IKS_SIMBOLO_LITERAL_STRING, TK_LIT_STRING, yylineno);
			  return TK_LIT_STRING;		}

" "		{ }
"\n"	{ }
"\t"	{ }

"/*"	        { BEGIN( MLCOMMENT ); }
"//"[^\r\n]*    { }
<MLCOMMENT>"*/" { BEGIN( INITIAL ); }
<MLCOMMENT>.    { }
<MLCOMMENT>\n	{ }
.               { return TOKEN_ERRO; }

%%
/*USER CODE*/

int getLineNumber(void)
{
	return yylineno;
}

