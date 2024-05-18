#include <string>

string multiplyAbsolute(string s1, string s2)
{
  int m = s1.size();
  int n = s2.size();
  vector<int> result(m + n, 0);

  // Perform multiplication digit by digit
  for (int i = m - 1; i >= 0; i--)
  {
    for (int j = n - 1; j >= 0; j--)
    {
      int mul = (s1[i] - '0') * (s2[j] - '0');
      int sum = mul + result[i + j + 1];
      result[i + j + 1] = sum % 10;
      result[i + j] += sum / 10;
    }
  }

  // Convert the result array to string
  string resStr;
  for (int num : result)
  {
    resStr.push_back(num + '0');
  }

  // Remove leading zeros
  size_t start = resStr.find_first_not_of('0');
  if (start == string::npos)
  {
    return "0";
  }
  else
  {
    return resStr.substr(start);
  }
}

string multiplyStrings(string s1, string s2)
{
  // Handle negative sign and remove it for processing
  int sign = processSign(s1) * processSign(s2);

  // Multiply the absolute values of s1 and s2
  string result = multiplyAbsolute(s1, s2);

  // Add back the sign if necessary
  return (sign == -1) ? ("-" + result) : result;
}

int processSign(string &s)
{
  int sign = 1;
  if (s[0] == '-')
  {
    sign = -1;
    s = s.substr(1); // Remove the negative sign
  }
  return sign;
}