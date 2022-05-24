#include <vector>
#include <climits>
using namespace std;


vector<int> sdBF(vector<int> vec1, vector<int> vec2) {
  const int N=vec1.size(), M=vec2.size();
  int mn=INT_MAX, a1=-1, a2=-1;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      if (abs(vec1[i]-vec2[j])<mn) {
        a1=i; a2=j;
        mn=abs(vec1[i]-vec2[j]);
      }
    }
  }
  return {vec1[a1], vec2[a2]};
}



int bsearch(vector<int> vec, int num) {
  const int N = vec.size();
  int left=0, right=N-1;
  int mid=0; // first element
  while (left < right) {
    mid = (left+right)/2;
    if (vec[mid]==num) { // found num
      return vec[mid];
    } else if (num > vec[mid]) { // search to right
      left=mid+1;
    } else { // search to left
      right=mid-1;
    }
  }

  // have not found the number:
  // find smallest difference between: mid-1, mid, mid+1
  int leftV= mid-1>=0? vec[mid-1] : 1e9;
  int rightV= mid+1<N? vec[mid+1] : 1e9;

  int res = vec[mid]; // assume answer
  int mn=abs(num-vec[mid]);

  if (abs(num-leftV) < mn) {  // left limit lower abs
    res=vec[mid-1];
    mn=num-leftV;
  }

  if (abs(num-rightV) < mn) {  // right limit lower abs
    res=vec[mid+1];
  }

  return res;
}

vector<int> sd2(vector<int> vec1, vector<int> vec2) {
  // sort arrays
  sort(vec1.begin(), vec1.end());
  sort(vec2.begin(), vec2.end());

  const int N = vec1.size(), M=vec2.size();

  int mn = INT_MAX, r1, r2;

  for (int i=0; i<N; i++) {
    // find that number, or the right next to it
    int num1=vec1[i];
    int num2=bsearch(vec2, num1);
    if (abs(num1-num2) < mn) {
      r1=num1; r2=num2;
      mn=abs(num1-num2);
    }
  }

  return {r1, r2};
}



vector<int> sdOPT(vector<int> vec1, vector<int> vec2) {
  sort(vec1.begin(), vec1.end());
  sort(vec2.begin(), vec2.end());
	
  const int N=vec1.size(), M=vec2.size();
	
  // at each iteration: try to close in the difference
  int i=0, j=0;
  int diff, mn=INT_MAX;
  vector<int> res(2);
  while (i<N && j<M) {
    int nexti=i, nextj=j;
    // zero difference
    if (vec1[i]==vec2[j]) return {vec1[i], vec2[j]};
    else if (vec1[i]<vec2[j]) { // advance i
      nexti=i+1;
      diff=abs(vec1[i]-vec2[j]);
    } else { // advance j
      nextj=j+1;
      diff=abs(vec1[i]-vec2[j]);
    }
		
    if (diff < mn) {
      mn=diff;
      res={vec1[i], vec2[j]};
    }
    i=nexti; j=nextj;
  }
  return res;
}




// TODO