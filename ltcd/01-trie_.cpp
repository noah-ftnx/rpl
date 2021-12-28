#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

struct Node {
  unordered_map<char, Node*> child;
  bool leaf;

  bool has(char c) { return child.contains(c); }
  void put(char c) { child.insert(make_pair(c, new Node())); }
  Node* get(char c) { return has(c)? child[c]:nullptr; }
};

class Solution {
 private:
  Node* root = new Node();

  void insert(const string& s) {
    assert(s.size() > 0);
    auto node = root;
    for (auto c: s) {
      if (!node->has(c)) node->put(c);
      node=node->get(c);
    }
    node->leaf = true;
  }

  void insert(const vector<string>& dict) { for (auto w: dict) insert(w); }

  string minimal_prefix(const string& word) {
    auto node = root;
    for (int i=0; i<word.size(); i++) {
      const char c = word[i];
      if (node->leaf) { return word.substr(0, i); } // found
      if (!node->has(c)) { return word; }
      node=node->get(c);
    }
    return word;
  }

 public:
  string replaceWords(vector<string>& dictionary, string sentence) {
    insert(dictionary); // create dict

    string result="";
    int s=0;
    for (int i=0; i<sentence.size(); i++) {
      const char c = sentence[i];
      if (c == ' ' || i == sentence.size()-1) { // found word
        string word = sentence.substr(s, i-s);
        string replacement = minimal_prefix(word);
        result += replacement + " ";
        s=i+1; // next word start
      }
    }
    result.pop_back();
    return result;
  }
};



#include "test/01.h"
int main() { run_tests(); return 0; }