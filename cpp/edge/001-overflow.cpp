#include <vector>
#include <iostream>
using namespace std;

void negativeInUnsigned() {

  vector<int> vec;
  cout << "vec.size: " << vec.size() << endl;
  vec.push_back(5);
  cout << "vec insert\n";
  cout << "vec.size: " << vec.size() << endl;

  int szm1a = vec.size()-1;
  size_t szm1b = vec.size()-1;
  cout << "vec.size-1 " << szm1a << endl;
  cout << "vec.size-1 " << szm1b << endl;

  cout << "(-1 < vec.size-1)? (when size_t < int)? " << boolalpha << (-1 < szm1a)<< endl;
  cout << "(-1 < vec.size-1)? (when size_t < size_t)? " << boolalpha << (-1 < szm1b)<< endl;
  cout << "-1 int:  " << -1 << endl;
  cout << "-1 size_t:  " << ((size_t)-1) << endl;
  cout << "-1 uint_32_t:  " << ((uint32_t)-1) << endl;

}

int main () {
  sizetCasting();
}