#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int OptimalAppraoch(vector<int> &nums)
    {
        int prefixSum = 1;
        int suffixSum = 1;
        int maxProduct = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            prefixSum *= nums[i];
            suffixSum *= nums[n - i - 1];
            maxProduct = max(maxProduct, max(prefixSum, suffixSum));

            if (prefixSum == 0)
            {
                prefixSum = 1;
            }
            if (suffixSum == 0)
            {
                suffixSum = 1;
            }
        }
        return maxProduct;
    }
};

int main()
{
    vector<int> arr = {2, 3, -2, 4};
    Solution obj;
    cout << obj.OptimalAppraoch(arr) << endl;
    return 0;
}