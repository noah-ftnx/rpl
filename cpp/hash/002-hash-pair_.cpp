#include <unordered_set>
#include <utility>
using namespace std;

struct PairHash {
  size_t operator()(pair<int, int> p) const {
    return p.first ^ p.second;
  }
};

int main() {
  // Declare set: (for pair of ints)
  unordered_set<pair<int, int>, PairHash> st;
  // Add an item
  st.insert(make_pair(10, 5));

  return 0;
}

