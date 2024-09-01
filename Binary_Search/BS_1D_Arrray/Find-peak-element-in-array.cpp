#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    int BruteForceApproach(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if ((i == 0 || (nums[i] > nums[i - 1])) && (i == n - 1) || (nums[i + 1] < nums[i]))
            {
                return i;
            }
        }
        return INT_MAX;
    }

    int OptimalApproach(vector<int> &nums)
    {
        int n = nums.size();
        int low = 1;
        int high = n - 2;

        if (n == 1)
        {
            return 0;
        }
        if (nums[0] > nums[1])
        {
            return 0;
        }
        if (nums[n - 1] > nums[n - 2])
        {
            return n - 1;
        }
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if ((nums[mid] > nums[mid - 1]) and (nums[mid] > nums[mid + 1]))
            {
                return mid;
            }
            else if (nums[mid] > nums[mid - 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return INT_MAX;
    }
};

int main()
{
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    Solution obj;
    cout << "Peak element in array is:" << obj.BruteForceApproach(nums) << endl;
    return 0;
}