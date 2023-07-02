class Solution {
  public:
    int cntPaths(int srow, int scol, int m, int n, vector<vector<int>> &dp) {
      if (srow >= m || scol >= n) return 0;
      if (srow == m - 1 && scol == n - 1) return 1;
      if (dp[srow][scol] != -1) return dp[srow][scol];
      int leftAns = cntPaths(srow + 1, scol, m, n, dp);
      int rightAns = cntPaths(srow, scol + 1, m, n, dp);
      return dp[srow][scol] = leftAns + rightAns;
    }
  public:
    int uniquePaths(int m, int n) {
      int srow = 0;
      int scol = 0;
      vector<vector<int>> dp(m, vector<int>(n, -1));
      int ans = cntPaths(srow, scol, m, n, dp);
      return ans;
    }
};


class Solution {
  public:
    // int cntPaths(int srow, int scol, int m, int n, vector<vector<int>> &dp) {
    //   if (srow >= m || scol >= n) return 0;
    //   if (srow == m - 1 && scol == n - 1) return 1;
    //   if (dp[srow][scol] != -1) return dp[srow][scol];
    //   int leftAns = cntPaths(srow + 1, scol, m, n, dp);
    //   int rightAns = cntPaths(srow, scol + 1, m, n, dp);
    //   return dp[srow][scol] = leftAns + rightAns;
    // }
  public:
    int uniquePaths(int m, int n) {
      // int srow = 0;
      // int scol = 0;
      // vector<vector<int>> dp(m, vector<int>(n, -1));
      // int ans = cntPaths(srow, scol, m, n, dp);
      // return ans;
      int total = m + n - 2;
      int r = m - 1;

      double ans = 1;
      for (int i = 1; i <= r; i++) {
        ans = ans * (total - r + i) / i;
      }
      return (int)ans;
    }
};