#include <bits/stdc++.h>
bool isPossibleSolution(vector<int> time, long long int maxDays, long long int chapters, long long int mid)
{
  long long int dayCount = 1;
  long long int timeSum = 0;
  for (long long int i = 0; i < chapters; i++)
  {
    if (timeSum + time[i] <= mid)
    {
      timeSum += time[i];
    }
    else
    {
      dayCount++;
      if (dayCount > maxDays || time[i] > mid)
      {
        return false;
      }
      timeSum = time[i];
    }
  }
  return true;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
  // Write your code here.

  // calculate sum of time
  long long int sum = 0;
  for (int i = 0; i < time.size(); i++)
  {
    sum += time[i];
  }

  // define start and end indexes
  long long int start = 0;
  long long int end = sum;
  // mid
  long long int mid = start + (end - start) / 2;

  // find sol
  long long int ans = -1;
  while (start <= end)
  {
    if (isPossibleSolution(time, n, m, mid))
    {
      ans = mid;
      end = mid - 1;
    }
    else
    {
      start = mid + 1;
    }
    mid = start + (end - start) / 2;
  }
  return ans;
}