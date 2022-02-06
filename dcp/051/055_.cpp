#include <unordered_map>
#include <string>
#include <vector>
#include <random>
using namespace std;

class Shortener {
 private:
  unordered_map<string, string> to_short; 	// url to short
  unordered_map<string, string> to_url; 	// short to url

  string gen_short(string url) {
    string res;
    while(res.size() < 6) {
      int r = rand();
      if (r%2 == 0) { // use char
        r=rand()%('z'-'a');
        r+='a';
      } else { // use digit
        r=rand()%('9'-'0');
        r+='0';
      }
      res+=(char)r;
    }
    return res;
  }

  string gen_unique_short(string url) {
    string s;
    while(true) {
      s = gen_short(url);
      if (!to_url.contains(s)) break;
    }
    return s;
  }

 public:
  string shorten(string url) {
    if (url.empty()) return "";
    else if (to_short.contains(url)) return to_short[url];

    string code = gen_unique_short(url);
    to_short[url]=code;
    to_url[code]=url;

    return code;
  }

  string restore(string code) {
    if (to_url.contains(code)) return to_url[code];
    return "";
  }
};



#include "test/055.h"
int main() { run_tests(); return 0; }