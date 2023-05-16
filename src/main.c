#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#ifdef POOPYTER_EMSCRIPTEN
#include <emscripten.h>
#endif

#include "poopyter.h"

#ifndef POOPYTER_KERNEL_SUFFIX
  #define POOPYTER_KERNEL_SUFFIX ".dylib"
#endif
#define KERNEL(k) k POOPYTER_KERNEL_SUFFIX

struct kernel *load_kernel(const char *path) {
  // dlopen() will work w/ a url when USE_PTHREADS
  // and PROXY_TO_PTHREAD enabled
  void *handle = dlopen(path, RTLD_NOW|RTLD_LOCAL);
  if (!handle) {
    printf("dlopen: %s\n", dlerror());
    exit(1);
  }
  struct kernel *k = dlsym(handle, "poopyter_kernel");
  if (!k) {
    printf("dlsym: %s\n", dlerror());
    exit(1);
  }
  if (k->abi_version != POOPYTER_ABI) {
    printf("abi mismatch: found %d expected %d\n", k->abi_version, POOPYTER_ABI);
    exit(1);
  }
  return k;
}

int main(int argc, char **argv) {
  struct kernel *add5 = load_kernel(KERNEL("libadd5"));
  printf("%d\n", add5->execute(10));

  struct kernel *mul3 = load_kernel(KERNEL("libmul3"));
  printf("%d\n", mul3->execute(30));

  return 0;
}
