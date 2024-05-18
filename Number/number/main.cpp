#include <iostream>

class Number {
  public:
    std::string strReverse(std::string str) {
      int len = str.length();
      int i = 0;
      int j = (len - 1);

      while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;

        i++;
        j--;
      }

      return str;
    }

    std::string numberToString(int num, int base) {
      std::string result;

      while (num > 0) {
        int digit = num % base;
        int offset = 0;

        if (digit < 10) {
          offset = 48;
        } else {
          offset = 55;
        }
        
        result += (char) digit + offset;
        num /= base;
      }

      return result;
    }

    int stringToNumber(std:: string data, int base) {
      int num = 0;
      int place = 1;

      for (int i = (data.length() - 1); i > -1; i--) {
        int offset = 0;

        if (data[i] >= '0' && data[i] <= '9') {
          offset = 48;
        } else if (data[i] >= 'A' && data[i] <= 'F') {
          offset = 55;
        }

        num += ((int) data[i] - offset) * place;
        place *= base;
      }

      return num;
    }

    std::string convertBase(std::string data) {
      int base_1;
      std::cout << "number base: ";
      std::cin >> base_1;

      int num = stringToNumber(data, base_1);

      std::cout << "num: " << num << std::endl;

      int base_2;
      std::cout << "conversion base: ";
      std::cin >> base_2;

      std::string result = numberToString(num, base_2);
      result = strReverse(result);

      std::cout << "base "<< base_1 << ": " << num << std::endl;
      std::cout << "base "<< base_2 << " : " << result << std::endl;

      return result;
    }
};

int main() {
  Number number;
  std::string num;

  while (true) {
    std::cout << std::endl << "Enter number: ";
    std::cin >> num;

    std::string result = number.convertBase(num);
  }
}