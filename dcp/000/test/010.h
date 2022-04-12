#ifndef INC_070__CPP_DCP_000_TEST_010_H_
#define INC_070__CPP_DCP_000_TEST_010_H_

#include <iostream>
void add(int a, int b) {
  cout << a << " + " << b << " = " << (a+b) << endl;
}

void run_tests() {
  schedule_way1((void*)add, 500);
  schedule_way2(add, 500);
  schedule_way3(add, 500);
  schedule_way4(add, 500);
}


#endif  // INC_070__CPP_DCP_000_TEST_010_H_
