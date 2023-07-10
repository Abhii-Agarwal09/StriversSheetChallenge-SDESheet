#include <bits/stdc++.h>
bool comparison(pair<int, int> a, pair<int, int> b) {
    double ra1 = (double)a.second / (double)a.first;
    double ra2 = (double)b.second / (double)b.first;
  return ra1 > ra2;
}
double maximumValue(vector<pair<int, int>> &items, int n, int w) {
  // Write your code here.
  // ITEMS contains {weight, value} pairs.
  // sort based on values/weight
  sort(items.begin(), items.end(), comparison);
  int weight = 0;
  double val = 0.0;
  for (int i = 0; i < n; i++) {
    if (weight + items[i].first <= w) {
      val += items[i].second;
      weight += items[i].first;
    } else {
      // weight = weight + items[i].first;
      int reqWeight = w - weight;
      weight += reqWeight;
      val += (items[i].second / (double)items[i].first) * (double)reqWeight;
      break;
    }
  }
  return val;
}