#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
    {
        // Write Your Code Here.
        int leftProfit = 0, rightProfit = 0;

        if (n == 0 || w == 0)
        {
            return 0;
        }

        if (weight[n - 1] <= w)
        {
            leftProfit += profit[n - 1] + unboundedKnapsack(n, w - weight[n - 1], profit, weight);
        }

        rightProfit += unboundedKnapsack(n - 1, w, profit, weight);

        // cout << "Left Profit is: " << leftProfit << endl;
        // cout << "Right Profit is: " << rightProfit << endl;
        // cout << "-----------------------------" << endl;
        return max(leftProfit, rightProfit);
    }

    int unboundedKnapsackDP(int n, int w, vector<int> &profit, vector<int> &weight)
    {
        // Write Your Code Here.
        vector<vector<int>> memo(n + 1, vector<int>(w + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                if (weight[i - 1] <= j)
                {
                    memo[i][j] = max(profit[i - 1] + memo[i][j - weight[i - 1]], memo[i - 1][j]);
                }
                else
                {
                    memo[i][j] = memo[i - 1][j];
                }
            }
        }
        return memo[n][w];
    }
};

int main()
{
    int n = 3;
    int w = 15;
    vector<int> profit = {7, 2, 4};
    vector<int> weight = {5, 10, 11};

    Solution obj;
    cout << obj.unboundedKnapsackDP(3, w, profit, weight) << endl;
    return 0;
}