#include <vector>
#include <cmath>
#include <unordered_set>
#include <iostream>
using namespace std;

vector<int> solve(vector<float> X) {
    float fsum=0; int isum=0;
    const int N = X.size();
    vector<float> fracs;
    for (int i=0; i<N; i++) {
        fsum+=X[i]; // numbers as is
        isum+=X[i]; // floored numbers
        fracs.push_back(X[i]- floor(X[i]));
    }

    int floorSum = isum;
    int ceilSum= round(fsum);
    int diff = ceilSum-floorSum; // MAX: will be N. MIN: 0
    cout << "DIFF:" << diff << endl;

    // must ceil 'diff' amount of numbers
    // pick from fracs: NOTE: frac part should match

    // TRICKY: greater: float (not int!)
    sort(fracs.begin(), fracs.end(), greater<float>());

    // the first `diff` numbers should be selected
    // we may have duplicates
    unordered_multiset<float> picks;
    for (int i=0; i<diff; i++){
        picks.insert(fracs[i]);
    }

    // create the result
    vector<int> Y;
    for (int i=0; i<N; i++) {
        float fr=X[i]-floor(X[i]);

        // find the first occurrence of the fractional (if exists)
        auto it = picks.find(fr);
        if (it != picks.end()) {
            // round this number up
            Y.push_back(ceil(X[i]));
            picks.erase(it);
        } else { // floor
            Y.push_back(floor(X[i]));
        }
    }
    return Y;
}


#include "test/410.h"
int main() { run_tests(); return 0; }