class SolutionWRONG {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n<0 || tasks.empty()) return 0;

        const int time_to_exec=1;
        /**
        DRY RUN:

            - A:
            - B:

            last_issue:
            - A: 6
            - B: 4

            cycle:7
            worklist: B

            ready_cycle: 4+1+2=7
            delay=ready_cycle-cycle=0

            cycle+=delay // issue delay

            last_issue[A]=cycle

            A,B,_,A,B,_,A,B

            timeToExec=1;
            cooldown=n;

            cycle:
            map:
            - A: 3: 0+1+2 
           


            AAABBB
            0123456789x
            A__A__AB__B__B = 10

            AB_AB_AB = 8

                  i
            A A A B B B
            0




            # step 1:
            one pass to build histogram: OP -> occurences
            map/histogram:
            - A: 3
            - B: 3

            # step 2:
            Prepare a worklist:
            for each hist item:
              pop one, and enqueue
              A:2, B:2
              Q: A,B

            # step 3:
            while wokrlist not empty:
                - simulates clock (at the end of this loop)
                - consumes worklist, and histogram:
                  + pop from queue (say A)
                    - push same instruction from histogram (say A, if exists)
                      (consume histogram)
                  + schedule task:
                      + calculate delay:
                        - if was scheduled before: ready_cycle: last_sched+timeToExec+cooldown
                      + wait=ready_cycle-cycle
                         + cycle+=wait
                      + then issue: last_issue[A]=cycle
                  + cycle++
        */

        // Idea: schedule tasks of same operation as further as possible
        // STEP 1: build histogram:
        unordered_map<char, int> hist;
        for (char task: tasks) { // TODO: IN NOTES
            hist[task]++;
        }


        // STEP 2: prepare worklist
        queue<char> worklist;
        for (auto &pair: hist) { // TODO: IMPORTANT!!
            worklist.push(pair.first);
            pair.second--;
        }


        // EDGE CASE:
        // AAAAABCDEF
        // this aproach:
        // ABCDEFA__A__A__A__A
        // put weight for 'A's
        // Heap: based on 2 factors:
        // - ready time: (smallest wins)
        // - break tie:
        //   - by using occurences of instruction (hist number) (biggest wins)

        for (auto pair: hist) {
            cout << "KV: " << pair.first << ": " << pair.second << endl;
        }


        int cycle=0;

        // KV: task -> issue cycle
        // when an instruction was scheduled
        unordered_map<char, int> inst_sched;

        // STEP 3: consume worklist & hist
        while (!worklist.empty()) {
            char task=worklist.front(); worklist.pop();

            // A. update worklist (consume from hist)
            // we have more of this task
            if (hist[task] > 0) {
                worklist.push(task);
                hist[task]--;
            }


            // B. stall if we have to
            auto it=inst_sched.find(task);
            if (it != inst_sched.end()) {
                int issue_time=it->second;
                int ready_cycle=time_to_exec+issue_time+n;
                if (ready_cycle > cycle) {
                    int delay_time=ready_cycle-cycle;
                    cycle+=delay_time; // STALL
                }
            }

            // C. schedule task
            inst_sched[task]=cycle;

            // ADVANCE CYCLE
            cycle+=time_to_exec;
        }

        return cycle;
    }
};