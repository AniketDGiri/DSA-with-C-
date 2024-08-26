#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int BetterApproach(vector<int> &nums, int k)
    {
        unordered_map<int, int> countMap;
        countMap.insert({0, 1});

        int n = nums.size();
        int tempSum = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            tempSum += nums[i];
            if (countMap.find(tempSum - k) != countMap.end())
            {
                cnt += countMap[tempSum - k];
            }
            countMap[tempSum]++;
        }
        return cnt;
    }
};

int main()
{
    vector<int> arr = {1, -1, 0};
    Solution obj;
    cout << obj.BetterApproach(arr, 0) << endl;
    return 0;
}