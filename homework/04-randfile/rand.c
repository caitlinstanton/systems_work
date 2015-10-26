#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int generate_rand() {
  int randdata = open("/dev/random",O_RDONLY,0444);
  if (randdata == -1) {
    printf("Error %d - %s\n",errno,strerror(errno));
    return errno;
  }

  int buff = 0;
  int randread = read(randdata,&buff,sizeof(buff));
  if (randread == -1) {
    printf("Error %d - %s\n",errno,strerror(errno));
    return errno;
  }
  close(randdata);

  return buff;
}

int main() {

  printf("TEST -- Print an int of 4 bytes: %u \n\n",generate_rand());

  int randdata = open("array.txt", O_CREAT | O_WRONLY, 0644);
  if (randdata == -1) {
    printf("Error %d - %s\n",errno,strerror(errno));
    return errno;
  }

  printf("Random numbers generated in nums[]\n");
  int nums[10];
  int i = 0;
  for (; i < 10; i++) {
    nums[i] = generate_rand();
    write(randdata, &nums[i], 4);
    if (errno) {
      printf("Error %d - %s\n",errno,strerror(errno));
      return errno;
    }
    printf("Value %d: %d\n", i, nums[i]);
  }
  close(randdata);

  randdata = open("array.txt",O_RDONLY);
  if (randdata == -1) {
    printf("Error %d - %s\n",errno,strerror(errno));
    return errno;
  }

  int buff[10];
  printf("\n%zd bytes are being read\n\n", read(randdata,buff,10*sizeof(int)));
  if (errno) {
    printf("Error %d - %s\n",errno,strerror(errno));
    return errno;
  }
  else {
    printf("randdata has been read successfully\n\n");
  }

  printf("Values in buff[], and comparison between values in buff[] and nums[]:\n");
  printf("If the values in buff[] and nums[] are equal, then test will equal 1/n");
  for (i = 0; i < 10; i++){
    printf("Value %i = %12d\n",i,buff[i]);
    printf("Comparison -> %d\n",buff[i] == nums[i]);
  }
  close(randdata);

  return 0;

}
