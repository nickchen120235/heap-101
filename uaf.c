// Inspired by https://exploit.education/phoenix/heap-two/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct login {
  char name[24];
  int is_admin;
} login_t;

login_t* user = NULL;
char* service = NULL;

void help() {
  printf("\n[1] Register\n");
  printf("[2] Deactivate account\n");
  printf("[3] Create service\n");
  printf("[0] Admin area\n");
}

int main() {
  char choice[3];
  while(1) {
    help();
    printf("Enter your choice: ");
    fgets(choice, 3, stdin);
    switch(choice[0]) {
      case '1': {
        user = malloc(sizeof(login_t));
        printf("Username: ");
        fgets(user->name, 20, stdin);
        user->name[strcspn(user->name, "\n")] = 0;
        user->is_admin = 0;
        printf("Welcome, %s\n", user->name);
        break;
      }
      case '2': {
        free(user);
        printf("See you again!\n");
        break;
      }
      case '3': {
        printf("Service name: ");
        service = malloc(0x24);
        fgets(service, 0x24, stdin);
        service[strcspn(service, "\n")] = 0;
        printf("That's a cool name!\n");
        break;
      }
      case '0': {
        if (user && user->is_admin == 0xdeadbeef) {
          printf("You are admin!\n");
          return EXIT_SUCCESS;
        }
        else {
          printf("Who are you?\n");
        }
        break;
      }
      default: {
        printf("Unknown command\n");
      }
    }
  }
  return EXIT_SUCCESS;
}
