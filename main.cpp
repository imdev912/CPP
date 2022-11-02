#include <iostream>
using namespace std;

string reverseString(string str) {
  int i = 0;
  int j = str.length() - 1;

  while (i < j) {
    char tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
    i++;
    j--;
  }

  return str;
}

string numberToString(int num, int base) {
  string str;
  
  while (num != 0) {
    int digit = num % base;
    int offset = 0;

    if (digit < 10) {
      offset = 48;
    } else {
      offset = 55;
    }

    str += char(digit) + offset;
    num /= base;
  }

  return str;
}

int stringToNumber(string str, int base) {
  int num = 0;
  int place = 1;

  for (int i = str.length() - 1; i >= 0; i--) {
    int offset = 0;

    if (str[i] >= '0' && str[i] <= '9') {
      offset = 48;
    } else if (str[i] >= 'A' && str[i] <= 'F') {
      offset = 55;
    }
    
    num += (int(str[i]) - offset) * place;
    place *= base;
  }

  return num;
}

string changeBase(string str, int b1, int b2) {
  int num = stringToNumber(str, b1);
  string res = numberToString(num, b2);
  return reverseString(res);
}

int main() {
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  string s;
  int b1, b2;
  cin >> s >> b1 >> b2;
  string res = changeBase(s, b1, b2);
  cout << res << endl;
  return 0;
}