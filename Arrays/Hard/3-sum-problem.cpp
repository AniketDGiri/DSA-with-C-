#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> BetterApproach(vector<int> &arr)
    {

        vector<vector<int>> finalAns;
        int n = arr.size();
        int j = 0, k = 0;

        for (int i = 0; i < n; i++)
        {
            while (i != 0 and arr[i] == arr[i - 1])
            {
                i++;
            }
            j = i + 1;
            k = n - 1;

            while (j < k)
            {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum < 0)
                {
                    j++;
                }
                else if (sum > 0)
                {
                    k--;
                }
                else
                {
                    vector<int> tempAns = {arr[i], arr[j], arr[k]};
                    sort(tempAns.begin(), tempAns.end());
                    finalAns.push_back(tempAns);

                    while (j < k and arr[j] == arr[j + 1])
                    {
                        j++;
                    }
                    while (j < k and arr[k] == arr[k - 1])
                    {
                        k--;
                    }
                }
            }
        }
        return finalAns;
    }
};

int main()
{
    return 0;
}