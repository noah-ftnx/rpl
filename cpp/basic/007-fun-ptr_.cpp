#include <iostream>
#include <functional>
using namespace std;

int add(float a, long b) {
  return (int)a + (int)b + 15;
}

void demo() {
  // Way 1:
  std::function<int(float, long)> fptr1 = add;
  int r1 = fptr1(10, 20);
  cout << "r: " << r1 << endl;

  // Way 2:
  using fptr_tp = decltype(add);
  fptr_tp *fptr2 = add;
  int r2 = fptr2(10, 20);
  cout << "r: " << r2 << endl;

  // Way 3:
  int (*fptr3)(float, long) = add;
  int r3 = fptr3(10, 20);
  cout << "r: " << r3 << endl;

  // Way 4:
  using fptr_alias = int (*)(float, long);
  fptr_alias fptr4 = add;
  int r4 = fptr4(10, 20);
  cout << "r: " << r4 << endl;
}

int main() {
  demo();
  return 0;
}
