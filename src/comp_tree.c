#include <stdio.h>
#include <stdlib.h>
#include "comp_tree.h"
#include "iloc.h"

comp_tree_t* treeCreateNode(int type, comp_dict_item_t* symbol){
	comp_tree_t *newNode  = (comp_tree_t*)malloc(sizeof(comp_tree_t));
	newNode->nbChildren   = 0;
	newNode->type         = type;
	newNode->symbol       = symbol;
	newNode->children     = NULL;
	newNode->parent		  = NULL;

	return newNode;
}

int treeAppendNode(comp_tree_t *root, comp_tree_t *child)
{
    if(root && child)
    {
      root->nbChildren++;
      root->children = (comp_tree_t**)realloc(root->children,(root->nbChildren)*sizeof(comp_tree_t*));
      root->children[root->nbChildren-1] = child;
      child->parent = root;
      return root->nbChildren - 1;
    }
    return 0;
}

int treeInsertNode(comp_tree_t *root, int idx, int type, comp_dict_item_t* symbol)
{
    unsigned i;
    root->nbChildren++;
    if(idx > root->nbChildren)
    {
     //printf("\nWARNING: Invalid node index!");
    }
    else
    {
     root->children = (comp_tree_t**)realloc(root->children,(root->nbChildren)*sizeof(comp_tree_t*));
     for( i=root->nbChildren-1; i>idx ; --i)
          root->children[i] = root->children[i-1];
     root->children[i] = treeCreateNode(type,symbol);
     //printf("\nNOTE: Node inserted on the position %d with symbom ", idx);
     dictGetData(root->children[i]->symbol);
    }
    return i ;
}

void treeEditNode(comp_tree_t *root, int idx, comp_dict_item_t* new_symbol)
{
     if(root->children[idx])
     {
      free(root->children[idx]->symbol);
      root->children[idx]->symbol = new_symbol;
     }
     //else
         //printf("\nWARNING: This node doesn't exist!");
}

void treeDeleteNode(comp_tree_t *root, int idx)
{
   unsigned i ;
   if(root->children[idx])
     {
      treeFree(root->children[idx]);
      for( i=idx ; i<root->nbChildren-1 ; ++i)
           root->children[i] = root->children[ i - 1 ] ;
      root->nbChildren--;
      root->children = (comp_tree_t**)realloc(root->children,(root->nbChildren)*sizeof(comp_tree_t*));
     }
   //else
       //printf("\nWARNING: This node doesn't exist!");
}

void treeFree(comp_tree_t *tree)
{
   unsigned i ;
   if(tree == NULL) return ;

   for( i=0 ; i<tree->nbChildren ; ++i )
   {
        treeFree(tree->children[i]);
   }
   
   free(tree->children);
   free(tree->symbol);
   free(tree);
}

void treePrint(comp_tree_t *tree)
{
 unsigned i;
 if(tree->symbol)
 {
  dictGetData(tree->children[i]->symbol);
 }
 if(tree->nbChildren)
                     printf("\nNew level: ");
 for( i=0 ; i<tree->nbChildren ; ++i )
 {
  treePrint(tree->children[i]);
 }
}

int	treeSetSize(comp_tree_t *node, int type){

	switch(type)
	{
		case IKS_INT 	  	:	node->size = IKS_INT_SIZE; break;
		case IKS_FLOAT 		:	node->size = IKS_FLOAT_SIZE; break;
		case IKS_CHAR 		:	node->size = IKS_CHAR_SIZE; break;
		case IKS_STRING		:	node->size = IKS_STRING_SIZE; break;
		case IKS_BOOL	  	:	node->size = IKS_BOOL_SIZE; break;
	}
	
	node->symbol->offset = offsetGlobal;
  offsetGlobal += node->size;
	return node->size;
}

int treeSetSizeVector(comp_tree_t *node, int type, int length){
  switch(type)
  {
		case IKS_INT 	  :	{ node->size = IKS_INT_SIZE*length; 
                        node->symbol->vectorTypeSize = IKS_INT_SIZE;
                        break;}
		case IKS_FLOAT 	:	{ node->size = IKS_FLOAT_SIZE*length; 
                        node->symbol->vectorTypeSize = IKS_FLOAT_SIZE;
                        break;}
		case IKS_CHAR 	:	{ node->size = IKS_CHAR_SIZE*length; 
                        node->symbol->vectorTypeSize = IKS_CHAR_SIZE;
                        break;}
		case IKS_STRING	:	{ node->size = IKS_STRING_SIZE*length; 
                        node->symbol->vectorTypeSize = IKS_STRING_SIZE;
                        break;}
		case IKS_BOOL	  :	{ node->size = IKS_BOOL_SIZE*length; 
                        node->symbol->vectorTypeSize = IKS_BOOL_SIZE;
                        break;}
	}
	
  node->symbol->offset = offsetGlobal;
  offsetGlobal += node->size;
  return node->size;

}

int treeDepthSearch(comp_tree_t *node){
	if(node == NULL)
		fprintf(stderr,"Error: The tree is null.");
	if(node->nbChildren >0){
	int i;
	for(i=0; i<node->nbChildren;i++)
		treeDepthSearch(node->children[i]);
	if(node->symbol)	
		treePrintElementData(node->symbol);
	fprintf(stderr," comando: %d ",node->type);
	}
	else
		if(node->symbol)
			treePrintElementData(node->symbol);
	return 0;
}

void          treePrintElementData(comp_dict_item_t *symbol){
	switch(symbol->type){
                              case IKS_SIMBOLO_INDEFINIDO: 
                                   fprintf(stderr," %s ", symbol->data.undefined_type);
                                   break; 
                              case IKS_SIMBOLO_LITERAL_INT:
                                   fprintf(stderr," %d ", symbol->data.int_type);
                                   break;   
                              case IKS_SIMBOLO_LITERAL_FLOAT:
                                   fprintf(stderr," %f ", symbol->data.float_type);
                                   break;
                              case IKS_SIMBOLO_LITERAL_CHAR:
                                   fprintf(stderr," %c ", symbol->data.char_type);
                                   break;
                              case IKS_SIMBOLO_LITERAL_STRING:
                                   fprintf(stderr," %s ", symbol->data.string_type);
                                   break;
                              case IKS_SIMBOLO_LITERAL_BOOL: 
                                   fprintf(stderr," %d ", symbol->data.int_type);
                                   break;
                              case IKS_SIMBOLO_IDENTIFICADOR:
                                   fprintf(stderr," %s ", symbol->data.identifier_type);
                                   break;
                              default:
                                  fprintf(stderr," other type ");
                                   
     }                       
}











