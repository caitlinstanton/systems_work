#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main() {

	printf("What process do you want to run?\n");
	char input[100];
	fgets(input, sizeof(input), stdin);
	printf("You've shown that you want to run %s\n",input);

	printf("Confirm whether you want to run this process\n");
	printf("Type 'yes' or 'no'\n");
	char check[100];
	char *response;
	response = fgets(check, sizeof(check), stdin);

	if (strcmp(response,"yes") >= 0) {
		printf("Running process\n");
		char *placeholder = input;
		char *pointers[10];
		int i = 0;
		while(placeholder) {
			pointers[i] = strsep(&placeholder, " ");
			i++;
		}

		char *tmp = pointers[i - 1];
		pointers[i - 1] = strsep(&tmp, "\n");
		pointers[i] = NULL;
		errno = execvp(pointers[0],pointers);
		if (errno < 0) {
			printf("Error %d: %s\n", errno, strerror(errno));
		}
	} else {
		printf("Okay cool, whatever you want\n");
	}
	return 0;

}
