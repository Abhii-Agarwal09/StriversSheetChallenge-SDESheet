vector<int> generateRow(int rowNumber)
{
  long long ans = 1;
  vector<int> row;
  row.push_back(1);
  for (int col = 1; col < rowNumber; col++)
  {
    ans = ans * (rowNumber - col);
    ans /= col;
    row.push_back(ans);
  }
  return row;
}
vector<vector<int>> generate(int numrows)
{
  vector<vector<int>> ans;
  for (int i = 1; i <= numrows; i++)
  {
    vector<int> temp = generateRow(i);
    ans.push_back(temp);
  }
  return ans;
}