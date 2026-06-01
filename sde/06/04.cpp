#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// IMPLEMENT: isPalindrome
bool isPalindrome(ListNode* head);

#include "test/04.h"
int main() {
  run_tests(isPalindrome, "isPalindrome");
  print_report();
  return 0;
}
