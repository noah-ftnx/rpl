/*
 * Build CFG from LIR
 */


#include <vector>
using namespace std;

struct Instruction {
    bool isLabel;
};

/**
 * @instructions: of a method
*/
void solve(vector<Instruction> instructions) {
    const int N = (int) instructions.size();
    vector<int> leaders; // id of leaders
    for (int i=0; i<N; i++) {

        // leader: 1st op of a block: first op of method or right after a label
        bool isLeader = i==0 || instructions[i-1].isLabel;
        if (isLeader) {
            leaders.push_back(i);
            buildCfg(i-1); // build cfg for the label
        }
    }
}