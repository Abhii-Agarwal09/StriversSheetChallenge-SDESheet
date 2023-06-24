class Solution
{
public:
  int maxLen(vector<int> &A, int n)
  {
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = i; j < n; j++)
      {
        int sum = 0;
        int len = 0;
        for (int k = i; k <= j; k++)
        {
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