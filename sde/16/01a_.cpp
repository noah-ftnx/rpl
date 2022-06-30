class SolutionNaive {
 public:
  int strStr(string haystack, string needle) {
    if (needle.empty()) return 0;
    const int H = (int) haystack.size();
    const int N = (int) needle.size();
    if (N>H) return -1;

    // 'a' -> 'a'
    for (int i=0; i<=H-N; i++) {
      bool matching=true;
      for (int j=0; matching && j<N; j++) {
        if (haystack[i+j]!=needle[j]) matching=false;
      }
      if (matching) return i;
    }
    return -1;
  }
};