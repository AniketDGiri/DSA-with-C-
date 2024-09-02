#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

class Solution
{
private:
    int calculateCountOfDivisors(vector<int> &nums, int mid)
    {
        int totalCnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            totalCnt += ceil((float)nums[i] / mid);
        }
        return totalCnt;
    }

public:
    int OptimalApproach(vector<int> &nums, int threshold)
    {
        int n = nums.size();
        int low = 1;
        int high = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            high = max(high, nums[i]);
        }

        while (low <= high)
        {
            int mid = (low + high) / 2;
            int cnt = calculateCountOfDivisors(nums, mid);
            if (cnt <= threshold)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main()
{
    vector<int> arr = {1, 2, 5, 9};
    Solution obj;
    cout << obj.OptimalApproach(arr, 6) << endl;
    return 0;
}