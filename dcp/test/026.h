#ifndef RPL_DCP_TEST_026_H_
#define RPL_DCP_TEST_026_H_

#include <iostream>
#include <string>
using namespace std;

string list_to_string(List* l) {
  string r = "";
  auto node = l->head;
  while (node!=nullptr) {
    r+=std::to_string(node->data)+" ";
    node=node->next;
  }
  return r;
}

List* input1() {
  List *l = new List();
  l->insert(1);
  l->insert(2);
  l->insert(3);

  return l;
}

void test(List* l, int k, string correct) {
  delete_kth(l, k);
  auto result = list_to_string(l);
  cout << "k=" << k << ": " << result
       << (result!=correct? " (WRONG)":"") << endl;
}

void run_tests() {
  test(input1(), 0, "1 2 ");
  test(input1(), 1, "1 3 ");
  test(input1(), 2, "2 3 ");
}
#endif  // RPL_DCP_TEST_026_H_
