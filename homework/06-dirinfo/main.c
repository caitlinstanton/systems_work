#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>


int main(int num, char *input[]){
  char dir[256];
  if (num == 2){
    strcpy(dir, input[1]);
  } else {
    strcpy(dir, ".");
  }
  printf("%s\n", dir);

  DIR *d = opendir(dir);
  struct dirent *file;
  struct stat stat_buf;
  int total = 0;

  while (file = readdir(d)){
    stat(file->d_name,&stat_buf);
    if(file->d_type == 4 || file->d_type == 0){
      printf("%s\n", file->d_name);
      printf("     Type: %s\n", "directory");
      printf("     Size: %lu\n", stat_buf.st_size);
    } else {
      printf("%s\n",file->d_name);
      printf("     Type: %s\n","file");
      printf("     Size: %lu\n", stat_buf.st_size);
    }
    total = total + stat_buf.st_size;
  }

  printf("Total Size: %i\n", total);

  closedir(d);

  return 0;
}
