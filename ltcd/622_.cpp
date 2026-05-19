#include <vector>
using namespace std;

class MyCircularQueue {
  vector<int> data;
  int cap {};
  int head {};
  int sz {};

public:
  MyCircularQueue(int k) : data(k), cap(k) {
  }

  bool enQueue(int value) {
    if (isFull()) return false;

    int tail = (head + sz) % cap;
    data[tail] = value;
    sz++;
    return true;
  }

  bool deQueue() {
    if (isEmpty()) return false;

    head = (head + 1) % cap;
    sz--;
    return true;
  }

  int Front() {
    if (isEmpty()) return -1;
    return data[head];
  }

  int Rear() {
    if (isEmpty()) return -1;
    return data[(head + sz - 1) % cap];
  }

  bool isEmpty() {
    return sz == 0;
  }

  bool isFull() {
    return sz == cap;
  }
};

#include "test/622.h"
int main() { run_tests(); return 0; }
