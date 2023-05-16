// mul3

#include <stdio.h>

#include "poopyter.h"

int mul3(int n) {
  printf("hello from libmul3\n");
  return n * 3;
}

struct kernel poopyter_kernel = {
  POOPYTER_ABI,
  "mul3",
  &mul3
};
