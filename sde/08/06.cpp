#include <vector>
using namespace std;

// Given activity start/end times, return the maximum number of activities
// one person can perform.
// An activity ending at time T does not block another starting at time T.
// IMPLEMENT: maximumActivities
int maximumActivities(vector<int> &start, vector<int> &finish);

#include "test/06.h"
int main() { run_tests(); return 0; }
