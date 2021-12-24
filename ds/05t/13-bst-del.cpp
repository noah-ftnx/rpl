#include <vector> // for add
#include <string> // for to_string
using namespace std;

struct Node;

struct Tree {

  void add(const vector<int>& data, const string& path); // given
  string to_string(); // given

  void delete_node(int tgt);
};



#include "test/13.h"
int main() { run_tests(); return 0; }