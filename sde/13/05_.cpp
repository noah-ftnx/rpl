#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    if (s.empty()) return true;
    stack<char> st;
    const int S = s.size();
    unordered_map<char, char> mp;
    mp.insert({'}','{'});
    mp.insert({')','('});
    mp.insert({']','['});

    auto isOpening = [&](int i) {
      return mp.count(s[i])==0; // not exist in the map
    };

    auto isMatching = [&] (int i) {
      char c = s[i];
      // stack must match the parenthesis
      return !st.empty() && st.top() == mp[c];
    };

    for (int i=0; i<S; i++) {

      if (isOpening(i)) {
        st.push(s[i]);
      } else {
        if (isMatching(i)) {
          st.pop();
        } else return false;
      }
    }

    return st.empty();
  }
};