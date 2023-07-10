#include <bits/stdc++.h>
int jobScheduling(vector<vector<int>> &arr) {
  int n = arr.size();
  sort(arr.begin(), arr.end(), [](const vector<int> &a, const vector<int> &b) {
    return a[1] > b[1]; // Sort by deadlines in descending order
  });

  int maxDeadline = 0;
  for (int i = 0; i < n; i++) {
    maxDeadline = max(maxDeadline, arr[i][0]);
  }

  int maxProfit = 0;
  vector<int> jobs(maxDeadline + 1, -1);
  for (int i = 0; i < n; i++) {
    int deadline = arr[i][0];
    for (int j = deadline; j > 0; j--) {
      if (jobs[j] == -1) {
        maxProfit += arr[i][1];
        jobs[j] = arr[i][0];
        break;
      }
    }
  }
  return maxProfit;
}
