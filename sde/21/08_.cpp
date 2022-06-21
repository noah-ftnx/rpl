#include <sstream>
#include <deque>
#include <string>
using namespace std;

class Codec {
public:

 // Encodes a tree to a single string.
 string serialize(TreeNode* root) {
   if (root==nullptr) return "\n";

   return to_string(root->val) + "\n" +
          serialize(root->left) + serialize(root->right);
 }

 TreeNode* dfs(stringstream &iss) {
   if (iss.eof()) return nullptr;

   string str;
   getline(iss, str);

   if (str.empty()) return nullptr;

   auto node = new TreeNode(stoi(str));
   node->left=dfs(iss);
   node->right=dfs(iss);

   return node;
 }

 // Decodes your encoded data to tree.
 TreeNode* deserialize(string data) {
   stringstream iss(data);
   return dfs(iss);
 }
};