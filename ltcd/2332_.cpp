#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
    sort(buses.begin(), buses.end());
    sort(passengers.begin(), passengers.end());

    int p = 0;
    int last_boarded = -1;
    int seats = 0;

    for (int bus : buses) {
      seats = capacity;
      while (p < passengers.size() && passengers[p] <= bus && seats > 0) {
        last_boarded = passengers[p];
        ++p;
        --seats;
      }
    }

    int ans = seats > 0 ? buses.back() : last_boarded - 1;
    unordered_set<int> taken(passengers.begin(), passengers.end());
    while (taken.count(ans)) --ans;
    return ans;
  }
};

#include "test/2332.h"
int main() { run_tests(); return 0; }
