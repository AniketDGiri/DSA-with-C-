#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int OptimalApproach(vector<int> &nums)
    {
        unordered_map<int, int> prefixSum;
        unordered_map<int, int>::iterator itr;
        int maxLen = 0;
        int tempSum = 0;
        prefixSum.insert({0, -1});

        for (int i = 0; i < nums.size(); i++)
        {
            tempSum += nums[i];
            if (prefixSum.find(tempSum) != prefixSum.end())
            {
                // cout << "---" << nums[i] << endl;
                itr = prefixSum.find(tempSum);
                maxLen = max(maxLen, i - itr->second);
            }
            else
            {
                prefixSum.insert({tempSum, i});
            }
        }
        return maxLen;
    }
};

int main()
{
    vector<int> arr = {6, -2, 2, -8, 1, 7, 4, -10};

    Solution obj;
    cout << obj.OptimalApproach(arr) << endl;

    return 0;
}