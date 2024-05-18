#include <iostream>
#include <stack>

using namespace std;

int precedence(char c) {
  if (c == '^') {
    return 3;
  } else if (c == '/' || c == '*') {
    return 2;
  } else if (c == '+' || c == '-') {
    return 1;
  }

  return -1;
}

string postfixToInfix(string exp) {
  stack <string> st;

  for (int i = 0; i < exp.length(); i++) {
    char c = exp[i];

    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
      string op(1, c);
      st.push(op);
    } else {
      string op1 = st.top();
      st.pop();

      string op2 = st.top();
      st.pop();

      st.push("(" + op2 + c + op1 + ")");
    }
  }

  return st.top();
}

string infixToPostfix(string exp) {
  string result;
  stack <char> st;

  for (int i = 0; i <= exp.length(); i++) {
    char c  = exp[i];

    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
      result += c;
    } else if (c == '(') {
      st.push(c);
    } else if (c == ')') {
      while (st.top() != '(') {
        result += st.top();
        st.pop();
      }

      st.pop();
    } else {
      while (!st.empty() && (precedence(c) <= precedence(st.top()))) {
        if (c == '^' && st.top() == '^') {
          break;
        } else {
          result += st.top();
          st.pop();
        }
      }

      st.push(c);
    }
  }

  while (!st.empty()) {
    result += st.top();
    st.pop();
  }

  return result;
}

int main () {
  string exp;
  cout << "enter infix experession: ";
  getline(cin, exp);
  string infix = postfixToInfix(exp);
  std::cout << infix << std::endl;
  exp = infix;
  string postfix = infixToPostfix(exp);
  std::cout << postfix << std::endl;
  return 0;
}