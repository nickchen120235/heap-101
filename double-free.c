// Reference: https://github.com/shellphish/how2heap/blob/master/glibc_2.35/fastbin_dup.c

#include <stdio.h>
#include <stdlib.h>

int main() {
  // fill tcache
  void* dummy[8];
  for (int i = 0; i < 8; ++i) {
    dummy[i] = malloc(0x8);
  }
  for (int i = 0; i < 7; ++i) {
    free(dummy[i]);
  }

  int* a = calloc(1, 0x8);
  int* b = calloc(1, 0x8);

  printf("a = %p\n", a);
  printf("b = %p\n", b);

  free(a);
  free(b);
  free(a);

  return EXIT_SUCCESS;
}
