#include <iostream>
#include <vector>

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
};

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    Solution obj;
    obj.Approach1(arr);
    return 0;
}