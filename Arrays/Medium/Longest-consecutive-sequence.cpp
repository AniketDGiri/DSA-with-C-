#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool findNextNum(vector<int> &nums, int num)
    {
        for (const auto i : nums)
        {
            if (i == num)
                return true;
        }
        return false;
    }
    int BruteForceApproach(vector<int> &nums)
    {
        int longestCnt = 1;
        int nextEle = -1;
        for (const auto val : nums)
        {
            nextEle = val + 1;
            int tempLongestCnt = 1;
            while (findNextNum(nums, nextEle) == true)
            {
                nextEle++;
                tempLongestCnt++;
            }
            longestCnt = max(longestCnt, tempLongestCnt);
        }
        return longestCnt;
    }

    int BetterApproach(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int longestCnt = INT_MIN;
        int n = nums.size();
        int tempLongest = 1;
        int i = 0;
        while (i < n - 1)
        {
            if (nums[i] + 1 == nums[i + 1])
            {
                tempLongest++;
            }
            else
            {
                longestCnt = max(longestCnt, tempLongest);
                tempLongest = 1;
            }
            i++;
        }
        longestCnt = max(longestCnt, tempLongest);
        return longestCnt;
    }

    int OptimalApproach(vector<int> &nums)
    {
        unordered_set<int> setData;
        for (auto i : nums)
        {
            setData.insert(i);
        }
        int longestCnt = INT_MIN;
        int tempLongestCnt = 1;
        int val;
        for (const auto i : nums)
        {

            if (setData.find(i - 1) == setData.end())
            {
                tempLongestCnt = 1;
                val = i;
                while (setData.find(++val) != setData.end())
                {
                    tempLongestCnt++;
                }
                longestCnt = max(longestCnt, tempLongestCnt);
            }
        }
        return longestCnt;
    }
};

int main()
{
    vector<int> arr = {3, 8, 7, 6, 2, 1, 4};
    Solution obj;
    cout << obj.BruteForceApproach(arr) << endl;
    cout << obj.BetterApproach(arr) << endl;
    cout << obj.OptimalApproach(arr) << endl;

    return 0;
}