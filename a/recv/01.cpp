/**
* BASIC
*
* parameterized vs functional recursive calls
 *
*/

void recv1(int i, int N, int &sum) {
  if (i>N) return;
  sum+=i;
  recv1(i+1, N, sum);
}

int parameterized(int N) {
  int sum {};
  recv1(1, N, sum);
  return sum;
}


int functional(int N) {
  if (N==0) return 0;

  return N + functional(N-1);
}

int factorial(int N) {
  if (N<0) return 0;
  if (N==0) return 1;

  return N * factorial(N-1);
}

#include <iostream>
using namespace std;

int main() {
  cout << "N4: " << parameterized(4) << endl;
  cout << "N4: " << functional(4) << endl;
  cout << "factorial: " << factorial(5) << endl;
}