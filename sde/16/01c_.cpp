class SolutionRabinKarb {
  long hash(const string& s, int l) {
    long val=0;
    for (int i=0; i<l; i++) val+=s[i]-'a';
    return val;
  }

  void roll_hash(const string& s, int &pval, int M, int i) {
    pval-=s[i]-'a'; // remove first char
    pval+=s[i+M]-'a'; // add last char
  }

 public:
  int strStr(string haystack, string needle) {
    const int N = (int) haystack.size();
    const int M = (int) needle.size();

    auto verify = [&] (int i) {
      int j=0;
      while (j<M) {
        if (haystack[i++]!=needle[j++]) return false;
      }
      return true;
    };

    if (needle.empty()) return 0;
    if (M > N) return -1;

    int hval=hash(needle, M);
    int rval = hash(haystack, M);

    // 0 1 2 3 4 5
    // a b c
    // a a a a b c
    for (int i=0; i<=N-M; i++) {
      if (hval==rval && verify(i)) return i;

      roll_hash(haystack, rval, M, i);
    }
    return -1;
  }
};