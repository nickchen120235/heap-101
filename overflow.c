#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
  char* alice = malloc(0x10);
  char* bob = malloc(0x10);
  if (alice == NULL || bob == NULL) {
    printf("Initialization failed.\n");
    return EXIT_FAILURE;
  }

  strcpy(bob, "bob");

  printf("Can you make bob an admin?\n");
  printf("Enter your name: ");
  fgets(alice, 0x30, stdin);

  bob[strcspn(bob, "\n")] = 0;
  if (strcmp(bob, "admin") == 0) {
    printf("You did it! Bob is now an admin.\n");
  }
  else {
    printf("Bob is still not an admin...\n");
  }

  free(alice);
  free(bob);
  return EXIT_SUCCESS;
}
