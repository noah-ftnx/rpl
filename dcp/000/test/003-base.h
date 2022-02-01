#ifndef RPL_DCP_TEST_003_BASE_H_
#define RPL_DCP_TEST_003_BASE_H_

struct Node {
  Node* left {};
  Node* right {};
  string val;
  Node(string val, Node* left=nullptr, Node* right=nullptr) :
      val{val}, left{left}, right{right} {}
};

struct Tree {
  Node *root{};

  explicit Tree() = default;

  Tree(Node* node) : root{node} {}

  void input_perfect();
  void input_full1();
  void input_full2();
  void input_nonbst();
  void input_bst();

  string __get_bfs();

  string serialize();
  static Tree* deserialize(const string& str);
};


#endif  // RPL_DCP_TEST_003_BASE_H_
