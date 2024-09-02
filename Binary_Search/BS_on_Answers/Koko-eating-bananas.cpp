/*
# [875\. Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/)

## Description

Difficulty: **Medium**


## Solution

Language: ****

```
·‌·‌·‌·‌·‌·‌·‌·‌·‌·‌·‌·‌double·‌totalHrs·‌=·‌0;
·‌·‌·‌·‌·‌·‌·‌·‌{
·‌·‌·‌·‌·‌·‌·‌·‌·‌·‌·‌·‌int·‌mid·‌=·‌(low·‌+·‌high)·‌/·‌2;
·‌·‌·‌·‌·‌·‌·‌·‌int·‌high·‌=·‌maxEle;
·‌·‌·‌·‌·‌·‌·‌·‌while·‌(low·‌<=·‌high)
·‌·‌·‌·‌·‌·‌·‌·‌int·‌low·‌=·‌1;
·‌·‌·‌·‌·‌·‌·‌·‌·‌·‌·‌·‌maxEle·‌=·‌max(maxEle,·‌nums[i]);
·‌·‌·‌·‌·‌·‌·‌·‌}
·‌·‌·‌·‌·‌·‌·‌·‌for·‌(int·‌i·‌=·‌0;·‌i·‌<·‌n;·‌i++)
·‌·‌·‌·‌·‌·‌·‌·‌{
      ·‌·‌·‌int·‌maxEle·‌=·‌-1;
·‌·‌·‌·‌·‌·‌·‌·‌int·‌n·‌=·‌nums.size();
public:
    int minEatingSpeed(vector<int>& nums, int k) {
class Solution {
[
[3,6,7,11]
8
[30,11,23,4,20]
5
[30,11,23,4,20]
6
4
30
23
4
30
23
```
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    int BruteForceApproach(vector<int> &nums, int k)
    {
        int maxEle = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            maxEle = max(maxEle, nums[i]);
        }

        for (int i = 1; i < maxEle; i++)
        {
            int totalHrs = 0;
            for (int j = 0; j < n; j++)
            {
                totalHrs += ceil(static_cast<double>(nums[j]) / i);
            }
            if (totalHrs == k)
                return i;
        }
        return -1;
    }

    int OptimalApproach(vector<int> &nums, int k)
    {
        int maxEle = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            maxEle = max(maxEle, nums[i]);
        }
        int low = 1;
        int high = maxEle;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            double totalHrs = 0;

            for (int j = 0; j < n; j++)
            {
                totalHrs += ceil(static_cast<double>(nums[j]) / mid);
            }
            if (totalHrs <= k)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};

int main()
{
    vector<int> arr = {3, 6, 7, 11};
    int hrs = 8;
    Solution obj;
    cout << obj.BruteForceApproach(arr, hrs) << endl;
    cout << obj.OptimalApproach(arr, hrs) << endl;
    return 0;
}