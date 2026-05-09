/**
 * https://www.youtube.com/watch?v=eQCS_v3bw0Q&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=7
 * Print subsequences who's sum is K
 *
 * TODO: split into 3 quiz prompts: all / any / count.
 */
#include <vector>
#include <iostream>
using namespace std;

// IMPLEMENT: print all matching subsequences
void solve(vector<int> input, vector<int> &itaken, int K, int sum, int i) {
}

// IMPLEMENT: print all wrapper
void print_all_subsequences(vector<int> input, int K) {
}

// IMPLEMENT: print any matching subsequence
bool solve_any(vector<int> input, vector<int> &itaken, int K, int sum, int i) {
}

// IMPLEMENT: print any wrapper
void print_any_subsequence(vector<int> input, int K) {
}

// IMPLEMENT: count matching subsequences
int solve_cnt(vector<int> input, int K, int sum, int i) {
}

// IMPLEMENT: count wrapper
int count_subsequences(vector<int> input, int K) {
}

int main() {
  print_all_subsequences({1, 2, 1, 4}, 2);
  print_any_subsequence({1, 2, 1, 4}, 2);
  cout << "There are: " << count_subsequences({1, 2, 1, 4}, 2) << " that match 2\n";
}
