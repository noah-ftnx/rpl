class Solution {
 public:
  string countAndSay(int n) {
    auto getHist = [](string s) -> string {
      const int S = (int) s.size();
      string res;

      int cnt=1;
      for (int i=1; i<S; i++) {
        if (s[i]==s[i-1]) {
          cnt++;
        } else {
          // flush to output
          res+=to_string(cnt)+s[i-1];
          cnt=1;
        }
      }
      // add the last count: 1
      res+=to_string(cnt)+s[S-1];
      return res;
    };

    if (n<=0) return "";

    // for n=1: return "1": hence: --n
    string s = "1";
    while (--n) { s=getHist(s); }
    return s;
  }
};