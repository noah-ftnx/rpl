#include <string>
using namespace std;

string encode(string input)  {
  if (input.empty()) return "";
  string result;
  const char EMPTY='\0';
  char prev = EMPTY;
  int cnt=0;
  for (char c: input) {
    if (c != prev) { // different char
      if (prev != EMPTY) { // it's not the initial one
        result+=to_string(cnt)+prev;
      }
      cnt=1;  // reset counting
    } else { // same char
      cnt++;
    }
    prev=c;
  }
  result+=to_string(cnt)+prev;  // flush final result

  return result;
}



#include "test/029.h"
int main() { run_tests(); return 0; }