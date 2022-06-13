class Solution {
 private:

  void findLimits(Node *node,
                  int idx, int &limitL, int &limitR) {
    if (node==nullptr) return;

    limitL=min(limitL, idx);
    limitR=max(limitR, idx);

    findLimits(node->left, idx-1, limitL, limitR);
    findLimits(node->right, idx+1, limitL, limitR);
  }

 public:
  vector <int> bottomView(Node *root) {
    int limitL=INT_MAX, limitR=INT_MIN;
    findLimits(root, 0, limitL, limitR);
    limitL=abs(limitL); // convert to positive

    const int SIZE = limitL + 1 + limitR;
    vector<int> res(SIZE);

    // do level-order traversal
    struct Item {
      Node *node;
      int idx;
    };
    queue<Item> q;
    q.push({root, limitL});

    while(!q.empty()) {
      int levelNodes=q.size();
      while (levelNodes--) {
        auto item = q.front(); q.pop();
        res[item.idx] = item.node->data;

        if (item.node->left) q.push({item.node->left, item.idx-1});
        if (item.node->right) q.push({item.node->right, item.idx+1});
      }
    }

    return res;
  }
};
