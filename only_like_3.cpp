#include <iostream>

int recursive(int i, int j, int ithPowerOf3, int jthPowerOf3, int counter, int n)
{
  if (counter == n)
  {
    if (j == 0)
    {
      return ithPowerOf3;
    }
    else
    {
      return ithPowerOf3 + jthPowerOf3;
    }
  }
  else
  {
    if (j == i - 1)
    {
      return recursive(i + 1, 0, ithPowerOf3 * 3, 1, counter + 1, n);
    }
    else
    {
      return recursive(i, j + 1, ithPowerOf3, jthPowerOf3 * 3, counter + 1, n);
    }
  }
}

int find_nth_term(int n)
{
  return recursive(1, 0, 3, 1, 1, n);
}

int main()
{
  int idx;
  std::cout << "Enter index: ";
  std::cin >> idx;
  int res = find_nth_term(idx);
  std::cout << res << std::endl;
  return 0;
}