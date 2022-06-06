vector<int> JobScheduling(Job arr[], int n) {
  sort(arr, arr+n, [](Job a, Job b) {
    return a.profit > b.profit;
  });

  int maxDeadline=0;
  for (int i=0; i<n; i++) maxDeadline=max(maxDeadline, arr[i].dead);

  int profit=0, jobs=0;
  vector<int> scheduling(maxDeadline, -1);
  for (int i=0; i<n; i++) {

    // find scheduling slot:
    // schedule max paying jobsas late as possible to max profit
    int j=arr[i].dead-1;
    while (j>=0 && scheduling[j]!=-1) j--;

    // no slot for given deadline
    if (j<0) continue;

    // perform job & take profit
    scheduling[j]=arr[i].id;
    profit+=arr[i].profit;
    jobs++;
  }
  return {jobs, profit};
}