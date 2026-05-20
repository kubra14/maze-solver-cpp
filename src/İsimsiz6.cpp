typedef struct node BTREE;
BTREE *new_node(int data) {
BTREE *p = (BTREE*) malloc(sizeof(BTREE));
// BTREE *p = new node(); // C++'ta bu þekilde
p -> data = data;
p -> left = NULL;
p -> right = NULL;
return p;
}
