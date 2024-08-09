#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void PrintAllPermutationUsingRecursion(vector<int> &nums, int start, int size)
    {
        if (start == size)
        {
            for (const auto i : nums)
            {
                cout << i << " ";
            }
            cout << endl;
            return;
        }

        for (int i = start; i < size; i++)
        {
            swap(nums[start], nums[i]);
            PrintAllPermutationUsingRecursion(nums, start + 1, size);
            swap(nums[start], nums[i]);
        }
    }
    void Approach1(vector<int> &nums)
    {
        int n = nums.size();
        PrintAllPermutationUsingRecursion(nums, 0, n);
    }

    void findNextGreateElement(vector<int> &nums, int start)
    {
        int initialEle = nums[start - 1];
        int nextGreaterNum = nums[start];
        int nextGreaterIndex = start;
        for (int i = start + 1; i < nums.size(); i++)
        {
            if (nums[i] > initialEle and nums[i] < nextGreaterNum)
            {
                nextGreaterNum = nums[i];
                nextGreaterIndex = i;
            }
        }
        swap(nums[start - 1], nums[nextGreaterIndex]);
        sort(nums.begin() + start, nums.end());
    }

    // Optmial Approach
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size() - 1;
        int i = n;
        while (i > 0 and nums[i] < nums[i - 1])
        {
            i--;
        }
        if (i == 0)
        {
            sort(nums.begin(), nums.end());
            return;
        }
        findNextGreateElement(nums, i);
    }
};

int main()
{
    vector<int> arr = {4, 1, 3, 2};
    Solution obj;
    obj.nextPermutation(arr);

    cout << "Next Permutation is:";
    for (const auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}