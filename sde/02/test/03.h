#ifndef _H_
#define _H_

#include "../../../.inc/base.h"
#include "../../../.inc/to_string.h"

void prototype(vector<int>& nums1, int m, vector<int>& nums2, int n);
using fptr = decltype(prototype);

void test(fptr function, vector<int> v1, vector<int> v2, vector<int> correct) {
  int v1size=v1.size();
  v1.resize(v1size+v2.size());
  function(v1, v1size, v2, v2.size());
  cout << setw(40) << to_string(v1) << " ";

  bool wrong = v1!=correct;
  _wrong|=wrong;

  cout << ":\t " << (wrong? " (WRONG)": " correct") << endl;
}



void run_tests(string msg, fptr function) {
  cout << msg  << ":\n";

  test(function, {}, {}, {});
  test(function, {1,2,3}, {}, {1,2,3});
  test(function, {1,2,3}, {5,6,7}, {1,2,3, 5, 6, 7});
  test(function, {5,6,7}, {1,2,3}, {1,2,3, 5, 6, 7});

  test(function, {1,2,2,3,4}, {2,2,2}, {1,2,2,2,2,2,3,4});
  test(function, {1,2,2,3,4}, {2,2,5}, {1,2,2,2,2,3,4, 5});

  cout << endl;
}

#endif  // _H_
