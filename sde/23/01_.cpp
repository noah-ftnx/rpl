#include <unordered_map>
using namespace std;

class Solution2 { // no need for separate visited set

  Node* dfsCreateNodes(Node* node, unordered_map<Node*, Node*> &mp) {
    // visit:
    auto cpy = new Node(node->val);
    mp[node]=cpy; // mapping from orig node to the cpy

    for (auto nei: node->neighbors) {
      if (mp.count(nei) == 0) {
        dfsCreateNodes(nei, mp);
      }

      // push the newly created node in the adjacency list
      cpy->neighbors.push_back(mp[nei]);
    }

    return cpy;
  }

 public:
  Node* cloneGraph(Node* node) {
    if (node==nullptr) return nullptr;

    unordered_map<Node*, Node*> mp;
    auto clone=dfsCreateNodes(node, mp);

    return clone;
  }
};