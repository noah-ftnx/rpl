/**
 * https://www.youtube.com/watch?v=eQCS_v3bw0Q&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=7
 * Print subsequences who's sum is K
 */
#include <vector>
#include <iostream>
using namespace std;

void solve(vector<int> input, vector<int> &itaken, int K, int sum, int i) {
  if (i==input.size()) {
    if (sum==K) {
      for (auto it: itaken) cout << input[it] << " "; cout << endl;
    }
    return;
  }

  // case 1: take i
  itaken.push_back(i);
  sum+=input[i];
  solve(input, itaken, K, sum, i+1);

  // case 2: don't take i
  sum-=input[i];
  itaken.pop_back();
  solve(input, itaken, K, sum, i+1);
}

void print_all_subsequences(vector<int> input, int K) {
  vector<int> itaken;
  solve(input, itaken, K, 0, 0);
}

bool solve_any(vector<int> input, vector<int> &itaken, int K, int sum, int i) {
  if (i==input.size()) {
    if (sum==K) {
      for (auto it: itaken) cout << input[it] << " "; cout << endl;
      return true;
    }
    return false;
  }

  sum+=input[i];
  itaken.push_back(i);
  if (solve_any(input, itaken, K, sum, i+1)) return true;

  sum-=input[i];
  itaken.pop_back();
  return solve_any(input, itaken, K, sum, i+1);
}


void print_any_subsequence(vector<int> input, int K) {
  vector<int> itaken;
  solve_any(input, itaken, K, 0, 0);
}

int solve_cnt(vector<int> input, int K, int sum, int i) {
  if (i == input.size()) {
    return (int) (sum == K);
  }

  // take it (but not always
  sum+=input[i];
  int l=solve_cnt(input, K, sum, i+1);

  sum-=input[i];
  int r=solve_cnt(input, K, sum, i+1);

  return l+r;
}

int count_subsequences(vector<int> input, int K) {
  return solve_cnt(input, K, 0, 0);
}


int main() {
  print_all_subsequences({1, 2, 1, 4}, 2);
  print_any_subsequence({1, 2, 1, 4}, 2);
  cout << "There are: " << count_subsequences({1, 2, 1, 4}, 2) << " that match 2\n";
}