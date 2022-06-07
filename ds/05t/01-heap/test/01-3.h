#ifndef _H_
#define _H_

#include "../../../../.inc/base.h"
#include "../../../../.inc/vec.h"

void test(const vector<int> vec, vector<int> correct) {
  // string s;
  // stringstream ss;
  // for (auto i: vec) ss << setw(3) << to_string(i) << " ";

  // s=ss.str();
  // ss.str("");
  cout << setw(30) << to_string(vec, 2);

  auto heap = MinHeap(vec);
  // function(n, m);

  cout << "  ->  ";
  cout << setw(30) << to_string(heap.get_vector(), 3);

  bool wrong = heap.get_vector() != correct;
  _wrong|=wrong;

  cout  <<  (wrong? " (WRONG)": " correct") << endl;
}

void run_tests(string msg) {
  cout << msg  << ":\n";
  test({25, 3, 10, 15, 2, 40}, {2, 3, 10, 15, 25, 40});

  test({3}, {3});
  test({3, 10}, {3, 10});
  test({10, 3}, {3, 10});

  cout << endl;
}

#endif  // _H_
