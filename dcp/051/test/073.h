#ifndef INC_070__CPP_DCP_051_TEST_073_H_
#define INC_070__CPP_DCP_051_TEST_073_H_

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

bool _wrong=false;
string listToString(List *l) {
  string res;
  Node* node= l->head;
  while (node) {
    res+=to_string(node->data) + ",";
    node=node->next;
  }
  if (!res.empty()) res.pop_back();
  return res;
}

void test(List *l, string correct) {
  string result = listToString(l) + "|";
  l->reverse();
  result+= listToString(l);

  bool wrong = result!=correct;
  _wrong|=wrong;
  cout << setw(15) << result << " \t"
       << (wrong? " (WRONG)":  "correct") << endl;
}

void run_tests() {
  List* l1 = new List();
  test(l1, "|");

  l1->insert(1);
  test(l1, "1|1");

  l1->insert(2);
  test(l1, "1,2|2,1");

  // we are not reversing again, so we have: 2->1
  l1->insert(3);
  l1->insert(4);
  l1->insert(5);
  test(l1, "2,1,3,4,5|5,4,3,1,2");
}

#endif  // INC_070__CPP_DCP_051_TEST_073_H_
