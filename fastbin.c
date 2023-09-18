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
  int* c = calloc(1, 0x8);

  printf("a = %p\n", a);
  printf("b = %p\n", b);
  printf("c = %p\n", c);

  free(a);
  free(b);
  free(c);

  int* d = calloc(1, 0x8);
  printf("d = %p\n", d);
  free(d);

  return 0;
}
