#include <iostream>

using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        // Here we are checking if n is negative
        bool checkNegative = false;
        if (n < 0)
        {
            n = -1 * n;
            checkNegative = true;
        }
        double ans = 1.0;
        long long i = n;
        while (n)
        {
            if (n % 2)
            {
                ans = ans * x;
                n = n - 1;
            }
            else
            {
                x = x * x;
                n = n / 2;
            }
        }
        if (checkNegative)
        {
            return (double)(1.0) / (double)(ans);
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    cout << obj.myPow(2.00000, -2) << endl;
    return 0;
}