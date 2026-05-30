#include <vector>
using namespace std;

// IMPLEMENT: search target in rotated sorted array
int search(vector<int>& nums, int target);

#include "test/04.h"
int main() { run_tests("Search in Rotated Sorted Array", search); return 0; }
