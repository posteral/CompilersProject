#ifndef COMP_TREE_H
#define COMP_TREE_H
#include "comp_dict.h"

typedef struct comp_tree_t {
	int type;
	comp_dict_item_t* symbol;
	int nbChildren;
	struct comp_tree_t **children;
} comp_tree_t;

comp_tree_t *ast;

comp_tree_t*  treeCreateNode(int nbChildren, int type, comp_dict_item_t* symbol);
int           treeAppendNode(comp_tree_t *root, comp_tree_t *child);
int           treeInsertNode(comp_tree_t *root, int idx, int type, comp_dict_item_t* symbol);
void          treeEditNode(comp_tree_t *root, int idx, comp_dict_item_t* new_symbol);
void          treeDeleteNode(comp_tree_t *root, int idx);
void          treeFree(comp_tree_t *tree);
void          treePrint(comp_tree_t *tree);
int*          createIntData(int data);

#endif
