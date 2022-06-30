bool isPalindrome(string s, int i, int j) {
  while (i<j) {
    if (s[i] != s[j]) return false;
    i++; j--;
  }

  return true;
}

int Solution::solve(string A) {
  if (A.empty()) return 0;

  int N = A.size();

  // max palindrome that starts at i
  int mx=1;
  for (int j=N-1; j>0; j--) {
    if (A[0]==A[j] && isPalindrome(A, 0, j)) {
      mx=j+1;
      // iMx=i;
      break;
    }
  }

  return N-mx;
}



int SolutionOPT::solve(string A) {
  if (A.size() <= 1) return 0;

  const int N = A.size();
  string tmp = A;
  reverse(A.begin(), A.end());
  tmp+="$"+A;

  const int T = tmp.size();
  vector<int> lps(T, 0);
  int prev=0, i=1;
  while(i<T) {
    if (tmp[i] == tmp[prev]) {
      lps[i]=++prev;
      i++;
    } else {
      if (prev>0) { // can do some backtracking
        // dont go to the very beginning:
        prev=lps[prev-1];
      } else { // no further backtracking
        // have to move i
        lps[i]=0;
        i++;
      }
    }
  }
  return N-lps[T-1];
}