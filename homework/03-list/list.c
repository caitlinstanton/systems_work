#include <stdio.h>;
#include <stdlib.h>;

#include "list.h";

void print_list ( node*n ) {
	printf("[");
	while (n->next != NULL) {
		printf("%i->", n->value);
		n = n->next;
	}
	printf("%i]\n", n->value);
}

node* insert_front ( node*n, int val ) {
	node*added = (node*)malloc(sizeof(node));
	added->value = val;
	added->next = n;
	return added;
}

node* free_list ( node*n ) {
	if (n == NULL) {
		return n;
	}
	free_list(n->next);
	free(n);
	n = NULL;
	return n;
}
