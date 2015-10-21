#include <stdio.h>;
#include <stdlib.h>;

#include "list.h";

int main() {


	//Creating llist (node)
	node* llist = (node*)malloc(sizeof(node));
	llist->value = 0;
	llist->next = NULL;

	//Printing value of llist using print_list
	printf("This is when llist is just one node: \n");
	printf("(Printing with print_list)");
	print_list(llist);

	//Adding values to linked list with insert_front
	int i;
	for (i = 1; i < 5; i++){
		llist = insert_front(llist, i);
	}

	//Printing new linked list with print_list
	printf("After values are added to llist with insert_front: \n");
	printf("(Printing with print_list)");
	print_list(llist);

	printf("Before free_list: \n");
	if (llist == NULL)
		printf("null\n");
	else
		printf("not null\n");
	//Using free_list to free all of the memory in the linked list
	llist = free_list(llist);
	printf("After free_list: \n");
	if (llist == NULL)
		printf("null\n");
	else
		printf("not null\n");

	return 0;

}
