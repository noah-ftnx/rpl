#include <vector>
using namespace std;

// GIVEN: returns: 1 to k inclusive
#include "test/051pre.h"
int randk(int k);

int random_num(int k) {  // assume k=4
  int base1 = randk(k+1); // range: 1-5
  return base1-1; // range: 0-4
}

void shuffle(vector<int>& deck) {
  const int N = (int) deck.size();

  for (int i=N-1; i>=0; i--) { // N:5
                               // 4: 0-4
    // 3: 0-3
    // 2: 0-2
    // 1: 0-1
    // 0: 0-0
    // N:4
    int j = random_num(i);
    swap(deck[i], deck[j]);
  }
}


#include "test/051.h"
int main() { run_tests(); return 0; }