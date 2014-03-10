%{
#include "parser.h" //arquivo automaticamente gerado pelo bison
%}
%%
int { return TK_PR_INT; }
. { return TOKEN_ERRO; }
%%
