#include <stdio.h>

int sp = 0;

int space(int n)
{
  for (int i = 0; i < n; i++) {
    printf("  ");
  }

  return 0;
}

int fun(int n)
{
  int x=1, k;
  
  if (n==1) {
    return x;
  }

  sp++;
  space(sp);
  printf("f(%d):\n", n);
  
  for (k=1; k < n; ++k) {
    int t1 = fun(k);
    int t2 = fun(n - k);
    int t3 = x +  t1 * t2;
    
    sp++;
    space(sp);
    printf("n : %d\n", n);
    space(sp);
    printf("k : %d\n", k);
    sp++;
    space(sp);
    printf("x + f(%d) * f(%d)\n", k, n - k);
    space(sp);
    printf("%d + %d * %d = %d\n", x, t1, t2, t3);

    x = t3;
    sp--;
    sp--;
  }

  space(sp);
  printf(":f(%d) :: %d\n", n, x);
  sp--;
  
  return x;
}

int main()
{
  printf("%d", fun(3));
  return 0;
}
