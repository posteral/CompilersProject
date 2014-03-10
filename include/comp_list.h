typedef struct comp_list_t_t {
	int data;
	struct comp_list_t_t* next;
} comp_list_t;

struct comp_list_t_t *listCreate();
int		listEmpty(struct comp_list_t_t *head);
void	listPush(struct comp_list_t_t  **head, int data);
struct comp_list_t_t *listDelete(struct comp_list_t_t *head, int data);
void	listPrint(struct comp_list_t_t *head);
