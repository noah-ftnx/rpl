#ifndef RPL_DCP_051_TEST_067_H_
#define RPL_DCP_051_TEST_067_H_

#include <iostream>
#include <iomanip>

#include "../../../.check/check.h"

bool _wrong {};


string LFU::to_string() {
  string res;
  res+="Size: " + std::to_string(_size) + ": freq: " +
         std::to_string(min_freq)+"-"+std::to_string(max_freq)+":\n";
  for (auto p: freq_lists) {
    int freq = p.first;
    List* list = p.second;
    res+="# " + std::to_string(freq) + ": ";
    Node* node=list->head;
    while (node) {
      res+=std::to_string(node->data) + " ";
      node=node->next;
    }
    res+="\n";
  }

  return res;
}

void test1() {
  LFU lfu(3);

  bool wrong;
  string str;
  lfu.set(3, 10);
  lfu.set(2, 11);
  lfu.set(2, 12);

  cout << "\n-- After 3 sets --\n";

  // correctness check
  str = lfu.to_string();
  wrong=str!="Size: 2: freq: 1-2:\n# 2: 12 \n# 1: 10 \n";
  str.pop_back();
  cout << str << (wrong? "(WRONG)":"") << endl;
  _wrong|=wrong;

  _wrong|=check_intPrettyMin("lfu size", lfu.size(), 2);

  cout << "\n-- After 1 extra addition --\n";
  lfu.set(5, 7);
  str = lfu.to_string();
  wrong=str!="Size: 3: freq: 1-2:\n# 2: 12 \n# 1: 7 10 \n";
  _wrong|=wrong;
  str.pop_back();
  cout << str << (wrong? "(WRONG)":"") << endl;
  _wrong|=check_intPrettyMin("lfu size", lfu.size(), 3);

  cout << "\n-- Getting key:2 --\n";
  _wrong|=check_intPrettyMin("lfu: get 2", lfu.get(2), 12); // 2: MRU
  str = lfu.to_string();
  wrong=str!="Size: 3: freq: 1-3:\n# 3: 12 \n# 1: 7 10 \n";
  cout << str << (wrong? "(WRONG)":"") << endl;


  cout << "\n-- Evicting key:3 val:10 --\n";
  lfu.set(15, 9); // evicts key:3
  str = lfu.to_string();
  wrong=str!="Size: 3: freq: 1-3:\n# 3: 12 \n# 1: 9 7 \n";
  cout << str << (wrong? "(WRONG)":"") << endl;


  // cout << lfu.to_string() << endl; // TMP

  cout << "\n-- Evicting key:5 val:7 --\n";
  lfu.set(16, 10); // evicts 5
  str = lfu.to_string();
  wrong=str!="Size: 3: freq: 1-3:\n# 3: 12 \n# 1: 10 9 \n";
  cout << str << (wrong? "(WRONG)":"") << endl;

  cout << "\n-- Get key:2 --\n";
  _wrong|=check_intPrettyMin("lfu: get 2", lfu.get(2), 12); // 2: MRU
  str = lfu.to_string();
  wrong=str!="Size: 3: freq: 1-4:\n# 4: 12 \n# 1: 10 9 \n";
  cout << str << (wrong? "(WRONG)":"") << endl;


  cout << "\n-- Get key:3. (nan) --\n";
  _wrong|=check_intPrettyMin("lfu size", lfu.get(3), INT_MIN);

  cout << "\n-- Get key:5 (nan --\n";
  _wrong|=check_intPrettyMin("lfu size", lfu.get(5), INT_MIN);

  cout << "\n-- Evicting key:15 value:9 --\n";
  lfu.set(20, 10); // evicts 15
  str = lfu.to_string();
  wrong=str!="Size: 3: freq: 1-4:\n# 4: 12 \n# 1: 10 10 \n";
  cout << str << (wrong? "(WRONG)":"") << endl;

  cout << "\n-- Get key:15 --\n";
  _wrong|=check_intPrettyMin("lfu: get 15", lfu.get(9), INT_MIN);
  str = lfu.to_string();
  wrong=str!="Size: 3: freq: 1-4:\n# 4: 12 \n# 1: 10 10 \n";
  cout << str << (wrong? "(WRONG)":"") << endl;


  cout << "\n-- Get key:2 --\n";
  _wrong|=check_intPrettyMin("lfu: get 2", lfu.get(2), 12); // 2: MRU
  str = lfu.to_string();
  wrong=str!="Size: 3: freq: 1-5:\n# 5: 12 \n# 1: 10 10 \n";
  cout << str << (wrong? "(WRONG)":"") << endl;

  cout << "\n-- Get key:20 --\n";
  _wrong|=check_intPrettyMin("lfu: get 20", lfu.get(20), 10); // 2: MRU
  str = lfu.to_string();
  wrong=str!="Size: 3: freq: 1-5:\n# 2: 10 \n# 5: 12 \n# 1: 10 \n";
  cout << str << (wrong? "(WRONG)":"") << endl;


  cout << "\n-- Get key:20 --\n";
  _wrong|=check_intPrettyMin("lfu: get 20", lfu.get(20), 10); // 2: MRU
  str = lfu.to_string();
  wrong=str!="Size: 3: freq: 1-5:\n# 3: 10 \n# 5: 12 \n# 1: 10 \n";
  cout << str << (wrong? "(WRONG)":"") << endl;

  cout << "\n-- Get key:16 --\n";
  _wrong|=check_intPrettyMin("lfu: get 16", lfu.get(16), 10); // 2: MRU
  str = lfu.to_string();
  wrong=str!="Size: 3: freq: 2-5:\n# 2: 10 \n# 3: 10 \n# 5: 12 \n";
  cout << str << (wrong? "(WRONG)":"") << endl;

  cout << "\n-- Evicting key:16 val:10 --\n";
  lfu.set(22, 42); // evicts 5
  str = lfu.to_string();
  wrong=str!="Size: 3: freq: 1-5:\n# 1: 42 \n# 3: 10 \n# 5: 12 \n";
  cout << str << (wrong? "(WRONG)":"") << endl;
  if (true) return;

  cout << "\n-- Get key:20 --\n";
  _wrong|=check_intPrettyMin("lfu: get 16", lfu.get(16), 10); // 2: MRU
  str = lfu.to_string();
  wrong=str!="Size: 3: freq: 1-5:\n# 5: 12 \n# 1: 10 10 \n";
  cout << str << (wrong? "(WRONG)":"") << endl;
}

void print_errors() {
  if (_wrong) cout << "\nWRONG RESULTS.\n";
  else cout << "\nCorrect.\n";
}

void run_tests() {
  test1();
  print_errors();
}

#endif  // RPL_DCP_051_TEST_067_H_