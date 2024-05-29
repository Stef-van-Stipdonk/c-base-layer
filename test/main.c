#include "base.h"
#include <stdio.h>

int main(void) {
  printf("%s\n", "Hello World!");

  printf("clang = %d\n", COMPILER_CLANG);
  printf("gcc = %d\n", COMPILER_GCC);
  printf("linux = %d\n", OS_LINUX);
  printf("mac = %d\n", OS_MAC);
  printf("windows = %d\n", OS_WINDOWS);

  // Dynamic array example
  List(int) nums = NULL;
  initList(nums);

  listAppend(nums, 1);
  listAppend(nums, 2);

  printf("capacity: %lu, used: %lu\n", listCapacity(nums), listUsed(nums)); 
  return 0;
}
