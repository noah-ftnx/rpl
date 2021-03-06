#ifndef __HEAP__
#define __HEAP__


class MinHeap {
 private:
  vector<int> vec;

 public:
  MinHeap(const vector<int>& input);
  ~MinHeap();

  void heapsort();
  void heapify();

  int size() { return vec.size(); }

  int left(int i);
  int right(int i);
  int parent(int i);

  void push(int v);

  void pop();
  int top();

  void percolate_up(int i);
  void percolate_down(int i);

  vector<int>& get_vector() { return vec; }
};

#endif