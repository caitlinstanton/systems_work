#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

#define SHMSIZE 1000

int main() {

  int semkey = ftok("makefile", 21);
  int semid, shmkey, shmid, fd;
  int *size;
  char buf[100];

  union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *__buf;
  };

  semid = semget(semkey, 1, 0644 | IPC_CREAT);

  //Sets sem_op to take one semaphore
  struct sembuf sb;
  sb.sem_op = -1;
  sb.sem_flg = SEM_UNDO;
  semop(semid, &sb, 1);
  printf("Access Granted\n");

  //Accesses shared memory
  shmkey = ftok("makefile", 300);
  shmid = shmget(shmkey, SHMSIZE, 0644 | IPC_CREAT);
  size = shmat(shmid, 0, 0);

  //Opens telephone.txt (story file)
  fd = open("telephone.txt", O_RDWR | O_APPEND,0644);
  if (fd < 0) {
    printf("Error %d: %s\n", errno, strerror(errno));
    sb.sem_op = 1;
    semop(semid, &sb, 1);
    exit(0);
  }

  //Reads last line if there is anything in the file
  //Asks to start the story if the file is empty
  if ((*size) > 0) {
    char *buf = malloc(SHMSIZE);
    lseek(fd, -(*size), SEEK_END);
    read(fd, buf,(*size));
    printf("The Story So Far:\n%s\n",buf);
  } else {
    printf("Start the story!\n");
  }

  //Adding a new line to the story
  printf("What do you want to say?\n");
  char *line = malloc(256);
  fgets(line, SHMSIZE, stdin);

  //Shows the size of the last line written
  (*size) = write(fd, line, strlen(line));
  printf("\nBytes written: %d\n", (*size));

  //Exiting the story
  close(fd);
  sb.sem_op = 1;
  semop(semid,&sb,1);
  printf("\nDone writing\n");

  return 0;

}
