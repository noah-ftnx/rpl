#ifndef RPL_DS_05T_TEST_10_CPFIX_H_
#define RPL_DS_05T_TEST_10_CPFIX_H_

#include <stack>
Tree::Tree(const string& postfix) {
  stack<Node*> st;
  for (auto c: postfix) {
    Node* node = new Node(c);
    if (!isdigit(c)) { // symbol
      auto rhs = st.top(); st.pop();
      auto lhs = st.top(); st.pop();
      node->left=lhs;
      node->right=rhs;
      // up navigation
      node->left->parent=node;
      node->right->parent=node;
    }
    st.push(node);
  }
  root = move(st.top());
}

void check(string postfix, string result) {
  auto tree = Tree(postfix);
  string prt = tree.to_string();
  cout << postfix << ": " << prt << (prt != result? " (WRONG)":"") << endl;
}

void run_tests() {
  check("2", "2");
  check("23+", "2+3");
  check("23+4*", "(2+3)*4");
  check("51+2/", "(5+1)/2");
  check("135*+72/-", "(1+(3*5))-(7/2)");
  check("534*2^+", "5+((3*4)^2)");
}

#endif  // RPL_DS_05T_TEST_10_CPFIX_H_
