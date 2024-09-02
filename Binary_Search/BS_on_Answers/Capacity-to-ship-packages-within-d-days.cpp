#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
private:
    int calcuateWeight(vector<int> &nums, int mid)
    {
        int totalPackages = 0;
        int tempPackages = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (tempPackages + nums[i] <= mid)
            {
                tempPackages += nums[i];
            }
            else
            {
                totalPackages++;
                tempPackages = nums[i];
            }
        }
        if (tempPackages > 0)
        {
            totalPackages++;
        }
        return totalPackages;
    }

public:
    int OptimalApproach(vector<int> &weights, int days)
    {
        int low = INT_MIN;
        int high = 0;
        int n = weights.size();
        for (int i = 0; i < n; i++)
        {
            high += weights[i];
            low = max(low, weights[i]);
        }

        while (low <= high)
        {
            int mid = (low + high) / 2;
            int cnt = calcuateWeight(weights, mid);
            if (cnt <= days)
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
    vector<int> arr = {1, 2, 3, 1, 1};
    int days = 4;
    Solution obj;
    cout << obj.OptimalApproach(arr, days) << endl;
    return 0;
}