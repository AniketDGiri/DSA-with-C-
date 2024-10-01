#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<vector<int>> memo;

public:
    Solution() : memo(100, vector<int>(100, 0)) {};
    int countSubsetsWithPartitions(vector<int> &nums, int k)
    {
        int n = nums.size();
        for (int i = 0; i < n + 1; i++)
        {
            memo[i][0] = 1;
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < k + 1; j++)
            {
                if (nums[i - 1] <= j)
                {
                    memo[i][j] = (memo[i - 1][j - nums[i - 1]]) + memo[i - 1][j];
                }
                else
                {
                    memo[i][j] = memo[i - 1][j];
                }
            }
        }
        return memo[n][k];
    }
};

int main()
{
    vector<int> arr = {1, 1, 1, 1};
    int d = 0;
    int sum = 0;
    for (auto i : arr)
    {
        sum += i;
    }

    int k = (sum + d) / 2;
    cout << "K is:" << k << endl;
    Solution obj;
    cout << obj.countSubsetsWithPartitions(arr, k) << endl;
    return 0;
}