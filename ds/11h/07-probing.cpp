#include <string>
#include <vector>
using namespace std;

struct PhoneEntry {
  string name;      // key
  string telephone; // value

  PhoneEntry(string name, string telephone)
      : name(name), telephone(telephone) {}

  int hash_string(int n_ = 454545) const {
    long long sum = 0, n = n_;
    const int dict_size = 26;
    for (int i = 0; i < (int) name.size(); i++) {
      sum = (sum * dict_size + name[i] - 'a') % n;
    }
    return sum;
  }

  int hash() const { return hash_string(); }
};

class PhoneHashTable {
private:
  vector<PhoneEntry *> table;
  PhoneEntry *del {};
  int items {};
  int capacity {};

public:
  // IMPLEMENT
  explicit PhoneHashTable(int capacity);

  // IMPLEMENT
  ~PhoneHashTable();

  // IMPLEMENT
  int count() const;

  // IMPLEMENT
  bool put(PhoneEntry e);

  // IMPLEMENT
  bool remove(PhoneEntry e);

  // IMPLEMENT
  bool get(PhoneEntry &e) const;
};

#include "test/07-probing.h"
int main() { run_tests(); return 0; }
