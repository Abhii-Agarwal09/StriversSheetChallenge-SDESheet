class Solution
{
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target)
  {
    int size = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < size - 3; i++)
    {
      if (i > 0 && nums[i] == nums[i - 1])
      {
        continue;
      }

      for (int j = i + 1; j < size - 2; j++)
      {
        if (j > i + 1 && nums[j] == nums[j - 1])
        {
          continue;
        }

        int k = j + 1;
        int l = size - 1;

        while (k < l)
        {
          long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[l];
          if (sum < target)
          {
            k++;
          }
          else if (sum > target)
          {
            l--;
          }
          else
          {
            ans.push_back({nums[i], nums[j], nums[k], nums[l]});
            while (k < l && nums[k] == nums[k + 1])
            {
              k++;
            }
            while (k < l && nums[l] == nums[l - 1])
            {
              l--;
            }
            k++;
            l--;
          }
        }
      }
    }

    return ans;
  }
};