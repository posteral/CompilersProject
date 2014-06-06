#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
void listPushCode(struct comp_list_t_t **head, const char *code){
	
	comp_list_t* current = *head;
	
	if(*head==NULL){
		*head = (comp_list_t*)malloc(sizeof(comp_list_t));
		strcpy((*head)->code,code);
		(*head)->next = NULL;
	}
	else{
		while (current->next!=NULL){
			current = current->next;
		}			
		current->next = (comp_list_t*)malloc(sizeof(comp_list_t));
		strcpy(current->next->code,code);
		current->next->next = NULL;
	}	
}

void listDelete(struct comp_list_t_t *head)
{
	
	comp_list_t *next, *deleteMe;
  	deleteMe = head;
  	while (deleteMe) {
    		next = deleteMe->next;
    		free(deleteMe);
    		deleteMe = next;
 	 }	

}

struct comp_list_t_t *listDeleteElement(struct comp_list_t_t *currP, int data){
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
	currP->next = listDeleteElement(currP->next, data);

	/*
	* Return the pointer to where we were called from.  Since we did not
	* remove this node it will be the same.
	*/
	return currP;
}

void listPrint(struct comp_list_t_t *head){
	comp_list_t* current = head;
	if(current!=NULL){
		fprintf(stderr, "%s\n", current->code);
		current = current->next;
	}
	fprintf(stderr,"\n");
	while (current != NULL){
		fprintf(stderr, "%s\n", current->code);
		current = current->next;
	}
	fprintf(stderr,"\n");
}

comp_list_t* listAdd(const char* code, comp_list_t* head){
	comp_list_t* newItem = malloc(sizeof(comp_list_t*));
	strcpy(newItem->code, code);
	if(head != NULL)
	{
		head->prev->next = newItem;
		newItem->prev = head->prev;
		head->prev = newItem;
		newItem->next = head;
		return head;
	}
	else
	{
		newItem->next = newItem;
		newItem->prev = newItem;
		return newItem;
	}
}

comp_list_t* listConcatenate(comp_list_t* list1, comp_list_t* list2){	
	if(list1 != NULL && list2 != NULL)
	{
		comp_list_t* last = list1;
		while (last->next != NULL)
			last = last->next;
		last->next=list2;
		list2->prev=last;
		return list1;
	}
	else if(list1 == NULL)
	{
		return list2;
	}
	else if(list2 == NULL)
	{
		return list1;
	}
}
