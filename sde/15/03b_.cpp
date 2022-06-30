
class SolutionOverkill1 {

 public:
  string intToRoman(int num) {
    if (num==0) return "0";

    string roman;
    if (num <0) { // add - sign and make positive
      roman="-";
      num=-num;
    }

    // add M's
    while(num >= 1e3) {
      roman+="M";
      num-=1e3;
    }

    while (num>0) {
      if (num>=900) {
        roman+="CM";
        num-=900;
      } else if (num >= 500) {
        roman+="D";
        num-=500;
      } else if (num >=400) {
        roman+="CD";
        num-=400;
      } else if (num >=100) {
        roman+="C";
        num-=100;
      } else if (num>=90) {
        roman+="XC";
        num-=90;
      } else if (num>=50) {
        roman+="L";
        num-=50;
      } else if  (num>=40) {
        roman+="XL";
        num-=40;
      } else if (num>=10) {
        roman+="X";
        num-=10;
      } else if (num>=9) {
        roman+="IX";
        num-=9;
      } else if (num>=5) {
        roman+="V";
        num-=5;
      } else if (num>=4) {
        roman+="IV";
        num-=8;
      } else {
        roman+="I";
        num--;
      }
    }

    return roman;
  }
};


#include <unordered_map>
using namespace std;

class SolutionOverkill2 {
 public:
  string intToRoman(int num) {
    if (num==0) return 0;

    string res;
    if (num<0) {  // make positive and add '-'
      res="-";
      num=-num;
    }

    vector<pair<int, char>> mp {
        {1, 'I'},    // 0
        {5, 'V'},    // 1
        {10, 'X'},   // 2
        {50, 'L'},   // 3
        {100, 'C'},  // 4
        {500, 'D'},  // 5
        {1000, 'M'}  // 6
    };


    // just for 'M's:
    // - we can divide with 1k, add relevant 'M's to answer
    // - module with 1k, and then continue like below:

    const int M = (int) mp.size();
    int i = M-1; // last valid index
    while (num>0) {

      int mergeIdx = (i%2==0)? i-2: i-1;

      if (num>=mp[i].first) {
        num-=mp[i].first;
        res+=mp[i].second;
        // edge case: using 2 chars:
        // prev index is valid and is in special bounds
      } else if (mergeIdx>=0 && num >= mp[i].first-mp[mergeIdx].first) {
        // it's in special bounds
        // subtract special sum
        num-=(mp[i].first-mp[mergeIdx].first);
        // add 2 chars:
        res+=mp[mergeIdx].second;
        res+=mp[i].second;
      } else { // not greater than either: decrease i
        i--; // check for smaller nums
      }
    }

    return res;
  }
};

class SolutionSleek {
 public:
  string intToRoman(int num) {
    if (num==0) return 0;

    string res;
    if (num<0) {  // make positive and add '-'
      res="-";
      num=-num;
    }

    // if we did not have special regions:
    // divide and module
    vector<pair<int, string>> mp {
        {1,    "I"},
        {4,    "IV"},
        {5,    "V"},
        {9,    "IX"},
        {10,   "X"},
        {40,   "XL"},
        {50,   "L"},
        {90,   "XC"},
        {100,  "C"},
        {400,  "CD"},
        {500,  "D"},
        {900,  "CM"},
        {1000, "M"}
    };

    const int M = (int) mp.size();
    int i = M-1;
    while(num>0) {
      // LEFTHERE:
      if (num>=mp[i].first) {
        int times = num/mp[i].first;
        num%=mp[i].first;

        while(times--) {
          res+=mp[i].second;
        }
      } else i--;
    }

    return res;
  }
};