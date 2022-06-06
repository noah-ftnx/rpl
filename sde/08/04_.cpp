double fractionalKnapsack(int W, Item arr[], int n) {

  // sort according to the highest price per unit
  sort(arr, arr+n, [](Item a, Item b) {
    // price per unit
    double aPpu = a.value/(double)a.weight;
    double bPpu = b.value/(double)b.weight;
    return aPpu > bPpu;
  });

  vector<double> ppu;
  for (int i=0; i<n; i++) {
    auto it=arr[i];
    ppu.push_back(it.value/(double)it.weight);
  }

  double res=0;
  int i=0;
  while (W>0 && i<n) {
    // either take it all, or take the kilos allowed until filling the bag
    int mxw = min(W, arr[i].weight);
    double profit = mxw* (double)ppu[i];
    res+=profit;

    W-=mxw;
    i++;
  }
  return res;
}