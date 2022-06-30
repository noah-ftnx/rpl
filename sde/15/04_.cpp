class SolutionOverkill {
 public:
  int myAtoi(string s) {
    // Step1: deal with leading zeros:
    int lz; // count leading zeros
    for (lz=0; lz< (int) s.size(); lz++) {
      if (s[lz]!= ' ') break;
    }

    // remove leading zeros:
    //_ _ _ - 5
    //0 1 2 3 4
    s=s.substr(lz);
    if (s.empty()) return 0;

    // if there is anything other than a sign or a digit, then it's an invalid num
    if (!(s[0]>='0' && s[0]<='9') && s[0]!='-' && s[0]!='+') return 0;

    // Step 2: deal with signs
    bool negative=false;
    if (s[0]=='-') {
      negative=true;
      s=s.substr(1);
    } else if (s[0]=='+') {
      s=s.substr(1);
    }

    if (s.empty()) return 0;


    // Step 3: ignore trailing non-nums
    {
      const int S = (int) s.size();
      int nd=0; // first non-digit
      while (s[nd]>='0' && s[nd]<='9') nd++;
      // 0 1 2 3
      // 2 3 f f
      // 3 4 . 4 4 (EDGE CASE)
      s=s.substr(0, nd);
    }


    if (s.empty()) return 0;

    // Step 4:
    // we have sign, and clean number
    long ans=0;
    long tenMul=1;
    const int S = (int) s.size();
    for (int i=S-1; i>=0; i--) {

      char c = s[i];
      long num=c-'0';

      num*=tenMul;
      ans+=num;
      tenMul*=10; // might overflow
      // EDGE CASE:
      if (tenMul > INT_MAX*10L) {
        // we can only accept zeros at the front from this point:
        for (int j=i; j>=0; j--) {
          if (s[j]!='0') return negative? INT_MIN : INT_MAX;
        }
        // return the answer we got so far
        return negative? -ans : ans;
      }

      if (negative) { if (-ans<INT_MIN) return INT_MIN; }
      else { if(ans>INT_MAX) return INT_MAX; }
    }

    return negative? -ans : ans;
  }
};



#include <climits>
#include <string>
using namespace std;

class SolutionSleek {
 public:
  int myAtoi(string s) {
    const int S = (int) s.size();
    int i=0;
    auto inputConsumed = [&]() { return i==S; };

    if (inputConsumed()) return 0; // empty input

    auto isDigit = [](char c) { return c>='0' && c<='9'; };

    // ignore leading whitespace:
    while(i<S && s[i] == ' ') i++;
    if (inputConsumed()) return 0; // just spaces

    // deal with sign, and check validity
    bool isNegative=false;
    if (s[i]=='-' || s[i]=='+') {
      isNegative=s[i]=='-';
      i++;
    }

    if (inputConsumed()) return 0;

    if (!isDigit(s[i])) return 0; // must be a digit

    long res=0;
    while(i< S && isDigit(s[i])) {
      res*=10L;
      int digit = s[i]-'0';
      if (isNegative) digit=-digit;

      res+=digit;

      if (res>INT_MAX) return INT_MAX;
      else if (res<INT_MIN) return INT_MIN;

      i++;
    }


    return res;
  }
};