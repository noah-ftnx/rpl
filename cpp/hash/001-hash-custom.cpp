#include <unordered_map>
using namespace std;

struct FromTo {
  int from; int to;
  FromTo(int from, int to) : from(from), to(to) {}

  bool operator==(const FromTo& other) const {
    return from == other.from && to==other.to;
  }
};

struct FromToHash {
  size_t operator()(const FromTo& a) const {
    size_t hashFrom = std::hash<int>()(a.from);
    size_t hashTo = std::hash<int>()(a.to) << 1;
    return hashFrom ^ hashTo;
  }
};

int main() {
  unordered_map<FromTo, int, FromToHash> mp;

  mp.insert({{10, 5}, 10});

  return 0;
}

