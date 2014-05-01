#include <stdio.h>
#include <stdlib.h>
#include "comp_tree.h"

comp_tree_t* treeCreateNode(int type, comp_dict_item_t* symbol){
	comp_tree_t *newNode  = (comp_tree_t*)malloc(sizeof(comp_tree_t));
  newNode->nbChildren   = 0;
	newNode->type         = type;
	newNode->symbol       = symbol;
  newNode->children     = NULL;

	return newNode;
}

int treeAppendNode(comp_tree_t *root, comp_tree_t *child)
{
    if(root && child)
    {
      root->nbChildren++;
      root->children = (comp_tree_t**)realloc(root->children,(root->nbChildren)*sizeof(comp_tree_t*));
      root->children[root->nbChildren-1] = child;
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
		case IKS_INT 	  :	node->size = IKS_INT_SIZE; break;
		case IKS_FLOAT 	:	node->size = IKS_FLOAT_SIZE; break;
		case IKS_CHAR 	:	node->size = IKS_CHAR_SIZE; break;
		case IKS_STRING	:	node->size = IKS_STRING_SIZE; break;
		case IKS_BOOL	  :	node->size = IKS_BOOL_SIZE; break;
	}
	
  return node->size;
}

treeSetSizeVector(comp_tree_t *node, int type, int length){
  switch(type)
  {
		case IKS_INT 	  :	node->size = IKS_INT_SIZE*length; break;
		case IKS_FLOAT 	:	node->size = IKS_FLOAT_SIZE*length; break;
		case IKS_CHAR 	:	node->size = IKS_CHAR_SIZE*length; break;
		case IKS_STRING	:	node->size = IKS_STRING_SIZE*length; break;
		case IKS_BOOL	  :	node->size = IKS_BOOL_SIZE*length; break;
	}
	
  return node->size;

}
