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

    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        return totalChangeWays(amount, coins, n);
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