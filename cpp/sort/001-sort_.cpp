#include <vector>
#include <iostream>
using namespace std;

int main () {
  vector<int> vec{10, 3, 1, 7};
  sort(vec.begin(), vec.end());                       // DEFAULT: Ascending
  sort(vec.begin(), vec.end(), less<int>());    // Ascending (same as default)
  sort(vec.begin(), vec.end(), greater<int>()); // Descending
  sort(vec.rbegin(), vec.rend());                     // Descending trick

  for (int v: vec) cout << v << " "; cout << endl;

  return 0;
}
