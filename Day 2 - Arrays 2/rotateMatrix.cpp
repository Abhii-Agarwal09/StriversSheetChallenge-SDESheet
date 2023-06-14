class Solution
{
public:
  void rotate(vector<vector<int>> &matrix)
  {
    int row = matrix.size();
    int col = matrix[0].size();
    for (int i = 0; i < row; i++)
    {
      for (int j = i + 1; j < col; j++)
      {
        cout << i << " " << j << endl;
        swap(matrix[i][j], matrix[j][i]);
      }
    }
    for (int i = 0; i < row; i++)
    {
      int m = 0;
      int n = matrix[i].size() - 1;
      while (m < n)
      {
        swap(matrix[i][m], matrix[i][n]);
        m++;
        n--;
      }
    }
  }
};