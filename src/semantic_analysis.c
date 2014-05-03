#include "semantic_analysis.h"
#include <stdio.h>
#include <stdlib.h>

void semanticAnalysisPrintError(int error_code, int line){
	switch(error_code)
    {
            case IKS_ERROR_UNDECLARED: printf("\nSemantic error in line %d: Identifier not declared in this scope\n", getLineNumber());break;
            case IKS_ERROR_DECLARED: printf("\nSemantic error in line %d: Identifier already declared in line %d\n", getLineNumber(),line);break;
            case IKS_ERROR_VARIABLE: printf("\nSemantic error in line %d: Misuse of variable declared in line %d\n", getLineNumber(), line);break;
            case IKS_ERROR_VECTOR: printf("\nSemantic error in line %d: Misuse of vector declared in line %d\n", getLineNumber(), line);break;
            case IKS_ERROR_FUNCTION: printf("\nSemantic error in line %d: Misuse of function declaration in line %d\n", getLineNumber(), line);break;
            case IKS_ERROR_MISSING_ARGS: printf("\nSemantic error in line %d: Missing arguments in function declared in line %d\n", getLineNumber(), line);break;
            case IKS_ERROR_EXCESS_ARGS: printf("\nSemantic error in line %d: Too many arguments in function declared in line %d\n", getLineNumber(), line);break;
            case IKS_ERROR_WRONG_TYPE_ARGS:printf("\nSemantic error in line %d: Incompatible arguments in function declared in line %d\n", getLineNumber(), line);break;
            case IKS_ERROR_WRONG_PAR_RETURN: printf("\nSemantic error in line %d: Return type is different than the one defined for the function.\n", getLineNumber()); break;
            case IKS_ERROR_WRONG_PAR_INPUT: printf("\nSemantic error in line %d: input parameter is not an identifier.\n", getLineNumber()); break;
            case IKS_ERROR_WRONG_PAR_OUTPUT: printf("\nSemantic error in line %d: output parameter is not a string or arithmetic expression.\n", getLineNumber()); break;
            case IKS_ERROR_CHAR_TO_X: printf("\nSemantic error in line %d: it's not possible  to convert a char.\n", getLineNumber()); break;
            case IKS_ERROR_STRING_TO_X: printf("\nSemantic error in line %d: it's not possible to convert a string.\n", getLineNumber()); break;
            case IKS_ERROR_WRONG_TYPE: printf("\nSemantic error in line %d: incompatible types.\n", getLineNumber()); break;
    }

    if(error_code != IKS_SUCCESS)
	{
		printf("Exiting with error code %d...\n", error_code);
	    exit(error_code);
	}
}

int semanticAnalysisIdentifierVerification(comp_tree_t* node, int type){

	if(node->type != type)
	{
		if(node->type == IKS_VARIABLE)
		{
		    semanticAnalysisPrintError(IKS_ERROR_VARIABLE, node->symbol->line_occurrences->data);
		}
		else if(node->type == IKS_VECTOR)
		{
		    semanticAnalysisPrintError(IKS_ERROR_VECTOR, node->symbol->line_occurrences->data);
		}
		else if(node->type == IKS_FUNCTION)
		{
		    semanticAnalysisPrintError(IKS_ERROR_FUNCTION, node->symbol->line_occurrences->data);
		}
	}
	else
	{
		fprintf(stderr, "\nIdentifier verification [%s]: OK", node->symbol->data.identifier_type);
        return IKS_SUCCESS;
	}
}

int  semanticAnalysisTypeInference(comp_tree_t* node)
{
    if(node->children[0]->dataType == IKS_INT && node->children[1]->dataType == IKS_INT)
    {
        node->dataType = IKS_INT;
    }
    else if(node->children[0]->dataType == IKS_FLOAT && node->children[1]->dataType == IKS_FLOAT)
    {
        node->dataType = IKS_FLOAT;
    }
    else if(node->children[0]->dataType == IKS_BOOL && node->children[1]->dataType == IKS_BOOL)
    {
        node->dataType = IKS_BOOL;
    }
    else if((node->children[0]->dataType == IKS_FLOAT && node->children[1]->dataType == IKS_INT) || (node->children[0]->dataType == IKS_INT && node->children[1]->dataType == IKS_FLOAT))
    {
        node->dataType = IKS_FLOAT;
    }
    else if((node->children[0]->dataType == IKS_BOOL && node->children[1]->dataType == IKS_INT) || (node->children[0]->dataType == IKS_INT && node->children[1]->dataType == IKS_BOOL))
    {
        node->dataType = IKS_INT;
    }
    else if((node->children[0]->dataType == IKS_BOOL && node->children[1]->dataType == IKS_FLOAT) || (node->children[0]->dataType == IKS_FLOAT && node->children[1]->dataType == IKS_BOOL))
    {
        node->dataType = IKS_FLOAT;
    }
    else
    {
        fprintf(stderr,"\n>>>>>tipo 1: %d, tipo 2: %d", node->children[0]->dataType, node->children[1]->dataType);	
        semanticAnalysisPrintError(IKS_ERROR_WRONG_TYPE,0);
    }
    return node->dataType;
}

int  semanticAnalysisAssignmentCoercion(comp_tree_t* node)
{
    if (node->children[0]->dataType == IKS_INT)
    {
        if (node->children[1]->dataType == IKS_BOOL)
            node->children[1]->coercionType = IKS_INT;
        if (node->children[1]->dataType == IKS_STRING)
           semanticAnalysisPrintError(IKS_ERROR_STRING_TO_X, 0);
        if (node->children[1]->dataType == IKS_CHAR)
           semanticAnalysisPrintError(IKS_ERROR_CHAR_TO_X, 0);
    }

    if (node->children[0]->dataType == IKS_FLOAT)
    {
        if (node->children[1]->dataType == IKS_INT)
            node->children[1]->coercionType = IKS_FLOAT;
        if (node->children[1]->dataType == IKS_BOOL)
            node->children[1]->coercionType = IKS_FLOAT;
        if (node->children[1]->dataType == IKS_STRING)
           semanticAnalysisPrintError(IKS_ERROR_STRING_TO_X, 0);
        if (node->children[1]->dataType == IKS_CHAR)
           semanticAnalysisPrintError(IKS_ERROR_CHAR_TO_X, 0);
    }
    
    if (node->children[0]->dataType == IKS_STRING)
    {
        if (node->children[1]->dataType != IKS_STRING)     
           semanticAnalysisPrintError(IKS_ERROR_WRONG_TYPE,0);
    }
    
    if (node->children[0]->dataType == IKS_CHAR)
    {
        if (node->children[1]->dataType != IKS_CHAR)     
           semanticAnalysisPrintError(IKS_ERROR_WRONG_TYPE,0);
    }
}


void semanticAnalysisArithmeticCoercion(comp_tree_t* node)
{       
    if (node->dataType == IKS_INT)
    {
        if (node->children[0]->dataType == IKS_BOOL)
            node->children[0]->coercionType = IKS_INT;
        if (node->children[1]->dataType == IKS_BOOL)
            node->children[1]->coercionType = IKS_INT;
        if (node->children[0]->dataType == IKS_STRING ||
           node->children[1]->dataType == IKS_STRING)
           semanticAnalysisPrintError(IKS_ERROR_STRING_TO_X, 0);
        if (node->children[0]->dataType == IKS_CHAR   ||
           node->children[1]->dataType == IKS_CHAR)
           semanticAnalysisPrintError(IKS_ERROR_CHAR_TO_X, 0);
    }

    if (node->dataType == IKS_FLOAT)
    {
        if (node->children[0]->dataType == IKS_INT)
            node->children[0]->coercionType = IKS_FLOAT;
        if (node->children[1]->dataType == IKS_INT)
            node->children[1]->coercionType = IKS_FLOAT;
        if (node->children[1]->dataType == IKS_BOOL)
            node->children[1]->coercionType = IKS_FLOAT;
        if (node->children[0]->dataType == IKS_BOOL)
            node->children[0]->coercionType = IKS_FLOAT;
        if (node->children[0]->dataType == IKS_STRING ||
           node->children[1]->dataType == IKS_STRING)
           semanticAnalysisPrintError(IKS_ERROR_STRING_TO_X, 0);
        if (node->children[0]->dataType == IKS_CHAR   ||
           node->children[1]->dataType == IKS_CHAR)
           semanticAnalysisPrintError(IKS_ERROR_CHAR_TO_X, 0);
    }
}

int semanticAnalysisCommandVerification(comp_tree_t* node){
    comp_tree_t** aux;
        
		if(node->type == IKS_AST_RETURN)
		{
		    if(node->children[0]->dataType != node->dataType && node->children[0]->coercionType != node->dataType)
		    {
		        semanticAnalysisPrintError(IKS_ERROR_WRONG_PAR_RETURN, 0);
		        return IKS_ERROR_WRONG_PAR_RETURN;
		    }
		}
		else if(node->type == IKS_AST_INPUT)
		{
        if(node->children[0]->type != IKS_AST_IDENTIFICADOR)
		    {
		        semanticAnalysisPrintError(IKS_ERROR_WRONG_PAR_INPUT, 0);
		        return IKS_ERROR_WRONG_PAR_INPUT;
		    }
		}
		else if(node->type == IKS_AST_OUTPUT)
		{
				aux = node->children;

				while(aux != NULL)
				{
					if((aux[0]->dataType == IKS_STRING) || semanticAnalysisIsArithmeticExpression(aux[0]->type))
					{
						aux = aux[0]->children;
					}
					else
					{
						semanticAnalysisPrintError(IKS_ERROR_WRONG_PAR_OUTPUT, 0);
						return IKS_ERROR_WRONG_PAR_OUTPUT;
					}
				}
		}
}

int semanticAnalysisIsArithmeticExpression(int type)
{
	switch(type){
		case IKS_AST_ARIM_SOMA: 			return 1; break;
		case IKS_AST_ARIM_SUBTRACAO: 		return 1; break;
		case IKS_AST_ARIM_MULTIPLICACAO: 	return 1; break;
		case IKS_AST_ARIM_DIVISAO: 			return 1; break;
		case IKS_AST_ARIM_INVERSAO: 		return 1; break;
		default: 							return 0;
	}
}

int semanticAnalysisParameterVerification(comp_tree_t* node)
{
	if(!node)
		return 0; 
    fprintf(stderr,"\nenter in parameter verification!");
    comp_tree_t *aux1, *aux2;
    if(node->children)
      {
        aux1 = node;
        while(aux1->children)
        {
            printf("\ncomparing %s: ", aux1->children[0]->symbol->data.identifier_type); 
            aux2 = aux1->children[0];
            while(aux2->children) 
            {
              printf(" with %s: , ", aux2->children[0]->symbol->data.identifier_type); 
              if(aux1->children[0]->symbol == aux2->children[0]->symbol)
                semanticAnalysisPrintError(IKS_ERROR_DECLARED,aux2->children[0]->symbol->line_occurrences[0].data);
              aux2 = aux2->children[0];
            }
            aux1 = aux1->children[0];
        }
      }
    fprintf(stderr,"\nleaves in parameter verification!");
    return 1;
}

int semanticAnalysisDeclarationVerification(comp_tree_t* node, int is_declaration)
{
  // local identifier not declared
	if(!is_declaration) 
	{     
      comp_tree_t* aux;
      int found = 0;
      aux = node->scope;
      while(aux->children && !found)
      {
        if(node->symbol == aux->children[0]->symbol)
          found = 1;      
        aux = aux->children[0];  
      }
      if(!node->symbol->is_declared && !found)
          semanticAnalysisPrintError(IKS_ERROR_UNDECLARED, 0);
      else
        //local        
        if(found)
          {
            node->type = aux->type;
            node->dataType = aux->dataType;
            node->size = aux->size;
          }
        //global
        else
          {
            node->type = node->symbol->global->type;
            node->dataType = node->symbol->global->dataType;
            node->size = node->symbol->global->size;
          }
	}

  // identifier already declared as
	else 
	{
    // local
		if(node->scope!=NULL)
		{
      comp_tree_t* aux;
      int found = 0;
      if(node->scope->children)
        {
          aux = node->scope;
          while(aux->children && !found)
          {        
            if(node->symbol == aux->children[0]->symbol)
              found = 1;
            aux = aux->children[0]; 
          }
          if(found)
            {
              printf("1");
	            semanticAnalysisPrintError(IKS_ERROR_DECLARED, node->symbol->line_occurrences[0].data);
              return 0;
            }
        }
      else
        if(node->symbol->is_declared)
          {
            printf("2");
            semanticAnalysisPrintError(IKS_ERROR_DECLARED, node->symbol->line_occurrences[0].data);
            return 0;
          }		
    }
    // global
	  else 
      if (node->symbol->is_declared)
		  {
          printf("\n3 : %d ", node->symbol->is_declared);
		      semanticAnalysisPrintError(IKS_ERROR_DECLARED, node->symbol->line_occurrences[0].data);
          return 0;
		  }
	}
  fprintf(stderr, "\nDeclaration verification [%s]: OK", node->symbol->data.identifier_type);
  return 1;
}

int  semanticAnalysisSetGroupScope(comp_tree_t* node)
{
	if(!node)
		return 0;
    comp_tree_t* aux;
    if(node->children)
      {
        aux = node;
        while(aux->children)
        {
          aux->children[0]->scope = node;       
          aux = aux->children[0];  
        }
      }
     return 1;
}

int  semanticAnalysisInsertLocalVariables(comp_tree_t* scope, comp_tree_t* local_variables)
{
     comp_tree_t* aux = scope;
     while(aux->children) 
      {   
        fprintf(stderr, "\nn filhos: %d, %s ", aux->nbChildren, aux->children[0]->symbol->data.identifier_type);
        aux = aux->children[0];  
      }
     treeAppendNode(aux, local_variables);    
}

int semanticAnalysisSetArgumentList(comp_dict_item_t* symbol, comp_tree_t* node)
{
	if(!symbol || !node)
		return 0;
	
	
    comp_tree_t* aux = node;
    while(aux->children) 
      {
        symbol->nb_arguments++;   
        aux = aux->children[0];
      }
    fprintf(stderr, "\ntudo certo ate aqui!");
    symbol->arguments = node;
    fprintf(stderr, "\nnb arguments = %d\n",symbol->nb_arguments); 
} 

int semanticAnalysisPrintScope(comp_tree_t* scope)
{
    comp_tree_t* aux = scope;
    while(aux->children) 
      {   
        fprintf(stderr, "\nnode: %s ", aux->children[0]->symbol->data.identifier_type);
        aux = aux->children[0];  
      }
} 

int  semanticAnalysisGivenArguments(comp_tree_t* function, comp_tree_t* call_arg_list)
{
  int argument_index = 0;
  comp_tree_t* right_argument;
  comp_tree_t* call_argument = call_arg_list;
    
  if(function->symbol->arguments)
  {    
    right_argument = function->symbol->arguments->children[0];
    printf("\n NUMBER OF EXPECTED ARGUMENTS: %d\n", function->symbol->nb_arguments);

    while(argument_index < function->symbol->nb_arguments)
    {
      if(!call_argument)
        semanticAnalysisPrintError(IKS_ERROR_MISSING_ARGS,0);
		fprintf(stderr,"\nargument verification func %d e call %d",right_argument->dataType, call_argument->dataType);
      if(right_argument->dataType == call_argument->dataType || right_argument->dataType == call_argument->coercionType)
      {
		printf("\nARGUMENT OK\n");
		 
        argument_index++;
        if(right_argument->children)
          right_argument = right_argument->children[0];
       
		if(call_argument->children){
			if(semanticAnalysisIsArithmeticExpression(call_argument->type)){
				if(call_argument->nbChildren > 2)
					call_argument = call_argument->children[2];
				else
					call_argument = NULL;
			}
			else
				call_argument = call_argument->children[0];				
		}
		else
				call_argument = NULL;         
      }
      else 
        semanticAnalysisPrintError(IKS_ERROR_WRONG_TYPE_ARGS,0);     
    }
    if(call_argument){
	  if (semanticAnalysisIsArithmeticExpression(call_argument->parent->type)){
		  printf("\nparametro é expressao aritmetica\n");
	  }
			
	  fprintf(stderr,"\nMais argumentos... arg->type: %d arg->dataType: %d\n", call_argument->parent->type, call_argument->parent->dataType);
      semanticAnalysisPrintError(IKS_ERROR_EXCESS_ARGS,0);
	}
  }
  fprintf(stderr, "\nArgument list verification: OK");
}






