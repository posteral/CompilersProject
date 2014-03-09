typedef struct comp_tree_t {
	int id;
	int nbChildren;
	struct comp_tree_t *children[];
} comp_tree_t;

struct comp_tree_t* treeCreate();
bool treeIsEmpty(comp_tree_t *tree);
comp_tree_t* treeCreate(void);
void treeAddNode(comp_tree_t *root);
void treeRemoveNode(comp_tree_t *root)
