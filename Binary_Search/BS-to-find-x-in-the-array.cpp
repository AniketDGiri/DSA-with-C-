/*
URL: https://leetcode.com/problems/binary-search/description/

704. Binary Search

Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

 
Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1

 
Constraints:

    1 <= nums.length <= 104
    -104 < nums[i], target < 104
    All the integers in nums are unique.
    nums is sorted in ascending order.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void Approach_Binary_Search(vector<int> &nums, int key)
    {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == key)
            {
                cout << "Element is present at location " << mid + 1 << endl;
                return;
            }
            else if (nums[mid] < key)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        cout << "No such element is present" << endl;
    }
};

int main()
{
    vector<int> arr = {-1, 0, 3, 5, 9, 1};
    Solution obj;
    obj.Approach_Binary_Search(arr, 5);
    return 0;
}