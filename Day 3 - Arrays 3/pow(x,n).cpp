class Solution
{
public:
  double myPow(double x, int n)
  {
    if (n == 0 || x == 1)
    {
      return 1;
    }

    if (x == -1)
    {
      if (n % 2 == 0)
      {
        return 1;
      }
      else
      {
        return -1;
      }
    }

    if (n == INT_MAX || n == INT_MIN)
    {
      if (x == -1)
      {
        return -1;
      }
      else
      {
        return 0;
      }
    }

    double ans = 1;
    for (long long i = 1; i <= abs(n); i++)
    {
      ans *= x;
    }
    if (n < 0)
    {
      ans = 1.0 / ans;
    }
    return ans;
  }
};