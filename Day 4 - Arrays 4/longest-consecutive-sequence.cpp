class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {
    set<int> s;
    for (int i = 0; i < nums.size(); i++)
    {
      s.insert(nums[i]);
    }
    int cnt = 0;
    int maxi = -1;

    set<int>::iterator it;
    int prev = INT_MIN;
    for (it = s.begin(); it != s.end(); it++)
    {
      if (prev == INT_MIN)
      {
        prev = *it;
        cnt = 1;
      }
      else if (prev + 1 == *it)
      {
        cnt++;
        prev = *it;
      }
      else
      {
        maxi = max(cnt, maxi);
        cnt = 1;
        prev = *it;
      }
    }
    return max(maxi, cnt);
  }
};