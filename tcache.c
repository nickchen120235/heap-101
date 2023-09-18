#include <stdlib.h>

int main() {
  int* dummy20[8];
  for (int i = 0; i < 8; ++i) {
    dummy20[i] = malloc(0x20);
  }
  for (int i = 0; i < 8; ++i) {
    free(dummy20[i]);
  }

  int* dummy30[8];
  for (int i = 0; i < 8; ++i) {
    dummy30[i] = malloc(0x30);
  }
  for (int i = 0; i < 8; ++i) {
    free(dummy30[i]);
  }

  return 0;
}
