using namespace std;
#include <vector>

int longestPeak(vector<int> array) {
  auto isPeak = [&] (int i) {
    return array[i-1] < array[i] && array[i] > array[i+1];
  };

  const int N = (int) array.size();
  int mx {}; // 1, or 2 elements: loop won't enter

  for (int i=1; i<N-1;) { // first to 2nd-last elemnt
    if (isPeak(i)) {
      // try to expand outwards: left, right
      int l=i-1; // expand left
      while (l-1>=0 && array[l-1]<array[l]) l--;

      int r=i+1; // expand right
      while (r+1<N && array[r+1]<array[r]) r++;
      int len=r-l+1;
      mx=max(mx, len);
      // -3 -2 0 10 5 3 5 10 3 2
      i=r;
    }
    i++;
  }

  return mx;
}
