#include <unordered_set>
#include <utility>
using namespace std;

struct PairHash {
  size_t operator()(pair<int, int> p) const {
    return p.first ^ p.second;
  }
};

int main() {
  unordered_set<pair<int, int>, PairHash> mp;
  mp.insert(make_pair(10, 5));

  return 0;
}

