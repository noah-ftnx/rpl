#include <string>
#include <unordered_set>
#include <functional>
using namespace std;

int perms(unordered_set<string> input) {
    function<void(unordered_set<string>&, string, int)> find_perms =
        [&](unordered_set<string> &unq, string s, int c) {
            if (c==s.size()) { // BC
                unq.insert(s);
                return;
            }

            for (int i=c; i<s.size(); i++) {
                find_perms(unq, s, c+1); // skip
                swap(s[c], s[i]);
                find_perms(unq, s, c+1); // swap
                swap(s[c], s[i]); // BT
            }
    };

    unordered_set<string> res;
    for (auto s: input) {
        unordered_set<string> t;
        find_perms(t, s, 0);
        res.insert(t.begin(), t.end());
    }

    return res.size();
}

int count_anagram_reorderings(string s) {
    unordered_set<string> unq;
    // create anagrams (substrings)
    const int S = s.size();
    for (int i =0; i<S; i++)
        for (int j=i; j<S; j++) {
            unq.insert(string(s.begin()+i, s.begin()+j+1));
        }

    return perms(unq);
}

#include "test/002v1.h"
int main() { run_tests(); return 0; }
