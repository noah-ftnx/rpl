#include <string>
#include <vector>
#include <climits>
using namespace std;

int BF(int i, string &str) {
  const int S = (int) str.size();
  auto isPalindrome = [&] (int l, int r) -> bool {
    while (l<r) if (str[l++]!=str[r--]) return false;
    return true;
  };

  // base case:
  if (i==S) return 0; // no more paritions

  // whole string is a palindrome
  if (isPalindrome(i, S-1)) return 0; // no cuts required.

  int mn=1e9;
  for (int p=i; p<=S; p++) { // try partitions
    // left cut is not a palindrome
    if (!isPalindrome(i, p)) continue; // ignore non palindrome cuts
    int cuts = 1 + BF(p+1, str);
    mn=min(mn, cuts);
  }
  return mn;
}

int palindromePartitioningBF(string str) {
  return BF(0, str);
}


int MMZ(int i, string &str, vector<int> &dp) {
  const int S = (int) str.size();
  auto isPalindrome = [&] (int l, int r) -> bool {
    while (l<r) if (str[l++]!=str[r--]) return false;
    return true;
  };

  // base case:
  if (i==S) return 0; // no more paritions

  if (dp[i]!=-1) return dp[i];

  // whole string is a palindrome
  if (isPalindrome(i, S-1)) return 0; // no cuts required.

  int mn=1e9;
  for (int p=i; p<=S; p++) { // try partitions
    // left cut is not a palindrome
    if (!isPalindrome(i, p)) continue; // ignore non palindrome cuts
    int cuts = 1 + MMZ(p+1, str, dp);
    mn=min(mn, cuts);
  }
  return dp[i]=mn;
}

int palindromePartitioningMMZ(string str) {
  const int S = (int) str.size();
  vector<int> dp(S+1, -1);
  return MMZ(0, str, dp);
}


int palindromePartitioningBU(string str) {
  auto isPalindrome = [&] (int l, int r) -> bool {
    while (l<r) if (str[l++]!=str[r--]) return false;
    return true;
  };


  const int S = (int) str.size();
  if (S==0) return 0;
  vector<int> dp(S+1, 0);

  // base case:
  // i==S: no more paritions

  for (int i=S-1; i>=0; i--) {
    // whole string is a palindrome: no cuts required.
    if (isPalindrome(i, S-1)) { dp[i]=0; continue; }

    int mn=1e9;
    for (int p=i; p<=S; p++) { // try partitions
      // left cut is not a palindrome
      if (!isPalindrome(i, p)) continue; // ignore non palindrome cuts
      int cuts = 1 + dp[p+1];
      mn=min(mn, cuts);
    }
    dp[i]=mn;
  }
  return dp[0];
}



#include "test/dp053.h"
int main() {
  run_tests("BF", palindromePartitioningBF);
  run_tests("MMZ", palindromePartitioningMMZ);
  run_tests("BU", palindromePartitioningBU);
  // run_tests("OPT", palindromePartitioningBU);

  print_report();
  return 0;
}