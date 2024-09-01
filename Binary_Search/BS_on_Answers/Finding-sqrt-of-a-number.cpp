#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    int BruteForceApproach(int n)
    {
        int finalAns = -1;
        for (int i = 1; i < n; i++)
        {
            if (i * i <= n)
            {
                finalAns = max(finalAns, i);
            }
        }
        return finalAns;
    }

    int OptimalApproach1(int n)
    {

        return floor(sqrt(n));
    }

    int OptimalApproach2(int n)
    {
        int low = 1;
        int high = n;
        int finalAns = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if ((mid * mid) <= n)
            {
                finalAns = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return finalAns;
    }
};

int main()
{
    Solution obj;
    cout << obj.BruteForceApproach(81) << endl;
    cout << obj.OptimalApproach1(81) << endl;
    cout << obj.OptimalApproach2(81) << endl;
    return 0;
}