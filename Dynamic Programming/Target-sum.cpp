#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findAllPossible(vector<int> &nums, int target, int n)
    {
        int leftCount = 0, rightCount = 0;

        if (n == 0)
        {
            if (target == 0)
            {
                return 1;
            }
            return 0;
        }

        leftCount += findAllPossible(nums, target - nums[n - 1], n - 1);

        rightCount += findAllPossible(nums, target + nums[n - 1], n - 1);

        return leftCount + rightCount;
    }

    // this question is similar to the partition with given sum
};

int main()
{
    vector<int> arr = {1};
    int target = 1;

    Solution obj;
    // cout << obj.findTargetSumWays(arr, target) << endl;

    return 0;
}