#include <unordered_set>
#include <vector>
using namespace std;

struct VectorHash {
  size_t operator()(vector<int> vec) const {
    size_t res;
    for(auto num: vec) {
      res^=num;
    }
    return res;
  }
};

int main() {
  // Declare a set for vector of ints
  unordered_set<vector<int>, VectorHash> st;
  // Add an item
  st.insert({10, 5, 5});

  return 0;
}

