#include <iostream>
using namespace std;

int add(float a, long c) {
  return (int)a+(int)c+15;
}


void demo() {
  // Way 1:

  int r1 = fptr1(10, 20);
  cout << "r: " << r1 << endl;

  // Way 2:

  int r2=fptr2(10, 20);
  cout << "r: " << r2 << endl;

  // Way 3:

  int r3=fptr3(10, 20);
  cout << "r: " << r3 << endl;

  // Way 4:

  int r4=fptr4(10, 20);
  cout << "r: " << r4 << endl;
}


int main() {
  demo();
  return 0;
}
