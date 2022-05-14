
int lengthOfLISBF(vector<int>& nums);

int lengthOfLISMMZ(vector<int>& nums);

int lengthOfLISBU(vector<int>& nums);

int lengthOfLISOPT(vector<int>& nums);



#include "test/dp041.h"
int main() {
    run_tests("BF", lengthOfLISBF);
//    run_tests("MMZ", lengthOfLISMMZ);
//    run_tests("BU", lengthOfLISBU);
//    run_tests("OPT", lengthOfLISOPT);

    print_report();
    return 0;
}