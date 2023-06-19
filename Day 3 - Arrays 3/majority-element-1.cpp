class Solution
{
public:
  int majorityElement(vector<int> &nums)
  {
    int major = -1;
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (cnt == 0)
      {
        major = nums[i];
      }
      if (major == nums[i])
      {
        cnt++;
      }
      else
      {
        cnt--;
      }
    }
    return major;
    // unordered_map<int, int> map;
    // for (int i = 0; i < nums.size(); i++) {
    //   map[nums[i]]++;
    // }
    // unordered_map<int, int>::iterator it;
    // for (it = map.begin(); it != map.end(); it++) {
    //   if (it->second > (nums.size() / 2)) {
    //     return it->first;
    //   }
    // }
    // return -1;
  }
};