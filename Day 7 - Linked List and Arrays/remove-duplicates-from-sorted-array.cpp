class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {
    int size = nums.size();
    map<int, int> mp;
    for (int i = 0; i < size; i++)
    {
      mp[nums[i]]++;
    }
    map<int, int>::iterator it;
    int cnt = 0;
    for (it = mp.begin(); it != mp.end(); it++)
    {
      nums[cnt] = it->first;
      cnt++;
    }
    return cnt;
  }
};

class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {
    int size = nums.size();
    int index = 1;
    for (int i = 1; i < size; i++)
    {
      if (nums[i] == nums[i - 1])
        continue;
      nums[index] = nums[i];
      index++;
    }
    return index;
  }
};