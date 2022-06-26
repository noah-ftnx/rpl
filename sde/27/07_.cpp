struct Node {
  Node *child[2];
  Node() {
    child[0]=child[1]=nullptr;
  }

  void put (bool ch) { child[ch] = new Node(); }
  bool has(bool ch) { return child[ch] != nullptr; }
  Node* get(bool ch) { return child[ch]; }

  bool isEmpty() { return child[0]==nullptr && child[1]==nullptr; }
};


struct Trie {
  Node *root = new Node();
  void insert(int num) {
    Node *node = root;
    for (int i=31; i>=0; i--) {
      bool bitSet = (num>>i)&1;

      if (!node->has(bitSet)) node->put(bitSet);
      node=node->get(bitSet);
    }
  }

  int mxor(int num) { // O(32)
    if (root->isEmpty()) return -1;

    Node *node = root;
    int sum=0;
    for (int i=31; i>=0; i--) {
      bool bitSet = (num>>i)&1; // can be 1 or 0
      bool oppositeBit = !bitSet;

      if (node->has(oppositeBit)) {
        // can use this bit
        // add it to the sum
        sum+=(1 << i);
        node=node->get(oppositeBit);
      } else {
        node=node->get(bitSet);
      }
    }

    return sum;
  }
};

class Solution {
 public:
  vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    if (nums.empty() || queries.empty()) return {};

    const int N = (int) nums.size();
    const int Q = (int) queries.size();
    vector<int> res(Q);

    // so we can add just the nums needed
    sort(nums.begin(), nums.end());

    // store the index before sorting the queries..
    int i=0;
    for (auto &query: queries) query.push_back(i++);
    // sort queries according to maxNum
    sort(queries.begin(), queries.end(), [](const vector<int> &q1, const vector<int>  &q2) {
      int mx1 = q1[1];
      int mx2 = q2[1];

      return mx1 < mx2;
    });

    Trie trie;
    i=0; // numbers added
    for (auto query: queries) {
      const int xorNum = query[0];
      const int maxNum = query[1];
      const int queryIdx = query[2];

      // Build a trie iteratively
      // add extra numbers according to cur query..
      while (i< N && nums[i] <= maxNum) {
        trie.insert(nums[i++]);
      }

      res[queryIdx]=trie.mxor(xorNum);
    }

    return res;
  }
};
