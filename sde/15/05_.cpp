class SolutionSlower {
  int maxCommonChars(const string &a, const string &b, int cap) {
    int i=0, j=0;
    const int A = (int) a.size(), B = (int) b.size();
    while (i<A && j<B && a[i] == b[j]) {
      i++; j++;
      // cap: optimization: wont match more than that
      if (i==cap) break;
    }

    return i;
  }

 public:
  string longestCommonPrefix(vector<string>& strs) {
    const int N = (int) strs.size();
    if (N==0) return "";
    if (N==1) return strs[0];

    int lcp=strs[0].size();
    for (int i=0; i<N-1; i++) {
      string s1=strs[i];
      string s2=strs[i+1];
      lcp=min(lcp, maxCommonChars(s1, s2, lcp));
      if (lcp==0) return "";
    }

    return strs[0].substr(0, lcp);
  }
};


class SolutionSleek {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    string res ="";
    if (strs.empty()) return "";

    const int N = (int) strs.size();

    int mxPrefix = strs[0].size();
    for (int i=0; i<mxPrefix; i++) {

      // trying to match this char from each other string
      char c = strs[0][i];
      for (int j=1; j<N; j++) {
        string s = strs[j];
        const int S = (int) s.size();

        if (i>=S) return res; // bounds exceeded (for this particular string)

        if (strs[j][i] != c) return res; // not matching


        mxPrefix=min(mxPrefix, S); // update bounds
      }

      res+=c; // expand answer
    }

    return res;
  }
};