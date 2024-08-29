#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool OptimalApproach(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high)
        {
            // cout << "low: " << low << endl;
            // cout << "High: " << high << endl;

            int mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                return true;
            } // if
            else if (nums[low] <= nums[mid])
            {
                if (nums[low] == nums[mid])
                {
                    low = low + 1;
                }
                else if (nums[low] <= target and target <= nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            } // else if

            else
            {
                if (nums[mid] <= target and target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            } // else if

        } // while
        return false;
    }
};

int main()
{
    vector<int> arr = {1, 1, 1, 0, 1};
    Solution obj;
    cout << obj.OptimalApproach(arr, 0) << endl;
    return 0;
}