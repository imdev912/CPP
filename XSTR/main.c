#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int xstrlen(const char *str) {
  int len = 0;

  while (*str != '\0') {
    str++;
    len++;
  }

  return len;
}

void xstrcpy(char *ptr, const char *str) {
  while (*str != '\0') {
    *ptr++ = *str++;
  }

  *ptr = '\0';
}

void xstrcat(char *ptr, const char *str) {
  ptr = ptr + xstrlen(ptr);
  xstrcpy(ptr, str);
}

int xstrcmp(const char *str1, const char *str2) {
  const unsigned char *s1 = (const unsigned char *) str1;
  const unsigned char *s2 = (const unsigned char *) str2;
  unsigned char c1, c2;

  do {
    c1 = (unsigned char) *s1++;
    c2 = (unsigned char) *s2++;

    if (c1 == '\0') {
      return c1 - c2;
    }
  } while (c1 == c2);

  return c1 - c2;
}

void xputs(char *str) {
  while (*str != '\0') {
    printf("%c", *str);
    str++;
  }

  printf("\n");
}

int main() {
  char str[255];
  char ptr[255];

  printf("enter string: ");
  fgets(str, 255, stdin);
  str[strcspn(str, "\n")] = 0;
  printf("you entered: ");
  xputs(str);
  printf("\nstring lenght is: %d", xstrlen(str));

  xstrcpy(ptr, str);
  printf("\nyour copy is here: ");
  xputs(ptr);
  printf("copy string lenght is: %d", xstrlen(ptr));

  printf("\nreal length: %ld", strlen(str));

  xstrcat(ptr, str);
  printf("\ncombined result: %s\n", ptr);

  char test[15] = "hello";
  xstrcat(test, "boy");
  printf("\ntest combined result: %s\n", test);

  char test2[25] = "hello";
  xstrcat(test2, test);
  printf("\ntest combined result: %s\n", test2);

  printf("\ntest result: %d\n", xstrcmp("hellw", "hallo"));

  return 0;
}