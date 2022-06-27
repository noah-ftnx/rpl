class Solution {
 public:
  string reverseWords(string s) {
    if (s.empty()) return "";

    string res = "";
    bool firstWord=true;

    const int N = (int) s.size();
    for (int i=0; i<N;) {

      while(i<N && s[i]==' ') i++; // ignore spaces
      // these might be trailing spaces
      if (i==N) break;

      int j=i;
      while (j < N && s[j]!=' ') j++;
      string sub = s.substr(i, j-i);

      bool addSpace= !firstWord;

      res = sub + (addSpace? " " : "") + res; // prepend word to result

      i=j;
      firstWord=false; // no longer on 1st word
    }

    return res;
  }
};