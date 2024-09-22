#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<vector<int>> arr;

public:
    void FindPossibleSubset(int start, int end, vector<int> &temp, vector<int> &nums)
    {
        if (start == end)
        {
            arr.push_back(temp);
            return;
        }
        temp.push_back(nums[start]);
        FindPossibleSubset(start + 1, end, temp, nums);
        temp.pop_back();
        FindPossibleSubset(start + 1, end, temp, nums);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> temp;
        int n = nums.size();
        FindPossibleSubset(0, n, temp, nums);
        return arr;
    }

    vector<vector<int>> SubsetsApproach2(vector<int> &nums)
    {
        int n = nums.size();
        long long powerSetSize = FindPowerSet(n);
        for (long long j = 0; j < powerSetSize; j++)
        {
            vector<int> temp;
            for (int i = 0; i < n; i++)
            {
                if ((j & (1 << i)) != 0)
                {
                    temp.push_back(nums[i]);
                }
            }
            arr.push_back(temp);
        }
        return arr;
    }
    long long FindPowerSet(int x)
    {
        long long ans = 1;
        int val = 2;
        while (x != 0)
        {
            if (x % 2)
            {
                ans *= val;
                x = x - 1;
            }
            else
            {
                val = val * val;
                x = x / 2;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};
    Solution obj;
    vector<vector<int>> arr;
    arr = obj.SubsetsApproach2(nums);

    cout << "All possible subsets are: " << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "]";
        cout << endl;
    }

    // cout << obj.FindPowerSet(3) << endl;

    return 0;
}