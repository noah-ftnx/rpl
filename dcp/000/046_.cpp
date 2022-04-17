#include <string>
#include <vector>
using namespace std;

string longest_palidromeBF(string input) {
  auto is_palindrome = [&] (int i, int j) -> bool {
    for (; i<j; i++,j--)
      if (input[i]!=input[j]) return false;
    return true;
  };

  const int N = input.size();
  if (input.empty()) return "";
  int mxlen=-1, start;
  // enumerate all substrings
  for (int i=0; i<N; i++) { // starting index
    for (int j=i; j<N; j++) { // ending index
      // calculate max palindrome on the fly
      if (is_palindrome(i, j)) {
        const int sz = j-i+1;
        if (sz>mxlen) {
          mxlen=sz;
          start=i;
        }
      }
    }
  }

  return input.substr(start, mxlen);
}

string longest_palidromeBU(string input) {
  const int N = input.size();
  int mxlen=0; int start=0;
  vector<vector<bool>> tab(N, vector<bool>(N, {}));

  auto update_max = [&](int i, int j) {
    int sz = j-i+1;
    if (sz>mxlen) {
      mxlen=sz;
      start=i;
    }
  };

  // all palindromes of sz 1
  for (int i=0; i<N; i++) {
    tab[i][i]=true;
    update_max(i, i);
  }

  // some palindromes of sz 2
  // the ones above the diagonal
  for (int i=0; i<N-1; i++){
    if (input[i]==input[i+1]) {
      tab[i][i+1]=true;
      update_max(i, i+1);
    }
  }

  for (int sz=2; sz<N; sz++) { // size of palindromes
    for (int i=0; i<N-sz; i++) { // starting point of palindromes
      int j=i+sz; // ending point
      if (input[i]==input[j] && tab[i+1][j-1]) {
        tab[i][j]=true;
        update_max(i, j);
      }
    }
  }
  return input.substr(start, mxlen);
}


string longest_palindrome(string input) {
  const int K = (int) input.size();
  if (K <= 1) return input;

  auto expand = [&] (int l, int r) -> pair<int, int> {
    pair<int, int> res {-1, -1};
    while(l>=0 && r<K && input[l]==input[r]) {
      res = {l, r};
      l--; r++;
    }
    return res;
  };

  auto biggest_at_i = [&] (int i) -> pair<int, int> {
    pair<int, int> res {i, i};
    auto p1=expand(i, i+1);
    auto p2=expand(i-1, i+1);

    int sz1 = p1.second-p1.first;
    int sz2 = p2.second-p2.first;

    if (sz1 > sz2) res=p1;
    // else means: p2 is bigger or equal
    // plus: p2 is not invalid
    else if (p2.first!=-1) res=p2;

    return res;
  };

  // find biggest palindrome at each index
  int mx = -1;
  pair<int, int> mx_pair {-1, -1};
  for (int i=0; i<K; i++) {
    auto p = biggest_at_i(i);
    int len = p.second-p.first;
    if (len>mx) {
      mx=len;
      mx_pair=p;
    }
  }

  return input.substr(mx_pair.first, mx_pair.second-mx_pair.first+1);
}


#include "test/046.h"
int main() {
  run_tests("BF", longest_palidromeBF);
  run_tests("BU", longest_palidromeBU);
  run_tests("middle-expansion", longest_palindrome);

  print_errors();
  return 0;
}


#ifdef COMPLEX
pair<int, int> middle_expansion(string input, int l, int r) {
  const int N = input.size();
  while (l >=0 && r < N && input[l] == input[r]) {
    l--; r++;
  }

  return {++l, --r}; // last matching bounds
}

string longest_palindrome(string input) {
  if (input.empty()) return "";
  const int N = input.size();
  int mxlen = -1, mid = -1;

  auto store_max = [&] (int i, int sz) {
    if (sz < mxlen) return;
    mxlen=sz;
    mid=i;
  };

  auto get_size = [] (pair<int, int> p) -> int {
    int sz = p.second-p.first+1;
    return max(sz,-1);
  };

  for (int i=0; i<N; i++) {
    auto p1 = middle_expansion(input, i, i); // aba
    store_max(i, get_size(p1));

    auto p2 = middle_expansion(input, i, i+1); // azza
    store_max(i, get_size(p2));
  }

  const int half = mxlen/2;
  const bool is_even = mxlen%2==0;
  int l = mid-half+ static_cast<int>(is_even);
  int r = mid+half;
  return input.substr(l, r-l+1);
}
#endif