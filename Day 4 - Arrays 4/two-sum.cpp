class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    int size = nums.size();
    unordered_map<int, queue<int>> indexMap;
    for (int i = 0; i < size; i++)
    {
      indexMap[nums[i]].push(i);
    }
    vector<int> ans;

    sort(nums.begin(), nums.end());

    int i = 0;
    int j = size - 1;

    while (i < j)
    {
      int sum = nums[i] + nums[j];
      if (sum == target)
      {
        int index1 = indexMap[nums[i]].front();
        indexMap[nums[i]].pop();
        int index2 = indexMap[nums[j]].front();
        indexMap[nums[j]].pop();
        ans.push_back(index1);
        ans.push_back(index2);
        return ans;
      }
      else if (sum < target)
      {
        i++;
      }
      else
      {
        j--;
      }
    }
    ans.push_back(-1);
    ans.push_back(-1);
    return ans;
  }
};