#include <algorithm>
#include <climits>
#include <queue>
#include <set>
#include <vector>
using namespace std;

struct Node;

class Solution {
 private:
  void findLimits(Node *node, int idx, int &limitL, int &limitR);

 public:
  vector<int> topView(Node *root);
};

#include "test/08.h"

void Solution::findLimits(Node *node, int idx, int &limitL, int &limitR) {
  if (node==nullptr) return;
  limitL=min(limitL, idx);
  limitR=max(limitR, idx);
  findLimits(node->left, idx-1, limitL, limitR);
  findLimits(node->right, idx+1, limitL, limitR);
}

vector<int> Solution::topView(Node *root)
{
  if (root==nullptr) return {};

  int limitL=1, limitR=-1;
  findLimits(root, 0, limitL, limitR);
  limitL=abs(limitL);

  const int SIZE = limitL + 1 + limitR;

  struct Item { Node* node; int idx; };
  int itemsSet=0;

  vector<int> topView(SIZE, INT_MIN);
  queue<Item> q;
  q.push({root, limitL});

  while (!q.empty()) {
    int levelNodes=q.size();
    while(levelNodes--) {
      auto item = q.front(); q.pop();
      if (topView[item.idx] == INT_MIN) {
        topView[item.idx]=item.node->data;
        itemsSet++;
        if (itemsSet == SIZE) return topView;
      }

      if (item.node->left) q.push({item.node->left, item.idx-1});
      if (item.node->right) q.push({item.node->right, item.idx+1});
    }
  }
  return topView;
}

int main() { run_tests(); return 0; }
