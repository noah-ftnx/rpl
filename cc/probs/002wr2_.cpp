class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n<0 || tasks.empty()) return 0;

        const int time_to_exec=1;

        // Heap: based on 2 factors:
        // - ready time: (smallest wins)
        // - break tie:
        //   - by using occurences of instruction (hist number) (biggest wins)




        // EDGE CASE: TODO
        // AAAAABCDEF
        // this aproach:
        // ABCDEFA__A__A__A__A
        // put weight for 'A's


        // Idea: schedule tasks of same operation as further as possible
        // STEP 1: build histogram:
        unordered_map<char, int> hist;
        for (char task: tasks) { // TODO: IN NOTES
            hist[task]++;
        }

        struct TaskGroup {
            char task;
            // how many times to schedule this task
            int frequency;
            int ready_cycle;
        };


        struct TaskGroup {
            bool operator()(TaskGroup &a, TaskGroup &b) {
                // Rules: top tasks with
                // 1. least ready time
                // 2. if ties: use biggest frequency (is this needed?)

                // perc down works in reverse
                return (b.ready_cycle==a.ready_cycle && b.frequency > a.frequency) // Rule2
                       || b.ready_time < a.ready_time; // Rule1
            }
        };

        // have ready_list and active_list
        // ONE PQ NOT ENOUGH: ready_cycle NOT ENOUGH
        // SECOND MISTAKE!!

        // STEP 2: prepare ready_list and worklist
        for (auto &pair: hist) { // TODO: IMPORTANT!!
            const int ready_cycle=0;
            worklist.push({pair.first, pair.second, 0});
        }

        int cycle=0;
        // STEP 3: consume ready_list (and update fork active_list)
        while (!worklist.empty()) {
            TaskGroup taskGrp=worklist.top(); worklist.pop();

            // cout << "TOP: " << taskGrp.task << endl;

             // B. stall if we have to
             int delay_time=taskGrp.ready_cycle-cycle;
             // zero or negative -> no delay
             if (delay_time > 0) {
                 // introduce a delay (STALL)
                 cycle+=delay_time;
             }


            // C. schedule remaining tasks of same operation
            if(--taskGrp.frequency > 0) {
                // push it back in:
                // BUT calculate ready_cycle
                int ready_cycle=time_to_exec+cycle+n;
                taskGrp.ready_cycle=ready_cycle;

                // updated both: frequency and ready cycle
                // schedule next task of this op
                worklist.push(taskGrp);
            }

            // ADVANCE CYCLE
            cycle+=time_to_exec;
        }

        return cycle;
    }
};