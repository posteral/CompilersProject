/*DEFINITIONS*/
%x MLCOMMENT
%option   yylineno
%{
#include "main.h"
#include "comp_dict.h"
#include "parser.h" 
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
int		  { return TK_PR_INT;	  }
float	  { return TK_PR_FLOAT;	}
bool	  { return TK_PR_BOOL;	}
char	  { return TK_PR_CHAR;	}
string	{ return TK_PR_STRING;}
if		  { return TK_PR_IF;		}
then	  { return TK_PR_THEN;	}
else	  { return TK_PR_ELSE;	}
while	  { return TK_PR_WHILE;	}
do		  { return TK_PR_DO;		}
output	{ return TK_PR_OUTPUT;}
input	  { return TK_PR_INPUT;	}
return	{ return TK_PR_RETURN;}
false	  { return TK_LIT_FALSE;}
true  	{ return TK_LIT_TRUE;	}

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

"<="	{ return TK_OC_LE;	}
">="	{ return TK_OC_GE;	}
"=="	{ return TK_OC_EQ;	}
"!=" 	{ return TK_OC_NE;	}
"&&"	{ return TK_OC_AND; }
"||" 	{ return TK_OC_OR;	}

{ID}		  { char *key = malloc(sizeof(char) *strlen(yytext) + 1);
			      strcpy(key,yytext);			  
			      yylval.symbol = treeCreateNode(IKS_AST_IDENTIFICADOR, dictAddItem(&dictionary, key, IKS_SIMBOLO_IDENTIFICADOR, TK_IDENTIFICADOR, yylineno));
			      return TK_IDENTIFICADOR;	}
{INT} 		{ char *key = malloc(sizeof(char) * strlen(yytext) + 1);
			      strcpy(key,yytext);
			      yylval.symbol = treeCreateNode(IKS_AST_LITERAL, dictAddItem(&dictionary, key, IKS_SIMBOLO_LITERAL_INT, TK_LIT_INT, yylineno));
			      return TK_LIT_INT;		}
{FLOAT} 	{ char *key = malloc(sizeof(char) * strlen(yytext) + 1);
			      strcpy(key,yytext);
			      yylval.symbol = treeCreateNode(IKS_AST_LITERAL, dictAddItem(&dictionary, key, IKS_SIMBOLO_LITERAL_FLOAT, TK_LIT_FLOAT, yylineno));
			      return TK_LIT_FLOAT;		}
{CHAR}  	{ char *key = malloc(sizeof(char) * strlen(yytext) + 1);
			      strcpy(key,yytext);
			      char *untreated_token = key;
			      char *treated_token = untreated_token;
			      memmove(treated_token, untreated_token+1, strlen(untreated_token)-2);
			      treated_token[strlen(treated_token)-1] = 0;
			      yylval.symbol = treeCreateNode(IKS_AST_LITERAL, dictAddItem(&dictionary, key, IKS_SIMBOLO_LITERAL_CHAR, TK_LIT_CHAR, yylineno));
			      return TK_LIT_CHAR;		}
{STRING}  { char *key = malloc(sizeof(char) * strlen(yytext) + 1);
			      strcpy(key,yytext);
			      char *untreated_token = key;
			      char *treated_token = untreated_token;
			      memmove(treated_token, untreated_token+1, strlen(untreated_token)-2);
			      treated_token[strlen(treated_token)-2] = 0;
			      yylval.symbol = treeCreateNode(IKS_AST_LITERAL, dictAddItem(&dictionary, key, IKS_SIMBOLO_LITERAL_STRING, TK_LIT_STRING, yylineno));
			      return TK_LIT_STRING;		}

" "		{ }
"\n"	{ }
"\t"	{ }

"/*"	          { BEGIN( MLCOMMENT ); }
"//"[^\r\n]*    { }
<MLCOMMENT>"*/" { BEGIN( INITIAL ); }
<MLCOMMENT>.    { }
<MLCOMMENT>\n	  { }
.               { return TOKEN_ERRO; }

%%

/*USER CODE*/
int getLineNumber(void)
{
	return yylineno;
}

