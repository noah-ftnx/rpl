#include <vector>
using namespace std;

struct Job {
  int id;
  int dead;
  int profit;
};

// Return {jobsDone, totalProfit}.
// IMPLEMENT: JobScheduling
vector<int> JobScheduling(Job arr[], int n);

#include "test/03.h"
int main() { run_tests(); return 0; }
