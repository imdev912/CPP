/*
  by Rahul Singh, 28 September 2022

  Factorial of a number (Recirsive Approach)
  e.g. 5! = 5 * 4 * 3 * 2 * 1
*/

#include <iostream>

int factorial(int num)
{
  if (num <= 1) {
    return num;
  }

  return num * factorial(num - 1);
}

int main()
{
  int num;

  start:
  
  std::cout << "Enter number: ";
  std::cin >> num;

  int res = factorial(num);

  std::cout << "Factorial of " << num << " is: " << res << std::endl;
  std::cout << std::endl;

  goto start;

  return 0;
}