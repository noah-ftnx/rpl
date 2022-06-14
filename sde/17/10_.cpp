
#include <queue>
using namespace std;

class SolutionCOMPLEX {
 public:
  void findLimits(TreeNode* node, int idx, int &limitL, int &limitR) {
    if (node==nullptr) return; // base case

    limitL=min(limitL, idx);
    limitR=max(limitR, idx);

    findLimits(node->left, idx-1, limitL, limitR);
    findLimits(node->right, idx+1, limitL, limitR);
  }

  vector<vector<int>> verticalTraversal(TreeNode* root) {
    if(root==nullptr) return {{}};

    // find left-most and right-most limits
    int limitL=0, limitR=0;
    findLimits(root, 0, limitL, limitR); // -10, 3
    limitL=abs(limitL);

    const int COLUMNS=limitL+1+limitR;
    vector<vector<int>> res(COLUMNS, vector<int>());

    struct Item {
      TreeNode* node;
      int  col;
    };


    queue<Item> q;
    // must sort nodes on same coordinates
    int row=-1;
    q.push({root, limitL});

    while(!q.empty()) {
      int levelItems=q.size();
      row++;

      vector<int> visited(COLUMNS, 0);  // visited columns (for sorting)
      while(levelItems--) { // on same row (level)
        auto item = q.front(); q.pop();

        // add new item:
        res[item.col].push_back(item.node->val);
        // cout << "push: " << item.node->val << " ";

        visited[item.col]++;
        if (visited[item.col] > 1) { // already visited:
          // sort last 2 elements (newly inserted and prev one)
          // they have the same row (due to level-order) and same column
          sort(res[item.col].end()-visited[item.col], res[item.col].end(), less<int>());
          cout << "sorting: ";
        } else {
          cout << "       : ";
        }


        cout << "row: " << setw(2) << row << " col: " << setw(2) << item.col
             << " val: " << setw(3) << item.node->val << endl;

        if (item.node->left) q.push({item.node->left, item.col-1});
        if (item.node->right) q.push({item.node->right, item.col+1});
      }
    }
    return res;
  }
};








/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <set>
#include <map>
using namespace std;
class Solution {
 public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    if (root==nullptr) return {{}};
    // KEY -> VAL
    // COL -> MAP
    //         KEY -> VALS
    //         ROW -> values
    map<int, map<int, multiset<int>>> mp;

    struct Item {
      int col;
      int row;
      TreeNode* node;
    };

    queue<Item> q;
    q.push({0, 0, root});

    while(!q.empty()) {
      int levelItems=q.size();
      while(levelItems--) {
        auto item = q.front(); q.pop();
        mp[item.col][item.row].insert(item.node->val);

        if (item.node->left)  q.push({item.col-1, item.row+1, item.node->left});
        if (item.node->right) q.push({item.col+1, item.row+1, item.node->right});
      }
    }

    vector<vector<int>> res;
    // TODO reconstruct answer from mp
    // each item: will have multi maps per level
    for (auto cols: mp) { // K:V col, multimaps
      vector<int> vertical;

      for (auto mmp: cols.second) {
        // items in each multimap will be sorted
        // just append the  to the result
        for (auto val: mmp.second) vertical.push_back(val);
      }
      res.push_back(vertical);
    }
    return res;
  }
};