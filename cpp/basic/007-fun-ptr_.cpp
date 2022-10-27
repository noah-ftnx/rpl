#include <iostream>
using namespace std;

int add(float a, long c) {
  return (int)a+(int)c+15;
}

#include <functional>

void demo() {
  // Way 1:
  // std::function<int(float, float)> fptr1=add; // can still work
   std::function<int(float, long)> fptr1=add; // proper definition
  int r1 = fptr1(10, 20);
  cout << "r: " << r1 << endl;

  // Way 2:
  using fptr_tp = decltype(add);
  fptr_tp *fptr2=add;
  int r2=fptr2(10, 20);
  cout << "r: " << r2 << endl;

  // Way 3:
  int (*fptr3)(float a, long c) = add;
  int r3=fptr3(10, 20);
  cout << "r: " << r3 << endl;

  // Way 4: like 3 but most weird casting
  void *vptr4 = (void*) add;
  // left: same casting as void pointer
  // right: casting to function pointer: same as left, but no names needed
  int (*fptr4)(float a, long c) = (int (*)(float, long)) vptr4;
  int r4=fptr4(10, 20);
  cout << "r: " << r4 << endl;

}


int main() {
  demo();
  return 0;
}
