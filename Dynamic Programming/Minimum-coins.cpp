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
    }
};

int main()
{
    vector<int> arr = {2};
    int amount = 11;

    Solution obj;
    cout << obj.coinChange(arr, amount) << endl;
    return 0;
}