#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

  vector<int> singleVector(vector<int>& nums, int k) {
    vector<int> result(k, 0);
    for (int i = 0, j = 0; i < nums.size(); i++) {
      while (nums.size() - i > k - j && j > 0 && nums[i] > result[j - 1]) j--;
      if (j < k) result[j++] = nums[i];
    }

    return result;
  }

  bool isLarger(vector<int>& nums1, int i, vector<int>& nums2, int j) {
    while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
      i++;
      j++;
    }
    return j == nums2.size() || (i < nums1.size() && nums1[i] > nums2[j]);
  }

  vector<int> merge(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<int> result(k, 0);
    int a = 0, b = 0;

    for (int i = 0; i < k; i++) {
      //cout << "before " << a << endl;
      result[i] = isLarger(nums1, a, nums2, b) ? nums1[a++] : nums2[b++];
      //cout << "after " <<a << endl;
    }

    return result;
  }

  vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<int> result(k, 0);
    int diff = k - nums2.size();

    for (int i = max(0, diff); i <= nums1.size() && i <= k; i++) {
      vector<int> v1 = singleVector(nums1, i);
      vector<int> v2 = singleVector(nums2, k - i);
      vector<int> currMax = merge(v1, v2, k);
      if (isLarger(currMax, 0, result, 0)) result = currMax;
    }

    return result;
  }


// To execute C++, please define "int main()"
int main() {
  vector<int> v1 = {1,  1, 1, 1, 1};
  vector<int> v2 = {1, 1, 1, 2, 1};
  
  vector<int> v3 = maxNumber(v1, v2, 7);
  
  for(auto i = v3.begin(); i != v3.end(); i++)
  cout << *i << ' ';
}
