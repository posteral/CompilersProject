%{ 
#include <stdio.h>
#include "main.h"
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
%token<tree_node> TK_LIT_INT
%token<tree_node> TK_LIT_FLOAT
%token<tree_node> TK_LIT_FALSE
%token<tree_node> TK_LIT_TRUE
%token<tree_node> TK_LIT_CHAR
%token<tree_node> TK_LIT_STRING
%token<tree_node> TK_IDENTIFICADOR
%token TOKEN_ERRO

%type<tree_node> s
%type<tree_node> program
%type<tree_node> function_declaration
%type<tree_node> commands_function
%type<tree_node> command_block
%type<tree_node> command_sequence
%type<tree_node> non_void_command
%type<tree_node> statement
%type<tree_node> assignment
%type<tree_node> input
%type<tree_node> output
%type<tree_node> non_void_expression_list
%type<tree_node> return
%type<tree_node> control_flow
%type<tree_node> arg_list
%type<tree_node> non_void_arg_list
%type<tree_node> expression
%type<tree_node> func_call
%type<tree_node> header

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
  // -------------------------------------------------
  //                  COPA GRAMMAR
  // -------------------------------------------------
   
  // ---------------------------------------- PROGRAM:
	s: program 
		  {	
			  $$ = treeCreateNode(1, IKS_AST_PROGRAMA, NULL);
			  treeAppendNode($$, $1);
			  gv_declare(IKS_AST_PROGRAMA, (const void*)$$, NULL);
			  if($1!=NULL)
				  gv_connect($$, $1);			
		  };
	
	program : global_var_declaration program {$$ = $2;} 
		        | function_declaration program
			        {
				        if($2!=NULL)
					        {
						        treeAppendNode($1, $2);
						        gv_connect($1, $2);
					        }
				        $$ = $1;		
			        }
		        |	{$$ = NULL;};
	// ------------------------------------------------
	
	// ------------------------- VARIABLES DECLARATION:
	global_var_declaration : 	var_declaration ';' | vector_declaration ';';
	var_declaration :	        var_type TK_IDENTIFICADOR { }; 
	vector_declaration :		  var_type TK_IDENTIFICADOR '[' TK_LIT_INT ']'; //Ta certo? Na global eu nao estou deixando colocar [expression]
	var_type :                TK_PR_INT | TK_PR_FLOAT | TK_PR_BOOL | TK_PR_CHAR | TK_PR_STRING ;
	// ------------------------------------------------
	
	// -------------------------- FUNCTION DECLARATION:
	function_declaration :   header local_var_declaration commands_function 
					                    {		
						                    $$ = $1;
						                    gv_declare(IKS_AST_FUNCAO, (const void*)$$, ($1->symbol)->data.identifier_type);
						                    if($3!=NULL)
						                    {
						                      treeAppendNode($$,$3);
							                    gv_connect($$,$3);
						                    }
					                    };
	header :                  var_type TK_IDENTIFICADOR '(' parameter_list ')' { $$ = $2;	};
	parameter_list :          non_void_parameter_list | ;
	non_void_parameter_list : parameter ',' non_void_parameter_list | parameter ;
	parameter :               var_type TK_IDENTIFICADOR ;	
	local_var_declaration :   var_declaration ';' local_var_declaration | ;	
	commands_function: 	      '{' command_sequence '}' {$$=$2;};
	// ------------------------------------------------
	
	// -------------------------------------- COMMANDS:
	command_block:      '{' command_sequence '}' 
	                        {
	                          $$ = treeCreateNode(1, IKS_AST_BLOCO, NULL);
							              gv_declare(IKS_AST_BLOCO, (const void*)$$, NULL);
							              if($2!=NULL)
							              {
							                treeAppendNode($$,$2);
							                gv_connect($$,$2);
							              }
	                        };
	command_sequence : 	  statement 
				                | statement ';' command_sequence
					                {				
						                if($3!=NULL)
						                {
							                treeAppendNode($1, $3);
							                gv_connect($1, $3);
						                }
						                $$ = $1;
					                };
	statement :           non_void_command | { $$ = NULL; };
	non_void_command :    command_block | func_call | control_flow | assignment | input | output | return ;       
	assignment : 	        TK_IDENTIFICADOR '=' expression 
				                  {
					                  $$ = treeCreateNode(2, IKS_AST_ATRIBUICAO, NULL);
					                  treeAppendNode($$,$1);	
					                  treeAppendNode($$,$3);
					                  gv_declare(IKS_AST_ATRIBUICAO, (const void*)$$, NULL);
					                  gv_declare(IKS_AST_IDENTIFICADOR, (const void*)$1, ($1->symbol)->data.identifier_type);
					                  gv_connect($$, $1);
					                  gv_connect($$, $3);
				                  }
			                  | TK_IDENTIFICADOR '[' expression ']' '=' expression 
				                  {
					                  $$ = treeCreateNode(2, IKS_AST_ATRIBUICAO, NULL);
					                  comp_tree_t* son = treeCreateNode(1, IKS_AST_VETOR_INDEXADO, NULL);	
					                  treeAppendNode(son,$1);	
					                  treeAppendNode(son,$3);
					                  treeAppendNode($$,son);	
					                  treeAppendNode($$,$6);
					                  gv_declare(IKS_AST_ATRIBUICAO, (const void*)$$, NULL);
					                  gv_declare(IKS_AST_VETOR_INDEXADO, (const void*)son, NULL);
					                  gv_declare(IKS_AST_IDENTIFICADOR, (const void*)$1, ($1->symbol)->data.identifier_type);
					                  gv_connect($$, son);
					                  gv_connect($$, $6);
					                  gv_connect(son, $1);
					                  gv_connect(son, $3);
				                  };
	input :             TK_PR_INPUT TK_IDENTIFICADOR 
		                      {
			                      $$ = treeCreateNode(1, IKS_AST_INPUT, NULL);
			                      treeAppendNode($$,$2);
			                      gv_declare(IKS_AST_INPUT, (const void*)$$, NULL);
			                      gv_declare(IKS_AST_IDENTIFICADOR, (const void*)$2, ($2->symbol)->data.identifier_type);
			                      gv_connect($$, $2);						
		                      };
	output :            TK_PR_OUTPUT non_void_expression_list 
		                      {
			                      $$ = treeCreateNode(1, IKS_AST_OUTPUT, NULL);
			                      treeAppendNode($$,$2);
			                      gv_declare(IKS_AST_OUTPUT, (const void*)$$, NULL);
			                      gv_connect($$,$2);						
		                      };
	non_void_expression_list: 	expression ',' non_void_expression_list 
						              {				
							              treeAppendNode($1, $3);
							              gv_connect($1, $3);
							              $$ = $1;
						              }
					                    | expression ;
	return :            TK_PR_RETURN expression 
		                      {
			                      $$ = treeCreateNode(1, IKS_AST_RETURN, NULL);
			                      treeAppendNode($$,$2);
			                      gv_declare(IKS_AST_RETURN, (const void*)$$, NULL);
			                      gv_connect($$,$2);						
		                      };
	
	func_call : 	      TK_IDENTIFICADOR '(' arg_list ')'
				                  {
					                  $$ = treeCreateNode(2, IKS_AST_CHAMADA_DE_FUNCAO, NULL);
					                  treeAppendNode($$,$1);
					                  if($3 != NULL) 
					                    treeAppendNode($$,$3);
					                  gv_declare(IKS_AST_CHAMADA_DE_FUNCAO, (const void*)$$, NULL);
					                  gv_declare(IKS_AST_IDENTIFICADOR, (const void*)$1, ($1->symbol)->data.identifier_type);
					                  gv_connect($$, $1);
					                  if($3 != NULL) 
						                  gv_connect($$, $3);
				                  };	
	arg_list : 	        non_void_arg_list | { $$ = NULL; }; 
	non_void_arg_list : expression ',' non_void_arg_list 
				                  {
					                  treeAppendNode($1,$3);
					                  gv_connect($1, $3);
					                  $$=$1;		
				                  }
			                | expression;
	control_flow :	    TK_PR_IF '(' expression ')' TK_PR_THEN non_void_command 
				                {
					                $$ = treeCreateNode(1, IKS_AST_IF_ELSE, NULL);							
					                gv_declare(IKS_AST_IF_ELSE, (const void*)$$, NULL);
					                treeAppendNode($$,$3);
					                treeAppendNode($$,$6);
					                gv_connect($$,$3);
					                gv_connect($$,$6);	
				                } 
			                | TK_PR_IF '(' expression ')' TK_PR_THEN non_void_command TK_PR_ELSE non_void_command 
				                {
					                $$ = treeCreateNode(1, IKS_AST_IF_ELSE, NULL);							
					                gv_declare(IKS_AST_IF_ELSE, (const void*)$$, NULL);
					                treeAppendNode($$,$3);
					                treeAppendNode($$,$6);
					                treeAppendNode($$,$8);
					                gv_connect($$,$3);
					                gv_connect($$,$6);
					                gv_connect($$,$8);	
				                } 
			                | TK_PR_WHILE '(' expression ')' TK_PR_DO non_void_command 
				                {
					                $$ = treeCreateNode(1, IKS_AST_WHILE_DO, NULL);							
					                gv_declare(IKS_AST_WHILE_DO, (const void*)$$, NULL);
					                treeAppendNode($$,$3);
					                treeAppendNode($$,$6);
					                gv_connect($$,$3);
					                gv_connect($$,$6);	
				                } 
			                | TK_PR_DO non_void_command TK_PR_WHILE '(' expression ')' 
				                {
					                $$ = treeCreateNode(1, IKS_AST_DO_WHILE, NULL);							
					                gv_declare(IKS_AST_DO_WHILE, (const void*)$$, NULL);
					                treeAppendNode($$,$2);
					                treeAppendNode($$,$5);
					                gv_connect($$,$2);
					                gv_connect($$,$5);	
				                };
	// ------------------------------------------------
	
	// ----------------------------------- EXPRESSIONS:					
	expression : 	    TK_IDENTIFICADOR 
				                {
					                $$ = $1;							
					                gv_declare(IKS_AST_IDENTIFICADOR, (const void*)$1, ($1->symbol)->data.identifier_type);
				                } 	
			                | TK_IDENTIFICADOR '[' expression ']'
				                {
					                $$ = treeCreateNode(1, IKS_AST_VETOR_INDEXADO, NULL);
					                treeAppendNode($$,$1);	
					                treeAppendNode($$,$3);
					                gv_declare(IKS_AST_VETOR_INDEXADO, (const void*)$$, NULL);
					                gv_declare(IKS_AST_IDENTIFICADOR, (const void*)$1, ($1->symbol)->data.identifier_type);
					                gv_connect($$, $1);
					                gv_connect($$, $3);
				                }
			                | TK_LIT_INT
				                {
					                $$ = $1;
					                char int_literal[15];
					                sprintf(int_literal, "%d", ($1->symbol)->data.int_type);						
					                gv_declare(IKS_AST_LITERAL, (const void*)$1, int_literal);
				                }
			                | TK_LIT_FLOAT
				                {
					                $$ = $1;
					                char float_literal[15];
					                sprintf(float_literal, "%.2f", ($1->symbol)->data.float_type);						
					                gv_declare(IKS_AST_LITERAL, (const void*)$1, float_literal);
				                }
                  			| TK_LIT_FALSE  
				                {
					                $$ = $1;
					                char false_literal[15];
					                sprintf(false_literal, "%d", ($1->symbol)->data.bool_type);							
					                gv_declare(IKS_AST_LITERAL, (const void*)$1, false_literal);				
				                }
			                | TK_LIT_TRUE   
				                {
					                $$ = $1;
					                char true_literal[15];
					                sprintf(true_literal, "%d", ($1->symbol)->data.bool_type);							
					                gv_declare(IKS_AST_LITERAL, (const void*)$1, true_literal);
				                }
			                | TK_LIT_CHAR
				                {
					                $$ = $1;
					                char char_literal[15];
					                sprintf(char_literal, "%c", ($1->symbol)->data.char_type);							
					                gv_declare(IKS_AST_LITERAL, (const void*)$1, char_literal);
				                }   
			                | TK_LIT_STRING 
				                {
					                $$ = $1;							
					                gv_declare(IKS_AST_LITERAL, (const void*)$1, ($1->symbol)->data.string_type);
				                }
			                | expression '+' expression 
				                {
					                $$ = treeCreateNode(2, IKS_AST_ARIM_SOMA, NULL);
					                treeAppendNode($$,$1);	
					                treeAppendNode($$,$3);
					                gv_declare(IKS_AST_ARIM_SOMA, (const void*)$$, NULL);
					                gv_connect($$, $1);
					                gv_connect($$, $3);	
				                }
			                | expression '-' expression 
				                {
					                $$ = treeCreateNode(2, IKS_AST_ARIM_SUBTRACAO, NULL);
					                treeAppendNode($$,$1);	
					                treeAppendNode($$,$3);
					                gv_declare(IKS_AST_ARIM_SUBTRACAO, (const void*)$$, NULL);
					                gv_connect($$, $1);
					                gv_connect($$, $3);	
				                }
			                |'!' expression 			  
				                {
					                $$ = treeCreateNode(1, IKS_AST_LOGICO_COMP_NEGACAO, NULL);
					                treeAppendNode($$,$2);
					                gv_declare(IKS_AST_LOGICO_COMP_NEGACAO, (const void*)$$, NULL);
					                gv_connect($$, $2);	
				                }
			                | '+' expression { $$=$2; } 
			                | '-' expression 
			                  {
					                $$ = treeCreateNode(1, IKS_AST_ARIM_INVERSAO, NULL);
					                treeAppendNode($$,$2);
					                gv_declare(IKS_AST_ARIM_INVERSAO, (const void*)$$, NULL);
					                gv_connect($$, $2);	
				                }			  
			                | expression '*' expression 
				                {
					                $$ = treeCreateNode(2, IKS_AST_ARIM_MULTIPLICACAO, NULL);
					                treeAppendNode($$,$1);	
					                treeAppendNode($$,$3);
					                gv_declare(IKS_AST_ARIM_MULTIPLICACAO, (const void*)$$, NULL);
					                gv_connect($$, $1);
					                gv_connect($$, $3);	
				                }
			                | expression '/' expression 
				                {
					                $$ = treeCreateNode(2, IKS_AST_ARIM_DIVISAO, NULL);
					                treeAppendNode($$,$1);	
					                treeAppendNode($$,$3);
					                gv_declare(IKS_AST_ARIM_DIVISAO, (const void*)$$, NULL);
					                gv_connect($$, $1);
					                gv_connect($$, $3);	
				                }
			                | expression '<' expression 
				                {
					                $$ = treeCreateNode(2, IKS_AST_LOGICO_COMP_L, NULL);
					                treeAppendNode($$,$1);	
					                treeAppendNode($$,$3);
					                gv_declare(IKS_AST_LOGICO_COMP_L, (const void*)$$, NULL);
					                gv_connect($$, $1);
					                gv_connect($$, $3);	
				                }
			                | expression '>' expression 
				                {
					                $$ = treeCreateNode(2, IKS_AST_LOGICO_COMP_G, NULL);
					                treeAppendNode($$,$1);	
					                treeAppendNode($$,$3);
					                gv_declare(IKS_AST_LOGICO_COMP_G, (const void*)$$, NULL);
					                gv_connect($$, $1);
					                gv_connect($$, $3);	
				                }
			                | '(' expression ')' { $$=$2; }
			                | expression TK_OC_LE expression 
				                {
					                $$ = treeCreateNode(2, IKS_AST_LOGICO_COMP_LE, NULL);
					                treeAppendNode($$,$1);	
					                treeAppendNode($$,$3);
					                gv_declare(IKS_AST_LOGICO_COMP_LE, (const void*)$$, NULL);
					                gv_connect($$, $1);
					                gv_connect($$, $3);	
				                } 
			                | expression TK_OC_GE expression 
				                {
					                $$ = treeCreateNode(2, IKS_AST_LOGICO_COMP_GE, NULL);
					                treeAppendNode($$,$1);	
					                treeAppendNode($$,$3);
					                gv_declare(IKS_AST_LOGICO_COMP_GE, (const void*)$$, NULL);
					                gv_connect($$, $1);
					                gv_connect($$, $3);	
				                } 
			                | expression TK_OC_EQ expression 
				                {
					                $$ = treeCreateNode(2, IKS_AST_LOGICO_COMP_IGUAL, NULL);
					                treeAppendNode($$,$1);	
					                treeAppendNode($$,$3);
					                gv_declare(IKS_AST_LOGICO_COMP_IGUAL, (const void*)$$, NULL);
					                gv_connect($$, $1);
					                gv_connect($$, $3);	
				                } 
			                | expression TK_OC_NE expression 
				                {
					                $$ = treeCreateNode(2, IKS_AST_LOGICO_COMP_DIF, NULL);
					                treeAppendNode($$,$1);	
					                treeAppendNode($$,$3);
					                gv_declare(IKS_AST_LOGICO_COMP_DIF, (const void*)$$, NULL);
					                gv_connect($$, $1);
					                gv_connect($$, $3);	
				                } 
			                | expression TK_OC_AND expression 
				                {
					                $$ = treeCreateNode(2, IKS_AST_LOGICO_E, NULL);
					                treeAppendNode($$,$1);	
					                treeAppendNode($$,$3);
					                gv_declare(IKS_AST_LOGICO_E, (const void*)$$, NULL);
					                gv_connect($$, $1);
					                gv_connect($$, $3);	
				                }
			                | expression TK_OC_OR expression 
				                {
					                $$ = treeCreateNode(2, IKS_AST_LOGICO_OU, NULL);
					                treeAppendNode($$,$1);	
					                treeAppendNode($$,$3);
					                gv_declare(IKS_AST_LOGICO_OU, (const void*)$$, NULL);
					                gv_connect($$, $1);
					                gv_connect($$, $3);	
				                }
			                | func_call  ;
	// ------------------------------------------------
	
%%
