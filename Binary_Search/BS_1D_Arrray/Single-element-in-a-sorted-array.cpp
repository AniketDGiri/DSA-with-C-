#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int OptimalApproach(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
        {
            return nums[0];
        }

        if (nums[0] != nums[1])
            return nums[0];

        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        int low = 1, high = n - 2;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if ((nums[mid] != nums[mid - 1]) and (nums[mid] != nums[mid + 1]))
                return nums[mid];
            else if ((mid % 2 == 1 and nums[mid - 1] == nums[mid]) or (mid % 2 == 0) and nums[mid + 1] == nums[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 4, 4, 8, 8};
    Solution obj;
    cout << obj.OptimalApproach(arr) << endl;
    return 0;
}