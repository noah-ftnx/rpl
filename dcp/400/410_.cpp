#include <vector>
#include <cmath>
#include <unordered_set>
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

    // must ceil 'diff' amount of numbers
    // pick from fracs: NOTE: frac part should match

    sort(fracs.begin(), fracs.end(), greater<int>());

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
        if (picks.count(fr)) {
            // round this number up
            Y.push_back(ceil(X[i]));
            picks.erase(fr);
        } else { // floor
            Y.push_back(floor(X[i]));
        }
    }
    return Y;
}


#include "test/410.h"
int main() { run_tests(); return 0; }