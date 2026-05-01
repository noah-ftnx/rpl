#ifndef RPL_DCP_TEST_043_H_
#define RPL_DCP_TEST_043_H_

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

bool _wrong {};

void test1() {
  cout << "test1:\n";
  Stack* s = new Stack();
  vector<int> input { 5, 2, 3, 5, 10, 6, 7 };
  vector<int> correct_max { 5, 5, 5, 5, 10, 10, 10};
  for (int i=0; i<input.size(); i++) {
    s->push(input[i]);
    int mx = s->max();
    bool wrong = mx!=correct_max[i];
    _wrong|=wrong;
    cout << setw(5) << "add: " << setw(2) <<
         input[i] << " max: " << setw(2) << mx
    << ": " << (wrong? " Wrong":" [PASS]") << endl;
  }

  vector<int> correct_max2 { 10, 10, 5, 5, 5, 5};
  for (int i=0; i<input.size()-1; i++) {
    int val = s->pop();
    int mx = s->max();
    bool wrong = mx!=correct_max2[i];
    _wrong|=wrong;
    cout << setw(5) << "pop: " << setw(2) <<
        val << " max: " << setw(2) << mx
         << ": " << (wrong? " Wrong":" [PASS]") << endl;
  }
  cout << endl;
}


void test2() {
  cout << "test2\n";
  Stack* s = new Stack();
  vector<int> input { 2, 3, 5 };
  vector<int> correct_max { 2, 3, 5 };
  for (int i=0; i<input.size(); i++) {
    s->push(input[i]);
    int mx = s->max();
    bool wrong = mx!=correct_max[i];
    _wrong|=wrong;
    cout << setw(5) << "add: " << setw(2) <<
        input[i] << " max: " << setw(2) << mx
         << ": " << (wrong? " Wrong":" [PASS]") << endl;
  }

  vector<int> correct_max2 { 3, 2};
  for (int i=0; i<input.size()-1; i++) {
    int val = s->pop();
    int mx = s->max();
    bool wrong = mx!=correct_max2[i];
    _wrong|=wrong;
    cout << setw(5) << "pop: " << setw(2) <<
        val << " max: " << setw(2) << mx
         << ": " << (wrong? " [FAIL]":" [PASS]") << endl;
  }
  cout << "last max: " << s->max() << " [PASS]" << endl;
  s->pop();
  try {
    s->pop(); // throws exception
  } catch (char const* msg) {
   cout << "exception caught: "  << msg << endl;
  }
  s->push(1);
  bool w2 = s->max() != 1;
  _wrong|=w2;
  cout << "another max: " << s->max() << (w2? " [FAIL]":" [PASS]") << endl;
  cout << endl;
}


void run_tests() {
  test1();
  test2();

  cout << "\n" << (_wrong? "[FAIL]":"[PASS] (all results).") << endl;
}




#endif  // RPL_DCP_TEST_043_H_
