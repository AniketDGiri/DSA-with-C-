#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <climits>

using namespace std;
class Solution
{
public:
    // calculate all the possible subarrays
    int Approach1(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxSum = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int tempSum = 0;
            for (int j = i; j < n; j++)
            {
                tempSum += nums[j];
                if (tempSum == k)
                {
                    maxSum = max(maxSum, (j - i + 1));
                }
            }
        }
        return maxSum;
    }

    int Approach2(vector<int> &nums, int k)
    {
        unordered_map<int, int> SumMap;
        SumMap.insert({0, -1});
        int n = nums.size();
        int tempSum = 0;
        int maxSum = INT_MIN;
        unordered_map<int, int>::iterator itr;
        for (int i = 0; i < n; i++)
        {
            tempSum += nums[i];
            if (SumMap.find(tempSum - k) != SumMap.end())
            {
                itr = SumMap.find(tempSum - k);
                maxSum = max(maxSum, i - itr->second);
            }

            SumMap.insert({tempSum, i});
        }
        return maxSum;
    }

    int Approach3(vector<int> &nums, int k)
    {
        int i = 0, j = 0;
        int maxLen = 0;
        int tempLen = nums[0];

        int n = nums.size();

        while (j < n)
        {
            while (i <= j && tempLen > k)
            {
                tempLen -= nums[i];
                i++;
            }

            if (tempLen == k)
            {
                maxLen = max(maxLen, j - i + 1);
            }

            j++;
            if (j < n)
                tempLen += nums[j];
        }
        return maxLen;
    }
};

int main()
{
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int k = 15;
    Solution obj;
    cout << obj.Approach1(arr, k) << endl;
    cout << obj.Approach2(arr, k) << endl;
    cout << obj.Approach3(arr, k) << endl;

    return 0;
}