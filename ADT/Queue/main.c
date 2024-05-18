#include <stdio.h>
#define MAX_SIZE 999

static int pin = -1;
static int arr[MAX_SIZE];

void display() {
  if (pin > -1) {
    printf("\n\n");

    for (int i = 0; i <= pin; i++) {
      printf("%d\t", arr[i]);
    }

    printf("\n\n");
  }
}

void search() {
  int num;

  printf("\nEnter element to search: ");
  scanf("%d", &num);

  if (pin > -1) {
    for (int i = 0; i <= pin; i++) {
      if (arr[i] == num) {
        printf("\n%d present at %d position", num, i);
      }
    }
  }
}

void pop() {
  arr[pin] = arr[pin + 1];
  pin--;
  display();
}

void push() {
  printf("Enter element to add: ");

  int idx = pin;

  while (idx > -1) {
    arr[idx + 1] = arr[idx];
    idx--;
  }

  scanf("%d", &arr[0]);
  pin++;
  display();
}

void create() {
  int n;
  pin = -1;
        
  printf("\nNumber of elements to be added: ");
  scanf("%d", &n);
  printf("\n");

  for (int i = 0; i < n; i++) {
    printf("Enter %d element: ", i + 1);

    int idx = pin;

    while (idx > -1) {
      arr[idx + 1] = arr[idx];
      idx--;
    }

    scanf("%d", &arr[0]);
    pin++;
  }

  display();
}

int main() {
  int op;
  int num, idx;

  printf("\n1. %-10s\t2. %-10s\n3. %-10s\t4. %-10s\n", "create", "push", "pop", "search");

  do {
    printf("\noperation: ");
    scanf("%d", &op);

    switch (op) {
      // create
      case 1:
        create();
      break;

      // insert
      case 2:
        push();
      break;

      // delete
      case 3:
        pop();
      break;

      // search
      case 4:
        search();
      break;

      default:
        printf("\ninvalid operation\n");
      break;
    }

  } while (op);

  return 0;
}