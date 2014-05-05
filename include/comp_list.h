#ifndef COMP_LIST_H
#define COMP_LIST_H

typedef struct comp_list_t_t {
	int symbol_type;
	int data;
	struct comp_list_t_t* next;
} comp_list_t;

struct comp_list_t_t *listCreate();
int		listEmpty(struct comp_list_t_t *head);
void	listPush(struct comp_list_t_t  **head, int data);
struct comp_list_t_t *listDeleteElement(struct comp_list_t_t *head, int data);
void listDelete(struct comp_list_t_t *head);
void	listPrint(struct comp_list_t_t *head);

#endif
