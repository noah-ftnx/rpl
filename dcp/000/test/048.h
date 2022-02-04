#ifndef RPL_DCP_000_TEST_048_H_
#define RPL_DCP_000_TEST_048_H_


#include <iostream>
#include <iomanip>

bool _wrong {};


// TODO string tree

string get_tree_preorder(Node* node) {
  if (node==nullptr) return "";

  string res  = node->data
         + get_tree_preorder(node->left)
         + get_tree_preorder(node->right);
  return res;
}

string get_tree_inorder(Node* node) {
  if (node==nullptr) return "";

  string res = get_tree_inorder(node->left)
      + node->data
      + get_tree_inorder(node->right);
  return res;
}

void test(deque<char> preorder, vector<char> inorder) {
  string orig_pre; for (auto p: preorder) orig_pre+=p;
  string orig_ino; for (auto i: inorder) orig_ino+=i;

  // build tree
  Node* tree = build_tree(preorder, inorder);

  // get result
  string pre = get_tree_preorder(tree);
  string ino = get_tree_inorder(tree);

  cout << "Constructed tree:\n";
  // cout << "ORIG PRE: " << orig_pre << endl;
  // cout << "ORIG INO: " << orig_ino << endl;
  cout << " RES PRE: " << pre << endl;
  cout << " RES INO: " << ino << endl;

  bool wrong = (pre!=orig_pre || ino !=orig_ino);
  _wrong|=wrong;

  cout << (wrong? "WRONG RESULT": "Correct")  << ".\n\n";
}

void run_tests() {
  test({'a', 'b', 'd', 'e', 'c', 'f', 'g'}, {'d', 'b', 'e', 'a', 'f', 'c', 'g'});
  test({'a', 'b', 'c'}, {'a', 'b', 'c'});

  if(_wrong) cout << "\nWRONG RESULTS.\n";
}

#endif  // RPL_DCP_000_TEST_048_H_
