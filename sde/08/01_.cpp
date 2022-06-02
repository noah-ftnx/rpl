// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
 public:

  struct Meeting {
    int start;
    int end;
  };


  int maxMeetings(int start[], int end[], int n);

  //Function to find the maximum number of meetings that can
  //be performed in a meeting room.

};

// { Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int start[n], end[n];
    for (int i = 0; i < n; i++) cin >> start[i];

    for (int i = 0; i < n; i++) cin >> end[i];

    Solution ob;
    int ans = ob.maxMeetings(start, end, n);
    cout << ans << endl;
  }
  return 0;
}  // } Driver Code Ends


int Solution::maxMeetings(int start[], int end[], int n) {

  struct PqMeetingCmp {
    bool operator()(Meeting a, Meeting b) {
      // sort asc by end time:
      return (a.end > b.end);
    }
  };

  vector<Meeting> meetings;
  for (int i=0; i<n; i++) {
    meetings.push_back({start[i], end[i]});
  }

  priority_queue<Meeting, vector<Meeting>, PqMeetingCmp> pq;
  for (int i=0; i<n; i++) pq.push(meetings[i]);

  int lastEndTime=-1, cnt=0;
  while (!pq.empty()) {
    auto meeting = pq.top(); pq.pop();
    // a new class starts before the previous one has ended: ignore
    if (meeting.start <= lastEndTime) continue;

    cnt++;
    lastEndTime=meeting.end; // update end time
  }

  return cnt;
}


int maxMeetings(int start[], int end[], int n) {
  struct Meeting { int start, end; };

  vector<Meeting> meetings;
  for (int i=0; i<n; i++) meetings.push_back({start[i], end[i]});

  sort(meetings.begin(), meetings.end(),
       [](Meeting a, Meeting b) {
         return a.end < b.end;
       });

  int cnt=0, lastEndTime=-1;
  for (auto meeting: meetings) {
    if (meeting.start <=lastEndTime) continue;

    // can have the meeting
    cnt++;
    lastEndTime=meeting.end;
  }

  return cnt;
}