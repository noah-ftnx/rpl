#ifndef _H_
#define _H_

// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
 public:
  // min platforms so no train waits
  // TA: arrives at 5
  // TB:  leaves at 5 => extra platform
  /*
  arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
  dep[] = {0910, 1200, 1120, 1130, 1900, 2000}

  arr[] = {0900, 0950, 1100, 0900, 1500, 1800}
  dep[] = {0910, 1120, 1130, 1200, 1900, 2000}

  Answer: 4
  ---
       ---------
           ------
    ------------------  collides with: 2,3 but also 1
                           -----
                              ----

  Sort by arrival time:
  ---
   ------------------  collides with: 2,3 but also 1
       ---------
           ------

                           -----
                              ----


  0. put arr/dep time sin struct
  1. sort by arr time

  lastDep=-1

  2.from the start:
    if i arr time <= than prev arr time:
     an extra collision
   else:
     curPlatforms is 1

  mnPlatforms is max of curPlaforms
  update lastDeparture time (max)


  0 3 4   5 6     9
              -----
           ----
         ---
    ---
  ---

  --
   ---
     --
  ------
     ----

  */

  int findPlatform2(int arr[], int dep[], int n);
};






// { Driver Code Starts.
// Driver code
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int arr[n];
    int dep[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    for(int j=0;j<n;j++){
      cin>>dep[j];
    }
    Solution ob;
    cout <<ob.findPlatform(arr, dep, n)<<endl;
  }
  return 0;
}  // } Driver Code Ends


#endif
