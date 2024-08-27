#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int BetterApproach(vector<int> &nums, int k)
    {
        unordered_map<int, int> xorSum;
        unordered_map<int, int>::iterator itr;
        int tempSum = 0;
        int cnt = 0;
        xorSum.insert({0, 1});
        for (int i = 0; i < nums.size(); i++)
        {
            tempSum ^= nums[i];
            if (xorSum.find(tempSum ^ k) != xorSum.end())
            {
                cnt += xorSum[tempSum ^ k];
            }
            xorSum[tempSum]++;
        }
        return cnt;
    }
};

int main()
{
    vector<int> arr = {4, 2, 2, 6, 4};

    Solution obj;
    cout << obj.BetterApproach(arr, 6) << endl;
    return 0;
}