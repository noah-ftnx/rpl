int lengthOfLongestSubstringBF(string s) {
  if (s.empty()) return 0;

  const int S = s.size();

  int mx=0;
  for (int i=0; i<S; i++) {
    unordered_set<char> st;
    int cnt=0;
    for (int j=i; j<S; j++) {
      if (st.count(s[j])) {
        // found a repeating char
        break;
      } else {
        st.insert(s[j]);
        cnt++;
        mx=max(mx, cnt);
      }
    }
  }
  return mx;
}

int lengthOfLongestSubstring(string s) {
  if (s.empty()) return 0;

  const int S = s.size();
  int mx=0, cnt=0, mnIdx=0;
  unordered_map<char, int> mp;
  for (int i=0; i<S; i++) {
    // if a new char or an "expired" char (on prev substring)
    if (mp.count(s[i]) == 0 || mp[s[i]]<mnIdx) {
      cnt++;
      mx=max(mx, cnt);

      mp[s[i]]=i;  // add or update
    } else {
      // reset count: all the chars right after prev occurence
      // until this one
      cnt=i-mp[s[i]];
      mnIdx=mp[s[i]]+1;
      // update idx
      mp[s[i]]=i;
    }
  }
  return mx;
}