#include <vector>
#include <climits>

using namespace std;

int majorityElement(vector<int>& nums) {
  const int N = (int) nums.size();
  int cnt=0;
  int num=INT_MIN;

  for (int i=0; i<N; i++) {
    if (cnt==0) {
      num=nums[i];
    }

    if (nums[i]==num) cnt++;
    else cnt--;
  }
  return num;
}

#include "test/03.h"
int main() {
  run_tests(majorityElement, "majorityElement");
  print_report();
  return 0;
}
