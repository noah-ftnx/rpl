#ifndef RPL_DS_05T_TEST_10_CPFIX_H_
#define RPL_DS_05T_TEST_10_CPFIX_H_

#include <iostream>
string _to_string(const Node* root, Node* node) {
  if (node == nullptr) return "";

  bool skipParenthesis = (!node->left && !node->right);
  skipParenthesis|=node==root;

  string res;
  if (!skipParenthesis) res+="(";
  res+=_to_string(root, node->left) + node->data + _to_string(root, node->right);
  if (!skipParenthesis) res+=")";
  return res;
}

string Tree::to_string() { return _to_string(root, root); }

void check(string postfix, string result) {
  auto tree = Tree(postfix);
  string prt = tree.to_string();
  cout << postfix << ": '" << prt << "' " << (prt != result? " (WRONG)":"") << endl;
}

void run_tests() {
  check("2", "2");
  check("23+", "2+3");
  check("23+4*", "(2+3)*4");
  check("51+2/", "(5+1)/2");
  check("135*+72/-", "(1+(3*5))-(7/2)");
  check("534*2^+", "5+((3*4)^2)");
  // invalid postfix?
  // check("24", "");
  // check("23+4", "");
}

#endif  // RPL_DS_05T_TEST_10_CPFIX_H_
