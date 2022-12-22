#ifndef INC_070__CPP_DS_10G_TEST_10_H_
#define INC_070__CPP_DS_10G_TEST_10_H_

#include <iostream>

void run_tests() {
  // Create a graph given in the above diagram
  Graph g(6);
  g.addEdge(5, 2);
  g.addEdge(5, 0);
  g.addEdge(4, 0);
  g.addEdge(4, 1);
  g.addEdge(2, 3);
  g.addEdge(3, 1);

  // Function Call
  auto result = g.linearize();

  string res = "";
  for (auto node: result) res+= to_string(node) + " ";
  if (!res.empty()) res.pop_back();

  bool wrong = (res != "5 4 2 3 1 0")
          && (res != "4 5 2 0 3 1")
          && (res != "4 0 1 5 2 3");
  cout << res << endl << (wrong? "WRONG":"Correct.") << endl;
}

#endif  // INC_070__CPP_DS_10G_TEST_10_H_
