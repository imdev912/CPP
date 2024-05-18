#include <stdio.h>
#include <string.h>

int main() {
  char str[20];
  fgets(str, 20, stdin);
  int len = strlen(str);

  int i = 0;
  int j = (len - 1);

  while (i < j) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;

    i++;
    j--;
  }

  puts(str);
}