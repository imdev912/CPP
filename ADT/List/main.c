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

void delete() {
  if (pin > -1) {
    int idx;

    printf("\nEnter index to delete: ");
    scanf("%d", &idx);

    if (idx > -1 && idx <= pin) {
      int pos = idx;

      while (pos <= pin) {
        printf("%d\t", pos);
        arr[pos++] = arr[pos];
      }

      pin--;
      display();
    } else {
      printf("invalid index");
    }
  } else {
    printf("\nempty list\n");
  }
}

void insert() {
  int idx, num;

  printf("\nEnter index and number: ");
  scanf("%d %d", &idx, &num);

  if (idx > -1 && idx <= pin) {
    int pos = ++pin;

    while (pos > idx) {
      arr[pos] = arr[pos - 1];
      pos--;
    }

    arr[idx] = num;
    display();
  } else {
    printf("invalid index");
  }
}

void create() {
  int n;
  pin = -1;
        
  printf("\nNumber of elements to be added: ");
  scanf("%d", &n);
  printf("\n");

  for (int i = 0; i < n; i++) {
    printf("Enter %d element: ", i + 1);
    scanf("%d", &arr[++pin]);
  }

  display();
}

int main() {
  int op;
  int num, idx;

  printf("\n1. %-10s\t2. %-10s\n3. %-10s\t4. %-10s\n", "create", "insert", "delete", "search");

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
        insert();
      break;

      // delete
      case 3:
        delete();
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