typedef struct comp_tree_t {
	int id;
	struct comp_tree_t *children[];
} comp_tree_t;

comp_tree_t* treeCreate(void);

int treeEmpty(comp_tree_t *tree);
comp_tree_t* treeCreate(void);
void treeAddNode(comp_tree_t *root);
