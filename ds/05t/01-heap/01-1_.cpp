#include <vector>
using namespace std;

int left(int size, int idx) {
  int ch = (2*idx)+1;
  return ch<size? ch : -1;
}

int right(int size, int idx) {
  int ch = (2*idx)+2;
  return ch<size? ch : -1;
}

int parent(int idx) {
  return idx==0? -1: (idx-1)/2;
}

void percolate_up(vector<int> &vec, int idx) {
  while (parent(idx) >=0) {
    if (vec[idx]  < vec[parent(idx)]) {
      swap(vec[idx], vec[parent(idx)]);
      idx=parent(idx);
    } else break;
    // we had a heap, and we pushed new value as up as possible
    // so we have created once again a heap (incl the new value)
    // no need to further go up
  }
}

void percolate_down(vector<int> &vec, int idx) {
  while (true) {
    int L = left(vec.size(), idx);
    int R = right(vec.size(), idx);

    // if there is no left subtree, then
    // there is no right subtree (heaps are complete trees)
    if (L==-1) break;

    // find min child
    int minChild=L; // assumption
    if (R!=-1 && vec[R] < vec[L]) minChild=R;

    if (vec[idx] > vec[minChild]) {
      swap(vec[idx], vec[minChild]);
      idx=minChild;
    } else break; // already created a heap
  }
}

void insert(vector<int> &vec, int val) {
  int idx = vec.size();
  vec.resize(idx+1);
  vec[idx]=val;

  percolate_up(vec, idx);
}

int pop(vector<int> &vec) {
  int res = vec[0];

  int lastIdx=vec.size()-1;
  vec[0]=vec[lastIdx];
  vec.resize(lastIdx);

  percolate_down(vec, 0);

  return res;
}

#include "test/01-1.h"
int main() {
  run_tests("insert then pop");

  print_report();
  return 0;
}