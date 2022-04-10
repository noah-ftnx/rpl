#ifndef INC_070__CPP_DCP_000_TEST_006_H_
#define INC_070__CPP_DCP_000_TEST_006_H_

#include <cstdint>
#include <string>
#include <iostream>

string get_str(Node* node) {
  if (node == nullptr) return "<nullptr>";
  return to_string(node->value);
}


void check_node(XORList* xl, int i, string res) {
  Node* node = xl->get(i);
  string str = get_str(node);
  cout << "get:"<<i<<": " << str << (str!=res?" (WRONG)": "") << endl;
}

void run_tests() {
  XORList xl;
  xl.add(10);
  xl.add(15);
  xl.add(25);
  xl.add(30);
  xl.add(50);
  xl.add(99);
  xl.add(128);

  check_node(&xl, 0, "10");
  check_node(&xl, 1, "15");
  check_node(&xl, 2, "25");
  check_node(&xl, 3, "30");
  check_node(&xl, 4, "50");
  check_node(&xl, 5, "99");
  check_node(&xl, 6, "128");

  check_node(&xl, 7, "<nullptr>");
  check_node(&xl, -10, "<nullptr>");
}



#endif  // INC_070__CPP_DCP_000_TEST_006_H_
