#include <vector>
using namespace std;

/*
 * keep a cnt
 */
vector<int> mte1(vector<int> input, int moveNum) {
  const int N = (int) input.size();
  int cnt {}, wrIdx{};
  for (int i=0; i<N; i++) {
    if (input[i] == moveNum) {
      cnt++;
    } else {
      input[wrIdx++]=input[i];
    }
  }

  for (int i=N-1; i>N-1-cnt; i--) {
    input[i]=moveNum;
  }
  return input;
}



/*
 * left: last replacement idx for a non-move number
*/
vector<int> mte2(vector<int> input, int moveNum) {
  const int N = (int) input.size();
  int i=0, left=0;
  while (i<N) {
    if (input[i]==moveNum) i++;
    else {
      swap(input[left++], input[i++]);
    }
  }
  return input;
}

// TODO