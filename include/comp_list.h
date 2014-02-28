typedef struct comp_list_t {
	int data;
	struct comp_list_t* nextNode;
	struct comp_list_t* previousNode;
} comp_list_t;

comp_list_t* listCreate();
