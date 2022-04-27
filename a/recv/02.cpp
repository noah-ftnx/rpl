/**
 * BASIC
 *
 * reverse array
 */

#include <utility>
using namespace std;

const int N = 10;

void reverse(int array[N], int i) {
  if (i>=N/2) return; // reached middle

  swap(array[i], array[N-1-i]);
  reverse(array, i+1);
}

void reverse_array(int array[N]) { // O(N)
  reverse(array, 0);
}

#include <iostream>
using namespace std;

void print_array(int array[N]) {
  for (int i=0; i<N; i++) cout << array[i] << " "; cout << endl;
}

int main() {
  int array[N] {1, 3, 4, 5, 6, 7, 8, 9, 0, 2};
  print_array(array);
  reverse_array(array);
  print_array(array);
}