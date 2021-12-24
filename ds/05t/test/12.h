#ifndef RPL_DS_05T_TEST_12_H_
#define RPL_DS_05T_TEST_12_H_

#include <string>
#include <iostream>
template <class T>
void Tree<T>::add(const vector<T>& data, const string& path) {
  if(data.size() != (path.size())) { cout << "ERR\n"; exit(-1); }

  Node<T>* node = root;
  auto itd=data.begin();
  auto itp=path.begin();
  for(; itd!=data.end(); itd++, itp++) {
    if(*itp=='L') { // LEFT NODE
      if (node->left == nullptr) {
        node->left = new Node<T>(*itd);
        node->left->parent = node;
      } else {
        assert(node->left->data == *itd);
      }
      node = node->left;
    } else if(*itp=='R') { // RIGHT NODE
      if(node->right == nullptr) {
        node->right = new Node<T>(*itd);
        node->right->parent=node;
      } else {
        assert(node->right->data == *itd);
      }
      node=node->right;
    }
  }
}

void run_tests() {
  auto tree = new Tree<int>(50);
  tree->add( {20, 15, 16}, "LLR");
  tree->add( {20, 45, 35, 36}, "LRLR");
  tree->add( {60, 58}, "RL");
  tree->add( {60, 70, 73, 75}, "RRRR");

  deque<int> answer;
  deque<int> query{15, 20, 58};

  cout << "query: ";
  for (auto q: query) cout << q << " "; cout << endl;

  tree->query_successors(query, answer);

  // parse result
  string result;
  if (!query.empty()) {
    result+="unsolved: ";
    for (auto a: query) result+=to_string(a) +" ";
  }
  result+="\nsolution: ";
  for (auto a: answer) result+= to_string(a) + " ";
  result+="\n";
  cout << result;

  string correct = "unsolved: 58 \n"
                   "solution: 16 35 \n";
  cout << endl << (result!=correct?"(WRONG)":"correct result.") << endl;

}

#endif  // RPL_DS_05T_TEST_12_H_
