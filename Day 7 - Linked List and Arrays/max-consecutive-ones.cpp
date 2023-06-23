class Solution
{
public:
  int findMaxConsecutiveOnes(vector<int> &nums)
  {
    int ans = 0;
    int max = 0;
    ;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] == 1)
      {
        ans++;
        if (ans >= max)
        {
          max = ans;
        }
      }
      else
      {
        ans = 0;
      }
    }
    return max;
  }
};