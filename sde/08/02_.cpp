int findPlatformBF(int arr[], int dep[], int n) {

  struct Train { int arr, dep; };
  vector<Train> trains;
  for (int i=0; i<n; i++) trains.push_back({arr[i], dep[i]});

  // 1. sort trains on arrival
  sort(trains.begin(), trains.end(), [](Train a, Train b) {
    return a.arr < b.arr;
  });

  // 2. Need to answer:
  // for each arrival: how many trains were still at the station (from prev arrivals)

  int requiredPlatforms=0;

  for (int i=0; i<n; i++) {
    // go back and see how many trains are still at the station
    int prevTrains=0;

    for (int j=0; j<i; j++) { // check previous arrivals

      // current train: arrived before a previous arrival has left
      if (trains[i].arr <= trains[j].dep) prevTrains++;
    }

    requiredPlatforms=max(requiredPlatforms, 1+prevTrains);
  }

  return requiredPlatforms;
}

int findPlatformBetter(int arr[], int dep[], int n) {
  struct Train { int arr, dep; };
  vector<Train> trains;
  for (int i=0; i<n; i++) trains.push_back({arr[i], dep[i]});

  // sort trains on arrival
  sort(trains.begin(), trains.end(), [](Train a, Train b) {
    return a.arr < b.arr;
  });

  struct TrainPqCmp {
    bool operator()(Train a, Train b) {
      return a.dep > b.dep;
    }
  };

  // for each train: I care about how many trains are still at station
  priority_queue<Train, vector<Train>, TrainPqCmp> pq;
  int requiredPlatforms=0;

  for (int i=0; i<n; i++) {
    // go back and see how many trains are still at the station
    int prevTrains=0;

    // remove all departures that happened before current arrival
    // (keep in pq the trains that should still be at the station)
    while (!pq.empty() && pq.top().dep < trains[i].arr) pq.pop();

    pq.push(trains[i]);

    requiredPlatforms=max(requiredPlatforms, (int) pq.size());
  }

  return requiredPlatforms;
}


int findPlatformOPT(int arr[], int dep[], int n) {
  sort(arr, arr+n);
  sort(dep, dep+n);

  int res=0;

  // find the maximum distance between: the newest/current arrival and the latest departure
  // i: newest arrival, and j: latest departure
  for (int i=0, j=0; i<n; i++) {
    int arrival=arr[i];

    // advance all departures that have happened
    while(j<n && dep[j] < arr[i]) j++;
    // there must be at least a departure greater than an arrival
    // (as a dep comes after an arrival)

    int platforms = i-j+1;

    res=max(res, platforms);
  }

  return res;
}