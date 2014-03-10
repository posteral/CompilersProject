#include <stdlib.h>
#include <stdio.h>
#include "comp_list.h"

struct comp_list_t_t* listCreate(){
	return NULL;
}

int	listEmpty(struct comp_list_t_t *head){
	return head == NULL;
}


void listPush(struct comp_list_t_t **head, int data){
	
	comp_list_t* current = *head;
	
	if(*head==NULL){
		*head = (comp_list_t*)malloc(sizeof(comp_list_t));
		(*head)->data = data;
		(*head)->next = NULL;
	}
	else{
		while (current->next!=NULL){
			current = current->next;
		}			
		current->next = (comp_list_t*)malloc(sizeof(comp_list_t));
		current->next->data = data;
		current->next->next = NULL;
	}
	
	
}

struct comp_list_t_t *listDelete(struct comp_list_t_t *currP, int data){
	/* See if we are at end of list. */
	if (currP == NULL)
	return NULL;

	/*
	* Check to see if current node is one
	* to be deleted.
	*/
	if (currP->data == data) {
		comp_list_t *tempNextP;

		/* Save the next pointer in the node. */
		tempNextP = currP->next;

		/* Deallocate the node. */
		free(currP);

		/*
		* Return the NEW pointer to where we were called from.  I.e., the 
		* pointer the previous call will use to "skip* over" the removed 
		* node. 
		*/
		return tempNextP;
	}

	/*
	* Check the rest of the list, fixing the next pointer in case the 
	* next node is the one removed.
	*/
	currP->next = listDelete(currP->next, data);

	/*
	* Return the pointer to where we were called from.  Since we did not
	* remove this node it will be the same.
	*/
	return currP;
}

void listPrint(struct comp_list_t_t *head){
	comp_list_t* current = head;
	
	printf("\n");
	while (current != NULL){
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

