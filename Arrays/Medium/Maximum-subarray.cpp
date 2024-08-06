#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int Approach1(vector<int> &nums)
    {
        int n = nums.size();
        int maxSum = INT_MIN;
        int tempSum = 0;
        for (int i = 0; i < n; i++)
        {
            tempSum = 0;
            for (int j = i + 1; j < n; j++)
            {
                tempSum += nums[j];
                maxSum = max(maxSum, tempSum);
            }
        }
        return maxSum;
    }

    int Approach2(vector<int> &nums)
    {
        int maxSum = nums[0];
        int tempSum = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            tempSum = max(tempSum + nums[i], nums[i]);
            maxSum = max(maxSum, tempSum);
        }
        return maxSum;
    }
};

int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution obj;
    cout << obj.Approach1(arr) << endl;
    cout << obj.Approach2(arr) << endl;
    return 0;
}