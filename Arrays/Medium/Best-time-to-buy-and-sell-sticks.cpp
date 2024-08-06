#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int Approach2(vector<int> &nums)
    {
        int maxSum = 0;
        int tempSum = 0;
        int buyStock = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (buyStock < nums[i])
            {
                buyStock = nums[i];
            }
            else
            {
                tempSum = nums[i] - buyStock;
                maxSum = max(maxSum, tempSum);
            }
        }
        return maxSum;
    }
};

int main()
{
    return 0;
}