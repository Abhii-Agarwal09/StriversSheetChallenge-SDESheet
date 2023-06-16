class Solution
{
public:
  int findDuplicate(vector<int> &nums)
  {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
      map[nums[i]]++;
    }
    unordered_map<int, int>::iterator it;
    for (it = map.begin(); it != map.end(); it++)
    {
      if (it->second >= 2)
      {
        return it->first;
      }
    }
    return -1;
  }
};

class Solution
{
public:
  int findDuplicate(vector<int> &nums)
  {
    int fast = nums[0];
    int slow = nums[0];

    do
    {
      slow = nums[slow];
      fast = nums[nums[fast]];
    } while (slow != fast);

    fast = nums[0];
    while (fast != slow)
    {
      fast = nums[fast];
      slow = nums[slow];
    }
    return fast;
  }
};