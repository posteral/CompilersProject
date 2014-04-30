#ifndef COMP_TREE_H
#define COMP_TREE_H
#include "comp_dict.h"

/*
    brief:      The structure containing the symbols and its relationships according to the program.
*/
typedef struct comp_tree_t {
	int type;
	int dataType;  
	int coercionType;
	comp_dict_item_t* symbol;
	int nbChildren;
	struct comp_tree_t **children;
} comp_tree_t;

/*
    brief:      Create a node.
    parameters: nbChildren  - number of childrens of this node.    
                type        - type of the symbol contained in this new node.
                symbol      - the symbol added as node.
    return:     Pointer to the created node.
*/
comp_tree_t*  treeCreateNode(int nbChildren, int type, comp_dict_item_t* symbol);

/*
    brief:      Append a node. Append a children node.
    parameters: root        - a pointer to the father node.
                child       - a pointer to the children node.
    return:     Error code.
*/
int           treeAppendNode(comp_tree_t *root, comp_tree_t *child);

/*
    brief:      Insert a children node.
    parameters: root        - a pointer to the father node.
                idx         - .
                type        - the type of the children symbol.
                symbol      - a pointer to the symbol.
    return:     Error code.
*/
int           treeInsertNode(comp_tree_t *root, int idx, int type, comp_dict_item_t* symbol);

/*
    brief:      Edit a node.
    parameters: root        - a pointer to the root of the tree.
                idx         - the id of the node to be edited.
                new_symbol  - a pointer to the new symbol.
*/
void          treeEditNode(comp_tree_t *root, int idx, comp_dict_item_t* new_symbol);

/*
    brief:      Delete a node.
    parameters: root        - a pointer to the root of the tree.
                idx         - the id of the node to be deleted.
*/
void          treeDeleteNode(comp_tree_t *root, int idx);
void          treeFree(comp_tree_t *tree);
void          treePrint(comp_tree_t *tree);

#endif
