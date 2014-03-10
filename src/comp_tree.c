#include <stdio.h>
#include <stdlib.h>
#include "comp_tree.h"

//initializes tree
struct comp_tree_t* treeCreate(){
	comp_tree_t *newTree = NULL;
	return newTree;
}

//checks if tree is empty
int treeIsEmpty(comp_tree_t *tree){
	return tree == NULL;
}
	
void treeAddNode(comp_tree_t *root){
     /*comp_tree_t * new_node;
	 new_node = malloc(sizeof(comp_tree_t));
	 new_node->nbChildren = 0; 
     new_node->children = NULL;  
     
     //Empty tree:
     if(root == NULL) 
     {
             new_node->id = 0;
             root = new_node;             
	 }
	else
	{
        new_node->id = root->nbChildren;
        root->children[new_node->id] = new_node;       
        root->nbChildren++;
	}   
	*/  
}

void treeRemoveNode(comp_tree_t *root){
	/*
    // Empty node:
    if(root == NULL)
    {
 	   printf("WARNING: Node doesn't exist!");
    }
    else
    {
        // Leaf node:
    	if(root->children == NULL) 
    	{
    		free(root); 
    		root = NULL;
    	}
    	else
    	{
            int child_index = 0
			comp_tree_t *tmp_node = root->children[child_index]; 
			// Removing childrens:
			while(tmp_node != NULL)
			{
				if(tmp_node->children != NULL)
					treeRemoveNode(tmp_descriptor->children); 
					
				last_node = tmp_node; 
				child_index++;
				tmp_node = root->children[child_index]; 
				
				if(last_node != NULL)
					free(last_node); 
				last_node = NULL; 
			}
			if(root != NULL)
				free(root); 
    	}
    }
    */
    
}
