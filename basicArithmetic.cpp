/*
  by Rahul Singh, 28 September 2022

  Baisc Arithmetic
  (+) Addition
  (-) Subtraction
  (*) Multiplication
  (/) Division
*/

#include <iostream>

int menu() {
  std::cout << std::endl;
  std::cout << "x-- Operations --x" << std::endl;
  std::cout << std::endl;
  std::cout << "(+) Addition" << std::endl;
  std::cout << "(-) Subtraction" << std::endl;
  std::cout << "(*) Multiplication" << std::endl;
  std::cout << "(/) Division" << std::endl;
  std::cout << std::endl;
  std::cout << "e.g. a + b" << std::endl;
  std::cout << std::endl;

  return 0;
}

int main()
{
  float num1, num2, ans;
  char opr;

  menu();

  start:

  std::cout << "Enter equation: ";
  std::cin >> num1 >> opr >> num2;

  switch(opr)
  {
    case '+':
      ans = num1 + num2;
    break;

    case '-':
      ans = num1 - num2;
    break;

    case '*':
      ans = num1 * num2;
    break;

    case '/':
      ans = num1 / num2;
    break;

    default:
      ans = 0;
      std::cout << "Error: Invalid Operation (" << opr << ") " << std::endl;
    break;
  }

  std::cout << num1 << ' ' << opr << ' '<< num2 << " = " << ans << std::endl;
  std::cout << std::endl;

  goto start;

  return 0;
}