#include <vector>
#include <algorithm>
using namespace std;

void demo()  {
  vector<int> v;

  auto is_even = [](int x) { return x %2 ==0; };
  bool r = all_of(v.cbegin(), v.cend(), is_even);

  // embed lambda directly
  bool r2 = all_of(v.cbegin(), v.cend(), [](int x) { return x %2 ==0; });
}

int main() {
  demo();
  return 0;
}
