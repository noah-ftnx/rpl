#include <iostream>
#include <vector>
using namespace std;

/**
 * Remove and Reinsert element while iterating
 */
void test_del_add_while_iterating() {
  cout << __func__ << endl;

  vector<int> vec {3, 10, 25, 35};

  auto print = [](vector<int>& vec) {
    for (auto v: vec) cout << v << " "; cout << endl;
  };

  cout << "vector:\n";
  print(vec);
  cout << endl;
  cout << endl;

  // delete while iterating
  for (auto it=vec.begin(); it!=vec.end();) {
    if (*it==25) {
      it = vec.erase(it);
      cout << "vector just deleted:\n";
      print(vec);
      it=vec.insert(it, 45);
      cout << "vector just reinserted 45:\n";
      print(vec);
    } else {
      it++;
    }
  }

  cout << endl;
  cout << endl;
  cout << "vector after loop:\n";
  print(vec);
}

int main() {
  test_del_add_while_iterating();

  return 0;
}

