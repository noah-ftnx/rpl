#include <vector>
using namespace std;



int firstDuplicateValue(vector<int> array) {
  const int N = (int) array.size();

  for (int i=0; i<N; i++) {
    // found it: first marked number
    if (array[abs(array[i])-1] <0) return abs(array[i]);

    array[abs(array[i])-1]*=-1; // mark it as negative
  }
  return -1;
}