#include <vector>
using namespace std;

int find_index(vector<int> input, int num) {
  if (input.empty())  return -1;
  const int N = (int) input.size();

  int find_start = [&] () {
    int l=0, r=(int) input.size()-1;
    while(l < r) {
      int mid = (r+l)/2;
      if (input[mid] > input[r]) {
        l=mid+1;
      } else { // smaller, go to the left
        r=mid;
      }
    }
    return l;
  };

  int start = find_start();

  int L=0, R=N-1;
  if (num >= input[start] && num <=input[R]) {
    L=start; // search on left
  } else {
    R=start; // search on right
  }

  while (L <=R) {
    int mid = (L+R) /2;
    if (input[mid]==num) return mid;
    else if (num > input[mid]) {
      L=mid+1;
    } else {
     R=mid-1;
    }
  }
  return -1;
}


int find_index_cmplx(vector<int> input, int num) {
  if (input.empty())  return -1;
  const int N = (int) input.size();

  auto find_start = [&]() {
    int l=0, r=(int) N-1;
    while(input[l] > input[r]) {
      int mid = (r+l)/2;
      // found answer
      if (input[mid]<input[mid-1] && input[mid]<input[mid+1]) return mid;

      // still greater: go to the right
      if (input[mid] > input[r]) {
        l=mid+1;
      } else { // smaller, go to the left
        r=mid-1;
      }
    }
    return l;
  };

  int start = find_start();
  int L=0, R=N-1;
  while (L <= R) {
    int mid = (R+L)/2;
    int idx = (mid+start)%N;
    if (input[idx]== num) return idx;
    else if (num > input[idx]) {
      L=mid+1;
    } else {
      R=mid-1;
    }
  }

  return -1;
}




#include "test/058.h"
int main() { run_tests(); return 0; }