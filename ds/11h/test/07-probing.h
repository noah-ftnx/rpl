#ifndef RPL_DS_11H_TEST_07_PROBING_H_
#define RPL_DS_11H_TEST_07_PROBING_H_

#include "../../../.inc/base.h"
#include <iomanip>
#include <string>
using namespace std;

void check_get(PhoneHashTable &ht, string name, bool correct_found, string correct_phone = "") {
  PhoneEntry query(name, "");
  bool found = ht.get(query);
  bool wrong = found != correct_found || (found && query.telephone != correct_phone);
  _wrong |= wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << left << setw(24) << ("get " + name);
  cout << boolalpha << found;
  if (found) cout << " " << query.telephone;
  if (wrong) {
    cout << " (Expected: " << correct_found;
    if (correct_found) cout << " " << correct_phone;
    cout << ")";
  }
  cout << endl;
}

void check_put(PhoneHashTable &ht, PhoneEntry entry, bool correct) {
  bool result = ht.put(entry);
  bool wrong = result != correct;
  _wrong |= wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << left << setw(24) << ("put " + entry.name);
  cout << boolalpha << result;
  if (wrong) cout << " (Expected: " << correct << ")";
  cout << endl;
}

void check_remove(PhoneHashTable &ht, PhoneEntry entry, bool correct) {
  bool result = ht.remove(entry);
  bool wrong = result != correct;
  _wrong |= wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << left << setw(24) << ("remove " + entry.name);
  cout << boolalpha << result;
  if (wrong) cout << " (Expected: " << correct << ")";
  cout << endl;
}

void check_count(PhoneHashTable &ht, int correct) {
  int result = ht.count();
  bool wrong = result != correct;
  _wrong |= wrong;

  cout << (wrong ? "[FAIL] " : "[PASS] ");
  cout << left << setw(24) << "count";
  cout << result;
  if (wrong) cout << " (Expected: " << correct << ")";
  cout << endl;
}

void run_tests() {
  {
    cout << "basic + collisions" << endl;
    PhoneHashTable ht(5);
    check_get(ht, "a", false);
    check_put(ht, {"a", "111"}, true);
    check_put(ht, {"f", "222"}, true);
    check_put(ht, {"k", "333"}, true);
    check_get(ht, "a", true, "111");
    check_get(ht, "f", true, "222");
    check_get(ht, "k", true, "333");
    check_count(ht, 3);
    cout << endl;
  }

  {
    cout << "update + delete" << endl;
    PhoneHashTable ht(5);
    check_put(ht, {"a", "111"}, true);
    check_put(ht, {"f", "222"}, true);
    check_put(ht, {"k", "333"}, true);
    check_put(ht, {"f", "999"}, true);
    check_get(ht, "f", true, "999");
    check_remove(ht, {"f", ""}, true);
    check_get(ht, "f", false);
    check_get(ht, "k", true, "333");
    check_put(ht, {"k", "777"}, true);
    check_get(ht, "k", true, "777");
    check_count(ht, 2);
    check_remove(ht, {"f", ""}, false);
    cout << endl;
  }

  {
    cout << "reuse deleted slot + full" << endl;
    PhoneHashTable ht(3);
    check_put(ht, {"a", "111"}, true);
    check_put(ht, {"d", "222"}, true);
    check_put(ht, {"g", "333"}, true);
    check_put(ht, {"j", "444"}, false);
    check_remove(ht, {"d", ""}, true);
    check_put(ht, {"j", "444"}, true);
    check_get(ht, "j", true, "444");
    check_get(ht, "g", true, "333");
    cout << endl;
  }

  print_report();
}

#endif  // RPL_DS_11H_TEST_07_PROBING_H_
