class Solution {
  pair<int, int> expand(const string &s, int l, int r) {
    const int N = s.size();

    // expand only when: in bounds and chars match
    while (l-1>=0 && r+1 < N && s[l-1]==s[r+1]) {
      l--; r++;
    }

    return {l, r}; // range of substring
  }

  pair<int, int> expandFrom(const string &s, int i) {
    const int N = s.size();
    auto l1 = expand(s, i, i);
    auto l2 = make_pair(i, i);
    // if in limits, and chars match: might be the `abba` type
    if (i+1 < N && s[i]==s[i+1]) {
      l2 = expand(s, i, i+1);
    }

    int sz1=l1.second-l1.first+1;
    int sz2=l2.second-l2.first+1;

    return sz1>sz2? l1 : l2;
  }

 public:
  string longestPalindrome(string s) {
    if (s.empty()) return "";

    const int N = (int) s.size();
    int mxLen=0;
    pair<int, int> res {0, 0};
    for (int i=0; i<N; i++) {
      auto p = expandFrom(s, i);
      int len = p.second-p.first+1;
      if (len > mxLen) {
        mxLen=len;
        res=p;
      }
    }

    return s.substr(res.first, mxLen);
  }
};