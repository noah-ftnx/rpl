#include <vector>
using namespace std;

// For each value, replace it with the next greater value on its right.
// Use -1 if no greater value exists.
// IMPLEMENT: find_next_greater_element
void find_next_greater_element(vector<int> &vec);

#include "test/01-next-greater.h"
int main() { run_tests(); return 0; }
