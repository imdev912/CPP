#include <iostream>
using namespace std;

int main() {
  int arr[5];
  int prd_arr = 1;
  int zero = 0;

  for (int i = 0; i < 5; i++) {
    cin >> arr[i];
    prd_arr *= arr[i];

    if (arr[i] == 0) {
      zero++;
    }
  }

  int prd[5] = {0};

  for (int i = 0; i < 5; i++) {
    if (arr[i] == 0) {
      if (zero == 1) {
        prd[i] = 1;

        for (int j = 0; j < 5; j++) {
          if ( j != i) {
            prd[i] *= arr[j];
          }
        }
      }
    } else {
      prd[i] = prd_arr / arr[i];
    }
  }

  for (int i = 0; i < 5; i++) {
    cout << prd[i] << " ";
  }

  cout << endl;

  return 0;
}
