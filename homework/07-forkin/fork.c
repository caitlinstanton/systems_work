#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

int make_it_rand() {

	int fd = open("/dev/random", O_RDONLY);
	if (fd < 0) {
		printf("Error %d: %s\n", errno, strerror(errno));
		return errno;
	}

	int rand;
	read(fd,&rand,4);
	close(fd);

	if (rand < 0) {
		rand = rand * -1;
	}

	return rand;

}

int main() {

	int child_a, child_b;
	int delayed,status,num;

	printf("PID: %d\n",getpid());
	printf("Parent PID: %d\n",getppid());

	printf("PRE-FORKING:\n");
	printf("\n");

	child_a = fork();

	if (child_a < 0) {
		printf("Error %d: %s\n", errno, strerror(errno));
		return errno;
	}
	//num = 1;
	child_b = -1;

	if (child_a == 0) {
		child_b = fork();
		if (child_b < 0) {
			printf("Error %d: %s\n",errno, strerror(errno));
			return errno;
		}
		//num = 2;
	}

	if (!child_a && child_b) {
 		/* First Child */
		printf("[Child 1] PID: %d\n", getpid());
                delayed = make_it_rand() % 16 + 5;
                printf("[Child 1] Waiting for %i seconds\n",delayed);
                sleep(delayed);
                printf("[Child 1] DONE\n");

	}
	if (!child_b) {
		/* Second Child */
		printf("[Child 2] PID: %d\n", getpid());
		delayed = make_it_rand() % 16 + 5;
		printf("[Child 2] Waiting for %i seconds\n",delayed);
		sleep(delayed);
		printf("[Child 2] DONE\n");
	}
	if (child_a || child_b) {
		/* Parent */
		printf("[Parent] Waiting for child processes\n");
		num = wait(&status);
		printf("[Parent] Child with PID %i exited\n",num);
		printf("Exit status: %d\n",WEXITSTATUS(status));
    	}

	return 0;

}
