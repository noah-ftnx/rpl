#include <vector>
using namespace std;

struct Node;

class Solution {
 public:
  // IMPLEMENT: top view of a binary tree
  vector<int> topView(Node *root);
};

#include "test/08.h"
int main() { run_tests(); return 0; }
