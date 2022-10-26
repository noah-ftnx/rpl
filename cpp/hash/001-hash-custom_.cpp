#include <unordered_map>
using namespace std;

struct Foo {
  int field1; int field2;
  Foo(int p1, int p2) : field1(p1), field2(p2) {}

  bool operator==(const Foo& other) const {
    return field1 == other.field1 && field2==other.field2;
  }
};

struct FooHash {
  size_t operator()(const Foo& a) const {
    size_t hash1 = std::hash<int>()(a.field1);
    size_t hash2 = std::hash<int>()(a.field2) << 1;
    return hash1 ^ hash2;
  }
};

int main() {
  // Declare a map: Foo -> Int
  unordered_map<Foo, int, FooHash> mp;
  // Add an item
  mp.insert({{10, 5}, 10});

  return 0;
}

