#ifndef COMP_TREE_H
#define COMP_TREE_H
#include "comp_dict.h"

/*
    brief:      The structure containing the symbols and its relationships according to the program.
    atributes:  type          - IKS_VARIABLE, IKS_VECTOR, IKS_FUNCTION, IKS_PARAMETER, IKS_SCOPE or IKS_UNDEFINED. 
                size          - size associated to dataType variable.
                dataType      - IKS_INT, IKS_FLOAT, IKS_CHAR, IKS_STRING or IKS_BOOL.
                coercionType  - indicates a coercion to IKS_INT or IKS_FLOAT.
                nbCildren     - number of childrens of the node.
                vectorTypeSize- if the type is IKS_VECTOR, this attribute tells what the size of each element is.
                scope         - tree containing children with variables and parameters of the scope.
                symbol        - input to the symbol table containing the symbol node.
                children      - the children of the node.     
*/
typedef struct comp_tree_t {
	int type;
	int size;
	int dataType;  
	int coercionType;
	int nbChildren;

	const char* labelTrue;
	const char* labelFalse;
	comp_list_t* code;

	struct comp_dict_item_t*  symbol;
	struct comp_tree_t*       scope; 
	struct comp_tree_t**      children;
	struct comp_tree_t*		  parent;
} 	comp_tree_t;

/*
    brief:      Create a node.
    parameters: type        - type of the symbol contained in this new node.
                symbol      - the symbol added as node.
    return:     Pointer to the created node.
*/
comp_tree_t*  treeCreateNode(int type, comp_dict_item_t* symbol);

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

int	          treeSetSize(comp_tree_t *node, int type);

int 		  treeSetSizeVector(comp_tree_t *node, int type, int length);

int 		  treeDepthSearch(comp_tree_t *node);

void          treePrintElementData(comp_dict_item_t *symbol);

#endif
