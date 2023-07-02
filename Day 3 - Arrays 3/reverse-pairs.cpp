class Solution {
  public:
    int countPairs(vector<int> &arr, int low, int mid, int high) {
      int right = mid + 1;
      int cnt = 0;
      for (int i = low; i <= mid; i++) {
        while (right <= high && (long long)arr[i] > 2ll * arr[right]) right++;
        cnt += right - (mid + 1);
      } 
      return cnt;
    }
  public:
    void merge(vector<int> &arr, int low, int mid, int high) {
      vector<int> temp;	// temporary array
      int left = low;	// starting index of left half of arr
      int right = mid + 1;	// starting index of right half of arr

     	//storing elements in the temporary array in a sorted manner//
      while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
          temp.push_back(arr[left]);
          left++;
        } else {
          temp.push_back(arr[right]);
          right++;
        }
      }

     	// if elements on the left half are still left	//

      while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
      }

     	//  if elements on the right half are still left	//
      while (right <= high) {
        temp.push_back(arr[right]);
        right++;
      }

     	// transfering all elements from temporary to arr	//
      for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
      }
    }
  public:
    int mergeSort(int low, int high, vector<int> &nums) {
      if (low >= high) return 0;
      int cnt = 0;
      int mid = (low + high) / 2 ;
      cnt += mergeSort(low, mid, nums);
      cnt += mergeSort(mid + 1, high, nums);
      cnt += countPairs(nums, low, mid, high);
      merge(nums, low, mid, high);
      return cnt;
    }
  public:
    int reversePairs(vector<int> &nums) {
      int low = 0;
      int high = nums.size() - 1;
      int ans = mergeSort(low, high, nums);
      return ans;
    }
};