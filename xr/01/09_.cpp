#include <vector>
using namespace std;

bool mt1(vector<int> input) {
  const int N = input.size();
  bool increasing=true;
  for (int i=1; increasing && i<N; i++) {
    // check for increasing:
    if (input[i] < input[i-1]) {
      increasing=false;
    }
  }

  bool decreasing=true;
  for (int i=1; decreasing && i<N; i++) {
    // check for decreasing:
    if (input[i] > input[i-1]) {
      decreasing=false;
    }
  }

  return increasing || decreasing;
}

using namespace std;


bool mt2(vector<int> input) {
  const int N = input.size();
  bool increasing=true, decreasing=true;
  for (int i=1; (increasing || decreasing) && i<N; i++) {
    // check for increasing
    if (input[i] < input[i-1]) {
      increasing=false;
    }

    // check for decreasing:
    if (input[i] > input[i-1]) {
      decreasing=false;
    }
  }

  return increasing || decreasing;
}



// TODO