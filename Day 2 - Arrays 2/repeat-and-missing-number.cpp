vector<int> Solution::repeatedNumber(const vector<int> &A)
{
  long long n = A.size();
  long long sum = (n * (n + 1)) / 2;
  long long squareSum = (n * (n + 1) * (2 * n + 1)) / 6;

  long long actualSum = 0;
  long long actualSquareSum = 0;
  for (int i = 0; i < n; i++)
  {
    actualSum += A[i];
    actualSquareSum += (long long)A[i] * (long long)A[i];
  }

  long long eq1 = actualSum - sum;             // r - m
  long long eq2 = actualSquareSum - squareSum; // (r+m)(r-m)
  eq2 = eq2 / eq1;                             // r + m

  int repeating = (eq1 + eq2) / 2;
  int missing = eq2 - repeating;

  return {repeating, missing};
}
