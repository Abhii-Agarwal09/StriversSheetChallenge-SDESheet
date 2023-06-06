// Brute force
void markRow(vector<vector<int>> &matrix, int rowNum, int cols)
{
  for (int i = 0; i < cols; i++)
  {
    if (matrix[rowNum][i] != 0)
    {
      matrix[rowNum][i] = -100000;
    }
  }
}
void markCol(vector<vector<int>> &matrix, int colNum, int rows)
{
  for (int i = 0; i < rows; i++)
  {
    if (matrix[i][colNum] != 0)
    {
      matrix[i][colNum] = -100000;
    }
  }
}
void setZeroes(vector<vector<int>> &matrix)
{
  int rows = matrix.size();
  int cols = matrix[0].size();
  // cout << "Rows " << rows << " Cols " << cols << endl;
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      // cout << i << " " << j << endl;
      if (matrix[i][j] == 0)
      {
        markRow(matrix, i, cols);
        markCol(matrix, j, rows);
      }
    }
  }
  // cout << "second" << endl;
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      // cout << i << " " << j << endl;
      if (matrix[i][j] == -100000)
      {
        matrix[i][j] = 0;
      }
    }
  }
}

// Better approach
void setZeroes(vector<vector<int>> &matrix)
{
  int rows = matrix.size();
  int cols = matrix[0].size();

  vector<int> rowMark(rows);
  vector<int> colMark(cols);

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if (matrix[i][j] == 0)
      {
        rowMark[i] = 1;
        colMark[j] = 1;
      }
    }
  }

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if (rowMark[i] == 1 || colMark[j] == 1)
      {
        matrix[i][j] = 0;
      }
    }
  }
}

void setZeroes(vector<vector<int>> &matrix)
{
  int rows = matrix.size();
  int cols = matrix[0].size();

  int c = 1;
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if (matrix[i][j] == 0)
      {
        matrix[i][0] = 0;
        if (j != 0)
        {
          matrix[0][j] = 0;
        }
        else
        {
          c = 0;
        }
      }
    }
  }

  for (int i = 1; i < rows; i++)
  {
    for (int j = 1; j < cols; j++)
    {
      if (matrix[i][j] != 0)
      {
        if (matrix[0][j] == 0 || matrix[i][0] == 0)
        {
          matrix[i][j] = 0;
        }
      }
    }
  }

  if (matrix[0][0] == 0)
  {
    for (int i = 0; i < cols; i++)
    {
      matrix[0][i] = 0;
    }
  }
  if (c == 0)
  {
    for (int i = 0; i < rows; i++)
    {
      matrix[i][0] = 0;
    }
  }
}