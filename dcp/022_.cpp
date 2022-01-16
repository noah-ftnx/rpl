#include <vector>
#include <string>
using namespace std;

struct Node {
  static const int SZ=26;
  Node* child[SZ];
  bool word {};

  bool has(char c) { return child[c-'a'] != nullptr; }
  Node* get(char c) { return child[c-'a']; }
  void put(char c) { child[c-'a']=new Node(); }
};


struct Trie {
  Node* root = new Node();

  void insert(vector<string> dict) { for (auto s: dict) insert(s); }
  void insert(string word) {
    auto node = root;
    for (auto c: word) {
      if(!node->has(c)) node->put(c);
      node=node->get(c);
    }
    node->word=true;
  }

  void _break_words(Node* node, string input, int i, vector<vector<string>>& result, string cur_word) {
    if (node==nullptr) {  // dead end
      result.pop_back();
      return;
    } else if (i==input.size()) { // last char
      if (node->word) result.back().push_back(cur_word);
      else result.clear();
      return;
    }

    const char c = input[i]; // next char..
    if (node->word) {
      result.back().push_back(cur_word);

      // start over
      string new_word {};
      _break_words(root->get(c), input, i+1, result, new_word+c);

      // and keep trying.. for longer word.. as a new attempt...
      result.push_back({});
      _break_words(node->get(c), input, i+1, result, cur_word+c);
    } else {
      _break_words(node->get(c), input, i+1, result, cur_word+c);
    }

  }

  void break_words(string input, vector<vector<string>>& result) {
    result.push_back({}); // TRICKY!
    _break_words(root, input, 0, result, "");
  }
};


vector<vector<string>> search_dict(vector<string> dict, string input) {
  Trie t;
  t.insert(dict); // O(N*L): N: #words, L: longest word

  vector<vector<string>> result;
  t.break_words(input, result); //O(2^N)
  return result;
}



#include "test/022.h"
int main() { run_tests(); return 0; }