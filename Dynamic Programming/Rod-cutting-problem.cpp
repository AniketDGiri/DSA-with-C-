#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int cutRodRecursive(vector<int> &price, int n, int capacity)
    {
        int leftProfit = 0, rightProfit = 0;
        if (capacity == 0 || n == 0)
        {
            return 0;
        }

        if (n <= capacity)
        {
            leftProfit += price[n - 1] + cutRodRecursive(price, n, capacity - n);
        }
        rightProfit += cutRodRecursive(price, n - 1, capacity);

        return max(leftProfit, rightProfit);
    }
    int cutRod(vector<int> &price, int n)
    {
        // Write your code here.

        vector<vector<int>> memo(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (i <= j)
                {
                    memo[i][j] = max(price[i - 1] + memo[i][j - i], memo[i - 1][j]);
                }
                else
                {
                    memo[i][j] = memo[i - 1][j];
                }
            }
        }
        return memo[n][n];
        // return cutRodRecursive(price, n, n);
    }
};

int main()
{
    vector<int> profit = {3, 5, 8, 9, 10, 17, 17, 20};
    int n = profit.size();

    Solution obj;
    cout << obj.cutRod(profit, n) << endl;
    return 0;
}