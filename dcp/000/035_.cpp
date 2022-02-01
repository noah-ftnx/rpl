#include <vector>
using namespace std;

void partition(vector<char>& input) {
  const int N = (int) input.size();
  // 3 empty sections
  int low=0, mid=0, high=N-1;

  while (mid <= high) {
    if (input[mid]=='R') { // put in low
      swap(input[mid], input[low]);
      low++;
      mid++;
    } else if (input[mid]=='G') { // it's in place
      mid++;
    } else { // put in high
      swap(input[mid],input[high]);
      high--;
    }
  }
}



#include "test/035.h"
int main() { run_tests(); return 0; }