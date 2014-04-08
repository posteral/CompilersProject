%{
//#define YYDEBUG 1 
#include <stdio.h>
#include "main.h"

//yydebug = 1;
%}
%require "2.5"
%error-verbose

%union 
{ 
  struct comp_dict_item_t *symbol; 
};

%union
{
 struct comp_tree_t *tree_node;
};


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
%token<symbol> TK_LIT_INT
%token<symbol> TK_LIT_FLOAT
%token<symbol> TK_LIT_FALSE
%token<symbol> TK_LIT_TRUE
%token<symbol> TK_LIT_CHAR
%token<symbol> TK_LIT_STRING
%token<symbol> TK_IDENTIFICADOR
%token TOKEN_ERRO

%type<tree_node> s
%type<tree_node> program
%type<tree_node> function_declaration
%type<tree_node> command_block
%type<tree_node> command_sequence
%type<tree_node> non_void_command
%type<tree_node> assignment
%type<tree_node> input
%type<tree_node> output
%type<tree_node> non_void_expression_list
%type<tree_node> return
%type<tree_node> control_flow
%type<tree_node> expression
%type<tree_node> func_call

%type<symbol> header

%left TK_OC_OR
%left TK_OC_AND
%left '<' '>' TK_OC_LE TK_OC_GE TK_OC_EQ TK_OC_NE
%left '+' '-'
%left '*' '/' ';'
%left '}'
%right '{'
%right '!'

%nonassoc TK_PR_THEN
%nonassoc TK_PR_ELSE

%%
	/* Regras (e ações) da gramática da Linguagem K */
	s: program 
		{	
			$$ = treeCreateNode(1, IKS_AST_PROGRAMA, NULL);
			printf("\n%p %p", $$, $1);
			treeAppendNode($$, $1);
			gv_declare(IKS_AST_PROGRAMA, (const void*)$$, NULL);			
			gv_connect($$, $1);			
		};
	
	program : global_var_declaration program
		{
			$$ = $2;
			printf("\n %p", $2);
		} 
			| function_declaration program
		{
			//TO BE FINISHED
			$$ = $1;		
		};
			|
		{
			$$ = NULL;
		} ;
	
	global_var_declaration : 	var_declaration ';' | vector_declaration ';';
	var_declaration :	var_type TK_IDENTIFICADOR { }; 
	vector_declaration :		var_type TK_IDENTIFICADOR '[' expression ']';
	var_type : TK_PR_INT | TK_PR_FLOAT | TK_PR_BOOL | TK_PR_CHAR | TK_PR_STRING ;
	
	function_declaration : header local_var_declaration command_block 
		{		
			printf("\nfunction_declaration %p", $1);	
			$$ = treeCreateNode(2, IKS_AST_FUNCAO, $1);
			treeAppendNode($$,$3);
			//printf("%s", $$->symbol->key);
			gv_declare(IKS_AST_FUNCAO, (const void*)$$, ((comp_dict_item_t*)$$->symbol)->data.identifier_type);
			//gv_connect($$, $3);
		};
	header : var_type TK_IDENTIFICADOR '(' parameter_list ')' { $$ = $2; };
	parameter_list : non_void_parameter_list | ;
	non_void_parameter_list : parameter ',' non_void_parameter_list | parameter ;
	parameter : var_type TK_IDENTIFICADOR ;	
	local_var_declaration : var_declaration ';' local_var_declaration | ;	
	
	command_block: '{' command_sequence '}';
	command_sequence : statement | statement ';' command_sequence;
	statement : non_void_command | void_command ;
	non_void_command : command_block | func_call | control_flow | assignment | input | output | return ; 
	void_command : ;
	assignment : TK_IDENTIFICADOR '=' expression | TK_IDENTIFICADOR '[' expression ']' '=' expression ;
	input : TK_PR_INPUT TK_IDENTIFICADOR ;
	output : TK_PR_OUTPUT non_void_expression_list ;
	non_void_expression_list: expression ',' non_void_expression_list | expression ;
	return : TK_PR_RETURN expression ;
	
	func_call : TK_IDENTIFICADOR '(' arg_list ')';	
	arg_list : non_void_arg_list | void_arg_list ; 
	non_void_arg_list : arg ',' non_void_arg_list | arg;
	void_arg_list: ;
	arg: TK_LIT_INT | TK_LIT_FLOAT | TK_LIT_TRUE | TK_LIT_FALSE | TK_LIT_CHAR | TK_LIT_STRING | TK_IDENTIFICADOR | TK_IDENTIFICADOR '[' expression ']';
	
	control_flow :	TK_PR_IF '(' expression ')' TK_PR_THEN non_void_command |
					TK_PR_IF '(' expression ')' TK_PR_THEN non_void_command TK_PR_ELSE non_void_command |  
					TK_PR_WHILE '(' expression ')' TK_PR_DO non_void_command |
					TK_PR_DO non_void_command TK_PR_WHILE '(' expression ')' ;
						
	expression : 		TK_IDENTIFICADOR 
						{
							printf("\nidentificador %p", $1);
							$$ = treeCreateNode(1, IKS_AST_IDENTIFICADOR, $1);							
							gv_declare(IKS_AST_IDENTIFICADOR, (const void*)$$, ((comp_dict_item_t*)$1)->data.identifier_type);
						} 
						| TK_IDENTIFICADOR '[' expression ']'
						{
							$$ = treeCreateNode(2, IKS_AST_VETOR_INDEXADO, NULL);
							comp_tree_t* son = treeCreateNode(1, IKS_AST_IDENTIFICADOR, $1);
							treeAppendNode($$,son);	
							treeAppendNode($$,$3);
							gv_declare(IKS_AST_VETOR_INDEXADO, (const void*)$$, NULL);
							gv_declare(IKS_AST_IDENTIFICADOR, (const void*)son, ((comp_dict_item_t*)$1)->data.identifier_type);
							gv_connect($$, $1);
							gv_connect($$, $3);
						}
						| TK_LIT_INT
						{
							printf("\nTK_LIT_INT %p", $1);
							//$$ = arvoreCriaNodo(1,IKS_AST_LITERAL);
							//$$->pt_tabela = $1;
							//gv_declare(IKS_AST_LITERAL,(const void*)$$,((comp_dict_item_t*)$$->pt_tabela)->chave);
						}
						| TK_LIT_FLOAT  |
						TK_LIT_FALSE  |
						TK_LIT_TRUE   |
						TK_LIT_CHAR   |
						TK_LIT_STRING |
						expression '+' expression |
						expression '-' expression |
						'!' expression 			  |
						'+' expression 			  |
						'-' expression 			  |
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
						expression TK_OC_OR expression |
						func_call  ;
	

%%
