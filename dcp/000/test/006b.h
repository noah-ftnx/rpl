#ifndef RPL_DCP_TEST_006B_H_
#define RPL_DCP_TEST_006B_H_

#include <string>
#include <iostream>

List* create_list(vector<int> vec) {
  List* list = new List();
  for(auto n: vec) list->push_back(n);
  return list;
}

vector<List*> input_a() {
  List* l1 = create_list({10, 15, 30, 35});
  List* l2 = create_list({5, 11, 33, 105});
  List* l3 = create_list({30, 35, 37, 40});
  vector<List*> list({l1, l2, l3});
  return list;
}

vector<List*> input_b() {
  List* l1 = create_list({10,15,30});
  List* l2 = create_list({12,15,20});
  List* l3 = create_list({17,20,32});
  vector<List*> list({l1, l2, l3});
  return list;
}

void check(string msg, List* list, string correct) {
  string result;

  auto node = list->head;
  while(node) {
    result += to_string(node->data) + " ";
    node=node->next;
  }

  cout << msg << ": " << result << (result!=correct? " (WRONG)" :"") << endl;
}

void run_tests() {
  check("l1", merge_k_lists(input_a()), "5 10 11 15 30 30 33 35 35 37 40 105 ");
  check("l2", merge_k_lists(input_b()), "10 12 15 15 17 20 20 30 32 ");
}

#endif  // RPL_DCP_TEST_006B_H_
