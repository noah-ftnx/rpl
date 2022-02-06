#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<string> break_string(string input, int k) {
  if (input.size() <=1) return {};

  istringstream iss(input);
  string word;
  vector<string> words, result;
  while(!iss.eof()) {
    iss >> word;
    words.push_back(word);
  }

  int llen=-1;
  string line;
  for (int i=0; i<words.size(); i++) {
    word=words[i];
    int extra = word.size()+1;
    if (llen+extra <= k) { // fit on same line
      llen+=extra;
      line+=word+" ";
    } else {  // change line
      line.pop_back(); // remove last space
      result.push_back(line);  // push last line

      // reset for next line
      line=word+" ";
      llen=word.size(); // 1st word not including a space
    }
  }

  // add last line
  line.pop_back();
  result.push_back(line);

  return result;
}



#include "test/057.h"
int main() { run_tests(); return 0; }