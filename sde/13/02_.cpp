class Queue {
 public:

  const int MX_SZ=5000;
  int *arr = new int[MX_SZ];
  int first=-1, last=-1;

  /* FIFO: First in First out

     l
   f
   1 2 3 4

  */

  Queue() {
    // Implement the Constructor
  }

  /*----------------- Public Functions of Queue -----------------*/

  bool isEmpty() {
    // Implement the isEmpty() function
    return (first==-1);
  }

  int size() {
    if (first==-1) return 0;

    //   l
    //     f
    // 0 1 2 3 4 : N: 5
    // 0-1
    // 5-1+1: 5
    // 0-2=-2
    // -2+1=-1
    // N-1=4
    // 1-2=-1+1

    //   l
    //             f
    // 0 1 2 3 4 5 6 7 8 9 N:10, sz:6
    // 1-5=-5 +1 = -4
    // 10-4=6

    int res = last-first+1;
    return res<0? res+MX_SZ: res;
  }

  void enqueue(int data) {
    //           l
    //   f
    //   1 2 3 4 5
    if (first==last && first==-1) {
      first=last=0; // will add first element
    } else {
      int nextLast=(last+1)%MX_SZ; // wrap around
      if (nextLast == first) {
        // queue now full: cannot add this element
        // these pointers should never meet (after the 1st element)
        return;
      }

      last=nextLast;
    }
    // Implement the enqueue() function

    arr[last]=data;
  }

  int dequeue() {
    // pop first element
    if (first<0) return -1;

    int val = arr[first];
    // l   f
    // 0 1 3

    first=(first+1)%MX_SZ; // advance and wrap around

    if (first>last) {
      // list was emptied: reset to both -1
      first=last=-1;
    }

    return val;
  }

  int front() {
    // Implement the front() function
    if (first <0) return -1;
    return arr[first];
  }
};