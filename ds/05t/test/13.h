#ifndef RPL_DS_05T_TEST_13_H_
#define RPL_DS_05T_TEST_13_H_

#include <iostream>
#include <iomanip>

void Tree::add(const vector<int>& data, const string& path) {
  if(data.size() != (path.size())) { cout << "ERR\n"; exit(-1); }

  Node* node = root;
  auto itd=data.begin();
  auto itp=path.begin();
  for(; itd!=data.end(); itd++, itp++) {
    if(*itp=='L') { // LEFT NODE
      if (node->left == nullptr) {
        node->left = new Node(*itd);
      } else {
        assert(node->left->data == *itd);
      }
      node = node->left;
    } else if(*itp=='R') { // RIGHT NODE
      if(node->right == nullptr) {
        node->right = new Node(*itd);
      } else {
        assert(node->right->data == *itd);
      }
      node=node->right;
    }
  }
}

string _to_string(Node* node) {
  if (node == nullptr) return ".";
  return _to_string(node->left) + to_string(node->data) + _to_string(node->right);
}

string Tree::to_string() { return _to_string(root); }


Tree::Tree(int n) {
  root = new Node(n);
}


void check(Tree* tree, string msg, string correct) {
  string res = tree->to_string();
  cout << setw(40) << res << " \t " << msg <<(res!=correct? "\t\t (WRONG)":"")  << endl;
}

void run_tests() {
  auto tree = new Tree(50);
  tree->add({20, 15, 16}, "LLR");
  tree->add({20, 45, 35, 36}, "LRLR");
  tree->add({60, 58}, "RL");
  tree->add({60, 70, 73, 75}, "RRRR");

  cout << setw(40) << "TREE (inorder)"<< " \t " << "STATE\n";
  check(tree, "initial", ".15.16.20.35.36.45.50.58.60.70.73.75.");

  tree->delete_node(90);
  check(tree, "del 90 which does not exist.", ".15.16.20.35.36.45.50.58.60.70.73.75.");
  tree->delete_node(70);
  check(tree, "del 70.", ".15.16.20.35.36.45.50.58.60.73.75.");
  tree->delete_node(60);
  check(tree, "del 60.", ".15.16.20.35.36.45.50.58.73.75.");
  tree->delete_node(50);  // head
  check(tree, "del 50 (head).", ".15.16.20.35.36.45.58.73.75.");

  tree->delete_node(15);
  check(tree, "del 15.", ".16.20.35.36.45.58.73.75.");
  tree->delete_node(45);
  check(tree, "del 45.", ".16.20.35.36.58.73.75.");
  tree->delete_node(20);
  tree->delete_node(16);
  tree->delete_node(35);
  check(tree, "del 20,16,35.", ".36.58.73.75.");
  tree->delete_node(75);
  tree->delete_node(36);
  check(tree, "del 75, 36.", ".58.73.");
  tree->delete_node(73);
  tree->delete_node(58);
  check(tree, "del 58.", ".");
}

#endif  // RPL_DS_05T_TEST_13_H_