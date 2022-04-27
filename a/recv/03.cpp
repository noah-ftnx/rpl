/**
 * https://www.youtube.com/watch?v=AxNNVECce8c&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=6
 */

#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> input, vector<int> pset, int i) {
  if (i == input.size()) {
    if (pset.empty()) cout << "{}\n";
    else { for (auto p: pset) cout << p << " "; cout << endl; }
    return;
  }

  // case: take number
  pset.push_back(input[i]);
  print(input, pset, i+1);

  // case: not take
  pset.pop_back(); // backtrack
  print(input, pset, i+1);
}

void print_subsequences(vector<int> input) {
  print(input, {}, 0);
}


int main() {
  vector<int> vec {3,1,2};
  print_subsequences(vec);
}