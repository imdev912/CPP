#include <stdio.h>
#include <math.h>

int getDigits(int number) {
  int digits = 0;

  while (number) {
    number /= 10;
    digits += 1;
  }

  return digits;
}

int getArmstrong(int number) {
  int arms = 0;
  int power = getDigits(number);

  while (number) {
    int digit = number % 10;
    arms += pow(digit, power);
    number /= 10;
  }

  return arms;
}

int isArmstrong(int number) {
  if (number == getArmstrong(number)) {
    printf("%d is an armstrong number\n", number);
    return 1;
  }

  printf("%d is not an armstrong number\n", number);
  return 0;
}

int printArmstrong(int start, int end) {
  int count = 0;

  for (int number = start; number <= end; number++) {
    int arms = getArmstrong(number);

    if (arms == number) {
      count += 1;
      printf("%d: %d\n", count, arms);
    }
  }

  printf("%d armstrong number found between %d to %d\n", count, start, end);
  return 0;
}

int main() {
  int job;

  do {
    printf("\n0: exit \n1: check \n2: print \n\nenter case: ");
    scanf("%d", &job);

    switch (job) {
      case 0:
        printf("\n\nbye bye!\n\n");
      break;

      case 1:
        int number;
        
        printf("enter number: ");
        scanf("%d", &number);
        isArmstrong(number);
      break;

      case 2:
        int start, end;

        printf("enter range: ");
        scanf("%d %d", &start, &end);
        printArmstrong(start, end);
      break;

      default:
        printf("invaid input\n");
    }
  } while (job);

  printf("terminated\n");
  return 0;
}