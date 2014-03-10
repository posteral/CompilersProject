#include <stdio.h>
#include <stdlib.h>
#include "comp_tree.h"

struct comp_tree_t* treeCreateNode(int children, int *data)
{
      comp_tree_t *new_node = (comp_tree_t*)calloc(1,sizeof(comp_tree_t)) ;
      new_node->data = data;
      new_node->nbChildren = children;
      new_node->children = (comp_tree_t**)calloc(children, sizeof(comp_tree_t*));
      return new_node;
}

int treeAppendNode(comp_tree_t *root, int *data)
{
    root->nbChildren++;
    root->children = (comp_tree_t**)realloc(root->children,(root->nbChildren)*sizeof(comp_tree_t*));
    root->children[root->nbChildren-1] = treeCreateNode(0,data);
    printf("\nNOTE: Node with data %d was appended!", *root->children[root->nbChildren-1]->data);
    return root->nbChildren - 1;
}

int treeInsertNode(comp_tree_t *root, int idx, int *data)
{
    unsigned i;
    root->nbChildren++;
    if(idx > root->nbChildren)
    {
     printf("\nWARNING: Invalid node index!");
    }
    else
    {
     root->children = (comp_tree_t**)realloc(root->children,(root->nbChildren)*sizeof(comp_tree_t*));
     for( i=root->nbChildren-1; i>idx ; --i)
          root->children[i] = root->children[i-1];
     root->children[i] = treeCreateNode(0,data);
     printf("\nNOTE: Node with data %d was inserted on the position %d!", *root->children[i]->data, idx);
    }
    return i ;
}

void treeEditNode(comp_tree_t *root, int idx, int *new_data)
{
     if(root->children[idx])
     {
      free(root->children[idx]->data);
      root->children[idx]->data = new_data;
     }
     else
         printf("\nWARNING: This node doesn't exist!");
}

//Not working
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
   else
       printf("\nWARNING: This node doesn't exist!");
}

//Not working
void treeFree(comp_tree_t *tree)
{
   unsigned i ;
   if(tree == NULL) return ;

   for( i=0 ; i<tree->nbChildren ; ++i )
   {
        treeFree(tree->children[i]);
   }
   
   free(tree->children);
   free(tree->data);
   free(tree);
}

void treePrint(comp_tree_t *tree)
{
 unsigned i;
 if(tree->data)
 {
  printf("\n%d", *tree->data);
 }
 if(tree->nbChildren)
                     printf("\nNew level: ");
 for( i=0 ; i<tree->nbChildren ; ++i )
 {
  treePrint(tree->children[i]);
 }
}

int *createIntData(int data)
{
 int *ptr = (int*)calloc(1,sizeof(int));
 *ptr = data;
 return ptr;
}
