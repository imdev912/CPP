#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *head;

void display() {
  struct Node *ptr = head;

  printf("\n\n");

  while (ptr != NULL) {
    printf("%d", ptr->data);

    if (ptr->next != NULL) {
      printf(" > ");
    }

    ptr = ptr->next;
  }

  printf("\n\n");
}

void reverse() {
  struct Node *prev = NULL;
  struct Node *next = NULL;

  while (head != NULL) {
    next = head->next;
    head->next = prev;
    prev = head;
    head = next;
  }

  head = prev;
  display();
}

void search() {
  int num;
  int idx = -1;

  printf("\nEnter element to search: ");
  scanf("%d", &num);

  struct Node *ptr = head;

  while (ptr != NULL) {
    idx++;

    if (ptr->data == num) {
      printf("%d is present at %d index", num, idx);
    }

    ptr = ptr->next;
  }
}

int delete() {
  if (head == NULL) {
    printf("\nempty list\n");
    return 1;
  }

  int idx;

  printf("Enter index to delete: ");
  scanf("%d", &idx);

  if (idx < 1) {
    printf("\ninvalid index\n");
    return 1;
  }

  struct Node *prev = NULL;
  struct Node *curn = head;

  while (curn != NULL && idx > 1) {
    prev = curn;
    curn = curn->next;
    idx--;

    if (curn == NULL && idx > 0) {
      printf("\ninvalid index\n");
      return 1;
    }
  }

  prev->next = curn->next;
  free(curn);
  display();

  return 0;
}

void insert() {
  int idx, num;

  struct Node *prev = NULL;
  struct Node *next = head;

  struct Node *temp = (struct Node *) malloc(sizeof(int));
  printf("Enter index and element to add: ");
  scanf("%d %d", &idx, &temp->data);
  
  while (next != NULL && idx > 1) {
    prev = next;
    next = next->next;
    idx--;
  }

  temp->next = next;

  if (prev != NULL) {
    prev->next = temp;
  } else {
    head = temp;
  }

  display();
}

void create() {
  int n;
  head = NULL;
        
  printf("\nNumber of elements to be added: ");
  scanf("%d", &n);
  printf("\n");

  for (int i = 0; i < n; i++) {
    printf("Enter %d element: ", i + 1);

    struct Node *temp = (struct Node *) malloc(sizeof(int));
    struct Node *ptr = head;

    scanf("%d", &temp->data);
    temp->next = NULL;

    while (ptr != NULL) {
      if (ptr->next == NULL) {
        break;
      }

      ptr = ptr->next;
    }

    if (head == NULL) {
      head = temp;
    } else {
      ptr->next = temp;
    }
  }

  display();
}

int main() {
  int op;
  head = NULL;

  printf("\n1. %-10s\t2. %-10s\n3. %-10s\t4. %-10s\n5. %-10s\t\n", "create", "insert", "delete", "search", "reverse");

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

      // reverse
      case 5:
        reverse();
      break;

      default:
        printf("\ninvalid operation\n");
      break;
    }

  } while (op);

  return 0;
}