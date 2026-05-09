
// IMPLEMENT: printLISBF
string printLISBF(vector<int>& nums);

// IMPLEMENT: printLISMMZ
string printLISMMZ(vector<int>& nums);

// IMPLEMENT: printLISBU
string printLISBU(vector<int>& nums);

// IMPLEMENT: printLISOPT
string printLISOPT(vector<int>& nums);



#include "test/dp042.h"
int main() {
    run_tests("BF", printLISBF);
    run_tests("MMZ", printLISMMZ);
    run_tests("BU", printLISBU);
    run_tests("OPT", printLISOPT);

    print_report();
    return 0;
}