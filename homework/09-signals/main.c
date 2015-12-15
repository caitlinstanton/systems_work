#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>

static void sighandler (int signo) {
	int status,fd,child,fd2,readwho,readps;
	if (signo == SIGUSR1) {	//SIGUSER1 --> 10
		fd = open("who.txt",O_CREAT | O_APPEND | O_WRONLY,0644);
		child = fork();
		if (!child) {
			//Code for child fork
			dup2(fd,STDOUT_FILENO);
			execlp("who","who",NULL);
		} else {
			//Code for parent
			status = 1;
			wait(&status);
			close(fd);
		}
	} else if (signo == SIGUSR2) {	//SIGUSR2 --> 12
		fd = open("ps.txt",O_CREAT | O_APPEND | O_WRONLY,0644);
		child = fork();
		if (!child) {
			//Code for child fork
			dup2(fd,STDOUT_FILENO);
			execlp("ps","ps",NULL);
		} else {
			//Code for parent
			status = 1;
			wait(&status);
			close(fd);
		}
	} else if (signo == SIGINT) {	//SIGINT --> 2
		fd = open("who.txt",O_RDONLY);
		fd2 = open("ps.txt",O_RDONLY);
		char buffwho[1000];
		readwho = read(fd,buffwho,sizeof(buffwho));
		close(fd);
		printf("who\n%s\n",buffwho);
		char buffps[1000];
		readps = read(fd2,buffps,sizeof(buffps));
		close(fd2);
		printf("ps\n%s\n",buffps);
		exit(0);
	}
}

int main() {
	signal(SIGUSR1,sighandler);
	signal(SIGUSR2,sighandler);
	signal(SIGINT,sighandler);
	while (1) {
		printf("Hi! I'm [PID] %d\n",getpid());
		sleep(2);
	}
	return 0;
}
