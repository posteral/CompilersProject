%{ 
#include <stdio.h>
#include "main.h"
#include "semantic_analysis.h"
%}
%require "2.5"
%error-verbose

%union 
{ 
  struct comp_dict_item_t *symbol; 
  struct comp_tree_t *tree_node;
  int identifier_type;
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
%token TOKEN_ERRO

%token<tree_node> TK_LIT_INT
%token<tree_node> TK_LIT_FLOAT
%token<tree_node> TK_LIT_FALSE
%token<tree_node> TK_LIT_TRUE
%token<tree_node> TK_LIT_CHAR
%token<tree_node> TK_LIT_STRING
%token<tree_node> TK_IDENTIFICADOR

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
%type<tree_node> parameter_list
%type<tree_node> non_void_parameter_list
%type<tree_node> parameter

%type<identifier_type> var_type

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
        printf("\nprograma!");

			  $$ = treeCreateNode(IKS_AST_PROGRAMA, NULL);
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
	var_declaration :	        var_type TK_IDENTIFICADOR 
                              { 
                                printf("\nsymbol identifier: %d\n", $2->symbol->is_declared);
                                // not global    
                                if(local_scope->nbChildren != 0)
                                  $2->scope = local_scope->children[local_scope->nbChildren-1];
                                // global
                                else                                   
                                    $2->scope = NULL;
                                
													      if(semanticAnalysisDeclarationVerification($2,1))
                                  $2->symbol->is_declared = 1; 
                                    
                                $2->type = IKS_VARIABLE;		
							              
                                if(local_scope->nbChildren != 0)
														        treeAppendNode(local_scope->children[local_scope->nbChildren-1], $2);
                                
                                $2->dataType = $1;
                                treeSetSize($2, $1);
                             };
	vector_declaration :		  var_type TK_IDENTIFICADOR '[' TK_LIT_INT ']'
                              { 
                                // not global    
                                if(local_scope->nbChildren != 0)
                                  $2->scope = local_scope->children[local_scope->nbChildren-1];
                                // global
                                else
                                  $2->scope = NULL;

													      semanticAnalysisDeclarationVerification($2,1);
                                $2->type = IKS_VECTOR;		
							              
                                if(local_scope->nbChildren != 0)
														        treeAppendNode(local_scope->children[local_scope->nbChildren-1], $2);
                                
                                $2->dataType = $1;
                                treeSetSize($2, $1);
                             };
	var_type :  TK_PR_INT {printf("\nvar_type! int"); $$ = IKS_INT;} | TK_PR_FLOAT {$$ = IKS_FLOAT;} | TK_PR_BOOL {$$ = IKS_BOOL;} | TK_PR_CHAR {$$ = IKS_CHAR;} | TK_PR_STRING { $$ = IKS_STRING;};
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
  header :                  var_type TK_IDENTIFICADOR '(' parameter_list ')' 
								              {	
                                printf("\ncabecalho!");
                                printf("\nsymbol identifier: %d\n", $2->symbol->is_declared);
                                // not global    
                                if(local_scope->nbChildren != 0)
                                  $2->scope = local_scope->children[local_scope->nbChildren-1];
                                // global
                                else
                                  $2->scope = NULL;

                                semanticAnalysisDeclarationVerification($2,1);
                                // new scope
                                treeAppendNode(local_scope, $4);
                                // PERCORRER $4 SETANDO O NOVO ESCOPO?

                                $2->type = IKS_FUNCTION;									                                             
                                $2->dataType = $1;
                                treeSetSize($2, $1);

									              $$ = $2;
									              function_return_type = $1;
								              };
	parameter_list :          non_void_parameter_list 
                               {
                                  $$ = treeCreateNode(IKS_SCOPE, NULL); 
                                  treeAppendNode($$, $1);      
                                  printf("\nlista de parametros criada!");                                                           
                               } 
                            | {printf("\nno parameters!"); $$ = treeCreateNode(IKS_SCOPE, NULL); };
	non_void_parameter_list : parameter ',' non_void_parameter_list 
                               { 
                                  treeAppendNode($1, $3);
                                  treeAppendNode($$, $1);
                               } 
                            | parameter {$$ = $1; printf("\nultimo parametro!");};  
	parameter :               var_type TK_IDENTIFICADOR 
                               {  
                                printf("\nparametro!");
                                //COMO SETAR ESCOPO SE AINDA NAO CRIEI? - setar depois?

                                $2->type = IKS_PARAMETER;									                                             
                                $2->dataType = $1;
                                treeSetSize($2, $1);

                                $$ = $2;
                               };	

	local_var_declaration :   var_declaration ';' local_var_declaration | ;	
	commands_function: 	      '{' command_sequence '}' {$$=$2;};
	// ------------------------------------------------
	
	// -------------------------------------- COMMANDS:
	command_block:      '{' command_sequence '}' 
	                        {
	                          $$ = treeCreateNode(IKS_AST_BLOCO, NULL);
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
					                  $$ = treeCreateNode(IKS_AST_ATRIBUICAO, NULL);
									  $$->dataType = $1->dataType;
									  
					                  treeAppendNode($$,$1);	
					                  treeAppendNode($$,$3);
					                  
									  semanticAnalysisArithmeticCoercion($$);
									
					                  gv_declare(IKS_AST_ATRIBUICAO, (const void*)$$, NULL);
					                  gv_declare(IKS_AST_IDENTIFICADOR, (const void*)$1, ($1->symbol)->data.identifier_type);
					                  gv_connect($$, $1);
					                  gv_connect($$, $3);
				                  }
			                  | TK_IDENTIFICADOR '[' expression ']' '=' expression 
				                  {
					                  $$ = treeCreateNode(IKS_AST_ATRIBUICAO, NULL);
					                  comp_tree_t* child = treeCreateNode(IKS_AST_VETOR_INDEXADO, NULL);	
					                  child->dataType = $1->dataType;
					                  $$->dataType = $1->dataType;
					                  
					                  treeAppendNode(child,$1);	
					                  treeAppendNode(child,$3);
					                  treeAppendNode($$,child);	
					                  treeAppendNode($$,$6);
					         
									  semanticAnalysisArithmeticCoercion($$);
					                  
					                  gv_declare(IKS_AST_ATRIBUICAO, (const void*)$$, NULL);
					                  gv_declare(IKS_AST_VETOR_INDEXADO, (const void*)child, NULL);
					                  gv_declare(IKS_AST_IDENTIFICADOR, (const void*)$1, ($1->symbol)->data.identifier_type);
					                  gv_connect($$, child);
					                  gv_connect($$, $6);
					                  gv_connect(child, $1);
					                  gv_connect(child, $3);
				                  };
	input :             TK_PR_INPUT TK_IDENTIFICADOR 
		                      {
			                      $$ = treeCreateNode(IKS_AST_INPUT, NULL);
			                      treeAppendNode($$,$2);
			                      
			                      semanticAnalysisCommandVerification($$);
			                      
			                      gv_declare(IKS_AST_INPUT, (const void*)$$, NULL);
			                      gv_declare(IKS_AST_IDENTIFICADOR, (const void*)$2, ($2->symbol)->data.identifier_type);
			                      gv_connect($$, $2);						
		                      };
	output :            TK_PR_OUTPUT non_void_expression_list 
		                      {
			                      $$ = treeCreateNode(IKS_AST_OUTPUT, NULL);
			                      treeAppendNode($$,$2);
			                      
			                      semanticAnalysisCommandVerification($$);
			                      
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
			                      $$ = treeCreateNode(IKS_AST_RETURN, NULL);
			                      $$->dataType = function_return_type;
			                      treeAppendNode($$,$2);
			                      
			                      semanticAnalysisArithmeticCoercion($$);
			                      semanticAnalysisCommandVerification($$);
			                      
			                      gv_declare(IKS_AST_RETURN, (const void*)$$, NULL);
			                      gv_connect($$,$2);						
		                      };
	
	func_call : 	      TK_IDENTIFICADOR '(' arg_list ')'
				                  {
					                  $$ = treeCreateNode(IKS_AST_CHAMADA_DE_FUNCAO, NULL);
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
					                $$ = treeCreateNode(IKS_AST_IF_ELSE, NULL);							
					                gv_declare(IKS_AST_IF_ELSE, (const void*)$$, NULL);
					                treeAppendNode($$,$3);
					                treeAppendNode($$,$6);
					                gv_connect($$,$3);
					                gv_connect($$,$6);	
				                } 
			                | TK_PR_IF '(' expression ')' TK_PR_THEN non_void_command TK_PR_ELSE non_void_command 
				                {
					                $$ = treeCreateNode(IKS_AST_IF_ELSE, NULL);							
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
					                $$ = treeCreateNode(IKS_AST_WHILE_DO, NULL);							
					                gv_declare(IKS_AST_WHILE_DO, (const void*)$$, NULL);
					                treeAppendNode($$,$3);
					                treeAppendNode($$,$6);
					                gv_connect($$,$3);
					                gv_connect($$,$6);	
				                } 
			                | TK_PR_DO non_void_command TK_PR_WHILE '(' expression ')' 
				                {
					                $$ = treeCreateNode(IKS_AST_DO_WHILE, NULL);							
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
					                $$ = treeCreateNode(IKS_AST_VETOR_INDEXADO, NULL);
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
					                $1->dataType = IKS_SIMBOLO_LITERAL_INT;
					                char int_literal[15];
					                sprintf(int_literal, "%d", ($1->symbol)->data.int_type);						
					                gv_declare(IKS_AST_LITERAL, (const void*)$1, int_literal);
				                }
			                | TK_LIT_FLOAT
				                {
					                $$ = $1;
					                $1->dataType = IKS_SIMBOLO_LITERAL_FLOAT;
					                char float_literal[15];
					                sprintf(float_literal, "%.2f", ($1->symbol)->data.float_type);						
					                gv_declare(IKS_AST_LITERAL, (const void*)$1, float_literal);
				                }
                  			| TK_LIT_FALSE  
				                {
					                $$ = $1;
					                $1->dataType = IKS_SIMBOLO_LITERAL_BOOL;
					                char false_literal[15];
					                sprintf(false_literal, "%d", ($1->symbol)->data.bool_type);							
					                gv_declare(IKS_AST_LITERAL, (const void*)$1, false_literal);				
				                }
			                | TK_LIT_TRUE   
				                {
					                $$ = $1;
					                $1->dataType = IKS_SIMBOLO_LITERAL_BOOL;
					                char true_literal[15];
					                sprintf(true_literal, "%d", ($1->symbol)->data.bool_type);							
					                gv_declare(IKS_AST_LITERAL, (const void*)$1, true_literal);
				                }
			                | TK_LIT_CHAR
				                {
					                $$ = $1;
					                $1->dataType = IKS_SIMBOLO_LITERAL_CHAR;
					                char char_literal[15];
					                sprintf(char_literal, "%c", ($1->symbol)->data.char_type);							
					                gv_declare(IKS_AST_LITERAL, (const void*)$1, char_literal);
				                }   
			                | TK_LIT_STRING 
				                {
					                $$ = $1;							
					                $1->dataType = IKS_SIMBOLO_LITERAL_STRING;
					                gv_declare(IKS_AST_LITERAL, (const void*)$1, ($1->symbol)->data.string_type);
				                }
			                | expression '+' expression 
				                {									
					                $$ = treeCreateNode(IKS_AST_ARIM_SOMA, NULL);
					                treeAppendNode($$,$1);	
					                treeAppendNode($$,$3);
					                
					                semanticAnalysisTypeInference($$); 
									semanticAnalysisArithmeticCoercion($$);

					                gv_declare(IKS_AST_ARIM_SOMA, (const void*)$$, NULL);
					                gv_connect($$, $1);
					                gv_connect($$, $3);	
				                }
			                | expression '-' expression 
				                {
					                $$ = treeCreateNode(IKS_AST_ARIM_SUBTRACAO, NULL);
					                treeAppendNode($$,$1);	
					                treeAppendNode($$,$3);

					                semanticAnalysisTypeInference($$); 
									semanticAnalysisArithmeticCoercion($$);
									
					                gv_declare(IKS_AST_ARIM_SUBTRACAO, (const void*)$$, NULL);
					                gv_connect($$, $1);
					                gv_connect($$, $3);	
				                }
			                |'!' expression 			  
				                {
					                $$ = treeCreateNode(IKS_AST_LOGICO_COMP_NEGACAO, NULL);
					                treeAppendNode($$,$2);					                
					                gv_declare(IKS_AST_LOGICO_COMP_NEGACAO, (const void*)$$, NULL);
					                gv_connect($$, $2);	
				                }
			                | '+' expression { $$=$2; } 
			                | '-' expression 
			                  {
					                $$ = treeCreateNode(IKS_AST_ARIM_INVERSAO, NULL);
					                treeAppendNode($$,$2);
					                gv_declare(IKS_AST_ARIM_INVERSAO, (const void*)$$, NULL);
					                gv_connect($$, $2);	
				                }			  
			                | expression '*' expression 
				                {
					                $$ = treeCreateNode(IKS_AST_ARIM_MULTIPLICACAO, NULL);
					                treeAppendNode($$,$1);	
					                treeAppendNode($$,$3);
					                
									semanticAnalysisTypeInference($$); 
									semanticAnalysisArithmeticCoercion($$);
					                
					                gv_declare(IKS_AST_ARIM_MULTIPLICACAO, (const void*)$$, NULL);
					                gv_connect($$, $1);
					                gv_connect($$, $3);	
				                }
			                | expression '/' expression 
				                {
					                $$ = treeCreateNode(IKS_AST_ARIM_DIVISAO, NULL);
					                treeAppendNode($$,$1);	
					                treeAppendNode($$,$3);
					                
									semanticAnalysisTypeInference($$); 
									semanticAnalysisArithmeticCoercion($$);
					                
					                gv_declare(IKS_AST_ARIM_DIVISAO, (const void*)$$, NULL);
					                gv_connect($$, $1);
					                gv_connect($$, $3);	
				                }
			                | expression '<' expression 
				                {
					                $$ = treeCreateNode(IKS_AST_LOGICO_COMP_L, NULL);
					                treeAppendNode($$,$1);	
					                treeAppendNode($$,$3);
					                gv_declare(IKS_AST_LOGICO_COMP_L, (const void*)$$, NULL);
					                gv_connect($$, $1);
					                gv_connect($$, $3);	
				                }
			                | expression '>' expression 
				                {
					                $$ = treeCreateNode(IKS_AST_LOGICO_COMP_G, NULL);
					                treeAppendNode($$,$1);	
					                treeAppendNode($$,$3);
					                gv_declare(IKS_AST_LOGICO_COMP_G, (const void*)$$, NULL);
					                gv_connect($$, $1);
					                gv_connect($$, $3);	
				                }
			                | '(' expression ')' { $$=$2; }
			                | expression TK_OC_LE expression 
				                {
					                $$ = treeCreateNode(IKS_AST_LOGICO_COMP_LE, NULL);
					                treeAppendNode($$,$1);	
					                treeAppendNode($$,$3);
					                gv_declare(IKS_AST_LOGICO_COMP_LE, (const void*)$$, NULL);
					                gv_connect($$, $1);
					                gv_connect($$, $3);	
				                } 
			                | expression TK_OC_GE expression 
				                {
					                $$ = treeCreateNode(IKS_AST_LOGICO_COMP_GE, NULL);
					                treeAppendNode($$,$1);	
					                treeAppendNode($$,$3);
					                gv_declare(IKS_AST_LOGICO_COMP_GE, (const void*)$$, NULL);
					                gv_connect($$, $1);
					                gv_connect($$, $3);	
				                } 
			                | expression TK_OC_EQ expression 
				                {
					                $$ = treeCreateNode(IKS_AST_LOGICO_COMP_IGUAL, NULL);
					                treeAppendNode($$,$1);	
					                treeAppendNode($$,$3);
					                gv_declare(IKS_AST_LOGICO_COMP_IGUAL, (const void*)$$, NULL);
					                gv_connect($$, $1);
					                gv_connect($$, $3);	
				                } 
			                | expression TK_OC_NE expression 
				                {
					                $$ = treeCreateNode(IKS_AST_LOGICO_COMP_DIF, NULL);
					                treeAppendNode($$,$1);	
					                treeAppendNode($$,$3);
					                gv_declare(IKS_AST_LOGICO_COMP_DIF, (const void*)$$, NULL);
					                gv_connect($$, $1);
					                gv_connect($$, $3);	
				                } 
			                | expression TK_OC_AND expression 
				                {
					                $$ = treeCreateNode(IKS_AST_LOGICO_E, NULL);
					                treeAppendNode($$,$1);	
					                treeAppendNode($$,$3);
					                gv_declare(IKS_AST_LOGICO_E, (const void*)$$, NULL);
					                gv_connect($$, $1);
					                gv_connect($$, $3);	
				                }
			                | expression TK_OC_OR expression 
				                {
					                $$ = treeCreateNode(IKS_AST_LOGICO_OU, NULL);
					                treeAppendNode($$,$1);	
					                treeAppendNode($$,$3);
					                gv_declare(IKS_AST_LOGICO_OU, (const void*)$$, NULL);
					                gv_connect($$, $1);
					                gv_connect($$, $3);	
				                }
			                | func_call  ;
	// ------------------------------------------------
	
%%
