#ifndef COMP_LIST_H
#define COMP_LIST_H

typedef struct comp_list_t_t {
	int symbol_type;
	int data;
	
	char code[1000];
	char reg[1000];
	int dimension;
	char* label;
	char* command;
	char* operators[3];
	struct comp_list_t_t *next;
	struct comp_list_t_t *prev;
} comp_list_t;

comp_list_t *listCreate();
int			listEmpty(struct comp_list_t_t *head);
void		listPush(struct comp_list_t_t  **head, int data);
void listPushCode(struct comp_list_t_t **head, const char *code);
comp_list_t *listDeleteElement(struct comp_list_t_t *head, int data);
void 		listDelete(struct comp_list_t_t *head);
void		listPrint(struct comp_list_t_t *head);
comp_list_t *listAdd(const char* code, comp_list_t* head);
comp_list_t *listConcatenate(comp_list_t* list1, comp_list_t* list2);

#endif
