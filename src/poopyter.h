#pragma once

#define POOPYTER_ABI 1

#ifdef POOPYTER_EMSCRIPTEN
#include <emscripten.h>
#endif

struct kernel {
  int abi_version;
  const char *name;
  int (*execute)(int);
};

