#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    int minimumCoinsChangeRecursive(vector<int> &coins, int amount, int n)
    {
        int leftCount = INT_MAX, rightCount = INT_MAX;
        if (n == 0)
        {
            if (amount == 0)
            {
                return 0;
            }
            return INT_MAX - 1;
        }

        if (coins[n - 1] <= amount)
        {
            leftCount = 1 + minimumCoinsChangeRecursive(coins, amount - coins[n - 1], n);
        }
        rightCount = minimumCoinsChangeRecursive(coins, amount, n - 1);

        return min(leftCount, rightCount);
    }

    int coinChange(vector<int> &coins, int amount)
    {
        // int n = coins.size();
        // int minCount = minimumCoinsChangeRecursive(coins, amount, n);

        // if (minCount == INT_MAX || INT_MAX - 1)
        // {
        //     return -1;
        // }
        // return minCount;
        int n = coins.size();

        vector<vector<int>> memo(n + 1, vector<int>(amount + 1, 0));

        for (int i = 0; i <= amount; i++)
        {
            memo[0][i] = INT_MAX - 1;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                if (coins[i - 1] <= j)
                {
                    memo[i][j] = min(1 + memo[i][j - coins[i - 1]], memo[i - 1][j]);
                }
                else
                {
                    memo[i][j] = memo[i - 1][j];
                }
            }
        }
        if (memo[n][amount] == INT_MAX || memo[n][amount] == INT_MAX - 1)
        {
            return -1;
        }
        return memo[n][amount];
    }
};

int main()
{
    vector<int> arr = {1, 2, 5};
    int amount = 11;

    Solution obj;
    cout << obj.coinChange(arr, amount) << endl;
    return 0;
}