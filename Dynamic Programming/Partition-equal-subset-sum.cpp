#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<vector<int>> memo;

public:
    Solution() : memo(201, vector<int>(101, -1)) {};

    bool checkEqualPartition(vector<int> &nums, int sum, int start)
    {
        bool leftPart, rightPart;
        if (start == nums.size())
        {
            if (sum == 0)
            {
                return true;
            }
        }

        if (nums[start] <= sum)
        {
            leftPart = checkEqualPartition(nums, sum - nums[start], start + 1);
        }
        if (!leftPart)
        {
            rightPart = (nums, sum, start + 1);
        }
        return leftPart || rightPart;
    }

    bool checkEqualPartitionBottomUpApproach(vector<int> &nums, int sum, int start)
    {
        bool leftPart, rightPart;
        if (start == nums.size())
        {
            if (sum == 0)
            {
                return true;
            }
        }

        if (memo[start][sum] != -1)
        {
            return memo[start][sum];
        }
        if (nums[start] <= sum)
        {
            memo[start][sum] = checkEqualPartitionBottomUpApproach(nums, sum - nums[start], start + 1);
        }
        if (!leftPart)
        {
            memo[start][sum] = (nums, sum, start + 1);
        }
        return memo[start][sum];
    }

    bool canPartitionApproach1(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return false;
        }

        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if (sum % 2)
        {
            return false;
        }

        // return checkEqualPartition(nums, sum / 2, 0);
        return checkEqualPartitionBottomUpApproach(nums, sum / 2, 0);
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 5};
    Solution obj;
    cout << obj.canPartitionApproach1(arr) << endl;
    return 0;
}