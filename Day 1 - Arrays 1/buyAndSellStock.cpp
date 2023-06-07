#include <bits/stdc++.h>
int maximumProfit(vector<int> &prices)
{
  // Write your code here.
  int maxi = 0;
  int minPrice = INT_MAX;
  for (int i = 0; i < prices.size(); i++)
  {
    minPrice = min(minPrice, prices[i]);
    maxi = max(maxi, prices[i] - minPrice);
  }
  return maxi;
}