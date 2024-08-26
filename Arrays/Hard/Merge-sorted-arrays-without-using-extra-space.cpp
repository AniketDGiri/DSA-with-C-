#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void WithSpaceApproach(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        /*
        URL: https://leetcode.com/problems/merge-sorted-array/description/

88. Merge Sorted Array

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 
Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].

Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.

 
Constraints:

    nums1.length == m + n
    nums2.length == n
    0 <= m, n <= 200
    1 <= m + n <= 200
    -109 <= nums1[i], nums2[j] <= 109

 
Follow up: Can you come up with an algorithm that runs in O(m + n) time?
        */

        vector<int> tempArr;
        int i = 0, j = 0;

        while (i < m and j < n)
        {
            if (nums1[i] < nums2[j])
            {
                tempArr.push_back(nums1[i]);
                i++;
            }
            else
            {
                tempArr.push_back(nums2[j]);
                j++;
            }
        }
        if (i < m)
        {
            while (i < m)
            {
                tempArr.push_back(nums1[i]);
                i++;
            }
        }
        if (j < n)
        {
            while (j < n)
            {
                tempArr.push_back(nums2[j]);
                j++;
            }
        }

        for (int i = 0; i < n + m; i++)
        {
            nums1[i] = tempArr[i];
        }
        cout << "Sorted array is:";
        for (const auto i : nums1)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    void OptimalApproach(vector<int> &arr1, vector<int> &arr2)
    {
        int n = arr1.size();
        int m = arr2.size();

        int i = n - 1, j = 0;
        while (i >= 0 and j < m)
        {
            if (arr1[i] > arr2[j])
            {
                // cout << arr1[i] << " " << arr2[j];
                swap(arr1[i], arr2[j]);
                i--;
                j++;
            }
            else
            {
                break;
            }
        }
    }
};

int main()
{
    vector<int> arr1 = {1, 2, 3, 0, 0, 0};
    vector<int> arr2 = {2, 5, 6};

    Solution obj;
    // obj.OptimalApproach(arr1, arr2);
    // sort(arr1.begin(), arr1.end());
    // sort(arr2.begin(), arr2.end());
    obj.WithSpaceApproach(arr1, 3, arr2, 3);
    // Total Array elements;
    cout << "Total array elements";
    for (int i = 0; i < arr1.size(); i++)
    {
        cout << arr1[i] << " ";
    }
    cout << " ";
    for (int i = 0; i < arr2.size(); i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
}