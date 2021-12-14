
template <class T>
class Node {
 public:
  T data {};
  Node<T>* left {};
  Node<T>* right {};

  explicit Node(T data) : data{data} {}

  ~Node() { clear(); }

  void clear() {
    if(left) {
      delete left;
      left=nullptr;
    }
    if (right) {
      delete right;
      right=nullptr;
    }
  }
};

template <class T>
class Tree {
 private:
  Node<T>* root {};
 public:

  // CONSTRUCTORS / INSERTION
  explicit Tree() = default;

  explicit Tree(T root_value) {
    root = new Node<T>(root_value);
  }

  explicit Tree(Node<T>* root) : root{root} {}

  ~Tree() {
    delete root;
  }

  void print_bfs() { // print before
    queue<Node<T>*> q;
    q.push(root);
    while(!q.empty()) {
      auto node = q.front(); q.pop();
      cout << node->data << " ";
      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
    }
    cout << endl;
  }
};

int main () {

}