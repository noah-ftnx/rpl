#include <cassert>
#include <string>
using namespace std;

struct Node {
  Node* next;
  char data;
  Node(char d) : data{d} {}
};

class Stack {
 private:
  Node* _top {};

 public:
  bool empty() { return _top == nullptr; }

  void push(char c) {
    auto old=_top;
    _top=new Node(c);
    _top->next=old;
  }

  char top() {
    assert(!empty());
    return _top->data;
  }

  void pop() {
    _top=_top->next;
  }

};

bool match_parenthesis(string input) {
  Stack st;

  auto is_opening = [](char c) { return c == '(' || c == '[' || c == '{'; };
  auto is_closing = [](char c) { return c == ')' || c == ']' || c == '}'; };
  auto match = [](char a, char b) { // or a map
    switch(a) {
      case '(': return b == ')';
      case '{': return b == '}';
      case '[': return b == ']';
    }
    return true;
  };

  for (auto c: input) {
    if (is_opening(c)) {
      st.push(c);
    } else if (is_closing(c)) {
      if (!match(st.top(), c)) return false;
      st.pop();
    } else {
      // maybe ignore or die (depends on what we want..)
    }
  }

  return st.empty();  // must be empty
}

#include <map>
bool match_parenthesis_with_map(string input) {
  Stack st;

  auto is_opening = [](char c) { return c == '(' || c == '[' || c == '{'; };
  auto is_closing = [](char c) { return c == ')' || c == ']' || c == '}'; };

  map<char, char> mp;
  mp.insert({')','('});
  mp.insert({']','['});
  mp.insert({'}','{'});

  for (auto c: input) {
    if (is_opening(c)) {
      st.push(c);
    } else if (mp.contains(c)) {
      if (mp[c]!=st.top()) return false;
      st.pop();
    } else {
      // maybe ignore or die (depends on what we want..)
    }
  }

  return st.empty();  // must be empty
}



#include "test/027.h"
int main() { run_tests(); return 0; }