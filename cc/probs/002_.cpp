class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n<0 || tasks.empty()) return 0;

        const int time_to_exec=1;

        // Heap: based on 2 factors:
        // - ready time: (smallest wins)
        // - break tie:
        //   - by using occurences of instruction (hist number) (biggest wins)

        // Idea: schedule tasks of same operation as further as possible
        // STEP 1: build histogram:
        unordered_map<char, int> hist;
        for (char task: tasks) {
            hist[task]++;
        }

        struct TaskGroup {
            char task;
            // how many times to schedule this task
            int frequency;
            int ready_cycle;
        };

        struct TaskReadyCmp {
            bool operator()(TaskGroup &a, TaskGroup &b) {
                // perc down tasks w/ less frequency
                return a.frequency < b.frequency;
            }
        };

        struct TaskWaitCmp {
            bool operator()(TaskGroup &a, TaskGroup &b) {
                // Rules: top tasks with
                // 1. least ready time
                // 2. if ties: use biggest frequency (is this needed?)

                return b.ready_cycle < a.ready_cycle;
                // no need for that:
                // // perc down works in reverse
                // return (b.ready_cycle==a.ready_cycle && b.frequency > a.frequency) // Rule2
                //     || b.ready_cycle < a.ready_cycle; // Rule1
            }
        };


        // ready_list: tasks ready to execute
        priority_queue<TaskGroup, vector<TaskGroup>, TaskReadyCmp> ready_list;
        // tasks that have to wait to be executed
        priority_queue<TaskGroup, vector<TaskGroup>, TaskWaitCmp> wait_list;

        // STEP 2: prepare ready_list and worklist
        for (auto &pair: hist) {
            const int ready_cycle=0;
            ready_list.push({pair.first, pair.second, 0});
        }

        int cycle=0;
        // STEP 3: consume ready_list (and update with wait_list)
        while (!ready_list.empty() || !wait_list.empty()) {

            // cout << "TOP: " << taskGrp.task << endl;

            // 1. Add new ready tasks:
            // why on top:
            // - well when we stall we continue
            // - so it must be added here to update ready_list after stalling
            while (!wait_list.empty() &&
                    wait_list.top().ready_cycle <= cycle) {
                // take a task group, and promote from wait to ready
                auto ready_task=wait_list.top(); wait_list.pop();
                ready_list.push(ready_task);
            }

            // nothing is ready -> must STALL
            if (ready_list.empty()) {
                cycle++;
                continue;
            }

            TaskGroup task=ready_list.top(); ready_list.pop();

            // C. schedule remaining tasks of same operation
            // decrease freq as it is executed
            if(--task.frequency > 0) {
                // push it back in:
                // BUT calculate ready_cycle
                int ready_cycle=time_to_exec+cycle+n;
                task.ready_cycle=ready_cycle;

                // updated both: frequency and ready cycle
                // schedule next task of this op
                wait_list.push(task);
            }

            // ADVANCE CYCLE
            cycle+=time_to_exec;
        }

        return cycle;
    }
};