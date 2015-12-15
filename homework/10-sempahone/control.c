#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#include <fcntl.h>
#include <unistd.h>

#include <string.h>
#include <errno.h>

#define SHMSIZE 1000

union semun{
  int val;
  struct semid_ds *buf;
  unsigned short *array;
  struct seminfo *_buf;
};

int main(int argc, char **argv){

  //Check cmd line arg
  //if create: make shared mem, make semaphore, make file
  //if remove: remove shared mem, remove semaphore, display contents of file

  int semkey = ftok("makefile", 21);
  int shmkey = ftok("makefile", 300);
  int shmid;
  int semid;
  int fd;

  if (argc == 1){
    printf("Pass either -c or -r as command line arguments\n");
  }

  else if (strcmp(argv[1], "-c") == 0){
    //create shared mem
    shmid = shmget(shmkey, SHMSIZE, 0644 | IPC_CREAT | IPC_EXCL);
    if (shmid < 0){
      printf("Error %d: %s\n", errno, strerror(errno));
    } else{
      char *line = (char*) shmat(shmid, 0, 0);
      strcpy(line, "");
      shmdt(line);
      printf("Shared Memory Created\n");
    }

    //create semaphore
    semid = semget(semkey, 1, 0644 | IPC_CREAT);
    if (semid < 0){
      printf("Error %d: %s\n", errno, strerror(errno));
    } else {
      printf("Semaphore created\n");
      union semun su;
      su.val = 1;
      semctl(semid, 0, SETVAL, su);
    }

    //create file
    fd = open("telephone.txt", O_CREAT | O_TRUNC, 0644);
    if (fd < 0){
      printf("Error %d: %s\n", errno, strerror(errno));
    } else {
      printf("File created\n");
    }
    close(fd);
  }

  else if (strcmp(argv[1], "-r") == 0){
    //remove shared mem
    shmid = shmget(shmkey, SHMSIZE, 0644);
    int r = shmctl(shmid, IPC_RMID, NULL);
    if (r < 0){
      printf("Error: %s\n", strerror(errno));
    }else{
      printf("Shared Memory removed\n");
    }

    //remove semaphore
    semid = semget(semkey, 1, 0644);
    semctl(semid, 0, IPC_RMID);
    printf("Semaphore removed\n");

    //print file
    printf("The Story:\n");
    char* args[] = {"cat", "telephone.txt", NULL};
    execvp(args[0],args);

  }  else{
    printf("Invalid command line arguemnts\n");
  }

  return 0;

}
