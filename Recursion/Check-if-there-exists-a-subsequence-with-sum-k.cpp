#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool CheckSum(int start, int end, vector<int> &nums, int tempSum, bool totalCount, int k)
    {

        if (start == end)
        {
            cout << "Temp Sum is: " << tempSum << endl;
            if (tempSum == k)
                return true;
            return totalCount;
        }
        tempSum += nums[start];
        if (totalCount == false)
        {

            totalCount = CheckSum(start + 1, end, nums, tempSum, totalCount, k);
        };

        tempSum -= nums[start];
        if (totalCount == false)
        {

            totalCount = CheckSum(start + 1, end, nums, tempSum, totalCount, k);
        }

        return totalCount;
    }

    int CountAllSubsequencesWithSumK(vector<int> &nums)
    {
        int start = 0, end = nums.size();
        int tempSum = 0;
        bool totalCount = false;
        int k = 3;
        totalCount = CheckSum(start, end, nums, tempSum, totalCount, k);
        return totalCount;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3};
    Solution obj;
    cout << obj.CountAllSubsequencesWithSumK(arr) << endl;

    return 0;
}