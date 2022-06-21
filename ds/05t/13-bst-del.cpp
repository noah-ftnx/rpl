#include "test/13-pre.h"

struct Node; // TODO
  // member: int: data

struct Tree {
  Node *root; // taken care by ctor
  Tree(int n); // given

  void delete_node(int tgt); // TODO


  void add(const vector<int>& data, const string& path); // given
  string to_string(); // given
};



#include "test/13.h"
int main() { run_tests(); return 0; }