#include <iostream>
using namespace std;

int main() {
  int arr[5];
  int sum_arr = 0;

  for (int i = 0; i < 5; i++) {
    cin >> arr[i];
    sum_arr += arr[i];
  }

  int sum[5] = {0};

  for (int i = 0; i < 5; i++) {
    sum[i] = sum_arr - arr[i];
    cout << arr[i] << " ";
  }

  cout << endl;

  for (int i = 0; i < 5; i++) {
    cout << sum[i] << " ";
  }

  cout << endl;

  return 0;
}
