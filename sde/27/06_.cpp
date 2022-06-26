struct Node {
  Node* child[2];

  bool has(bool i) { return child[i] != nullptr; }
  Node* get(bool i) { return child[i]; }
  void put(bool i) { child[i]=new Node(); }
};

struct Trie {
  Node* root = new Node();

  void insert(int num) {
    Node *node = root;
    for (int i=31; i>=0; i--) {
      bool bitSet = (num>>i) & 1;

      if (!node->has(bitSet)) node->put(bitSet);
      node=node->get(bitSet);
    }
  }

  int mxor(int num) {
    // try to match w/ the opposite num if possible
    Node *node = root;
    int sum = 0;
    for (int i=31; i>=0; i--) {
      bool bitSet = (num>>i) & 1; // might be 0 or 1
      bool opposite = !bitSet;
      bool useBit;

      if (node->has(opposite)) { // take it
        // this will lead to bigger num
        useBit=1; // xor will be '1'
        node=node->get(opposite);
      } else { // take bitSet
        useBit=0; // xor will be '1'
        node=node->get(bitSet);
      }

      // we have a useBit (0 or 1) at position: i
      // if 0: dont to anything
      if (useBit) { // add to sum
        sum+= (1 << i);
      }
    }
    return sum;
  }
};

class Solution {
 public:
  int findMaximumXOR(vector<int>& nums) {
    Trie trie;
    for (auto num: nums) {
      trie.insert(num);
    }
    int mx=0;
    for (auto num: nums) {
      mx=max(mx, trie.mxor(num));
    }
    return mx;
  }
};