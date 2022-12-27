#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int solve(vector<char>& tasks, int n) {
    int cycle = 0;
    const int time_to_finish = 1; // each instr needs 1 unit of time
    unordered_map<char, int> instr_issued;
    // AAABBB
    // A__A__AB__B__B
    // A: 1
    // cycle: 3
    // penalty: 0
    for (char task: tasks) {

        int penalty = 0;
        auto it = instr_issued.find(task);
        if (it != instr_issued.end()) {
            int last_cycle = it->second;
            // cycle where cooldown ends
            int cooldown_ends = last_cycle + n + time_to_finish;
            if (cooldown_ends > cycle) {
                penalty = cooldown_ends - cycle;
            }
        }

        // penalty must be added before issuing the next instruction
        cycle+=penalty;

        // then issue instruction. store when exec started
        instr_issued[task] = cycle;

        // increase cycle
        cycle+=time_to_finish;
    }
    return cycle;
}

#include "test/001.h"
int main() { run_tests(); return 0; }