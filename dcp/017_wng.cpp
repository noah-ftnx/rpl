#include <string>
#include <vector>
using namespace std;

#include <iostream>
#include <iomanip>

struct Node {
  int start, end; // string indexes
  int len;
  int depth;
  bool folder {};

  Node(int start, int end, int depth, bool folder) :
      start{start}, end{end}, depth{depth}, folder{folder} {
    len=end-start+1;
  }

  string name(string fullpath) {
    return fullpath.substr(start, len) + " D:" + to_string(depth) + " l:" + to_string(len);
  }

  vector<Node*> child;
};


int _find_max(Node* node, const string& path) {
  // a
  // a/b
  // a/b/c
  if (node->child.empty()) {
    cout << "leaf node: " << setw(20) << node->name(path)  << " MAX: " << (node->len +1) << endl;
    return node->len+1;
  }

  int res {};
  for (auto child: node->child) {
    cout << " par node: " << setw(20) << node->name(path) << " of " << setw(20) << child->name(path) << endl;//  << " MAX: " << node_max << endl;
    int node_max = _find_max(child, path)+node->len+1;
    res = max(res, node_max);
  }
  return res;
}

int find_max(const vector<Node*> tree, const string& path) {
  int res = 0;
  for (auto root: tree) {
    res = max(res, _find_max(root, path))-1;
  }
  return res;
}

// "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"
// dir\n
// \t subdir1 \n
// \t subdir2 \n
// \t \t file.ext
int longest_path(string fsys) {
  if (path.empty()) return 0;

  vector<Node*> tree; // root folders
  vector<Node*> cur_folders; // keeps the last folder at each depth

  int start = 0;
  int depth = 0;
  bool folder = true;
  if (fsys.back() != '\n') fsys.push_back('\n');
  for (int i=start; i<fsys.size(); i++) { // O(P): path length
    char c = fsys[i];
    if (c == '\n') { // ending
      const int end = i-1;
      Node* node = new Node(start, end, depth, folder);

      if (folder) {
        if (depth==0) tree.push_back(node);  // root directories
          // keep only the last folder per depth
        else while (depth<=cur_folders.back()->depth) cur_folders.pop_back();  // TRICKY
      }

      // link file/folder to parent folder
      if (!cur_folders.empty()) cur_folders.back()->child.push_back(node);

      // add current depth folder
      if (folder) cur_folders.push_back(node);

      // reset for next iteration
      start=i+1; // next start idx
      folder=true;
      depth=0;
    } else if (c == '\t') { // adjust depth & starting index
      depth++;
      start=i+1;
    } else if(c=='.') {
      folder=false;
    }
  }

  return find_max(tree, fsys);
}



#include "test/017.h"
int main() { run_tests(); return 0; }