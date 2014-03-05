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
		//printf("\noi");
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

void listPrint(struct comp_list_t_t *head){
	comp_list_t* current = head;
	
	printf("\n");
	while (current != NULL){
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

