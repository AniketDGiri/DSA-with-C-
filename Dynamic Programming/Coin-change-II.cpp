#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int totalChangeWays(int amount, vector<int> &coins, int n)
    {
        int leftCount = 0, rightCount = 0;
        if (n == 0)
        {
            if (amount == 0)
            {
                return 1;
            }
            return 0;
        }

        if (coins[n - 1] <= amount)
        {
            leftCount += totalChangeWays(amount - coins[n - 1], coins, n);
        }
        rightCount += totalChangeWays(amount, coins, n - 1);

        return leftCount + rightCount;
    }

    int changeDP(int amount, vector<int> &coins)
    {
        int n = coins.size();
        // return totalChangeWays(amount, coins, n);

        vector<vector<int>> memo(n + 1, vector<int>(amount + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            memo[i][0] = 1;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                if (coins[i - 1] <= j)
                {
                    memo[i][j] = memo[i][j - coins[i - 1]] + memo[i - 1][j];
                }
                else
                {
                    memo[i][j] = memo[i - 1][j];
                }
            }
        }
        return memo[n][amount];
    }

    int changeUsingMemo(int amount, vector<int> &coins, vector<vector<int>> &memo, int n)
    {
        int leftCount = 0, rightCount = 0;

        if (n == 0)
        {
            if (amount == 0)
            {
                return 1;
            }
            return 0;
        }

        if (memo[n][amount] != -1)
        {
            return memo[n][amount];
        }
        if (coins[n - 1] <= amount)
        {
            leftCount += changeUsingMemo(amount - coins[n - 1], coins, memo, n);
        }
        rightCount += changeUsingMemo(amount, coins, memo, n - 1);

        return memo[n][amount] = leftCount + rightCount;
    }

    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        // return totalChangeWays(amount, coins, n);

        vector<vector<int>> memo(n + 1, vector<int>(amount + 1, -1));
        return changeUsingMemo(amount, coins, memo, n);
    }
};

int main()
{
    vector<int> arr = {1, 2, 5};
    int amount = 5;
    Solution obj;
    cout << obj.change(amount, arr) << endl;
    return 0;
}