#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<int> memo;

public:
    Solution() : memo(46, 0) {}

    int climbStairs(int n)
    {
        if (n < 0)
        {
            return 0;
        }

        if (memo[n] != 0)
        {
            return memo[n];
        }
        if (n == 0 || n == 1)
        {

            return 1;
        }

        memo[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return memo[n];
    }
};

int main()
{
    int n = 40;
    Solution obj;
    cout << obj.climbStairs(n) << endl;
}
