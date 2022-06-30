class SolutionSol1 {
 public:
  bool isAnagram(string s, string t) {
    const int S = s.size();
    const int T = t.size();
    if (S != T) return false;

    vector<int> st(26, 0);
    for (auto c: s) st[c-'a']++;

    for (auto c: t) st[c-'a']--;

    for (int n: st) if (n != 0) return false;
    return true;
  }
};
