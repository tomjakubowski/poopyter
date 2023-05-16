// add5

#include <stdio.h>
#include <unistd.h>

#include "poopyter.h"

int add5(int n) { 
  printf("hello from libadd5\n");
  printf("i'm feeling sleepy...\n");
  sleep(1);
  printf("zzz...\n");
  sleep(1);
  return n + 5; 
}

struct kernel poopyter_kernel = {
  POOPYTER_ABI,
  "add5",
  &add5
};
