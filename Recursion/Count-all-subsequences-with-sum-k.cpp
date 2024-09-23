#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int CheckSum(int start, int end, vector<int> &nums, int tempSum, int totalCount, int k)
    {
        if (start == end)
        {
            if (tempSum == k)
                return totalCount + 1;
            return totalCount;
        }
        tempSum += nums[start];
        totalCount = CheckSum(start + 1, end, nums, tempSum, totalCount, k);
        tempSum -= nums[start];
        totalCount = CheckSum(start + 1, end, nums, tempSum, totalCount, k);
        return totalCount;
    }

    int CountAllSubsequencesWithSumK(vector<int> &nums)
    {
        int start = 0, end = nums.size();
        int tempSum = 0, totalCount = 0;
        int k = 10;
        totalCount = CheckSum(start, end, nums, tempSum, totalCount, k);
        return totalCount;
    }
};

int main()
{
    vector<int> arr = {2, 5, 1, 4, 3};
    Solution obj;
    cout << obj.CountAllSubsequencesWithSumK(arr) << endl;

    return 0;
}