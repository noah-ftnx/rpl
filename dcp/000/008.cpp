#include <utility>
using namespace std;

struct Node {
  int value;
  Node* left;
  Node* right;
  Node(int v) : value{v}, left{nullptr}, right{nullptr} {}
};

// IMPLEMENT: count_unival
int count_unival(Node* node);

#include "test/008.h"
int main() { run_tests(); }