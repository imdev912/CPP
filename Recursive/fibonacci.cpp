/*
  by Rahul Singh, 28 September 2022

  Fibonacci Sequence (Recirsive Approach)
  e.g. f(n) = f(n-1) + f(n-2)
  0 1 1 2 3 5 8 13 ...
*/

#include <iostream>

int fibonacci(int num)
{
  if (num <= 1) {
    return num;
  }

  return fibonacci(num - 1) + fibonacci(num - 2);
}

int menu() {
  std::cout << std::endl;
  std::cout << "x-- Operations --x" << std::endl;
  std::cout << std::endl;
  std::cout << "(1) fibonacci number" << std::endl;
  std::cout << "(2) fibonacci sequence" << std::endl;
  std::cout << "(3) fibonacci series" << std::endl;
  std::cout << std::endl;

  return 0;
}

int main()
{
  int num, opr;

  menu();

  start:
  
  std::cout << "Enter operation: ";
  std::cin >> opr;

  int fibo = 0;
  int sum = 0;

  switch (opr)
  {
    case 1:
      std::cout << "Enter term: ";
      std::cin >> num;

      if (num > 1) {
        fibo = fibonacci(num - 1);
      }

      std::cout << num << " term of fibonacci sequence is: " << fibo << std::endl;
    break;

    case 2:
      std::cout << "Enter number of terms: ";
      std::cin >> num;
      std::cout << num << " terms of fibonacci sequence are: ";

      for (int i = 0; i < num; i++) {
        std::cout << fibonacci(i) << ' ';
      }
    break;

    case 3:
      std::cout << "Enter number of terms: ";
      std::cin >> num;

      for (int i = 0; i < num; i++) {
        sum += fibonacci(i);
      }

      std::cout << "fibonacci series of first " << num << " terms is: " << sum << std::endl;
    break;
    
    default:
      std::cout << "Error: Invalid operation!" << std::endl;
    break;
  }

  std::cout << std::endl;

  goto start;

  return 0;
}