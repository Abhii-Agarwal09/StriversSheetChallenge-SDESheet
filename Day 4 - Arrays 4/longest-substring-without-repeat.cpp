class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    int len = s.length();
    unordered_map<char, int> mp;

    int start = 0;
    int end = 0;

    int maxi = 0;

    while (end < len)
    {
      char ch = s[end];

      if (mp.find(ch) != mp.end())
      {
        // element present in map
        start = max(mp[ch] + 1, start);
      }
      // element not present
      maxi = max(maxi, end - start + 1);
      mp[ch] = end;
      end++;
    }
    return maxi;
  }
};