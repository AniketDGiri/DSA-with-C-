#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<vector<int>> memo;

public:
    Solution() : memo(100, vector<int>(100, 0)) {}
    // int CalculateAllPossibleSubsets(vector<int> &nums, int k, int start, int count)
    // {
    //     int leftCount = 0, rightCount = 0;
    //     if (start == nums.size())
    //     {
    //         if (k == 0)
    //         {
    //             return 1;
    //         }
    //         return 0;
    //     }
    //     // chosse element if the given element is less than k
    //     if (nums[start] <= k)
    //     {
    //         leftCount += CalculateAllPossibleSubsets(nums, k - nums[start], start + 1, count);
    //     }
    //     rightCount += CalculateAllPossibleSubsets(nums, k, start + 1, count);

    //     return leftCount + rightCount;
    // }

    // int CountAllSubsetsUsingRecursion(vector<int> &nums, int k)
    // {
    //     return CalculateAllPossibleSubsets(nums, 3, 0, 0);
    // }

    int CalculateAllPossibleSubsetsDP(vector<int> &nums, int k, int start, int count)
    {
        int leftCount = 0, rightCount = 0;
        if (start == nums.size())
        {
            if (k == 0)
            {
                return 1;
            }
            return 0;
        }
        // chosse element if the given element is less than k
        if (nums[start] <= k)
        {
            leftCount += CalculateAllPossibleSubsetsDP(nums, k - nums[start], start + 1, count);
        }
        rightCount += CalculateAllPossibleSubsetsDP(nums, k, start + 1, count);
        memo[start][k] = leftCount + rightCount;

        return memo[start][k];
    }

    int CountAllSubsetsUsingDP(vector<int> &nums, int k)
    {
        return CalculateAllPossibleSubsetsDP(nums, 3, 0, 0);
    }
};

int main()
{
    vector<int> arr = {1, 2, 2, 3};
    Solution obj;
    cout << obj.CountAllSubsetsUsingDP(arr, 3) << endl;
    return 0;
}