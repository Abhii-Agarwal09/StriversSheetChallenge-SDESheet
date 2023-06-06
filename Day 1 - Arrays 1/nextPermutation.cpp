void nextPermutation(vector<int> &arr)
{
  int index = -1;
  int size = arr.size();
  for (int i = size - 2; i >= 0; i--)
  {
    if (arr[i] < arr[i + 1])
    {
      index = i;
      break;
    }
  }
  if (index == -1)
  {
    reverse(arr.begin(), arr.end());
    return;
  }
  for (int i = size - 1; i >= index; i--)
  {
    if (arr[i] > arr[index])
    {
      swap(arr[index], arr[i]);
      break;
    }
  }
  reverse(arr.begin() + index + 1, arr.end());
  return;
}