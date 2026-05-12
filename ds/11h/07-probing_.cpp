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
  explicit PhoneHashTable(int capacity) : del(new PhoneEntry("", "")), capacity(capacity) {
    table.resize(capacity);
  }

  ~PhoneHashTable() {
    for (auto entry : table) {
      if (entry && entry != del) delete entry;
    }
    delete del;
  }

  int count() const {
    return items;
  }

  bool put(PhoneEntry e) {
    int idx = e.hash() % capacity;
    int first_deleted = -1;

    for (int i = 0; i < capacity; i++, idx = (idx + 1) % capacity) {
      if (table[idx] == del) {
        if (first_deleted == -1) first_deleted = idx;
        continue;
      }

      if (table[idx] == nullptr) {
        int insert_idx = first_deleted == -1 ? idx : first_deleted;
        table[insert_idx] = new PhoneEntry(e);
        items++;
        return true;
      }

      if (table[idx]->name == e.name) {
        table[idx]->telephone = e.telephone;
        return true;
      }
    }

    if (first_deleted != -1) {
      table[first_deleted] = new PhoneEntry(e);
      items++;
      return true;
    }

    return false;
  }

  bool remove(PhoneEntry e) {
    int idx = e.hash() % capacity;

    for (int i = 0; i < capacity; i++, idx = (idx + 1) % capacity) {
      if (table[idx] == nullptr) return false;

      if (table[idx] != del && table[idx]->name == e.name) {
        delete table[idx];
        table[idx] = del;
        items--;
        return true;
      }
    }

    return false;
  }

  bool get(PhoneEntry &e) const {
    int idx = e.hash() % capacity;

    for (int i = 0; i < capacity; i++, idx = (idx + 1) % capacity) {
      if (table[idx] == nullptr) return false;

      if (table[idx] != del && table[idx]->name == e.name) {
        e.telephone = table[idx]->telephone;
        return true;
      }
    }

    return false;
  }
};

#include "test/07-probing.h"
int main() { run_tests(); return 0; }
