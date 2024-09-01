#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int BruteApproach(int n, int m)
    {
        int finalAns = -1;
        for (int i = 1; i <= m; i++)
        {
            int temp = 1;
            for (int j = 1; j <= n; j++)
            {
                temp *= i;
            }
            if (temp == m)
                finalAns = i;
        }
        return finalAns;
    }

    int OptimalApproach(int n, int m)
    {
        int finalAns = -1;
        int low = 1;
        int high = m;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int temp = 1;
            for (int j = 1; j <= n; j++)
            {
                temp *= mid;
            }

            if (temp == m)
            {
                finalAns = mid;
                break;
            }
            else if (temp > m)
                high = mid - 1;
            else
                low = mid + 1;

            // cout << "Mid is: " << mid << endl;
        }
        return finalAns;
    }
};

int main()
{
    Solution obj;
    cout << obj.BruteApproach(4, 81) << endl;
    cout << obj.OptimalApproach(4, 81) << endl;
    return 0;
}