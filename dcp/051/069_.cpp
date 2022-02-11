#include <vector>
using namespace std;

int largest_product3_slower(vector<int> input) {
  sort(input.begin(), input.end(), less<int>());  // ascending nlogn

  const int N = (int) input.size();

  bool can_use_negatives= (input[0]<0 && input[1]<0);

  int res = input[N-1]*input[N-2]*input[N-3]; // positives

  if (can_use_negatives) res=max(res, input[0]*input[1]*input[N-1]);

  return res;
}

#include <climits>
int largest_product3(vector<int> input) {
  int mx1=INT_MIN;
  int mx2=INT_MIN;
  int mx3=INT_MIN;

  int mn1=INT_MAX;
  int mn2=INT_MAX;

  for (auto num: input) {
    if (num > mx1) {
      mx3=mx2;
      mx2=mx1;
      mx1=num;
    } else if (num > mx2) {
      mx3=mx2;
      mx2=num;
    } else if (num > mx3) {
      mx3=num;
    }

    if (num < mn1) {
      mn2=mn1;
      mn1=num;
    } else if (num < mn2) {
      mn2=num;
    }
  }

  return max(mx1*mx2*mx3, mn1*mn2*mx1);
}



#include "test/069.h"
int main() { run_tests(); return 0; }