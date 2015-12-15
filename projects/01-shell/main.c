#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

/*
  Notes:
  - cd, if you tab after the filepath, it will give you an error, you can change this!
  - cd ~
  - tab completion ?
  - Custom stuff, create a configurable file -- and so on... -- command to set the configureable file
  - Color -- editable in the tempShell config
*/


/*
  contains
  Find the index of a string in an array of strings

  Parameters: char **command_array, int length, char *c = thing to find in command_array
  Returns: index of c if found, 0 if not found
*/
int contains(char **command_array, int length, char *c) {
  int i = 0;

  for (i = 0; i < length; i++) {
    if (!strcmp(command_array[i], c)) {
      return i;
    }
  }
  return 0;
}

/* 
   file_redirection_parse
   Goes through the possible redirection symbols
   Performs the necessary file redirection

   Parameters: char **command_array, int i = length of command_array
   Returns: void
*/
void file_redirection_parse(char **command_array, int i) {
  int index = -1;
  if (index = contains(command_array, i, ">")) {
    int fd = open(command_array[index + 1], O_CREAT | O_TRUNC | O_RDWR, 0644);
    dup2(fd, STDOUT_FILENO);
    int j = index;
    for (j = index; j < i; j++) {
      command_array[j] = NULL;
    }
    execvp(command_array[0], command_array);
    printf("Unknown command\n");
    exit(0);
  }
  else if (index = contains(command_array, i, ">>")) {
    int fd = open(command_array[index + 1], O_CREAT | O_APPEND | O_RDWR, 0644);
    dup2(fd, STDOUT_FILENO);
    int j = index;
    for (j = index; j < i; j++) {
      command_array[j] = NULL;
    }
    execvp(command_array[0], command_array);
    printf("Unknown command\n");
    exit(0);
  }
  else if (index = contains(command_array, i, "2>")) {
    int fd = open(command_array[index + 1], O_CREAT | O_TRUNC | O_RDWR, 0644);
    dup2(fd, STDERR_FILENO);
    int j = index;
    for (j = index; j < i; j++) {
      command_array[j] = NULL;
    }
    execvp(command_array[0], command_array);
    printf("Unknown command\n");
    exit(0);
  }
  else if (index = contains(command_array, i, "2>>")) {
    int fd = open(command_array[index + 1], O_CREAT | O_APPEND | O_RDWR, 0644);
    dup2(fd, STDERR_FILENO);
    int j = index;
    for (j = index; j < i; j++) {
      command_array[j] = NULL;
    }
    execvp(command_array[0], command_array);
    printf("Unknown command\n");
    exit(0);
  }
  else if (index = contains(command_array, i, "&>")) {
    int fd = open(command_array[index + 1], O_CREAT | O_TRUNC | O_RDWR, 0644);
    dup2(fd, STDERR_FILENO);
    dup2(fd, STDOUT_FILENO);
    int j = index;
    for (j = index; j < i; j++) {
      command_array[j] = NULL;
    }
    execvp(command_array[0], command_array);
    printf("Unknown command\n");
    exit(0);
  }
  else if (index = contains(command_array, i, "&>>")) {
    int fd = open(command_array[index + 1], O_CREAT | O_APPEND | O_RDWR, 0644);
    dup2(fd, STDERR_FILENO);
    dup2(fd, STDOUT_FILENO);
    int j = index;
    for (j = index; j < i; j++) {
      command_array[j] = NULL;
    }
    execvp(command_array[0], command_array);
    printf("Unknown command\n");
    exit(0);
  }
  else if (index = contains(command_array, i, "<")) {
    int fd = open(command_array[index + 1], O_RDONLY);
    dup2(fd, STDIN_FILENO);
    int j = index;
    for (j = index; j < i; j++) {
      command_array[j] = NULL;
    }
    execvp(command_array[0], command_array);
    printf("Unknown command\n");
    exit(0);
  }
  else if (index = contains(command_array, i, "|")) {
    int fd[2];
    pipe(fd);
    if (!fork()) {
      dup2(fd[1], 1);
      int j = index;
      for (j = index; j < i; j++) {
	command_array[j] = NULL;
      }
      execvp(command_array[0], command_array);
      printf("Error in command.");
      exit(0);
    }
    dup2(fd[0], 0);  
    close(fd[1]);
    execvp(command_array[index + 1], &command_array[index + 1]);
  }
}

/* 
   parse_command_helper
   Forks off a child process
   Creates an array from the user input (command and its args)
   If redirection is necessary, calls file_redirection_parse
   The child process runs the command using execvp

   Parameters: char *command = user input
   Returns: void
*/
void parse_command_helper(char *command) {
  int pid = fork();
  if (pid != 0) {
    //Parent
    int status = 1;
    wait(&status);
  }
  else{
     //Child
    char **command_array = (char **)malloc(1000);
    char *command_argument = command;
    char *command_args = command;
    
    command_array[0] = command;
    int i = 0;
    
    while (command_argument = strsep(&command_args, " ")) {
      command_array[i++] = command_argument;
    }
    
    command_array[i] = NULL;

    if (contains(command_array, i, ">") || contains(command_array, i, ">>") || contains(command_array, i, "<") || contains(command_array, i, "<<") || contains(command_array, i, "2>") || contains(command_array, i, "&>") || contains(command_array, i, "2>>") || contains(command_array, i, "&>>") || contains(command_array, i, "|")) {
      file_redirection_parse(command_array, i);
    }
    else {
      execvp(command_array[0], command_array);
      printf("Unknown command\n");
      exit(0);
    }
  }   
}

/* 
   parse_command
   Handles special cases where user input is 'exit'
   Or user input is 'cd'
   Else calls parse_command_helper

   Parameters: char *command = the user input
   Returns: void
*/
void parse_command(char *command) {
  if (!strcmp(command, "exit")) {
    exit(0);
  }
  else if (command[0] == 'c' && command[1] == 'd') {
    char **command_array = (char **)malloc(1000);
    char *command_argument = command;
    char *command_args = command;
    
    command_array[0] = command;
    int i = 0;
    
    while (command_argument = strsep(&command_args, " ")) {
      command_array[i++] = command_argument;
    }
    
    command_array[i] = NULL;
    
    int error = chdir(command_array[1]);
    if (error == -1) {
      printf("Error: %s\n", strerror(errno));
    }
  }
  else {
    parse_command_helper(command);
  }
}

int main() {
  int run = 1;
  while (run) {
    char *command = (char *)malloc(1000);
    char *directory = (char *)malloc(1024);
    if (getcwd(directory, 1024) != NULL) {
      printf("%s $ ", directory);
    }
    fgets(command, 1000, stdin);
    command[strlen(command) - 1] = 0;
    char *command_argument = command;
    char *command_args = command;
    
    while (command_argument = strsep(&command_args, ";")) {
      parse_command(command_argument);
    }
  }
  
  // Cleanup
  
  return 0;
}
