#include <iostream>
#include <vector>
#include <climits>

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
    int PrintMaximumSubarraySum(vector<int> &nums)
    {
        int left = 0, right = 0;
        int maxSum = nums[0];
        int tempSum = nums[0];
        int n = nums.size();
        int i = 0, j = 0;
        for (int k = 1; k < n; k++)
        {
            if (tempSum + nums[k] > nums[k])
            {
                tempSum = tempSum + nums[k];
                j++;
            }
            else
            {
                tempSum = nums[k];
                i = j = k;
            }

            if (tempSum > maxSum)
            {
                left = i;
                right = j;
                maxSum = tempSum;
            }
        }

        for (int i = left; i <= right; i++)
        {
            cout << nums[i] << " ";
        }
        cout << endl;
        return maxSum;
    }
};

int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution obj;
    cout << obj.Approach1(arr) << endl;
    cout << obj.Approach2(arr) << endl;
    cout << obj.PrintMaximumSubarraySum(arr) << endl;
    return 0;
}