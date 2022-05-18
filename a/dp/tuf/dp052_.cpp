#include <string>
#include <vector>
using namespace std;

int BF(int i, int j, bool cntT, string &exp) {
  if (i==j) { // cntT
    // 'T' True    -> 1    T T
    // 'T' False   -> 0    T F
    // 'F' False   ->  1   F F
    // 'F' True    -> 0    F T
    // return (exp[i]=='T' && cntT) ||
    // 	 		(exp[i]=='F' && !cntT);
    // OR XNOR: which is bool equality
    return (exp[i]=='T' == cntT);
  } else if (i>j) return 0;

  int cnt {};
  for (int p=i+1; p<=j; p+=2) {
    const int LT = BF(i, p-1, true, exp);
    const int LF = BF(i, p-1, false, exp);

    const int RT = BF(p+1, j, true, exp);
    const int RF = BF(p+1, j, false, exp);

    int ways {};
    switch (exp[p]) {
      case '&':
      {
        if (cntT) ways=(LT*RT);
        else ways=(LT*RF) + (LF*RT) + (LF*RF);
      } break;
      case '|':
      {
        if (cntT) ways=(LT*RT) + (LF*RT) + (LT*RF);
        else ways=(LF*RF);
      } break;
      case '^':
      {
        if (cntT) ways=(LT*RF) + (LF*RT);
        else ways=(LT*RT) + (LF*RF);
      }; break;
    }
    cnt+=ways;
  }
  return cnt;
}

int evaluateExpBF(string &exp) {
  return BF(0, exp.size()-1, 1, exp);
}



int MMZ(int i, int j, bool cntT, string &exp, vector<vector<vector<int>>> &dp) {
  if (i==j) { // cntT
    // 'T' True    -> 1    T T
    // 'T' False   -> 0    T F
    // 'F' False   ->  1   F F
    // 'F' True    -> 0    F T
    // return (exp[i]=='T' && cntT) ||
    // 	 		(exp[i]=='F' && !cntT);
    // OR XNOR: which is bool equality
    return (exp[i]=='T' == cntT);
  } else if (i>j) return 0;

  if (dp[i][j][cntT]!=-1) return dp[i][j][cntT];

  int cnt {};
  for (int p=i+1; p<=j; p+=2) {
    const int LT = MMZ(i, p-1, true, exp, dp);
    const int LF = MMZ(i, p-1, false, exp, dp);

    const int RT = MMZ(p+1, j, true, exp, dp);
    const int RF = MMZ(p+1, j, false, exp, dp);

    int ways {};
    switch (exp[p]) {
      case '&':
      {
        if (cntT) ways=(LT*RT);
        else ways=(LT*RF) + (LF*RT) + (LF*RF);
      } break;
      case '|':
      {
        if (cntT) ways=(LT*RT) + (LF*RT) + (LT*RF);
        else ways=(LF*RF);
      } break;
      case '^':
      {
        if (cntT) ways=(LT*RF) + (LF*RT);
        else ways=(LT*RT) + (LF*RF);
      }; break;
    }
    cnt+=ways;
  }
  return dp[i][j][cntT]=cnt;
}

int evaluateExpMMZ(string &exp) {
  const int N = (int) exp.size();
  vector<vector<vector<int>>> dp (N, vector<vector<int>>(N, vector<int>(2, -1)));
  return MMZ(0, exp.size()-1, 1, exp, dp);
}



int evaluateExpBU(string &exp) {
  if (exp.empty()) return 0;
  const int N = (int) exp.size();
  vector<vector<vector<int>>> dp (N, vector<vector<int>>(N, vector<int>(2, 0)));

  for (int i=0; i<N; i++) { // base case: 1 element
    for (int j=0; j<N; j++) {
      dp[i][j][0]=(exp[i]=='T' == 0);
      dp[i][j][1]=(exp[i]=='T' == 1);
    }
  }

  for (int i=N-1; i>=0; i--) {
    for (int j=0; j<N; j++) {
      for (int cntT=0; cntT<=1; cntT++){

      if (i>j) continue; // base case: no elements
      else if (i==j) continue; // base case: 1 element (inited above)

        int cnt {};
        for (int p=i+1; p<=j-1; p+=2) {
          const int LT = dp[i][p-1][1];
          const int LF = dp[i][p-1][0];
          const int RT = dp[p+1][j][1];
          const int RF = dp[p+1][j][0];

          int ways {};
          switch (exp[p]) {
            case '&':
            {
              if (cntT) ways=(LT*RT);
              else ways=(LT*RF) + (LF*RT) + (LF*RF);
            } break;
            case '|':
            {
              if (cntT) ways=(LT*RT) + (LF*RT) + (LT*RF);
              else ways=(LF*RF);
            } break;
            case '^':
            {
              if (cntT) ways=(LT*RF) + (LF*RT);
              else ways=(LT*RT) + (LF*RF);
            } break;
          }
          cnt+=ways;
          dp[i][j][cntT]=cnt;
        }

      }
    }
  }

  return dp[0][N-1][1];
}



#include "test/dp052.h"
int main() {
  run_tests("BF", evaluateExpBF);
  run_tests("MMZ", evaluateExpMMZ);
  run_tests("BU", evaluateExpBU);
  // run_tests("OPT", evaluateExpOPT);

  print_report();
  return 0;
}