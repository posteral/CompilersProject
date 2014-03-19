/*DEFINITIONS*/
%x MLCOMMENT
%option   yylineno
%{
#include "tokens.h"
#include "comp_dict.h"
comp_dict_t *dictionary;
#include "parser.h" //arquivo automaticamente gerado pelo bison

%}

/* Regular Expressions*/
ID          [_a-zA-Z][_a-zA-Z0-9]*
INT         -?([0-9]+)
FLOAT       -?([0-9]+"."[0-9]+)
CHAR        ("\'")[^\']?("\'")
STRING      ("\"")[^\"]*("\"")
WHITESPACE  [ \t\v\f]*

/*RULES*/
%%
int		{ dictAddItem(&dictionary, "int", TK_PR_INT); 
			return TK_PR_INT;	}
float	{ dictAddItem(&dictionary, "float", TK_PR_FLOAT);
		  return TK_PR_FLOAT;	}
bool	{ dictAddItem(&dictionary, "bool", TK_PR_BOOL);
		  return TK_PR_BOOL;	}
char	{ dictAddItem(&dictionary, "char", TK_PR_CHAR);
		  return TK_PR_CHAR;	}
string	{ dictAddItem(&dictionary, "string", TK_PR_STRING);
		  return TK_PR_STRING;	}
if		{ dictAddItem(&dictionary, "if", TK_PR_IF);
		  return TK_PR_IF;		}
then	{ dictAddItem(&dictionary, "then", TK_PR_THEN);
		  return TK_PR_THEN;	}
else	{ dictAddItem(&dictionary, "else", TK_PR_ELSE); 
		  return TK_PR_ELSE;	}
while	{ dictAddItem(&dictionary, "while", TK_PR_WHILE); 
		  return TK_PR_WHILE;	}
do		{ dictAddItem(&dictionary, "do", TK_PR_DO);
		  return TK_PR_DO;		}
output	{ dictAddItem(&dictionary, "output", TK_PR_OUTPUT);
		  return TK_PR_OUTPUT;	}
input	{ dictAddItem(&dictionary, "input", TK_PR_INPUT); 
		  return TK_PR_INPUT;	}
return	{ dictAddItem(&dictionary, "return", TK_PR_RETURN); 
		  return TK_PR_RETURN;	}
false	{ dictAddItem(&dictionary, "false", TK_LIT_FALSE); 
		  return TK_LIT_FALSE;	}
true	{ dictAddItem(&dictionary, "true", TK_LIT_TRUE); 
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

"<="	{ dictAddItem(&dictionary, "<=", TK_OC_LE); 
		  return TK_OC_LE;	}
">="	{ dictAddItem(&dictionary, ">=", TK_OC_GE);
		  return TK_OC_GE;	}
"=="	{ dictAddItem(&dictionary, "==", TK_OC_EQ); 
		  return TK_OC_EQ;	}
"!=" 	{ dictAddItem(&dictionary, "!=", TK_OC_NE); 
		  return TK_OC_NE;	}
"&&"	{ dictAddItem(&dictionary, "&&", TK_OC_AND); 
		  return TK_OC_AND; }
"||" 	{ dictAddItem(&dictionary, "||", TK_OC_OR); 
		  return TK_OC_OR;	}

{ID}		{ char *key = malloc(sizeof(char) * strlen(yytext));
			  strcpy(key,yytext);
			  dictAddItem(&dictionary, key, TK_IDENTIFICADOR);
			  return TK_IDENTIFICADOR;	}
{INT}		{ char *key = malloc(sizeof(char) * strlen(yytext));
			  strcpy(key,yytext);
			  dictAddItem(&dictionary, key, TK_LIT_INT);
			  return TK_LIT_INT;		}
{FLOAT}		{ char *key = malloc(sizeof(char) * strlen(yytext));
			  strcpy(key,yytext);
			  dictAddItem(&dictionary, key, TK_LIT_FLOAT);
			  return TK_LIT_FLOAT;		}
{CHAR}		{ char *key = malloc(sizeof(char) * strlen(yytext));
			  strcpy(key,yytext);
			  char *untreated_token = key;
			  char *treated_token = untreated_token;
			  memmove(treated_token, untreated_token+1, strlen(untreated_token)-2);
			  treated_token[strlen(treated_token)-1] = 0;	
			  dictAddItem(&dictionary, key, TK_LIT_CHAR);
			  return TK_LIT_CHAR;		}
{STRING}	{ char *key = malloc(sizeof(char) * strlen(yytext));
			  strcpy(key,yytext);
			  char *untreated_token = key;
			  char *treated_token = untreated_token;
			  memmove(treated_token, untreated_token+1, strlen(untreated_token)-2);
			  treated_token[strlen(treated_token)-1] = 0;
			  dictAddItem(&dictionary, key, TK_LIT_STRING);
			  return TK_LIT_STRING;		}

" "		{ }
"\n"	{ }
"\t"	{ }

"/*"	        { BEGIN( MLCOMMENT ); }
"//"[^\r\n]*    { }
<MLCOMMENT>"*/" { BEGIN( INITIAL ); }
<MLCOMMENT>.    {  }
<MLCOMMENT>\n	{ }
.               { return TOKEN_ERRO; }

%%
/*USER CODE*/

int getLineNumber(void)
{
	return yylineno;
}

