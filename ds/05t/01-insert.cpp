#include <queue>

class Tree {

  ///////////// for verification
  string __get_bfs() {
    queue<Node<T>*> q;
    q.push(root);
    string r;
    while (!q.empty()) {
      auto n=q.front();
      q.pop();
      r+= std::to_string(n->data) + " ";
      if (n->left) q.push(n->left);
      if (n->right) q.push(n->right);
    }
    return r;
  }
  /////////////
};



// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------



vector<string> correct_bfs {
    "1 2 4 5 8 9 10 11 ",
    "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 ",
};

string Tree::__get_bfs() {
  queue<Node<T>*> q;
  q.push(root);
  stringstream ss;
  while (!q.empty()) {
    auto node = q.front();
    q.pop();
    ss << node->data << " ";
    if (node->left) q.push(node->left);
    if (node->right) q.push(node->right);
  }
  return ss.str();
}

void run_tests() {
  auto tree = Tree<int>(1);
  tree.add( { 2, 4, 8 }, { 'L', 'L', 'L' });
  tree.add( { 2, 4, 9 }, { 'L', 'L', 'R' });
  tree.add( { 2, 5, 10 }, { 'L', 'R', 'L' });
  tree.add( { 2, 5, 11 }, { 'L', 'R', 'R' });
  string ss1=tree.__get_bfs();
  cout << ss1  << (ss1.compare(correct_bfs[0])!=0?" (WRONG)": "")<< endl;

  tree.add( { 3, 6, 12 }, { 'R', 'L', 'L' });
  tree.add( { 3, 6, 13 }, { 'R', 'L', 'R' });
  tree.add( { 3, 7, 14 }, { 'R', 'R', 'L' });
  tree.add( { 3, 7, 15 }, { 'R', 'R', 'R' });
  string ss2=tree.__get_bfs();
  cout << ss2  << (ss2.compare(correct_bfs[1])!=0?" (WRONG)": "")<< endl;
}


int main() { run_tests(); }