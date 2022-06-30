class Solution {
 public:
  int compareVersion(string version1, string version2) {
    auto readRevision = [](string s, int &i) -> long {
      const int S = s.size();
      long ver=0;
      while (i<S && s[i]!='.') {
        ver*=10;
        long num = s[i]-'0';
        ver+=num;
        i++;
      }

      if (i<S) i++; // ignore dot
      return ver;
    };

    const int V1=version1.size();
    const int V2=version2.size();

    int val1=0, val2=0;
    int i=0, j=0;

    while (i<V1 || j<V2) {
      val1=readRevision(version1, i);
      val2=readRevision(version2, j);

      if (val1 < val2) return -1;
      else if (val1 > val2) return 1;
    }

    return 0;
  }
};