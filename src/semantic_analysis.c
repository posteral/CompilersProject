#include "semantic_analysis.h"
#include <stdio.h>
#include <stdlib.h>

void semanticAnalysisPrintError(int error_code, int line){
	switch(error_code)
    {
            case IKS_ERROR_UNDECLARED: printf("Semantic error in line %d: Identifier not declared in this scope\n", getLineNumber());break;
            case IKS_ERROR_DECLARED: printf("Semantic error in line %d: Identifier already declared in line %d\n", getLineNumber(),line);break;
            case IKS_ERROR_VARIABLE: printf("Semantic error in line %d: Misuse of variable declared in line %d\n", getLineNumber(), line);break;
            case IKS_ERROR_VECTOR: printf("Semantic error in line %d: Misuse of vector declared in line %d\n", getLineNumber(), line);break;
            case IKS_ERROR_FUNCTION: printf("Semantic error in line %d: Misuse of function declaration in line %d\n", getLineNumber(), line);break;
            case IKS_ERROR_MISSING_ARGS: printf("Semantic error in line %d: Missing arguments in function declared in line %d\n", getLineNumber(), line);break;
            case IKS_ERROR_EXCESS_ARGS: printf("Semantic error in line %d: Too many arguments in function declared in line %d\n", getLineNumber(), line);break;
            case IKS_ERROR_WRONG_TYPE_ARGS:printf("Semantic error in line %d: Incompatible arguments in function declared in line %d\n", getLineNumber(), line);break;
            case IKS_ERROR_WRONG_PAR_RETURN: printf("Semantic error in line %d: Return type is different than the one defined for the function.\n", getLineNumber()); break;
            case IKS_ERROR_WRONG_PAR_INPUT: printf("Semantic error in line %d: input parameter is not an identifier.\n", getLineNumber()); break;
            case IKS_ERROR_WRONG_PAR_OUTPUT: printf("Semantic error in line %d: output parameter is not a string or arithmetic expression.\n", getLineNumber()); break;
            case IKS_ERROR_CHAR_TO_X: printf("Semantic error in line %d: it's not possible  to convert a char.\n", getLineNumber()); break;
            case IKS_ERROR_STRING_TO_X: printf("Semantic error in line %d: it's not possible to convert a string.\n", getLineNumber()); break;
            case IKS_ERROR_WRONG_TYPE: printf("Semantic error in line %d: incompatible types.\n", getLineNumber()); break;
    }

    if(error_code != IKS_SUCCESS)
	{
	    exit(error_code);
	}
}

/*int semanticAnalysisIdentifierVerification(comp_tree_t* node, int struct_type){
	if(!symbol->data.identifier_type.is_declared)
	{
	   semanticAnalysisPrintError(IKS_ERROR_UNDECLARED, symbol->line_occurrences->data);
	}
	
	else if(symbol->data.identifier_type.struct_type != struct_type)
	{
		if(symbol->data.identifier_type.struct_type == IKS_VARIABLE)
		{
		    semanticAnalysisPrintError(IKS_ERROR_VARIABLE, symbol->line_occurrences->data);
		}
		else if(symbol->data.identifier_type.struct_type == IKS_VECTOR)
		{
		    semanticAnalysisPrintError(IKS_ERROR_VECTOR, symbol->line_occurrences->data);
		}
		else if(symbol->data.identifier_type.struct_type == IKS_FUNCTION)
		{
		    semanticAnalysisPrintError(IKS_ERROR_FUNCTION, symbol->line_occurrences->data);
		}
	}
	else
	{
        return IKS_SUCCESS;
	}
}*/

int  semanticAnalysisTypeInference(comp_tree_t* node)
{
    if(node->children[0]->dataType == IKS_INT && node->children[1]->dataType == IKS_INT)
    {
        return IKS_INT;
    }
    else if(node->children[0]->dataType == IKS_FLOAT && node->children[1]->dataType == IKS_FLOAT)
    {
        return IKS_FLOAT;
    }
    else if(node->children[0]->dataType == IKS_BOOL && node->children[1]->dataType == IKS_BOOL)
    {
        return IKS_BOOL;
    }
    else if((node->children[0]->dataType == IKS_FLOAT && node->children[1]->dataType == IKS_INT) || (node->children[0]->dataType == IKS_INT && node->children[1]->dataType == IKS_FLOAT))
    {
        return IKS_FLOAT;
    }
    else if((node->children[0]->dataType == IKS_BOOL && node->children[1]->dataType == IKS_INT) || (node->children[0]->dataType == IKS_INT && node->children[1]->dataType == IKS_BOOL))
    {
        return IKS_INT;
    }
    else if((node->children[0]->dataType == IKS_BOOL && node->children[1]->dataType == IKS_FLOAT) || (node->children[0]->dataType == IKS_FLOAT && node->children[1]->dataType == IKS_BOOL))
    {
        return IKS_FLOAT;
    }
}

void semanticAnalysisArithmeticCoercion(comp_tree_t* node)
{
    if (node->dataType == IKS_INT)
    {
        if ( node->children[0]->dataType == IKS_BOOL)
        {
            node->children[0]->coercionType = IKS_INT;
        }
        if (node->children[1]->dataType == IKS_BOOL)
        {
            node->children[1]->coercionType = IKS_INT;
        }
    }

    if (node->dataType == IKS_FLOAT)
    {
        if ( node->children[0]->dataType == IKS_INT)
        {
            node->children[0]->coercionType = IKS_FLOAT;
        }
        if (node->children[0]->dataType == IKS_INT)
        {
            node->children[0]->coercionType = IKS_FLOAT;
        }
        if ( node->children[1]->dataType == IKS_BOOL)
        {
            node->children[1]->coercionType = IKS_FLOAT;
        }
        if (node->children[1]->dataType == IKS_BOOL)
        {
            node->children[0]->coercionType = IKS_FLOAT;
        }
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
					if((aux[0]->dataType == IKS_STRING) || isArithmeticExpression(aux[0]->type))
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

int isArithmeticExpression(int type)
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

int semanticAnalysisParameterVerification(comp_tree_t* identifier_node, comp_tree_t* call_node)
{
}

int semanticAnalysisDeclarationVerification(comp_tree_t* node, int is_declaration){
  // global identifier not declared
	if(!is_declaration && node->scope == NULL && !node->symbol->is_declared) 
	{
	    semanticAnalysisPrintError(IKS_ERROR_UNDECLARED, 0);
	}
  // local identifier not declared
	if(!is_declaration && node->scope != NULL) 
	{
      comp_tree_t* aux;
      int found = 0;
      if(node->scope->nbChildren)
        {
          aux = node->scope;
          while(aux->nbChildren && !found)
          {
            if(node->symbol == aux->children[0]->symbol)
              found = 1;
            
            aux = aux->children[0];  
          }
          if(!found)
	          semanticAnalysisPrintError(IKS_ERROR_UNDECLARED, 0);
        }
      else
        if(!node->symbol->is_declared)
          semanticAnalysisPrintError(IKS_ERROR_UNDECLARED, 0);
	}

  // identifier already declared as
	if(is_declaration) 
	{
    // local
		if(node->scope!=NULL)
		{
       comp_tree_t* aux;
      int found = 0;
      if(node->scope->nbChildren)
        {
          aux = node->scope;
          while(aux->nbChildren && !found)
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
  return 1;
}

