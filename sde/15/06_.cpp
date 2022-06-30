class Solution {

  long hash(const string &s, int S) {
    long val = 0;
    for (int i=0; i<S; i++) {
      val+=s[i]-'a';
    }
    return val;
  }

  bool matches(const string &s, const string &p, int i, int M) {
    bool matching=true;
    for (int j=0; matching && j<M; j++)
      matching=s[i+j]==p[j];

    return matching;
  }

  void roll(long & pval, const string &s, int i, int M) {
    pval-=s[i]-'a';  // remove first value
    pval+=s[i+M]-'a';  // add new value
  }

  bool strStr(string s, string p) {
    const int N = (int) s.size();
    const int M = (int) p.size();

    long sval = hash(s, M);
    long pval = hash(p, M);

    // TRICKY BOUNDS
    // s: aaac
    // p: aac
    for (int i=0; i<=N-M; i++) {
      if (sval==pval && matches(s, p, i, M)) return true;

      roll(sval, s, i, M);
    }

    return false;
  }

 public:
  int repeatedStringMatch(string a, string b) {

    if (b.empty()) return 0;
    if (a==b) return 1;

    string tmp;
    int cnt=0;
    while(tmp.size() < b.size()) {
      tmp+=a;
      cnt++;
    }
    if (tmp==b) return cnt;

    // check if it matches
    if (strStr(tmp, b)) return cnt;

    cout << "not matching\n";

    // add an exrta copy and check again
    cnt++; tmp+=a;
    if (strStr(tmp, b)) return cnt;

    // else:
    return -1;
  }
};