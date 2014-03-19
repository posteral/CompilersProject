%{
#include <stdio.h>
%}

/* Declaração dos tokens da gramática da Linguagem K */
%token TK_PR_INT
%token TK_PR_FLOAT
%token TK_PR_BOOL
%token TK_PR_CHAR
%token TK_PR_STRING
%token TK_PR_IF
%token TK_PR_THEN
%token TK_PR_ELSE
%token TK_PR_WHILE
%token TK_PR_DO
%token TK_PR_INPUT
%token TK_PR_OUTPUT
%token TK_PR_RETURN
%token TK_OC_LE
%token TK_OC_GE
%token TK_OC_EQ
%token TK_OC_NE
%token TK_OC_AND
%token TK_OC_OR
%token TK_LIT_INT
%token TK_LIT_FLOAT
%token TK_LIT_FALSE
%token TK_LIT_TRUE
%token TK_LIT_CHAR
%token TK_LIT_STRING
%token TK_IDENTIFICADOR
%token TOKEN_ERRO

%left TK_OC_OR TK_OC_AND
%left '+' '-'
%left '*' '/'
 
%nonassoc TK_PR_THEN ';'
%nonassoc TK_PR_ELSE

%%
 /* Regras (e ações) da gramática da Linguagem K */
	
	program : global_var_declaration program | function_declaration program | ;
	
	global_var_declaration : 	var_declaration ';' | vector_declaration ';' ;
	var_declaration :	var_type ' ' TK_IDENTIFICADOR {$3 = 0;}; 
	vector_declaration :		var_type ' ' TK_IDENTIFICADOR '[' TK_LIT_INT ']';
	var_type : TK_PR_INT | TK_PR_FLOAT | TK_PR_BOOL | TK_PR_CHAR | TK_PR_STRING ;
	
	function_declaration : header  	local_var_declaration command_block ;
	header : var_type ' ' TK_IDENTIFICADOR '(' parameter_list ')' ;
	parameter_list : non_void_parameter_list | ;
	non_void_parameter_list : parameter ',' non_void_parameter_list | parameter ;
	parameter : var_type ' ' TK_IDENTIFICADOR ;	
	local_var_declaration : var_declaration ';' local_var_declaration | ;	
	
	command_block: '{' command_sequence '}';
	command_sequence : command | command';' command_sequence | ;
	command: command_block | func_call | var_declaration | vector_declaration | control_flow | assignment | input | output | return | ;
	assignment : TK_IDENTIFICADOR '=' expression | TK_IDENTIFICADOR '[' expression ']' '=' expression ;
	input : TK_PR_INPUT TK_IDENTIFICADOR ;
	output : TK_PR_OUTPUT non_void_expression_list ;
	non_void_expression_list: expression ',' non_void_expression_list | expression ;
	return : TK_PR_RETURN expression ;
	
	func_call : TK_IDENTIFICADOR '(' arg_list ')';	
	arg_list : non_empty_arg_list | ; 
	non_empty_arg_list : arg ',' non_empty_arg_list | arg; 
	arg: TK_LIT_INT | TK_LIT_FLOAT | TK_LIT_TRUE | TK_LIT_FALSE | TK_LIT_CHAR | TK_LIT_STRING | TK_IDENTIFICADOR ;
	
	control_flow :	TK_PR_IF '(' expression ')' TK_PR_THEN command |
						TK_PR_IF '(' expression ')' TK_PR_THEN command TK_PR_ELSE command |  
						TK_PR_WHILE '(' expression ')' TK_PR_DO command |
						TK_PR_DO command TK_PR_WHILE '(' expression ')' ;
						
	expression : 		TK_IDENTIFICADOR |
						TK_IDENTIFICADOR '[' expression ']' |
						TK_LIT_INT |
						TK_LIT_FLOAT |
						TK_LIT_FALSE |
						TK_LIT_TRUE |
						TK_LIT_CHAR |
						TK_LIT_STRING |
						expression '+' expression |
						expression '-' expression |
						expression '*' expression |
						expression '/' expression |
						expression '<' expression |
						expression '>' expression |
						'(' expression ')' |
						expression TK_OC_LE expression  |
						expression TK_OC_GE expression  |
						expression TK_OC_EQ expression  |
						expression TK_OC_NE expression  |
						expression TK_OC_AND expression |
						expression TK_OC_OR expression  |
						TK_IDENTIFICADOR '(' expression_list ')';
	
	expression_list : non_void_expression_list | ;
	

%%