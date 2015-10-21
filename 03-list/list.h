typedef struct node { int value; struct node* next; } node;

void print_list ( node* n );

node* insert_front ( node* n, int a );

node* free_list ( node* n );
