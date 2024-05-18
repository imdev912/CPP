#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stack>

int main () {
  char *str= (char *) malloc(sizeof(char) * 20);
  std::stack <char> stack;

  fgets(str, 20, stdin);

  int len = strlen(str);
  
  for (int i = 0; i < len; i++) {
    if (str[i] == '{' || str[i] == '(' || str[i] == '[') {
      stack.push(str[i]);
    } else if (str[i] == '}' || str[i] == ')' || str[i] == ']') {
      if (stack.empty() || ((stack.top() == '{' && str[i] != '}') || (stack.top() == '(' && str[i] != ')') || (stack.top() == '[' && str[i] != ']'))) {
        std::cout << std::endl << "unbalanced: " << std::endl << str[i] << std::endl;
        return 1;
      } else {
        switch (stack.top()) {
          case '{':
            if (str[i] == '}') {
              std::cout << stack.top() << "  " << str[i] << std::endl;
              stack.pop();
            }
          break;

          case '(':
            if (str[i] == ')') {
              std::cout << stack.top() << "  " << str[i] << std::endl;
              stack.pop();
            }
          break;

          case '[':
            if (str[i] == ']') {
              std::cout << stack.top() << "  " << str[i] << std::endl;
              stack.pop();
            }
          break;
        }
      }
    }
  }

  if (stack.empty()) {
    std::cout << std::endl << "balanced" << std::endl;
  } else {
    std::cout << std::endl << "unbalanced: " << std::endl;

    while (!stack.empty()) {
      std::cout << stack.top() << std::endl;
      stack.pop();
    }
  }

  std::cout << std::endl;
  return 0;
}