#include <stdio.h>

//Problem 1 -- Find the sum of  the multiples of 3 and 5 that are less than 1000
int sum_mult_3of5() {
  int sum = 0;
  int mult = 1;
  while (mult < 1000) {
    if ((mult % 3 == 0) || (mult % 5 == 0)) {
      sum = sum + mult;
    }
    mult = mult + 1 ;
  }
  return sum;
}

//Problem 2 -- Find the sum of the even-valued Fibonacci terms that don't exceed 4000000
int sum_evenFib(){
  long num1 = 1 ;
  long num2 = 2;
  long next = 0;//largest even number in the sequence
  long sum = 0;
  while (next < 4000000) {
    if (next % 2 == 0) {
      sum = sum + next; 
	}
    next = num1 + num2;
    num1 = num2;
    num2 = next;
  }
  return sum + 2;
}

int main() {
  printf("sum_mult_3of5() is %d \n", sum_mult_3of5());
  printf("sum_evenFib() is %d \n", sum_evenFib());
  
  return 0;
}