class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    int size = nums.size();
    vector<vector<int>> ans;
    set<vector<int>> st;
    // check for size = 3
    if (size == 3)
    {
      if (nums[0] + nums[1] + nums[2] == 0)
      {
        ans.push_back({nums[0], nums[1], nums[2]});
      }
      return ans;
    }
    // sort
    sort(nums.begin(), nums.end());
    for (int i = 0; i < size - 2; i++)
    {
      int k = i + 1;
      int j = size - 1;
      int reqSum = 0 - nums[i];
      cout << reqSum << endl;

      while (k < j)
      {
        int sum = nums[k] + nums[j];
        if (sum < reqSum)
        {
          k++;
        }
        else if (sum > reqSum)
        {
          j--;
        }
        else
        {
          st.insert({nums[i], nums[j], nums[k]});
          k++;
        }
      }
    }
    set<vector<int>>::iterator it;
    for (it = st.begin(); it != st.end(); it++)
    {
      ans.push_back(*it);
    }
    return ans;
  }
};