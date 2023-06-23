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

class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    int size = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < size; i++)
    {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      int k = i + 1;
      int j = size - 1;
      while (k < j)
      {
        int sum = nums[i] + nums[k] + nums[j];
        if (sum < 0)
        {
          k++;
        }
        else if (sum > 0)
        {
          j--;
        }
        else
        {
          ans.push_back({nums[i], nums[j], nums[k]});
          k++;
          j--;
          while (k < j && nums[k] == nums[k - 1])
            k++;
          while (k < j && nums[j] == nums[j + 1])
            j--;
        }
      }
    }
    return ans;
  }
};