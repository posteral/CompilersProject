typedef struct comp_tree_t {
	int *data;
	int nbChildren;
	struct comp_tree_t **children;
} comp_tree_t;

struct comp_tree_t* treeCreateNode(int children, int *data);
int treeAppendNode(comp_tree_t *root, int *data);
int treeInsertNode(comp_tree_t *root, int idx, int *data);
void treeEditNode(comp_tree_t *root, int idx, int *new_data);
void treeDeleteNode(comp_tree_t *root, int idx);
void treeFree(comp_tree_t *tree);
void treePrint(comp_tree_t *tree);
int *createIntData(int data);
