#ifndef SEMANTIC_ANALYSIS_H
#define SEMANTIC_ANALYSIS_H

#include "comp_dict.h"
#include "comp_tree.h"
#include "iks_ast.h"

#define IKS_SUCCESS 0 //caso não houver nenhum tipo de erro

/* Verificação de declarações */
#define IKS_ERROR_UNDECLARED	1	  //identificador não declarado
#define IKS_ERROR_DECLARED		2 	//identificador já declarado

/* Uso correto de identificadores */
#define IKS_ERROR_VARIABLE 		3 	//identificador deve ser utilizado como variável
#define IKS_ERROR_VECTOR 		  4 	//identificador deve ser utilizado como vetor
#define IKS_ERROR_FUNCTION 		5 	//identificador deve ser utilizado como função

/* Tipos e tamanho de dados */
#define IKS_ERROR_WRONG_TYPE 	  6 	//tipos incompatíveis
#define IKS_ERROR_STRING_TO_X 	7 	//coerção impossível do tipo string
#define IKS_ERROR_CHAR_TO_X 	  8	  //coerção impossível do tipo char

/* Argumentos e parâmetros */
#define IKS_ERROR_MISSING_ARGS		  9 	//faltam argumentos
#define IKS_ERROR_EXCESS_ARGS		    10 	//sobram argumentos
#define IKS_ERROR_WRONG_TYPE_ARGS 	11 	//argumentos incompatíveis

/* Verificação de tipos em comandos */
#define IKS_ERROR_WRONG_PAR_INPUT	  12 //parâmetro não é identificador
#define IKS_ERROR_WRONG_PAR_OUTPUT	13 //parâmetro não é literal string ou expressão
#define IKS_ERROR_WRONG_PAR_RETURN	14 //parâmetro não é expressão compatível com tipo do retorno

/* Coercion */
#define COERCION_TO_FLOAT	0
#define COERCION_TO_INT		1

int           function_return_type;
comp_tree_t*  local_scope;

void semanticAnalysisPrintError(int error_code, int line);
int  semanticAnalysisEvaluation(comp_tree_t* ast);
int  semanticAnalysisIdentifierVerification(comp_tree_t* node, int type);
int  semanticAnalysisTypeInference(comp_tree_t* node);
int  semanticAnalysisAssignmentCoercion(comp_tree_t* node);
void semanticAnalysisArithmeticCoercion(comp_tree_t* node);
int  semanticAnalysisArgumentVerification(comp_tree_t*, comp_tree_t*);
int  semanticAnalysisParameterVerification(comp_tree_t* node);
int  semanticAnalysisCommandVerification(comp_tree_t* node);
int  semanticAnalysisIsArithmeticExpression(int type);
int  semanticAnalysisDeclarationVerification(comp_tree_t* node, int is_declaration);
int  semanticAnalysisSetGroupScope(comp_tree_t* node);  
int  semanticAnalysisInsertLocalVariables(comp_tree_t* scope, comp_tree_t* local_variables);
int  semanticAnalysisPrintScope(comp_tree_t* scope);
int  semanticAnalysisGivenArguments(comp_tree_t* function, comp_tree_t* call_arg_list);

#endif
