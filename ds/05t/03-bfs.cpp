


// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------



void run_tests_trv() {
  auto t = Tree();
  t.root = new Node(10);
  t.root->left=new Node(5);
  t.root->right=new Node(25);
  t.root->right->left=new Node(20);
  t.root->right->right=new Node(30);
  t.root->left->right=new Node(7);
  t.root->left->left=new Node(3);

  cout << "VERIFY MANUALLY:\n";
  t.print_bfs();
  cout << "10 5 25 3 7 20 30 <- correct output\n";
}

int main () { run_tests(); }