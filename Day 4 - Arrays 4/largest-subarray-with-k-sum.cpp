class Solution
{
public:
  int maxLen(vector<int> &A, int n)
  {
    int maxi = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        int sum = 0;
        int len = 0;
        for (int k = i; k <= j; k++) {
          sum += A[k];
          len++;
        }
        if (sum == 0)
        {
          maxi = max(maxi, len);
        }
      }
    }
    return maxi;
  }
};

class Solution
{
public:
  int maxLen(vector<int> &A, int n)
  {
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
      int sum = 0;
      int len = 0;
      for (int j = i; j < n; j++)
      {
        sum += A[j];
        len++;
        if (sum == 0)
        {
          maxi = max(maxi, len);
        }
      }
    }
    return maxi;
  }
};

// using hashing
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int maxi = 0;
        int prefixSum = 0;
        unordered_map<int, int> mp;
        
        for (int i = 0; i < n; i++) {
            prefixSum += A[i];
            if (prefixSum == 0) {
                maxi = max(maxi, i + 1);
            }
            int rem = prefixSum - 0; // 0 can be k also
            if (mp.find(rem) != mp.end()) {
                int len = i - mp[rem];
                maxi = max(maxi, len);
            }
            if (mp.find(prefixSum) == mp.end()) {
                mp[prefixSum] = i;
            }
        }
        return maxi;
    }
};